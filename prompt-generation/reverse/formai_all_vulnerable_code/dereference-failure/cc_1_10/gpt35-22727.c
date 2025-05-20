//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

char* readFile(char* filename){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    char* buffer = (char*)malloc(MAX_LEN*sizeof(char));
    if(buffer == NULL){
        printf("Could not allocate memory for file %s\n", filename);
        exit(1);
    }

    int c;
    int i = 0;
    while((c = fgetc(fp)) != EOF && i < MAX_LEN-1){
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    fclose(fp);
    return buffer;
}

void writeFile(char* filename, char* output){
    FILE* fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Could not open file %s for writing\n", filename);
        exit(1);
    }

    fprintf(fp, "%s", output);
    fclose(fp);
}

int countIndent(char* line){
    int i = 0;
    while(line[i] == ' '){
        i++;
    }
    return i;
}

char* beautifyHTML(char* input){
    char* output = (char*)malloc(MAX_LEN*sizeof(char));
    if(output == NULL){
        printf("Could not allocate memory for output\n");
        exit(1);
    }

    int nestingLevel = 0;
    int indentLevel = 0;
    char* line = strtok(input, "\n");
    while(line != NULL){
        int len = strlen(line);

        // remove leading and trailing white space
        while(len > 0 && (line[len-1] == ' ' || line[len-1] == '\t')){
            line[--len] = '\0';
        }
        while(*line == ' ' || *line == '\t'){
            line++;
        }

        int currIndent = countIndent(line);
        if(currIndent < indentLevel){
            nestingLevel--;
        }
        indentLevel = currIndent;

        for(int i=0; i<nestingLevel; i++){
            strcat(output, "  ");
        }
        strcat(output, line);
        strcat(output, "\n");

        if(line[len-1] == '>' && line[len-2] != '/'){
            nestingLevel++;
        }

        line = strtok(NULL, "\n");
    }

    return output;
}

int main(){
    char* input = readFile("index.html");
    char* output = beautifyHTML(input);
    writeFile("output.html", output);
    printf("Beautification complete!\n");

    // free allocated memory
    free(input);
    free(output);
    return 0;
}