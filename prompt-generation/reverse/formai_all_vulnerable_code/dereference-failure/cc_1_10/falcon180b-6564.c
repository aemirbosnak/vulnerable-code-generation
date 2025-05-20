//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    int size;
    KeyValuePair *pairs;
} JSONObject;

JSONObject *parseJSON(char *json) {
    JSONObject *obj = NULL;
    char *token = NULL;
    size_t tokenLen = 0;
    int depth = 0;
    KeyValuePair *pair = NULL;

    obj = malloc(sizeof(JSONObject));
    obj->size = 0;
    obj->pairs = NULL;

    token = strtok(json, " \t\r\n");
    while (token!= NULL) {
        tokenLen = strlen(token);
        if (token[0] == '{') {
            depth++;
        } else if (token[0] == '}') {
            depth--;
        } else if (token[0] == ':' && depth > 0) {
            pair = malloc(sizeof(KeyValuePair));
            pair->key = strndup(json, token - json);
            pair->value = strdup(token + 1);
            obj->pairs = realloc(obj->pairs, sizeof(KeyValuePair) * ++obj->size);
            obj->pairs[obj->size - 1] = *pair;
            free(pair);
        }
        token = strtok(NULL, " \t\r\n");
    }

    return obj;
}

void printJSON(JSONObject *obj) {
    int i;

    for (i = 0; i < obj->size; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }
}

int main() {
    char *json = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    JSONObject *obj = parseJSON(json);
    printJSON(obj);
    free(obj);
    return 0;
}