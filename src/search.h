//
//  Search.hpp
//  pmt
//
//  Created by Thaisa Mirely on 10/30/15.
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef search_h
#define search_h

#include <stdio.h>
#include "command_model.h"
#include "boyer_moore_algorithm.h"

class Search{

private:
    std::vector<int> occurrence_per_line;
    std::vector<std::string> out_lines;
    std::vector<int> n_lines;
    std::vector<long> n_BM_duratio_excecution;
    
    void SearchPatternInFiles(std::string pattern, CommandModel command_model);
    void SearchResultOut(std::string text_file_names);

public:
    typedef std::vector<int> (*PSearchType)(CommandModel, std::string, long long&);
    void SearchPattern(CommandModel command_model, PSearchType p_search_type);

};
#endif /* Search_hpp */
