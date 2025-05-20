//FormAI DATASET v1.0 Category: File Encyptor ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 1024

void encrypt(char * data, int key);

int main(int argc, char** argv){

    if(argc != 3){
        printf("Usage: ./encrypt <input_file> <output_file> <key>");
        exit(1);
    }

    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");
    int key = atoi(argv[3]);

    if(in == NULL || out == NULL){
        printf("Error opening input or output file.");
        exit(1);
    }

    char* data = (char*) malloc(sizeof(char) * MAX_SIZE);
    int length = 0;

    while((data[length++] = fgetc(in)) != EOF){
        if(length > MAX_SIZE){
            printf("Input file is too large.");
            exit(1);
        }
    }

    encrypt(data, key);
    fprintf(out,"%s", data);

    free(data);
    fclose(in);
    fclose(out);

    printf("File %s encrypted successfully.", argv[1]);

    return 0;
}

void encrypt(char * data, int key){

    for(int i = 0; data[i] != '\0'; i++){
        if(isalpha(data[i])){
            if(isupper(data[i])){
                data[i] = ((data[i] - 'A' + key) % 26) + 'A';
            } else {
                data[i] = ((data[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
}