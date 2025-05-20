//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} KeyValuePair;

void parse_line(char* line, KeyValuePair* key_value_pair) {
    char* delimiter = "=";
    char* token = strtok(line, delimiter);
    strcpy(key_value_pair->key, token);
    token = strtok(NULL, delimiter);
    strcpy(key_value_pair->value, token);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE* metadata_file = fopen(argv[1], "r");
    if (metadata_file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    KeyValuePair key_value_pairs[MAX_KEY_VALUE_PAIRS];
    int num_key_value_pairs = 0;

    while (fgets(line, MAX_LINE_LENGTH, metadata_file)!= NULL) {
        parse_line(line, &key_value_pairs[num_key_value_pairs]);
        num_key_value_pairs++;
    }

    fclose(metadata_file);

    printf("Metadata:\n");
    for (int i = 0; i < num_key_value_pairs; i++) {
        printf("%s: %s\n", key_value_pairs[i].key, key_value_pairs[i].value);
    }

    return 0;
}