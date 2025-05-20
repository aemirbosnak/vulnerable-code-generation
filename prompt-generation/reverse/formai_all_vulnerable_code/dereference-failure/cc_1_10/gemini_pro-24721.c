//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 16
#define MAX_CODE_TABLE_SIZE 4096

typedef struct {
    unsigned char code;
    char *string;
} code_table_entry;

code_table_entry code_table[MAX_CODE_TABLE_SIZE];
int code_table_size;
unsigned char *output_buffer;
int output_buffer_size;
int output_buffer_index;

void add_to_code_table(unsigned char code, char *string) {
    if (code_table_size >= MAX_CODE_TABLE_SIZE) {
        fprintf(stderr, "Error: Code table is full.\n");
        exit(1);
    }

    code_table[code_table_size].code = code;
    code_table[code_table_size].string = strdup(string);
    code_table_size++;
}

void print_code_table() {
    for (int i = 0; i < code_table_size; i++) {
        printf("%d: %s\n", code_table[i].code, code_table[i].string);
    }
}

void compress(char *input_string) {
    int input_string_length = strlen(input_string);
    char *current_string = strdup(input_string);
    unsigned char current_code = 0;

    while (*current_string != '\0') {
        int found = 0;

        for (int i = 0; i < code_table_size; i++) {
            if (strcmp(current_string, code_table[i].string) == 0) {
                current_code = code_table[i].code;
                found = 1;
                break;
            }
        }

        if (found) {
            output_buffer[output_buffer_index++] = current_code;
            current_string += strlen(code_table[current_code].string);
        } else {
            add_to_code_table(code_table_size, current_string);
            output_buffer[output_buffer_index++] = code_table_size - 1;
            current_string++;
        }
    }

    output_buffer[output_buffer_index++] = 0;
}

void decompress(unsigned char *input_buffer) {
    char *current_string = strdup("");
    unsigned char current_code = 0;

    while (*input_buffer != 0) {
        current_code = *input_buffer++;

        if (current_code < code_table_size) {
            strcat(current_string, code_table[current_code].string);
            printf("%s", current_string);
            current_string = strdup(code_table[current_code].string);
        } else {
            current_string = realloc(current_string, strlen(current_string) + strlen(code_table[current_code - 1].string) + 1);
            strcat(current_string, code_table[current_code - 1].string);
            strcat(current_string, code_table[current_code].string);
            printf("%s", current_string);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
        exit(1);
    }

    output_buffer_size = strlen(argv[1]) * 2;
    output_buffer = malloc(output_buffer_size);
    output_buffer_index = 0;

    compress(argv[1]);

    printf("Compressed string: ");
    for (int i = 0; i < output_buffer_index; i++) {
        printf("%d ", output_buffer[i]);
    }
    printf("\n");

    decompress(output_buffer);

    return 0;
}