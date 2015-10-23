/*
 * [main.c] - Defining feature of command line arguments
 * Program to search exact and approximate search patterns in text.
 * Similar to the GNU grep program
 *
 */

 /* Written October, 2015 by Thaisa Mirely */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <glob.h>

#define VERSION_CODE "1.0"

extern char parttern;
extern char *text_file;

void show_help() {
    fprintf(stderr, "pmd version %s \n\
            command structure -  $ pmt [options] pattern textfile [textfile...]\n\
            <options>:\n\
            -v, --version            :   Print the version number of pmt, and exit.\n\n\
            -h, --help               :   Print a help message briefly summarizing command-line options, and exit\n\n\
            -e, --edit emax          :   Finds all standard approximate occurrences in a maximum edition of distance 'emax'\n\n\
                                         'emax' it is an integer, equivalent the maximum edition of distance\n\n\
            -p, --pattern patternfile:   Performs the search of all the standards contained in the file 'patternfile'\n\n\
                                         'patternfile' is a text file containing several standards\n", VERSION_CODE);
    exit(-1) ;
}


int main(int argc, char **argv) {

    int option;
    int maximum_distance_of_edition = 0;
    char *pattern_file = NULL;
    const char *option_string = "vhe:p:";

    /* Options structure */
    const struct option command_options[] = {
        {"version", no_argument,       0, 'v'},
        {"help",    no_argument,       0, 'h'},
        {"edit",    required_argument, 0, 'e'},
        {"pattern", required_argument, 0, 'p'},
        { 0,         0,                0,  0 },
    };

    while ( (option = getopt_long(argc, argv, option_string, command_options, NULL)) > 0 ) {
        switch (option) {
            case 'v':
                printf("pmt version %s", VERSION_CODE) ;
                break ;
            case 'h':
                show_help() ;
                break ;
            case 'e':
                maximum_distance_of_edition = atoi(optarg);
                break ;
            case 'p':
                pattern_file = optarg;
                break ;
            default: show_help();
                 exit(EXIT_FAILURE);
        }
    }
}
