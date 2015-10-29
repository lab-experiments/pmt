//
//  inputControl.h
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely.
//

#ifndef __pmt_project__inputControl__
#define __pmt_project__inputControl__

#include <stdio.h>

#include "CommandModel.h"

#define VERSION_CODE "1.0"

/*valida os dados argumentos de entrada do programa*/
CommandModel setCommand(int argc, const char * argv[]);

#endif /* defined(__pmt_project__inputControl__) */
