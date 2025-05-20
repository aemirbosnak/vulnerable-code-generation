//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4
#define MAX_LINE_LENGTH 1024

void beautify(char* input){
    int indent = 0, i = 0, j = 0;
    char* output = malloc(MAX_LINE_LENGTH*sizeof(char));

    while(input[i]!='\0'){
        if(input[i] == '<'){
            if(input[i+1] == '/' && indent > 0){
                indent--;
            }
            for(int k = 0; k < TAB_SIZE*indent; k++){
                output[j++] = ' ';
            }

            if(input[i+1]!='/'){
                indent++;
            }
        }
        output[j++] = input[i++];
        if (input[i-1] == '\n') {
            //Check for pre-existing indent
            int space_count = 0;
            for(int k = i; input[k] == ' '; k++){
                space_count++;
            }

            if(input[i] == '<' && input[i+1]!='/'){
                //Leave current indent
            } 
            else if (space_count % TAB_SIZE == 0) {
                indent = space_count / TAB_SIZE;
            } 
            else {
                //Add on one extra tab
                indent = (space_count / TAB_SIZE)+1;
            }
        }
    }
    output[j] = '\0';
    printf("%s",output);
    free(output);
}

int main(int argc, char** argv){
    if(argc != 2){
        fprintf(stderr, "Usage: html-beautifier FILENAME.html\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if(!file){
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char* input = malloc(MAX_LINE_LENGTH*sizeof(char));
    while(fgets(line, MAX_LINE_LENGTH, file)){
        strcat(input, line);
    }
    fclose(file);

    beautify(input);
    free(input);

    return 0;
}