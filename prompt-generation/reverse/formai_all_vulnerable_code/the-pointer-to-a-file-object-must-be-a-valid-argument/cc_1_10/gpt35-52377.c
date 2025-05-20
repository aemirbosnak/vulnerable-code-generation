//FormAI DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

void indent(int level);
void strip(char* source, char* dest);
void stripComment(char* source, char* dest, int* commentFlag);

int main() {
    char beautified[MAX_SIZE], buffer[MAX_SIZE], stripped[MAX_SIZE];
    int level = 0;
    int commentFlag = 0;
    int length = 0;
    FILE *fp;

    fp = fopen("file.html", "r");

    while(fgets(buffer, MAX_SIZE, fp)) {
        stripComment(buffer, stripped, &commentFlag);
        strip(stripped, beautified);

        // Ignore empty lines
        if(beautified[0]) {
            for(int i = 0; i < length; ++i) {
                if(beautified[i] == '<') {
                    indent(level++);
                    putchar('<');

                    // If closing tag, reduce indentation
                    if(beautified[i + 1] == '/') {
                        --level;
                    }

                    putchar('\n');
                    indent(level);
                }
                else if(beautified[i] == '>') {
                    putchar('>');
                    if(beautified[i + 1] == '<') {
                        putchar('\n');
                        indent(level);
                    }
                }
                else {
                    putchar(beautified[i]);
                }
            }
            putchar('\n');
            length = 0;
        }
    }

    fclose(fp);
    return 0;
}

void indent(int level) {
    for(int i = 0; i < level; ++i) {
        printf("  ");
    }
}

void strip(char* source, char* dest) {
    int j = 0;
    for(int i = 0; i < strlen(source); ++i) {
        if(source[i] != '\r' && source[i] != '\n' && source[i] != '\t') {
            dest[j++] = source[i];
        }
    }
    dest[j] = '\0';
}

void stripComment(char* source, char* dest, int* commentFlag) {
    int j = 0;
    for(int i = 0; i < strlen(source); ++i) {
        if(source[i] == '<' && source[i + 1] == '!' && !(*commentFlag)) {
            *commentFlag = 1;
        }
        else if(*commentFlag && source[i - 2] == '-' && source[i - 1] == '-' && source[i] == '>') {
            *commentFlag = 0;
        }
        else if(!(*commentFlag)) {
            dest[j++] = source[i];
        }
    }
    dest[j] = '\0';
}