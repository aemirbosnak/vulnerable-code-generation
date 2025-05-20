//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 256

// Struct to store metadata key-value pairs
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

// Function to extract metadata from a line of text
Metadata* extract_metadata(char* line) {
    char* word = strtok(line, " \t");
    while (word!= NULL) {
        if (strncasecmp(word, "key=", 4) == 0) {
            Metadata* metadata = (Metadata*)malloc(sizeof(Metadata));
            strncpy(metadata->key, word + 4, MAX_KEY_LENGTH);
            word = strtok(NULL, " \t");
            strncpy(metadata->value, word, MAX_VALUE_LENGTH);
            return metadata;
        }
        word = strtok(NULL, " \t");
    }
    return NULL;
}

// Function to print metadata
void print_metadata(Metadata* metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

// Main function to read input file and extract metadata
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Metadata* metadata = NULL;
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        metadata = extract_metadata(line);
        if (metadata!= NULL) {
            print_metadata(metadata);
        }
    }

    if (metadata!= NULL) {
        free(metadata);
    }

    fclose(input_file);
    return 0;
}