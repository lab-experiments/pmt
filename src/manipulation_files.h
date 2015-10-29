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

bool IsFile(const std::string& name);

std::vector<std::string> GetFileLines(std::string file_name);

#endif /* defined(__pmt_project__manipulationFiles__) */
