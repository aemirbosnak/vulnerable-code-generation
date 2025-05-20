//Falcon-180B DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function prototypes
int read_file(FILE *file, char *buffer, int max_size);
void print_error(const char *message, int error_code);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        print_error("Error opening input file", errno);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        print_error("Error opening output file", errno);
        fclose(input_file);
        return 1;
    }

    char buffer[MAX_LINE_SIZE];
    while (read_file(input_file, buffer, MAX_LINE_SIZE) > 0) {
        fwrite(buffer, strlen(buffer), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

int read_file(FILE *file, char *buffer, int max_size) {
    int bytes_read = fread(buffer, 1, max_size, file);
    if (bytes_read <= 0) {
        if (ferror(file)) {
            print_error("Error reading file", errno);
        } else {
            printf("End of file reached\n");
        }
        return -1;
    }
    return bytes_read;
}

void print_error(const char *message, int error_code) {
    printf("Error: %s\n", message);
    if (error_code!= 0) {
        printf("Error code: %d\n", error_code);
    }
}