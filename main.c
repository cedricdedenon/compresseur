/**
 * @file main.c
 * @author Cedric DEDENON
 * @brief 
 * @version 0.2
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "functions.h"

int main(void){
  // Compression du fichier myFile.txt
  methodRLE("myFile", 'c');

  // Décompression du fichier myFile2.rle
  methodRLE("myFile2", 'd');
  return 1;
}