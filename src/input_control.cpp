//
//  inputControl.cpp
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely.
//  Copyright (c) 2015 Thaisa Mirely. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>

#include "input_control.h"
#include "manipulation_files.h"
#include "search.h"
#include "boyer_moore_algorithm.h"

void ShowHelp();

std::vector<std::string> ParseArgumentsFileName(int index, const char* args[],CommandModel command_model, std::string& pattern);



/* Estrutura com as opcoes da linha de comando.
 *TODO - adicao do comando -e, -edit, para busca aproximada
 */
const struct option CommandOptions[] =
{
    {"version", no_argument,       0, 'v'},
    {"help",    no_argument,       0, 'h'},
  //{"edit",    required_argument, 0, 'e'},
    {"pattern", required_argument, 0, 'p'},
    { 0,         0,                0,  0 },
};



CommandModel SetCommand(int argc, const char * argv[], Search::PSearchType& out_search_type){
 
    CommandModel command_model;
    int n_option;
    const char* option_string = "vhe:p:";
    std::string pattern;

    //Obtem os argumentos atraves do metodo getopt_long e determina a funcao de dada opcao
    while ( (n_option = getopt_long(argc, (char**)argv, option_string, CommandOptions, NULL)) > 0 )
    {
        switch (n_option)
        {
            case 'v':
                printf("pmt version %s", VERSION_CODE) ;
                break ;
            case 'h':
                ShowHelp() ;
                break ;
            //TODO - Implementacao pendente. Busca aproximada
            //case 'e':
            //    commandModel.setEmax(atoi(optarg));
            //    break ;
            case 'p':
                command_model.SetPattern(optarg);
                break ;
            default: ShowHelp();
                exit(EXIT_FAILURE);
        }
    }
    
    
    //verifica se ha arquivos de texto informados nos argumentos de excesso
    if (argv[optind] != NULL )
    {
        command_model.SetTextFilenames(ParseArgumentsFileName(optind, argv, command_model, pattern));
        if (!pattern.empty())
        {
            command_model.SetPattern(pattern);
        }
        
    }
    
    
    //checa se o padrao eh informado via arquivo ou string
    if(command_model.GetPattern().empty())
    {
        fprintf(stdout,"Pattern uninformed.");
        exit(EXIT_FAILURE);
    }
    
    
    if (command_model.GetEmax() != 0)
    {
        //SearchOccurrences = SearchUsingBoyerMoore;
    }
    else
    {
        out_search_type = SearchUsingBoyerMoore;
    }
    
    return command_model;
}



//obtem os argumentos em excesso e converte seu nome da forma wildcard para a forma literal
std::vector<std::string> ParseArgumentsFileName(int index,const char* args[],CommandModel command_model, std::string& pattern)
{
    std::vector<std::string> result_args_file_name;
    int flags = 0;
    glob_t results;
    int _return;
    
    for(int i = optind; args[i] != NULL; i++) {
        flags |= (1 > 1 ? GLOB_APPEND : 0);
        _return = glob(args[i], flags, 0, & results);
        if (_return != 0) {
            if(optind == 1)
            {
                //verifica se o primeiro parametro extra eh um padrao
                std::string first_arg(args[optind]);
                if(command_model.GetPattern().empty())
                {
                    if((first_arg.size() > 4) && (first_arg.substr(first_arg.size()-4) == ".txt"))
                    {
                        fprintf(stdout,"The pattern should be entered as a string and not as a pattern file.");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        pattern = first_arg;
                    }
                }
             }
             else
             {
                // exibe erro ao nao conseguir converter o nome do arquivo para literal
                fprintf(stderr, "%s: problem with %s (%s), stopping early\n",
                    args[0], args[i],
                    (_return == GLOB_ABORTED ? "filesystem problem" :
                     _return == GLOB_NOMATCH ? "no match of pattern" :
                     _return == GLOB_NOSPACE ? "no dynamic memory" : "unknown problem"));
                break;
              }
          }
    }
    
    //salva os nomes dos arquivos convertidos
    for (int i = 0; i < results.gl_pathc; i++)
    {
        result_args_file_name.push_back(results.gl_pathv[i]);
    }
    
    if(result_args_file_name.empty())
    {
        fprintf(stdout,"Text to search uninformed.");
        exit(EXIT_FAILURE);
    }
    
    globfree(& results);
    return result_args_file_name;
}



//funcao para exibicao de texto de ajuda, indicando o padrao de comando e as opcoes disponiveis.
void ShowHelp()
{
    fprintf(stdout, "pmt version %s \n\
            command structure -  $ pmt [options] pattern textfile [textfile...]\n\
            <options>:\n\
            -v, --version            :   Print the version number of pmt, and exit.\n\n\
            -h, --help               :   Print a help message briefly summarizing command-line options, and exit\n\n\
            -p, --pattern patternfile:   Performs the search of all the standards contained in the file 'patternfile'\n\n\
            'patternfile' is a text file containing several standards\n", VERSION_CODE);
    exit(-1) ;
    
    //TODO adição do parametro de distancia de edicao:
    //-e, --edit emax          :   Finds all standard approximate occurrences in a maximum edition of distance 'emax'\n\n\
    //'emax' it is an integer, equivalent the maximum edition of distance\n\n\

}

