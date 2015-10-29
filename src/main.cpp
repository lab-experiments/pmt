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
#include "exact_matching.h"

int main(int argc, const char * argv[]) {
    
    CommandModel command_model = SetCommand(argc,argv);
    
    if(command_model.GetEmax()!= 0)
    {
     // TODO - implementacao pendente;
     // makeApproximateSearch(commandModel.getPattern(), commandModel.getTextFilenames(), commandModel.getEmax());
    }
    else
    {
        MakeExactSearch(command_model.GetPattern(), command_model.GetTextFileNames());
    }
    return 0;
}
