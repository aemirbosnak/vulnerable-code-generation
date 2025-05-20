//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY 256
#define MAX_VALUE 256

typedef struct {
    char key[MAX_KEY];
    char value[MAX_VALUE];
} Pair;

typedef struct {
    Pair pairs[MAX_KEY];
    int size;
} Json;

Json* parse_json(char* str) {
    Json* json = malloc(sizeof(Json));
    json->size = 0;

    char key[MAX_KEY];
    char value[MAX_VALUE];
    int key_len = 0;
    int value_len = 0;
    int in_key = 1;
    int in_value = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"') {
            if (in_key) {
                in_key = 0;
                in_value = 1;
            } else {
                in_key = 1;
                in_value = 0;
                Pair pair;
                strcpy(pair.key, key);
                strcpy(pair.value, value);
                json->pairs[json->size++] = pair;
                key_len = 0;
                value_len = 0;
            }
        } else if (in_key) {
            key[key_len++] = str[i];
        } else if (in_value) {
            value[value_len++] = str[i];
        }
    }

    return json;
}

void print_json(Json* json) {
    for (int i = 0; i < json->size; i++) {
        printf("%s: %s\n", json->pairs[i].key, json->pairs[i].value);
    }
}

int main() {
    char* json_str = "{\"name\": \"Ada Lovelace\", \"age\": 36}";
    Json* json = parse_json(json_str);
    print_json(json);
    free(json);
    return 0;
}