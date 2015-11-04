//
//  Search.cpp
//  pmt
//
//  Created by Thaisa Mirely on 10/30/15.
//  Copyright © 2015 tmbs. All rights reserved.
//

#include "search.h"
#include "manipulation_files.h"
#include "boyer_moore_algorithm.h"

Search::PSearchType p_search = nullptr;

void Search::SearchPattern(CommandModel command_model, Search::PSearchType p_search_type)
{
    std::vector<std::string> pattern_lines;
    p_search = p_search_type;
    
    if(IsFile(command_model.GetPattern()))
    {
        pattern_lines = GetFileLines(command_model.GetPattern());
    }
    else
    {
        pattern_lines.push_back(command_model.GetPattern());
    }
    
    
    for (int i = 0; i < pattern_lines.size(); i++)
    {
        SearchPatternInFiles(pattern_lines[i], command_model);
    }
    
}



void Search::SearchPatternInFiles(std::string pattern, CommandModel commad_model)
{
    for(int j = 0; j < commad_model.GetTextFileNames().size(); j++){
        
        std::ifstream file;
        file.open(commad_model.GetTextFileNames()[j].c_str());
        std::string line;
        
        if (!file)
        {
            printf("Not exists or corrupted file.");
            exit(EXIT_FAILURE);
        }
        
        int index = 1;
        while (std::getline(file, line))
        {
            long long duration = 0;
            
            std::vector<int> result_by_line = p_search(commad_model, line, duration);
            n_BM_duratio_excecution.push_back(duration);
            
            if(!result_by_line.empty()){
                n_lines.push_back(index);
                out_lines.push_back(line);
                occurrence_per_line.push_back((int)result_by_line.size());
            }
            index++;
        }
        
        file.close();
        
        SearchResultOut(commad_model.GetTextFileNames()[j].c_str());
    }
}



//exibição de resultado das buscas no console
void Search::SearchResultOut(std::string text_file_name)
{
    int occur = 0;
    for (int i = 0; i < occurrence_per_line.size(); i++ )
    {
        occur += occurrence_per_line[i];
    }
    printf("[occurrences numbers]: %d\n ", occur);
    printf("***********************************************************\n");
    
    for (int i = 0; i < Search::n_lines.size(); i++) {
        printf("[%s]- line %d : %s \n ", text_file_name.c_str(), n_lines[i], out_lines[i].c_str());
    }
    printf("***********************************************************\n");
    
    occurrence_per_line.clear();
    n_lines.clear();
    out_lines.clear();
    n_BM_duratio_excecution.clear();
}


