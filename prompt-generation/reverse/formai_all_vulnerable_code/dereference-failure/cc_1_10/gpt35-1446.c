//FormAI DATASET v1.0 Category: Syntax parsing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }

    char line[1024];
    int line_count = 0;
    int parentheses_count = 0;
    int brackets_count = 0;
    int braces_count = 0;
    int angle_count = 0;

    while(fgets(line, sizeof(line), fp)) {
        line_count++;
        int i = 0;
        while(line[i] != '\0') {
            if(line[i] == '(') {
                parentheses_count++;
            } else if(line[i] == ')') {
                parentheses_count--;
            } else if(line[i] == '{') {
                braces_count++;
            } else if(line[i] == '}') {
                braces_count--;
            } else if(line[i] == '[') {
                brackets_count++;
            } else if(line[i] == ']') {
                brackets_count--;
            } else if(line[i] == '<') {
                angle_count++;
            } else if(line[i] == '>') {
                angle_count--;
            }
            i++;
        }
    }

    fclose(fp);

    if(parentheses_count != 0) {
        printf("Error: Parentheses count is off by %d\n", parentheses_count);
        exit(1);
    } else if(brackets_count != 0) {
        printf("Error: Brackets count is off by %d\n", brackets_count);
        exit(1);
    } else if(braces_count != 0) {
        printf("Error: Braces count is off by %d\n", braces_count);
        exit(1);
    } else if(angle_count != 0) {
        printf("Error: Angle brackets count is off by %d\n", angle_count);
        exit(1);
    } else {
        printf("Syntax check successful!\n");
    }
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    if(strstr(filename, ".c") == NULL) {
        printf("Error: Not a valid C source file\n");
        exit(1);
    }

    parse(filename);

    return 0;
}