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

#include "ManipulationFiles.h"

bool isFile(const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

/* responsavel por validar se arquivos existe e abri-los, assim como retornar todas as linhas. */
std::vector<std::string> getFileLines(std::string filename)
{    
    std::ifstream patternFile;
    patternFile.open(filename);
    std::vector<std::string> outLines;
    std::string line;
    
    if (!patternFile)
    {
        printf("Not exists or corrupted file.");
        exit(EXIT_FAILURE);
    }
    
    while (getline(patternFile, line))
    {
        outLines.push_back(line);
    }
    
    patternFile.close();
    
    return outLines;
}