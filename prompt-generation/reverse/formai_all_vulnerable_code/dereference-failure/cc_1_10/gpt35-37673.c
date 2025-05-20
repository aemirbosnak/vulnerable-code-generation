//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

/* This function reads a file and returns its content */
char* read_file(const char *file_path) {
    FILE *fp;
    long file_size;
    char *content;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    content = (char*) malloc(sizeof(char)*file_size + 1);
    fread(content, sizeof(char), file_size, fp);

    fclose(fp);

    return content;
}

/* This function writes to a file */
void write_file(const char *file_path, char *content) {
    FILE *fp;

    fp = fopen(file_path, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s", content);

    fclose(fp);
}

/* This function compresses a given string */
char* compress(char *input) {
    char *output = malloc(sizeof(char) * MAX_SIZE);
    char *current = input;
    char *prev = input - 1;
    int count = 1;
    int output_index = 0;

    while (*current) {
        if (*current == *prev) {
            ++count;
        } else {
            if (count > 1) {
                output_index += sprintf(output + output_index, "%d", count);
            }
            output[output_index++] = *current;
            count = 1;
        }
        prev = current;
        ++current;
    }

    if (count > 1) {
        output_index += sprintf(output + output_index, "%d", count);
    }

    output[output_index] = '\0';

    return output;
}

/* This function decompresses a given string */
char* decompress(char *input) {
    char *output = malloc(sizeof(char) * MAX_SIZE);
    char *current = input;
    int count = 0;
    int output_index = 0;

    while (*current) {
        if (*current >= '0' && *current <= '9') {
            count = count * 10 + *current - '0';
        } else {
            if (count == 0) {
                count = 1;
            }
            for (int i = 0; i < count; ++i) {
                output[output_index++] = *current;
            }
            count = 0;
        }
        ++current;
    }

    output[output_index] = '\0';

    return output;
}

int main(int argc, char **argv) {
    char *input, *compressed, *decompressed;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input = read_file(argv[1]);
    compressed = compress(input);
    decompressed = decompress(compressed);

    printf("Original size: %ld bytes\n", strlen(input));
    printf("Compressed size: %ld bytes\n", strlen(compressed));
    printf("Decompressed size: %ld bytes\n", strlen(decompressed));

    printf("Input:\n%s\n", input);
    printf("Compressed:\n%s\n", compressed);
    printf("Decompressed:\n%s\n", decompressed);
    
    write_file("compressed_file.txt", compressed);

    free(input);
    free(compressed);
    free(decompressed);

    return 0;
}