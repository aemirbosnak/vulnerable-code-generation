//FormAI DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to check if a given character is a delimiter
int is_delimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' 
        || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' 
        || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' 
        || ch == '}') {
            return 1;
        }
    return 0;
}

//Function to check if a given token is a keyword
int is_keyword(char* token) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", 
                             "continue", "default", "do", "double", "else", 
                             "enum", "extern", "float", "for", "goto", "if", 
                             "int", "long", "register", "return", "short", 
                             "signed", "sizeof", "static", "struct", "switch", 
                             "typedef", "union", "unsigned", "void", "volatile", "while"
                            };
    int i, flag = 0;
    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], token) == 0) {
            flag = 1;
            break;
        }
    }

    return flag;
}

//Function to identify a given token and return its type
char* get_token_type(char* token) {
    char* token_type = (char*)malloc(50*sizeof(char));
    if (is_keyword(token)) {
        strcpy(token_type, "KEYWORD");
    } else {
        char* ptr;
        strtol(token, &ptr, 10);
        if (*ptr != '\0') {
            strcpy(token_type, "IDENTIFIER");
        } else {
            strcpy(token_type, "NUMBER");
        }
    }
    return token_type;
}
 
//Recursive function to parse the input code and print the tokens and their type
void parse(char* code) {
    int length = strlen(code);
    char token[50], token_type[50];
    int i = 0, j = 0;
    while (i < length) {
        if (is_delimiter(code[i])) {
            i++;
        }
        else {
            //Extracting a token
            while (i < length && !is_delimiter(code[i])) {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            j = 0;

            //Printing the token and its type
            char* token_type = get_token_type(token);
            printf("<%s,%s> ", token, token_type);
            free(token_type);
        }
    }
}

int main() {
    char code[500];
    printf("Enter the C code: ");
    fgets(code, 500, stdin);
    printf("The tokens in the given C code are:\n");
    parse(code);
    return 0;
}