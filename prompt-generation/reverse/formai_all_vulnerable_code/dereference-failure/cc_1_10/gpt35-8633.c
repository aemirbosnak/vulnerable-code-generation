//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void custom_error(int error_code) {
    switch(error_code) {
        case 1:
            fprintf(stderr, "Error: Invalid argument provided\n");
            break;
        case 2:
            fprintf(stderr, "Error: Memory allocation failed\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown error code %d\n", error_code);
            break;
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        custom_error(1);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char *buffer;
    size_t buffer_size = 1024;
    buffer = (char *) malloc(buffer_size * sizeof(char));
    if(buffer == NULL) {
        custom_error(2);
        exit(EXIT_FAILURE);
    }

    int read_count = getline(&buffer, &buffer_size, fp);
    if(read_count == -1) {
        fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("File contents:\n%s", buffer);

    free(buffer);
    fclose(fp);
    return 0;
}