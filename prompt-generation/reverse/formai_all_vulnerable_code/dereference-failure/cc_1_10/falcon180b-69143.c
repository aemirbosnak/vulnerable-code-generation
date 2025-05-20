//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_LINE_SIZE 1000

// Function to remove leading and trailing white spaces
void trim(char* str) {
    int len = strlen(str);
    int i = 0;
    while (isspace(str[i])) {
        i++;
    }
    while (isspace(str[len - 1])) {
        len--;
    }
    str[len] = '\0';
}

// Function to check if a word is a keyword
int isKeyword(char* word) {
    char* keywords[] = {"Education", "Experience", "Skills", "Certifications", "Awards", "References"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to parse the resume and extract relevant information
void parseResume(char* resume) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE* fp = fopen(resume, "r");
    if (fp == NULL) {
        printf("Error: Unable to open the resume file.\n");
        exit(1);
    }
    while ((read = getline(&line, &len, fp))!= -1) {
        trim(line);
        if (strlen(line) == 0) {
            continue;
        }
        char* word = strtok(line, " ");
        while (word!= NULL) {
            if (isKeyword(word)) {
                printf("%s\n", word);
            } else if (strlen(word) > 1) {
                printf("%s\n", word);
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }
    parseResume(argv[1]);
    return 0;
}