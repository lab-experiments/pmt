//
//  inputControl.h
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely.
//

#ifndef __pmt_project__inputControl__
#define __pmt_project__inputControl__

#include <stdio.h>
#include "command_model.h"
#include "search.h"
#include "boyer_moore_algorithm.h"

#define VERSION_CODE "1.0"

//valida os dados argumentos de entrada do programa
CommandModel SetCommand(int argc, const char * argv[], Search::PSearchType& out_search_type);

#endif /* defined(__pmt_project__inputControl__) */
