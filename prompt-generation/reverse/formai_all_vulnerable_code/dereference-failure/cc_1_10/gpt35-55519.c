//FormAI DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store the parsed information
struct ParsedInfo {
    char type[20];
    char name[20];
    int size;
};

// Function to parse the input C syntax
struct ParsedInfo parseSyntax(char* input) {
    struct ParsedInfo info;
    char* token = strtok(input, " ");
    if(strcmp(token, "int") == 0) {
        strcpy(info.type, "int");
        token = strtok(NULL, " ");
        if(token[strlen(token)-1] == ';') {
            token[strlen(token)-1] = '\0';
            strcpy(info.name, token);
            info.size = sizeof(int);
        }
    }
    else if(strcmp(token, "float") == 0) {
        strcpy(info.type, "float");
        token = strtok(NULL, " ");
        if(token[strlen(token)-1] == ';') {
            token[strlen(token)-1] = '\0';
            strcpy(info.name, token);
            info.size = sizeof(float);
        }
    }
    else if(strcmp(token, "char") == 0) {
        strcpy(info.type, "char");
        token = strtok(NULL, " ");
        if(token[strlen(token)-1] == ';') {
            token[strlen(token)-1] = '\0';
            strcpy(info.name, token);
            info.size = sizeof(char);
        }
    }
    else {
        strcpy(info.type, "");
        info.name[0] = '\0';
        info.size = -1;
    }
    return info;
}

int main() {
    // Dynamic memory allocation and user input
    char *input = (char *)malloc(sizeof(char)*50);
    printf("Enter a C syntax to parse: ");
    fgets(input, 50, stdin);
    input[strlen(input)-1] = '\0';
    
    // Parsing the input
    struct ParsedInfo info = parseSyntax(input);
    
    // Displaying the parsed information
    if(info.size == -1)
        printf("Invalid syntax!\n");
    else
        printf("%s variable %s is of size %d bytes\n", info.type, info.name, info.size);
        
    free(input);
    return 0;
}