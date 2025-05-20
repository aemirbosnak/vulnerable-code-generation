//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_VALUE_PAIRS 100
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE* metadata_file = fopen(argv[1], "r");
    if (metadata_file == NULL) {
        printf("Error opening metadata file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    int num_key_value_pairs = 0;
    KeyValuePair* key_value_pairs = malloc(MAX_KEY_VALUE_PAIRS * sizeof(KeyValuePair));
    if (key_value_pairs == NULL) {
        printf("Error allocating memory for key-value pairs.\n");
        fclose(metadata_file);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, metadata_file)!= NULL) {
        char* key_start = strchr(line, '=');
        if (key_start == NULL) {
            printf("Invalid metadata format.\n");
            fclose(metadata_file);
            free(key_value_pairs);
            return 1;
        }

        *key_start = '\0';
        char* key = strdup(line);
        char* value_start = key_start + 1;
        char* value = strdup(value_start);

        if (num_key_value_pairs >= MAX_KEY_VALUE_PAIRS) {
            printf("Maximum number of key-value pairs reached.\n");
            fclose(metadata_file);
            free(key_value_pairs);
            return 1;
        }

        key_value_pairs[num_key_value_pairs].key = key;
        key_value_pairs[num_key_value_pairs].value = value;
        num_key_value_pairs++;
    }

    fclose(metadata_file);

    printf("Number of key-value pairs: %d\n", num_key_value_pairs);

    for (int i = 0; i < num_key_value_pairs; i++) {
        printf("Key: %s\n", key_value_pairs[i].key);
        printf("Value: %s\n\n", key_value_pairs[i].value);
    }

    free(key_value_pairs);
    return 0;
}