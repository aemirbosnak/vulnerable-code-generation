//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the file
char* readLine(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file\n");
        exit(1);
    }
    return line;
}

// Function to read the contents of a file into a string
char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char* contents = NULL;
    while ((contents = readLine(file))!= NULL) {
        printf("%s", contents);
    }
    return contents;
}

// Function to recursively search for a keyword in a string
int searchForKeyword(const char* keyword, const char* str) {
    int keywordLength = strlen(keyword);
    int strLength = strlen(str);
    if (strncmp(str, keyword, keywordLength) == 0) {
        printf("Keyword found: %s\n", keyword);
        return 1;
    }
    if (strLength > keywordLength) {
        return searchForKeyword(keyword, str + keywordLength);
    }
    return 0;
}

// Function to search for a keyword in a file
void searchFile(const char* filename, const char* keyword) {
    char* contents = readFile(filename);
    searchForKeyword(keyword, contents);
    free(contents);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <keyword>\n", argv[0]);
        return 1;
    }
    searchFile(argv[1], argv[2]);
    return 0;
}