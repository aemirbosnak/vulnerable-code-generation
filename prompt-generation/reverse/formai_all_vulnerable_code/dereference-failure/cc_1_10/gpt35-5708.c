//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* read_input(){
    char* input = (char*)malloc(sizeof(char) * 1024);
    scanf("%[^\n]%*c", input); // read input line
    return input;
}

int parse_input(char* input){
    char* token;
    const char delim[2] = " ";
    int count = 0;

    token = strtok(input, delim); // split string by space
    while(token != NULL){
        count++;
        if(count == 1){
            if(strcmp(token, "int") != 0){
                printf("Error: Expected data type 'int'\n");
                exit(1);
            }
        }
        else if(count == 2){
            if(token[strlen(token)-1] == ';'){ // check for semicolon at the end
                token[strlen(token)-1] = '\0'; 
            }
            if(!isalpha(token[0])){ // check for variable name starting with a letter
                printf("Error: Variable name must start with a letter\n");
                exit(1);
            }
            for(int i=1; i<strlen(token); i++){ // check for variable name only containing letters and numbers
                if(!isalnum(token[i])){
                    printf("Error: Variable name can contain only letters and numbers\n");
                    exit(1);
                }
            } 
        }
        token = strtok(NULL, delim);
    }
    if(count != 2){ // check for correct number of arguments
        printf("Error: Expected two arguments (data type and variable name)\n");
        exit(1);
    }
    return 0;
}

int main(){
    char* input;
    printf("Enter C syntax to parse (Ex: int a;): ");
    input = read_input();
    parse_input(input);
    printf("Input parsed successfully!\n");
    free(input);
    return 0;
}