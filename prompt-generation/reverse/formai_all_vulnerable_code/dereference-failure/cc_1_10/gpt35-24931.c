//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 1000

char* addTab(char* s, int tabCount) {
    char* res = malloc(strlen(s) + tabCount);
    memset(res, '\t', tabCount);
    strcat(res, s);
    return res;
}

char* getToken(FILE* inFile) {
    char* s = malloc(100);
    char c = fgetc(inFile);
    int index = 0;
    while(c != EOF) {
        if(c == '>' || c == '\n') {
            s[index] = c;
            break;
        } else if(c == '<') {
            if(index > 0) {
                ungetc(c, inFile);
                break;
            }
        }
        if(c != ' ' || index > 0) {
            s[index++] = c;
            if(index > 90)
                break;
        }
        c = fgetc(inFile);
    }
    s[index] = '\0';
    return s;
}

void prettyPrint(char* fileName) {
    FILE* inFile = fopen(fileName, "r");
    char* token = NULL;
    int tabCount = 0;
    int newLineAfter = 0;
    int firstTag = 1;
    char* stack[MAX_STACK_SIZE];
    int stackPtr = -1;
    while(!feof(inFile)) {
        token = getToken(inFile);
        if(token == NULL)
            break;
        if(token[0] == '<') {
            if(token[1] == '/') {
                //Closing tag
                stackPtr--;
                if(newLineAfter) {
                    printf("\n");
                    printf("%s%s", addTab(token, tabCount), newLineAfter ? "\n" : "");
                    newLineAfter = 0;
                } else {
                    printf("%s%s", addTab(token, tabCount), newLineAfter ? "\n" : "");
                }
                tabCount--;
            } else {
                if(newLineAfter) {
                    printf("\n");
                }
                if(firstTag) {
                    firstTag = 0;
                } else {
                    printf("\n");
                }

                if(token[strlen(token) - 1] == '/') {
                    printf("%s", addTab(token, tabCount));
                } else {
                    printf("%s%s", addTab(token, tabCount), newLineAfter ? "\n" : "");
                    stack[++stackPtr] = malloc(strlen(token));
                    strcpy(stack[stackPtr], token);
                    tabCount++;
                }
            }
            newLineAfter = 1;
        } else {
            printf("%s", token);
            newLineAfter = 0;
        }
        free(token);
    }
    fclose(inFile);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }
    prettyPrint(argv[1]);
    return 0;
}