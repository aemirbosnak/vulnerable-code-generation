//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

char *read_file(const char *filename) {
    FILE *file;
    char *buffer = NULL;
    size_t size = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
        size += strlen(buffer);
        buffer = realloc(buffer, size + 1);
    }

    fclose(file);
    return buffer;
}

void optimize_file(const char *filename, const char *output_filename) {
    char *buffer = read_file(filename);
    char *optimized_buffer = NULL;
    size_t size = 0;

    for (const char *p = buffer; *p!= '\0'; ++p) {
        if (isalnum(*p)) {
            optimized_buffer = realloc(optimized_buffer, size + 1);
            optimized_buffer[size++] = tolower(*p);
        }
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_filename);
        exit(1);
    }

    fwrite(optimized_buffer, 1, size, output_file);
    fclose(output_file);

    free(buffer);
    free(optimized_buffer);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    optimize_file(argv[1], argv[2]);

    return 0;
}