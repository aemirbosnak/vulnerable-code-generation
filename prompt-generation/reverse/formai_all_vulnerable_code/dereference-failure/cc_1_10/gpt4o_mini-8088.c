//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 100
#define MAX_JSON_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';
}

int parse_json(const char *json, KeyValuePair *pairs, int max_pairs) {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int pos = 0, pair_count = 0;

    while (*json) {
        // Skip white spaces
        if (isspace((unsigned char)*json) || *json == '{' || *json == '}') {
            json++;
            continue;
        }

        // Parse key
        if (*json == '"') {
            json++;
            char *key_start = key;
            while (*json && *json != '"') {
                *key_start++ = *json++;
            }
            *key_start = '\0';
            if (*json == '"') json++;

            trim_whitespace(key);
            if (*json == ':') json++;

            // Parse value
            if (*json == '"') {
                json++;
                char *value_start = value;
                while (*json && *json != '"') {
                    *value_start++ = *json++;
                }
                *value_start = '\0';
                if (*json == '"') json++;

                trim_whitespace(value);
                if (pair_count < max_pairs) {
                    strcpy(pairs[pair_count].key, key);
                    strcpy(pairs[pair_count].value, value);
                    pair_count++;
                }
            }
        }
    }
    return pair_count;
}

void print_pairs(KeyValuePair *pairs, int count) {
    printf("Parsed JSON Key-Value Pairs:\n");
    for (int i = 0; i < count; i++) {
        printf("Key: '%s', Value: '%s'\n", pairs[i].key, pairs[i].value);
    }
}

int main() {
    char json[MAX_JSON_LENGTH];
    KeyValuePair pairs[10];

    printf("Enter your JSON string (max %d characters):\n", MAX_JSON_LENGTH - 1);
    fgets(json, MAX_JSON_LENGTH, stdin);

    // Remove newline character if present
    size_t len = strlen(json);
    if (len > 0 && json[len - 1] == '\n') {
        json[len - 1] = '\0';
    }

    int count = parse_json(json, pairs, 10);
    print_pairs(pairs, count);

    return 0;
}