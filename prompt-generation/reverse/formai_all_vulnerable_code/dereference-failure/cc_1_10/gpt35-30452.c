//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

#define OPERATORS_SIZE 7 //define the size of operators array
#define KEYWORD_SIZE 11 //define the size of keyword array

char operators[OPERATORS_SIZE][5] = {"+", "-", "*", "/", "%", "=", "=="}; //array of operators
char keywords[KEYWORD_SIZE][10] = {"int", "double", "float", "char", "return", "if", "else", "while", "do", "for", "switch"}; //array of keywords

int is_operator(char c[]) { //function to check if a given string is operator
    for (int i=0; i<OPERATORS_SIZE; i++) {
        if(strcmp(c, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_keyword(char c[]) { //function to check if a given string is keyword
    for (int i=0; i<KEYWORD_SIZE; i++) {
        if(strcmp(c, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file;
    char ch, buffer[15], symbol[10] = "";
    int i=0, j=0;
    file = fopen("program.c", "r"); //opening a file in read mode
    if (file == NULL) {
        printf("Error: Unable to open file!");
        exit(1);
    }
    printf("Tokens:\n"); //print tokens
    while((ch=fgetc(file))!=EOF) { //reading each character from file
        if(ch == ' ' || ch == '\n' || ch == '\t') { //check if character is a whitespace character
            if(i!=0) {
                buffer[i] = '\0';
                i = 0;
                if(is_keyword(buffer) == 1) { //check if buffer is keyword
                    printf("<%s, KW>\n", buffer); //print buffer and token as keyword
                }
                else { //if buffer is not a keyword
                    printf("<%s, ID>\n", buffer); //print buffer and token as identifier
                }
            }
        }
        else if(is_operator(&ch) == 1) { //check if character is an operator
            symbol[j++] = ch;
            if(j > 1 || (j == 1 && (symbol[0] == '+' || symbol[0] == '-' || symbol[0] == '*' || symbol[0] == '/' || symbol[0] == '%' || symbol[0] == '='))) { //check if symbol is an operator
                symbol[j] = '\0';
                printf("<%s, OP>\n", symbol); //print symbol and token as operator
                j = 0;
                symbol[0] = '\0';
            }
        }
        else if(ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') { //check if character is a bracket
            printf("<%c, BR>\n", ch); //print character and token as bracket
        }
        else { //if character is neither a whitespace character nor an operator nor a bracket
            buffer[i++] = ch;
        }
    }
    fclose(file); //close the file
    return 0;
}