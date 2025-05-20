//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100
#define MAX_DICTIONARY_SIZE 256

typedef struct {
    char *key;
    int value;
} DictionaryEntry;

typedef struct {
    DictionaryEntry *entries;
    int size;
    int capacity;
} Dictionary;

Dictionary *create_dictionary(int capacity) {
    Dictionary *dict = malloc(sizeof(Dictionary));
    dict->size = 0;
    dict->capacity = capacity;
    dict->entries = malloc(sizeof(DictionaryEntry) * capacity);
    return dict;
}

void free_dictionary(Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->entries[i].key);
    }
    free(dict->entries);
    free(dict);
}

void insert(Dictionary *dict, const char *key, int value) {
    if (dict->size >= dict->capacity) {
        fprintf(stderr, "Dictionary capacity exceeded.\n");
        return;
    }
    dict->entries[dict->size].key = strdup(key);
    dict->entries[dict->size].value = value;
    dict->size++;
}

int find(Dictionary *dict, const char *key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->entries[i].key, key) == 0) {
            return dict->entries[i].value;
        }
    }
    return -1; // Not found
}

void compress(const char *input, FILE *output) {
    Dictionary *dict = create_dictionary(MAX_DICTIONARY_SIZE);
    char buffer[MAX_STRING_SIZE];
    int index = 0;
    
    while (*input) {
        buffer[index] = *input;
        buffer[index + 1] = '\0';
        
        int code = find(dict, buffer);
        
        if (code != -1) {
            index++;
        } else {
            if (index > 0) {
                buffer[index] = '\0';
                int current_code = dict->size;
                fprintf(output, "%d ", find(dict, buffer));
                insert(dict, buffer, current_code);
            } else {
                fprintf(output, "%d ", *input);
            }
            buffer[0] = *input;
            index = 1;
        }
        input++;
    }
    
    if (index > 0) {
        buffer[index] = '\0';
        fprintf(output, "%d ", find(dict, buffer));
    }
    
    free_dictionary(dict);
}

void decompress(FILE *input, FILE *output) {
    Dictionary *dict = create_dictionary(MAX_DICTIONARY_SIZE);
    int next_code = 256; // Starting after ASCII
    int code;
    char last_char = '\0';
    
    // Initializing dictionary with single character ASCII
    for (int i = 0; i < 256; i++) {
        char *single_char = malloc(2);
        single_char[0] = i;
        single_char[1] = '\0';
        insert(dict, single_char, i);
        free(single_char);
    }

    while (fscanf(input, "%d", &code) != EOF) {
        if (code < 256) {
            fputc(code, output);
            last_char = code;
        } else {
            char *entry;
            if (code < dict->size) {
                entry = dict->entries[code].key;
            } else {
                fprintf(stderr, "Invalid code %d encountered during decompression.\n", code);
                break;
            }
            fputs(entry, output);
            if (last_char) {
                char *new_entry = malloc(strlen(entry) + 2);
                sprintf(new_entry, "%c%s", last_char, entry);
                insert(dict, new_entry, next_code++);
                free(new_entry);
            }
            last_char = entry[strlen(entry) - 1];
        }
    }

    free_dictionary(dict);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "compress") == 0) {
        FILE *input = fopen(argv[2], "r");
        FILE *output = fopen(argv[3], "w");

        if (!input || !output) {
            fprintf(stderr, "Error opening files.\n");
            return EXIT_FAILURE;
        }

        char *input_data = malloc(MAX_STRING_SIZE);
        fread(input_data, sizeof(char), MAX_STRING_SIZE, input);
        compress(input_data, output);

        free(input_data);
        fclose(input);
        fclose(output);
    } else if (strcmp(argv[1], "decompress") == 0) {
        FILE *input = fopen(argv[2], "r");
        FILE *output = fopen(argv[3], "w");

        if (!input || !output) {
            fprintf(stderr, "Error opening files.\n");
            return EXIT_FAILURE;
        }

        decompress(input, output);

        fclose(input);
        fclose(output);
    } else {
        fprintf(stderr, "Invalid action. Use 'compress' or 'decompress'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}