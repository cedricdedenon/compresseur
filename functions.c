/**
 * @file functions.c
 * @author Cedric DEDENON
 * @brief 
 * @version 0.2
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "functions.h"

/**
 * @brief Ouvre le fichier entré en paramètre en lecture. Crée en sortie un second fichier correspondant à la compression ou la décompression
 *        du fichier initial. La compression ou la décompression est déterminée grâce à second paramètre 
 * 
 * @param nameFile le nom du fichier à compresser ou à décompresser
 * @param c_d compression (c_d=c) ou décompresser (c_d=d)
 */
void methodRLE(char *nameFile, char c_d){ 
    FILE *file1 = NULL;
    FILE *file2 = NULL;
    char *content, temp[TMAX]; 
    char fileName1[TMAX];
    char fileName2[TMAX];

    /*Pour la compression, on crée un fichier contenant le même nom mais avec l'extension .rle
    Pour la décompression, on crée un fichier contenant le même nom mais avec l'extension .txt */
    strcpy(fileName1, nameFile);
    strcpy(fileName2, nameFile);
    if(c_d == 'c'){
        strcat(fileName1, ".txt");
        strcat(fileName2, ".rle");
    } else{
        strcat(fileName1, ".rle");
        strcat(fileName2, ".txt");
    }
  
    if((file1=fopen(fileName1,"r")) == (FILE*) NULL || (file2=fopen(fileName2, "w+")) == (FILE*) NULL){
        printf("\nErreur pendant l'ouverture de fichier %s\n", nameFile);
        exit(567);
    }
    else{
        printf("\nOuverture reussi de %s\n", nameFile);
        // On lit ligne par ligne le fichier, et on applique l'algorithme de compression ou de décompression correspondant
        while(feof(file1) == 0){
            fgets(temp, TMAX, file1);
            if(c_d == 'c'){
                // Compression 
                content = algoCompressionRLE(temp);
            } else{
                // Décompression
                content = algoDecompressionRLE(temp);
            }
            fprintf(file2, content);
        }
    }

    fclose(file1);
    fclose(file2);
}


/**
 * @brief Algorithme de compression du fichier (ligne par ligne) selon la méthode RLE
 * 
 * @param content la chaine de caractères à compresser
 * @return char* la chaine de caractères compressée
 */
char* algoCompressionRLE(char *content){
    char *temp = "";
    int i=0, j=0, k=0, nb=1, p=0;
    char c, c_prev=content[0];

    for(i=1; content[i] != '\0'; i++){
        c = content[i];
        c_prev = content[i-1];

        if(c == c_prev){    
            nb++;
        } else{
            if(nb>=10){
                p = floor(nb/10);
                for(k=0;k<p;k++){
                    temp[j] = CAR_1; j++;
                    temp[j] = CAR_2; j++;
                }
                nb = nb-(p*10);
                if(nb == 1){
                    temp[j] = c_prev; j++;
                }
                if(nb == 0) nb=1;
            }

            if(nb>=1 && nb<4){
                for(k=0;k<nb;k++){
                    temp[j] = c_prev; j++;
                }
                nb=1;
            }
            else if (nb>=4 && nb<10){
                temp[j] = CAR_1; j++;
                temp[j] = nb + '0'; j++;
                temp[j] = c_prev; j++;
                nb=1;
            } 
        }           
    } 

 if(nb>=10){
    p = floor(nb/10);
    for(k=0;k<p;k++){
        temp[j] = CAR_1; j++;
        temp[j] = CAR_2; j++;
    }
    nb = nb-(p*10);
    if(nb == 1){
        temp[j] = c; j++;
    }
    if(nb == 0) nb=1;
}

    if(nb>=1 && nb<4){
        for(k=0;k<nb;k++){
            temp[j] = c; j++;
        }
        nb=1;
    } else if (nb>=4 && nb<10){
        temp[j] = CAR_1; j++;
        temp[j] = nb + '0'; j++;
        temp[j] = c; j++;
        nb=1;
    }  

    temp[j] = '\0';
    return temp;
}

/**
 * @brief Algorithme de décompression du fichier (ligne par ligne) selon la méthode RLE
 * 
 * @param content la chaine de caractères à décompresser
 * @return char* la chaine de caractères décompressée
 */
char* algoDecompressionRLE(char *content){
    char *temp = "";
    int i=0, j=0, k=0, nb=0, add_nb=0;
    char c, c_prev=content[0];

    for(i=1; content[i] != '\0'; i++){
        c = content[i];
        c_prev = content[i-1];

        if(c_prev == CAR_1){
            if(c == CAR_2){
                add_nb += 10;
            }
            if(isdigit(c)){
                nb = c - '0';
            }
        }else{
            if(add_nb != 0 && c != CAR_1){
                nb += add_nb;
                add_nb = 0;
            }

            if(nb > 1){
                for(k=1;k<nb;k++){
                    temp[j] = c; j++;
                }   
                nb = 0;
            } else if(c_prev != CAR_2){
                temp[j] = c_prev; j++;
            } 
        }
    }
    temp[j] = c; j++;
    temp[j] = '\0';
    return temp;
}
