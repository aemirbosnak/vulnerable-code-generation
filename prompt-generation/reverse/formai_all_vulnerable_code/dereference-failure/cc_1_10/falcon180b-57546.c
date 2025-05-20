//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

char *file_buffer = NULL;
int file_buffer_size = 0;
int num_lines = 0;

char *get_line(int line_num) {
    int offset = 0;
    for (int i = 0; i < line_num; i++) {
        offset += strlen(file_buffer + offset) + 1; // +1 for newline character
    }
    return file_buffer + offset;
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_num = 0;

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line_num >= MAX_LINES) {
            printf("Error: Too many lines in file.\n");
            exit(1);
        }
        if (file_buffer == NULL) {
            file_buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
            file_buffer_size = MAX_LINE_LENGTH;
        }
        if (file_buffer_size - strlen(file_buffer) < read) {
            file_buffer_size += MAX_LINE_LENGTH;
            file_buffer = realloc(file_buffer, file_buffer_size * sizeof(char));
        }
        strncat(file_buffer, line, read);
        num_lines++;
        line_num++;
    }

    fclose(fp);

    printf("Number of lines in file: %d\n", num_lines);

    return 0;
}