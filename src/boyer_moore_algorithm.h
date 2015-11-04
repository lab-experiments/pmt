//
//  BoyerMooreAlgorithm.h
//  pmt-project
//
// Created in october, 2015 by Thaisa Mirely.
//

#ifndef __pmt_project__BoyerMooreAlgorithm__
#define __pmt_project__BoyerMooreAlgorithm__

#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

#include "command_model.h"

std::vector<int> SearchUsingBoyerMoore(CommandModel command_line, std::string text_line, long long& duration);

#endif /* defined(__pmt_project__BoyerMooreAlgorithm__) */
