//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    FILE *fp;
    char *filename;
    char mode;
    int record_size;
    char buffer[BUFFER_SIZE];
    char line[MAX_LINE_LENGTH];
    size_t read_bytes;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filename> <mode> <record_size>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    mode = argv[2][0];
    record_size = atoi(argv[3]);

    if (record_size <= 0) {
        fprintf(stderr, "Invalid record size: %s\n", argv[3]);
        exit(1);
    }

    fp = NULL;

    switch (mode) {
        case 'w':
            fp = fopen(filename, "w");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file for writing: %s\n", filename);
                exit(1);
            }
            break;
        case 'a':
            fp = fopen(filename, "a");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file for appending: %s\n", filename);
                exit(1);
            }
            break;
        case 'r':
            fp = fopen(filename, "r");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file for reading: %s\n", filename);
                exit(1);
            }
            break;
        default:
            fprintf(stderr, "Invalid mode: %c\n", mode);
            exit(1);
    }

    if (mode == 'w' || mode == 'a') {
        fwrite("Initial data\n", record_size, 1, fp);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        size_t len = strlen(line);
        if (len > record_size) {
            fprintf(stderr, "Record size violation: %s\n", line);
            exit(1);
        }
        printf("%s", line);
    }

    if (mode == 'r') {
        while ((read_bytes = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
            fwrite(buffer, read_bytes, 1, stdout);
        }
    }

    fclose(fp);

    return 0;
}