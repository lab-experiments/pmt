//
//  main.cpp
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely.
//  Copyright (c) 2015 Thaisa Mirely. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

#include "command_model.h"
#include "input_control.h"
#include "search.h"
#include "boyer_moore_algorithm.h"

int main(int argc, const char * argv[]) {
    
    Search::PSearchType out_search_type = nullptr;

    CommandModel command_model = SetCommand(argc, argv, out_search_type);
    
    Search search;
    search.SearchPattern(command_model, out_search_type);

    return 0;
}
