//Falcon-180B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char* content = NULL;
    size_t size = 0;
    ssize_t read;

    while ((read = getline(&content, &size, file))!= -1) {
        if (read > 0 && content[read - 1] == '\n') {
            content[--read] = '\0';
        }
    }

    fclose(file);
    return content;
}

void write_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fwrite(content, strlen(content), 1, file);
    fclose(file);
}

void process_line(char* line) {
    char* token = strtok(line, " ");
    while (token) {
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    char* content = read_file("input.txt");
    if (!content) {
        return 1;
    }

    char* line = strtok(content, "\n");
    while (line) {
        process_line(line);
        line = strtok(NULL, "\n");
    }

    free(content);
    return 0;
}