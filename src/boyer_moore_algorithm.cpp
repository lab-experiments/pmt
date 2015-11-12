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
void BadCharacter(std::string pattern, int len_pattern, int bad_character[])
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



void ProcessBadCharacter(char *p_pattern, int len_pattern, int bad_character[]){
    int i;
    for(i=0; i<MAX_CHAR_LEN; ++i)
        bad_character[i] = len_pattern;
    for(i=0; i<len_pattern; ++i){
        bad_character[p_pattern[i]] =len_pattern-i-1;
    }
}



void GetSuffix(char *p_pattern, int len_pattern, int *p_suffix){
    int f = 0, g, i;
    
    p_suffix[len_pattern-1] = len_pattern;
    g = len_pattern-1;
    for(i = len_pattern-2;i>=0; --i){
        if(i > g && p_suffix[i+len_pattern-1-f]<i-g)
            p_suffix[i] = p_suffix[i+len_pattern-1-f];
        else{
            if(i<g)
                g=i;
            f=i;
            while(g >= 0 && p_pattern[g] == p_pattern[g+len_pattern-1-f])
                --g;
            p_suffix[i] = f-g;
        }
    }
    for(i = 0; i < len_pattern; i++);
}



void ProcessGoodSuffix(char *p_pattern, int len_pattern, int good_suffix[]){
    int i, j, p_suffix[MAX_CHAR_LEN];
    
    GetSuffix(p_pattern, len_pattern, p_suffix);
    
    for(i = 0; i < len_pattern; ++i)
        good_suffix[i] = len_pattern;
    j=0;
    
    for(i = len_pattern - 1; i >= -1; --i)
        if( i == - 1 || p_suffix[i] == i + 1)
            for(;j< len_pattern - 1 - i; ++j)
                if(good_suffix[j] == len_pattern){
                    good_suffix[j] = len_pattern - 1 - i;
                }
    
    for( i = 0; i <= len_pattern - 2; ++i){
        good_suffix[len_pattern - 1 - p_suffix[i]] = len_pattern - 1 - i;
    }
    for(i = 0; i < len_pattern; i++);
}



int MAX(int a, int b){
    if(a>b) return a;
    else return b;
}



std::vector<int> SearchUsingBoyerMoore(CommandModel command_model, std::string text, long long& duration)
{
    // inicia contador para tempo de execução da função
    high_resolution_clock::time_point begin_time = high_resolution_clock::now();
    
    std::string pattern = command_model.GetPattern();
    std::vector<int> result;
    int len_pattern = (int)pattern.length();
    int len_text = (int)text.length();
    char *p_pattern = &pattern[0u];
    char *p_text = &text[0u];
    
    int i, j, good_suffix[MAX_CHAR_LEN], bad_character[MAX_CHAR_LEN];
    
    ProcessGoodSuffix(p_pattern, len_pattern, good_suffix);
    
    ProcessBadCharacter(p_pattern, len_pattern, bad_character);
    
    j=0;
    while(j<= len_text - len_pattern){
        for(i = len_pattern - 1; i >=0 && p_pattern[i] == p_text[i+j]; --i);
        if(i<0){
            result.push_back(j);
            j+= good_suffix[0];
            // printf("\nj = %d\n", j);
        }
        else {
            j+= MAX(good_suffix[i], bad_character[p_text[i+j]] - len_pattern + 1 + i);
            // printf("\nj = %d\n", j);
        }
    }
    
    high_resolution_clock::time_point end_time = high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count();

    return result;
}

