//
//  manipulationFiles.cpp
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely.
//

#include <string.h>
#include <vector>
#include <fstream>
#include <sys/stat.h>

#include "manipulation_files.h"

bool IsFile(const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

//responsavel por validar se arquivos existe e abri-los, assim como retornar todas as linhas.//
std::vector<std::string> GetFileLines(std::string file_name)
{    
    std::ifstream pattern_file;
    pattern_file.open(file_name);
    std::vector<std::string> out_lines;
    std::string line;
    
    if (!pattern_file)
    {
        printf("Not exists or corrupted file.");
        exit(EXIT_FAILURE);
    }
    
    while (getline(pattern_file, line))
    {
        out_lines.push_back(line);
    }
    
    pattern_file.close();
    return out_lines;
}