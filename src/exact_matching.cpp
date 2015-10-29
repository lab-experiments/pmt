//
//  exactMatching.cpp
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely.
//

#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>

#include "manipulation_files.h"
#include "exact_matching.h"
#include "boyer_moore_algorithm.h"

using namespace std::chrono;

std::vector<int> occurrence_per_line;
std::vector<std::string> out_lines;
std::vector<int> n_lines;
std::vector<long> n_BM_duratio_excecution;

void SearchResultOut(std::string text_file_names);

void SearchPattern(std::string pattern, std::vector<std::string> text_files);

void OutputResult();

//metodo responsavel por selecionar a estrutura de busca padrao, se via arquivo de padrao ou string
void MakeExactSearch(std::string pattern, std::vector<std::string> text_file_names)
{
    std::vector<std::string> pattern_lines;

    if(IsFile(pattern))
    {
        pattern_lines = GetFileLines(pattern);
        for (int i = 0; i < pattern_lines.size(); i++)
        {
            SearchPattern(pattern_lines[i], text_file_names);
        }
    }
    else
    {
        SearchPattern(pattern, text_file_names);
    }
}


void SearchPattern(std::string pattern, std::vector<std::string> text_files)
{
    for(int j = 0; j < text_files.size(); j++){

        std::ifstream file;
        file.open(text_files[j].c_str());
        std::string line;

        if (!file)
        {
            printf("Not exists or corrupted file.");
            exit(EXIT_FAILURE);
        }

        int index = 1;
        while (std::getline(file, line))
        {
            // inicia contador para tempo de execução da função
            // high_resolution_clock::time_point begin_time = high_resolution_clock::now();

            std::vector<int> result_by_line = Search(pattern, line);

            // inicia contador para tempo de execução da função
            // high_resolution_clock::time_point end_time = high_resolution_clock::now();
            // long duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count();
            // nBMDurationExcecution.push_back(duration);

            if(!result_by_line.empty()){
                n_lines.push_back(index);
                out_lines.push_back(line);
                occurrence_per_line.push_back((int)result_by_line.size());
            }
            index++;
        }

        file.close();

        SearchResultOut(text_files[j].c_str());
    }
}


//exibição de resultado das buscas no console
void SearchResultOut(std::string text_file_names)
{
    int occur = 0;
    for (int i = 0; i < occurrence_per_line.size(); i++ )
    {
        occur += occurrence_per_line[i];
    }
    printf("[occurrences numbers]: %d\n ", occur);
    printf("-----------------------------------------------\n");

    for (int i = 0; i < n_lines.size(); i++) {
        printf("[%s] - line %d : %s \n ", text_file_names.c_str(), n_lines[i], out_lines[i].c_str());
    }
    printf("\n ");

// Relatorio de tempo de execucao
    // long sum = 0;
    // long long result = 0;
    // for (int i = 0; i < nBMDurationExcecution.size(); i++ )
    // {
    //     sum += nBMDurationExcecution[i];
    // }
    // result = sum / nLines.size();
    // printf("[occurrences numbers]: %lld\n ", result);
}