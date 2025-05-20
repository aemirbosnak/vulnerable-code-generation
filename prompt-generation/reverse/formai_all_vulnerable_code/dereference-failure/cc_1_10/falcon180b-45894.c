//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 // maximum length of a line
#define MAX_SUMMARY_SIZE 2048 // maximum length of a summary

char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    fgets(line, MAX_LINE_SIZE, file);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

char* summarize_line(char* line) {
    int len = strlen(line);
    if (len <= MAX_SUMMARY_SIZE) {
        return strdup(line);
    } else {
        char* summary = malloc(MAX_SUMMARY_SIZE);
        sprintf(summary, "%.*s...", MAX_SUMMARY_SIZE - 4, line);
        return summary;
    }
}

void summarize_file(FILE* file, char** summary) {
    char* line = read_line(file);
    while (line!= NULL) {
        *summary = realloc(*summary, strlen(*summary) + strlen(summarize_line(line)) + 2);
        strcat(*summary, summarize_line(line));
        strcat(*summary, "\n");
        free(line);
        line = read_line(file);
    }
}

int main() {
    char* filename = "example.txt";
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    char* summary = NULL;
    summarize_file(file, &summary);

    printf("Summary:\n%s", summary);

    free(summary);
    fclose(file);
    return 0;
}