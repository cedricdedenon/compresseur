/**
 * @file functions.h
 * @author Cedric DEDENON
 * @brief 
 * @version 0.2
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TMAX 500
#define CAR_1 '#'
#define CAR_2 '&'

void methodRLE(char *nameFile, char c_d);
char* algoCompressionRLE(char *text);
char* algoDecompressionRLE(char *text);

#endif