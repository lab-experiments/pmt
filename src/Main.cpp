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

#include "CommandModel.h"
#include "InputControl.h"
#include "ExactMatching.h"

int main(int argc, const char * argv[]) {
    
    CommandModel commandModel = setCommand(argc,argv);
    
    if(commandModel.getEmax()!= 0)
    {
     // TODO - implementacao pendente;
     // makeApproximateSearch(commandModel.getPattern(), commandModel.getTextFilenames(), commandModel.getEmax());
    }
    else
    {
        makeExactSearch(commandModel.getPattern(), commandModel.getTextFilenames());
    }
    return 0;
}
