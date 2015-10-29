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

#include "ManipulationFiles.h"
#include "ExactMatching.h"
#include "BoyerMooreAlgorithm.h"

using namespace std::chrono;

std::vector<int> occurrencePerLine;
std::vector<std::string> outLines;
std::vector<int> nLines;
std::vector<long> nBMDurationExcecution;

void searchResultOut(std::string textFilenames);

void searchPattern(std::string pattern, std::vector<std::string> textFiles);

void outputResult();

/*metodo responsavel por selecionar a estrutura de busca padrao, se via arquivo de padrao ou string*/
void makeExactSearch(std::string pattern, std::vector<std::string> textFilenames)
{
    std::vector<std::string> patternLines;

    if(isFile(pattern))
    {
        patternLines = getFileLines(pattern);

        for (int i = 0; i < patternLines.size(); i++)
        {
            searchPattern(patternLines[i], textFilenames);
        }
    }
    else
    {
        searchPattern(pattern, textFilenames);
    }
}


void searchPattern(std::string pattern, std::vector<std::string> textFiles)
{
    for(int j = 0; j < textFiles.size(); j++){

        std::ifstream file;
        file.open(textFiles[j].c_str());
        std::string line;

        if (!file)
        {
            printf("Not exists or corrupted file.");
            exit(EXIT_FAILURE);
        }

        int index = 1;
        while (getline(file, line))
        {
            // inicia contador para tempo de execução da função
            // high_resolution_clock::time_point begin_time = high_resolution_clock::now();

            std::vector<int> result_by_line = search(pattern, line);

            // inicia contador para tempo de execução da função
            // high_resolution_clock::time_point end_time = high_resolution_clock::now();
            // long duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count();
            // nBMDurationExcecution.push_back(duration);

            if(!result_by_line.empty()){
                nLines.push_back(index);
                outLines.push_back(line);
                occurrencePerLine.push_back((int)result_by_line.size());
            }
            index++;
        }

        file.close();

        searchResultOut(textFiles[j].c_str());
    }

}


/* exibição de resultado das buscas no console */
void searchResultOut(std::string textFilenames)
{
    int occur = 0;
    for (int i = 0; i < occurrencePerLine.size(); i++ )
    {
        occur += occurrencePerLine[i];
    }
    printf("[occurrences numbers]: %d\n ", occur);
    printf("-----------------------------------------------\n");

    for (int i = 0; i < nLines.size(); i++) {
        printf("[%s] - line %d : %s \n ", textFilenames.c_str(), nLines[i], outLines[i].c_str());

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


void outputReport()
{


}
