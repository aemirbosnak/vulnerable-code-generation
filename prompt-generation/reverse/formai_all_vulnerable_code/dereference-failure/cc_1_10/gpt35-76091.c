//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
/* 
 * File:   fileEncryptor.c
 * Author: Ada Lovelace
 *
 * Created on October 17, 2021, 9:00 AM
 * Last Modified on October 17, 2021, 10:00 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define KEY 15 //Encryption key

int main(int argc, char** argv) {
    
    FILE * inputFile = NULL;
    FILE * outputFile = NULL;
    
    char inputFilepath[50], outputFilepath[50], character;
    
    printf("Enter input file path: ");
    scanf("%s", inputFilepath);
    
    printf("Enter output file path: ");
    scanf("%s", outputFilepath);
    
    inputFile = fopen(inputFilepath, "r");
    outputFile = fopen(outputFilepath, "w");
    
    if(inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    } 
    
    if(outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(EXIT_FAILURE);
    }
    
    character = getc(inputFile);
    
    while(character != EOF) {
        fputc(character + KEY, outputFile);
        character = getc(inputFile);
    }
    
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Encryption completed successfully!\n");
    
    return(EXIT_SUCCESS);
}