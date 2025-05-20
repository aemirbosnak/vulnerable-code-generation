//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // maximum size of input file

typedef struct {
    char *data;
    int size;
} string_t;

void read_file(FILE *file, string_t *str) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        str->data[i++] = ch;
    }
    str->size = i;
}

void write_file(FILE *file, string_t str) {
    int i;
    for (i = 0; i < str.size; i++) {
        fputc(str.data[i], file);
    }
}

void compress(string_t str) {
    int i, j;
    for (i = 0; i < str.size - 1; i++) {
        for (j = i + 1; j < str.size; j++) {
            if (str.data[i] == str.data[j]) {
                str.data[j] = '\0';
            }
        }
        i--;
    }
    str.size = strlen(str.data);
}

void decompress(string_t str) {
    int i, j;
    for (i = 0; i < str.size; i++) {
        if (str.data[i]!= '\0') {
            for (j = i + 1; j < str.size; j++) {
                str.data[j] = str.data[i];
            }
        }
    }
    str.size = strlen(str.data);
}

int main() {
    FILE *input_file, *output_file;
    string_t input_str, output_str;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    read_file(input_file, &input_str);
    compress(input_str);
    write_file(output_file, input_str);

    fclose(input_file);
    fclose(output_file);

    return 0;
}