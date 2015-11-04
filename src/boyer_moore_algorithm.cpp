//
//  BoyerMooreAlgorithm.cpp
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely.
//

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "boyer_moore_algorithm.h"
#include "command_model.h"

using namespace std::chrono;

#define MAX_CHAR_LEN 256

// Preprocessamento da heuristica de bad character
void BadCharacter(std::string pattern, int len_pattern, int bad_character[MAX_CHAR_LEN])
{
    int i;
    //inicializa todas as ocorrencias com -1
    for (i = 0; i < MAX_CHAR_LEN; i++)
    {
        bad_character[i] = -1;
    }
    // Preenche o valor real da última ocorrência de um caractere
    for (i = 0; i < len_pattern; i++)
    {
        bad_character[pattern[i]] = i;
    }
}

void GoodSufixx()
{

}


std::vector<int> SearchUsingBoyerMoore(CommandModel command_model, std::string text, long long& duration)
{
    // inicia contador para tempo de execução da função
    //high_resolution_clock::time_point begin_time = high_resolution_clock::now();
    
    std::string pattern = command_model.GetPattern();
    int bad_char[MAX_CHAR_LEN];
    std::vector<int> result;
    int len_pattern = (int)pattern.length();
    int len_text = (int)text.length();
    
    BadCharacter(pattern, len_pattern, bad_char);
    
    int shift = 0;
    while (shift <= (len_text - len_pattern))
    {
        int i = len_pattern - 1;
        
        while (i >= 0 && pattern[i] == text[shift + i])
        {
            i--;
        }
        if(i < 0)
        {
            result.push_back(shift);
            shift += (shift + len_pattern < len_text) ? len_pattern - bad_char[text[shift + len_pattern]] : 1;
        }
        else
        {
            shift += std::max(1, i - bad_char[text[shift + i]]);
        }
    }
    
    return result;
    
   // high_resolution_clock::time_point end_time = high_resolution_clock::now();
   // duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count();

}

