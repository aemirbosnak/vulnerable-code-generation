//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256
#define DELIMITER "="

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        Metadata metadata;
        strcpy(metadata.key, "");
        strcpy(metadata.value, "");

        char *delimiter_pos = strchr(line, DELIMITER);
        if (delimiter_pos!= NULL) {
            *delimiter_pos = '\0';
            strncpy(metadata.key, line, MAX_KEY_LENGTH);
            strncpy(metadata.value, delimiter_pos + 1, MAX_VALUE_LENGTH);
        } else {
            strncpy(metadata.key, line, MAX_KEY_LENGTH);
        }

        fprintf(output_file, "Key: %s\nValue: %s\n", metadata.key, metadata.value);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}