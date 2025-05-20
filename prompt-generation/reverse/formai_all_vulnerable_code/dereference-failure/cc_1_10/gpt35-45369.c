//FormAI DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char* inputfile, char* outputfile, char* keyword);

int main(int argc, char** argv){

    if(argc!=4){
        printf("Error: Incorrect number of arguments. Usage: ./encrypt inputfile outputfile keyword\n");
        return 1;
    }

    char* inputfile = argv[1];
    char* outputfile = argv[2];
    char* keyword = argv[3];

    encrypt(inputfile, outputfile, keyword);

    printf("File %s has been successfully encrypted using keyword %s.\n", inputfile, keyword);
    printf("Encrypted text has been written to file %s.\n", outputfile);

    return 0;
}

void encrypt(char* inputfile, char* outputfile, char* keyword){

    FILE* input = fopen(inputfile, "r");
    FILE* output = fopen(outputfile, "w");

    if(input==NULL || output==NULL){
        printf("Error: Unable to open file.\n");
        return;
    }

    char* buffer = malloc(sizeof(char)*256);
    char* encrypted = malloc(sizeof(char)*256);
    char* encryptedChar = malloc(sizeof(char)*2);
    encryptedChar[1] = '\0';

    int keywordLen = strlen(keyword);
    int i, j;

    while(fgets(buffer, 256, input)){

        int bufferLen = strlen(buffer);

        for(i=0, j=0; i<bufferLen-1; i++, j++){

            if(j==keywordLen){
                j=0;
            }

            encryptedChar[0] = buffer[i] ^ keyword[j];
            strcat(encrypted, encryptedChar);
        }

        strcat(encrypted, "\n");
        fprintf(output, "%s", encrypted);

        memset(buffer, 0, sizeof(char)*256);
        memset(encrypted, 0, sizeof(char)*256);
    }

    free(buffer);
    free(encrypted);
    free(encryptedChar);

    fclose(input);
    fclose(output);
}