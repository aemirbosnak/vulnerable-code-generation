//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_parse(char *metadata_str) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->key = malloc(100);
    metadata->value = malloc(100);
    char *curr_char = metadata_str;
    char *key_start = metadata_str;
    char *value_start = metadata_str;
    int key_len = 0;
    int value_len = 0;
    while (*curr_char!= '\0') {
        if (*curr_char == ':') {
            metadata->key[key_len] = '\0';
            metadata->value[value_len] = '\0';
            break;
        }
        if (isalpha(*curr_char)) {
            key_start = curr_char;
        }
        if (isspace(*curr_char)) {
            value_start = curr_char + 1;
        }
        curr_char++;
        key_len++;
        value_len++;
    }
    strncpy(metadata->key, key_start, key_len);
    strncpy(metadata->value, value_start, value_len);
    return metadata;
}

void metadata_print(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main() {
    char *metadata_str = "Author: John Doe\nTitle: The Quick Brown Fox\n";
    metadata_t *metadata = metadata_parse(metadata_str);
    metadata_print(metadata);
    free(metadata->key);
    free(metadata->value);
    free(metadata);
    return 0;
}