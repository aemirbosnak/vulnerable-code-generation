//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000

typedef struct {
    char* data;
    int size;
} File;

void read_file(File* file, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->data = malloc(file->size + 1);
    if (file->data == NULL) {
        printf("Error: could not allocate memory for file %s\n", filename);
        exit(1);
    }

    fread(file->data, file->size, 1, fp);
    fclose(fp);
}

void write_file(const char* filename, const char* data, int size) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(data, size, 1, fp);
    fclose(fp);
}

int main() {
    File input_file;
    read_file(&input_file, "input.txt");

    char* output_data = malloc(input_file.size + 1);
    if (output_data == NULL) {
        printf("Error: could not allocate memory for output data\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < input_file.size; i++) {
        if (isalpha(input_file.data[i])) {
            output_data[j++] = toupper(input_file.data[i]);
        }
    }

    output_data[j] = '\0';

    write_file("output.txt", output_data, j);

    free(input_file.data);
    free(output_data);

    return 0;
}