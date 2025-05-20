//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    JSONPair *pairs;
    int num_pairs;
} JSONObj;

JSONObj *parse_json(char *json) {
    JSONObj *obj = malloc(sizeof(JSONObj));

    char *key = NULL;
    char *value = NULL;
    int in_key = 1;
    int in_value = 0;

    int i = 0;
    while (json[i] != '\0') {
        char c = json[i];

        if (c == '"') {
            if (in_key) {
                key = malloc(1);
                *key = '\0';
                in_key = 0;
                in_value = 1;
            } else if (in_value) {
                value = malloc(1);
                *value = '\0';
                in_key = 1;
                in_value = 0;
            }
        } else if (c == ':' && in_key) {
            key[strlen(key)] = '\0';
        } else if (in_value) {
            value[strlen(value)] = c;
        }

        i++;
    }

    value[strlen(value)] = '\0';

    obj->pairs = malloc(sizeof(JSONPair));
    obj->pairs[0].key = key;
    obj->pairs[0].value = value;
    obj->num_pairs = 1;

    return obj;
}

void print_json(JSONObj *obj) {
    for (int i = 0; i < obj->num_pairs; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }
}

int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30}";

    JSONObj *obj = parse_json(json);

    print_json(obj);

    return 0;
}