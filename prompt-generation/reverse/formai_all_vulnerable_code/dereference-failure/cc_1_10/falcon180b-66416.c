//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void read_file(char *filename, char *buffer) {
    FILE *fp;
    int bytes_read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp);
    if (bytes_read < 0) {
        printf("Error: Could not read file %s\n", filename);
        exit(1);
    }

    fclose(fp);
}

void process_buffer(char *buffer) {
    int i, j, k, num_words;
    char word[MAX_BUFFER_SIZE];
    char *token;

    num_words = 0;
    token = strtok(buffer, " ");
    while (token!= NULL) {
        num_words++;
        token = strtok(NULL, " ");
    }

    printf("Number of words: %d\n", num_words);
}

int main(int argc, char *argv[]) {
    char filename[MAX_BUFFER_SIZE], buffer[MAX_BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);
    read_file(filename, buffer);
    process_buffer(buffer);

    return 0;
}