//FormAI DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(int num) {
    char* msg;
    switch(num) {
        case 1: msg = "Error opening file"; break;
        case 2: msg = "Error reading file"; break;
        case 3: msg = "Error writing to file"; break;
        case 4: msg = "Out of memory"; break;
        default: msg = "Unknown error"; break;
    }
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

int main() {
    char filename[] = "example.txt";
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        handle_error(1);
    }

    int buf_size = 1024;
    char* buffer = malloc(buf_size * sizeof(char));
    if(buffer == NULL) {
        handle_error(4);
    }

    size_t bytes_read = fread(buffer, sizeof(char), buf_size, fp);
    if(ferror(fp) != 0) {
        handle_error(2);
    }

    FILE *output;
    output = fopen("output.txt", "w");
    if(output == NULL) {
        handle_error(3);
    }

    size_t bytes_written = fwrite(buffer, sizeof(char), bytes_read, output);
    if(ferror(output) != 0) {
        handle_error(3);
    }

    fclose(fp);
    fclose(output);
    free(buffer);

    return 0;
}