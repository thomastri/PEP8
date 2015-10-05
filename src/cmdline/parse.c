/* ************************************************************************* *
 * parse.c         p2                                                          *
 * -------                                                                   *
 *  Author:   YOUR NAME HERE                                                 *
 *  Purpose:  This code is used to parse the command-line arguments for      *
 *            CS 350 project 1.                                              *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.                                                    *
 * ************************************************************************* */

#include <stdio.h>              /* standard I/O */
#include <unistd.h>             /* declares getopt() */
#include <ctype.h>              /* declares isprint() */
#include <stdint.h>
#include <stdlib.h>

#include "parse.h"              /* prototypes for exported functions */

/* ************************************************************************* *
 * Local function prototypes                                                 *
 * ************************************************************************* */


/* ************************************************************************* *
 * Global variable declarations                                              *
 * ************************************************************************* */


/* ************************************************************************* *
 * parse_command_line -- parses the command-line arguments using getopt()    *
 *                                                                           *
 * Parameters                                                                *
 *   argc -- the number of command-line arguments                            *
 *   argv -- the array of command-line arguments (array of pointers to char) *
 *                                                                           *
 * Returns                                                                   *
 *   Parsing success status. If the command-line arguments are successfully  *
 *   parsed with no errors, we return the value 0. If any errors occur (such *
 *   as passing an invalid flag or passing a file that does not exist), we   *
 *   return 1 back to the calling function and stop processing               *
 *                                                                           *
 * Notes                                                                     *
 *   This function is designed to be extensible for multiple command-line    *
 *   options. In C, though, you can only return a single value. We get       *
 *   around this restriction by using call-by-reference parameters. For      *
 *   instance, if we want to set a boolean value, the parameter list would   *
 *   be modified as:                                                         *
 *                                                                           *
 *     parse_command_line (..., bool * boolval)                              *
 *                                                                           *
 *   Then, the function would be called from somewhere else like:            *
 *                                                                           *
 *     bool my_bool_value;                                                   *
 *     int return_code;                                                      *
 *     return_code = parse_command_line (..., &my_bool_value);               *
 * ************************************************************************* */

int
parse_command_line (int argc, char **argv, char **filename, char **typeflag)
{
	uint32_t iflag = 0;
	//uint32_t sflag = 0;
	opterr = 0;
	uint32_t c;

	while ((c = getopt(argc, argv, ":s:i")) != -1)
		{
			switch (c)
			{
			case 'i':
				iflag = 1;
				break;
			case 's':
				//sflag = 1;
				break;
			case '?':
				if (optopt == 'c')
					fprintf(stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
				return 1;
			default:
				return 1;

			}
		}
		*filename = argv[optind];

		if (iflag == 1){
			*typeflag = "i";
		}

    //printf ("Replace this with code that calls getopt();\n");
    //printf ("See http://www.gnu.org/software/libc/manual/html_node/Getopt.html\n");

    return 0;
}
