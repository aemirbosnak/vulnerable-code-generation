//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const int MAX_SIZE = 10000;

char* get_input(){
    char* input = (char*) malloc(MAX_SIZE * sizeof(char));
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = 0;

    return input;
}

bool is_whitespace(char c){
    if(c == ' ' || c == '\t' || c == '\n'){
        return true;
    }

    return false;
}

void remove_whitespace(char* input){
    int i, j;

    for(i = 0, j = 0; input[j]; ++j){
        if(!is_whitespace(input[j])){
            input[i++] = input[j];
        }
    }

    input[i] = '\0';
}

void beautify(char* input){
    int i, j, k, indent;
    char output[MAX_SIZE];

    indent = 0;

    for(i = 0, j = 0; input[i]; ++i){
        if(input[i] == '<' && input[i+1] != '/'){
            for(k = 0; k < indent; ++k){
                output[j++] = ' ';
            }

            ++indent;

            output[j++] = input[i];
            output[j++] = input[i+1];
            output[j++] = '\n';

            i += 1;
        }
        else if(input[i] == '<' && input[i+1] == '/'){
            --indent;

            for(k = 0; k < indent; ++k){
                output[j++] = ' ';
            }

            output[j++] = input[i];
            output[j++] = input[i+1];
            output[j++] = '\n';

            i += 1;
        }
        else if(input[i] == '>'){
            output[j++] = input[i];
            output[j++] = '\n';
        }
        else{
            output[j++] = input[i];
        }
    }

    output[j] = '\0';

    printf("Beautified code:\n%s", output);
}

int main(){
    printf("Enter the HTML code to beautify:\n");

    char* input = get_input();

    remove_whitespace(input);

    beautify(input);

    free(input);

    return 0;
}