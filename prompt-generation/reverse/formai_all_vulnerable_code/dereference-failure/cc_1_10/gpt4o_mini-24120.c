//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 4096  // Maximum table size for the LZW algorithm
#define MAX_CODE_SIZE 12      // Maximum bits per code, 2^12 = 4096

typedef struct {
    int code;
    char *value;
} DictionaryEntry;

DictionaryEntry table[MAX_TABLE_SIZE];
int next_code;

void init_dictionary() {
    for (int i = 0; i < 256; i++) {
        table[i].code = i;
        table[i].value = (char *)malloc(2);
        table[i].value[0] = (char)i;
        table[i].value[1] = '\0';
    }
    next_code = 256;
}

void free_dictionary() {
    for (int i = 0; i < next_code; i++) {
        free(table[i].value);
    }
}

int find_in_dictionary(const char *str) {
    for (int i = 0; i < next_code; i++) {
        if (strcmp(table[i].value, str) == 0) {
            return table[i].code;
        }
    }
    return -1;
}

void insert_into_dictionary(const char *str) {
    if (next_code < MAX_TABLE_SIZE) {
        table[next_code].code = next_code;
        table[next_code].value = (char *)malloc(strlen(str) + 2);
        strcpy(table[next_code].value, str);
        next_code++;
    }
}

void compress(const char *input, FILE *output) {
    char *current = (char *)malloc(1);
    current[0] = input[0];
    int current_code;

    for (int i = 1; i < strlen(input); i++) {
        char next_char[2] = {input[i], '\0'};
        char *combined = (char *)malloc(strlen(current) + strlen(next_char) + 1);
        strcpy(combined, current);
        strcat(combined, next_char);

        if (find_in_dictionary(combined) != -1) {
            free(current);
            current = combined;
        } else {
            current_code = find_in_dictionary(current);
            if (current_code != -1) {
                fwrite(&current_code, sizeof(int), 1, output);
            }
            insert_into_dictionary(combined);
            current = next_char;
        }

        free(combined);
    }

    current_code = find_in_dictionary(current);
    if (current_code != -1) {
        fwrite(&current_code, sizeof(int), 1, output);
    }
    free(current);
}

void decompress(FILE *input, char *output) {
    int code;
    char *prev_str = (char *)malloc(1);
    prev_str[0] = '\0';
    char *output_buffer = (char *)malloc(1024); // Adjust size as needed
    output_buffer[0] = '\0';

    fread(&code, sizeof(int), 1, input);
    strcat(output_buffer, table[code].value);

    while (fread(&code, sizeof(int), 1, input) == 1) {
        if (code < next_code) {
            strcat(output_buffer, table[code].value);
            insert_into_dictionary(prev_str);
            char *new_entry = (char *)malloc(strlen(prev_str) + 2);
            strcpy(new_entry, prev_str);
            strcat(new_entry, table[code].value);
            insert_into_dictionary(new_entry);
            free(new_entry);
        } else {
            char *new_entry = (char *)malloc(strlen(prev_str) + 2);
            strcpy(new_entry, prev_str);
            strcat(new_entry, prev_str);
            strcat(new_entry, table[code].value);
            insert_into_dictionary(new_entry);
            free(new_entry);
        }

        strcpy(prev_str, table[code].value);
    }

    strcpy(output, output_buffer);
    free(prev_str);
    free(output_buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s compress|decompress input_file output_file\n", argv[0]);
        return 1;
    }

    init_dictionary();
    if (strcmp(argv[1], "compress") == 0) {
        FILE *input = fopen(argv[2], "r");
        FILE *output = fopen(argv[3], "wb");
        if (input == NULL || output == NULL) {
            printf("Error opening files.\n");
            return 1;
        }

        char *buffer = (char *)malloc(1024);
        fread(buffer, 1, 1024, input);
        compress(buffer, output);
        
        free(buffer);
        fclose(input);
        fclose(output);
    } else if (strcmp(argv[1], "decompress") == 0) {
        FILE *input = fopen(argv[2], "rb");
        if (input == NULL) {
            printf("Error opening file.\n");
            return 1;
        }

        char output_buffer[1024];
        decompress(input, output_buffer);
        printf("Decompressed output:\n%s\n", output_buffer);
        fclose(input);
    } else {
        printf("Invalid command. Use 'compress' or 'decompress'.\n");
    }

    free_dictionary();
    return 0;
}