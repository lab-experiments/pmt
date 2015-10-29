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

#include "BoyerMooreAlgorithm.h"

#define MAX_CHAR_LEN 256

// Preprocessamento da heuristica de bad character
void badCharacter(std::string pattern, int len_pattern, int badCharacter[MAX_CHAR_LEN])
{
    int i;
    
    //inicializa todas as ocorrencias com -1
    for (i = 0; i < MAX_CHAR_LEN; i++)
    {
        badCharacter[i] = -1;
    }
    // Preenche o valor real da última ocorrência de um caractere
    for (i = 0; i < len_pattern; i++)
    {
        badCharacter[pattern[i]] = i;
    }
    
}


std::vector<int> search(std::string pattern, std::string text)
{
    std::vector<int> result;
    
    int len_pattern = (int)pattern.length();
    int len_text = (int)text.length();
    
    int badchar[MAX_CHAR_LEN];
    
    badCharacter(pattern, len_pattern, badchar);
    
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
            shift += (shift + len_pattern < len_text) ? len_pattern - badchar[text[shift + len_pattern]] : 1;
        }
        else
        {
            shift += std::max(1, i - badchar[text[shift + i]]);
        }
        
    }
    
    return result;
}

