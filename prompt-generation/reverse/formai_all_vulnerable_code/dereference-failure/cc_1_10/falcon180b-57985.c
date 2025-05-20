//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 1024

// Function to trim leading and trailing whitespace
void trim(char* str) {
    char* end;
    if (*str == '\0') {
        return;
    }
    end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
    while (isspace(*str)) {
        str++;
    }
}

// Function to tokenize a line of text
char* tokenize(char* line) {
    char* token = strtok(line, " \t\r\n");
    while (token!= NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " \t\r\n");
    }
}

// Function to read a file and tokenize each line
void read_file(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char token[MAX_TOKEN_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        trim(line);
        tokenize(line);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }
    read_file(file);
    fclose(file);
    return 0;
}