//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1000

char* readFile(char* fileName);
char* summarize(char* text);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: summarize <file_name>\n");
        return -1;
    }
    char* fileName = argv[1];
    char* text = readFile(fileName);
    char* summary = summarize(text);
    printf("%s", summary);
    free(text);
    free(summary);
    return 0;
}

char* readFile(char* fileName) {
    FILE* fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }
    char* text = malloc(MAX_LINES * MAX_LENGTH * sizeof(char));
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        strcat(text, line);
    }
    fclose(fp);
    return text;
}

char* summarize(char* text) {
    char* summary = malloc(MAX_LINES * sizeof(char));
    char* line = strtok(text, "\n");
    int count = 0;
    while (line != NULL && count < 6) {
        strcat(summary, line);
        strcat(summary, "\n");
        line = strtok(NULL, "\n");
        count++;
    }
    return summary;
}