//
//  manipulationFiles.h
//  pmt-project
//
// Created in october, 2015 by Thaisa Mirely.
//

#ifndef __pmt_project__manipulationFiles__
#define __pmt_project__manipulationFiles__

#include <string.h>
#include <vector>
#include <fstream>

bool isFile(const std::string& name);

/* responsavel por validar se arquivos existe e abri-los, assim como retornar todas as linhas. */
std::vector<std::string> getFileLines(std::string filename);

#endif /* defined(__pmt_project__manipulationFiles__) */
