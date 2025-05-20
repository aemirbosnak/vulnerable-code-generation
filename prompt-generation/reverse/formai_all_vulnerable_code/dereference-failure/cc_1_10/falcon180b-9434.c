//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000000 // 1 GB

// Function to read a file into memory
void read_file(FILE *file, char *buffer) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum limit.\n");
        exit(1);
    }

    fread(buffer, file_size, 1, file);
}

// Function to search for a pattern in memory
int search_pattern(char *buffer, char *pattern, int pattern_len) {
    int i = 0;
    int j = 0;
    while (i < strlen(buffer)) {
        if (buffer[i] == pattern[j]) {
            j++;
            if (j == pattern_len) {
                return i;
            }
        } else {
            j = 0;
        }
        i++;
    }
    return -1;
}

// Function to save recovered data to a new file
void save_data(char *output_file, char *buffer, int start_pos, int end_pos) {
    FILE *out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    fprintf(out_file, "Recovered data:\n");
    fwrite(buffer + start_pos, end_pos - start_pos, 1, out_file);

    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./program input_file pattern output_file\n");
        exit(1);
    }

    char *input_file = argv[1];
    char *pattern = argv[2];
    char *output_file = argv[3];

    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    read_file(file, buffer);
    fclose(file);

    int pattern_len = strlen(pattern);
    int start_pos = search_pattern(buffer, pattern, pattern_len);

    if (start_pos == -1) {
        printf("Pattern not found in file.\n");
        exit(1);
    }

    int end_pos = start_pos + pattern_len - 1;
    save_data(output_file, buffer, start_pos, end_pos);

    free(buffer);
    return 0;
}