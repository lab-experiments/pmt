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


std::vector<int> Search(std::string pattern, std::string text)
{
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
}

