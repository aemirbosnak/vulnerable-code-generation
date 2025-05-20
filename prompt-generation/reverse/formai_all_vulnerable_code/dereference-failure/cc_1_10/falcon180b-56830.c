//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 10000
#define MAX_KEY_VALUE_SIZE 100

typedef struct {
    char *key;
    char *value;
} key_value_pair_t;

typedef struct {
    int num_pairs;
    key_value_pair_t *pairs;
} json_object_t;

void add_pair(json_object_t *obj, char *key, char *value) {
    obj->num_pairs++;
    obj->pairs = realloc(obj->pairs, sizeof(key_value_pair_t) * obj->num_pairs);
    obj->pairs[obj->num_pairs - 1].key = strdup(key);
    obj->pairs[obj->num_pairs - 1].value = strdup(value);
}

char *get_value(json_object_t *obj, char *key) {
    int i;
    for (i = 0; i < obj->num_pairs; i++) {
        if (strcmp(obj->pairs[i].key, key) == 0) {
            return obj->pairs[i].value;
        }
    }
    return NULL;
}

int main() {
    char *json_str = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    json_object_t *obj = NULL;
    char *key, *value;
    char *token;
    int i;

    obj = malloc(sizeof(json_object_t));
    obj->num_pairs = 0;
    obj->pairs = NULL;

    token = strtok(json_str, "{");
    while (token!= NULL) {
        key = strtok(token, ":");
        value = strtok(NULL, ",");
        if (key!= NULL && value!= NULL) {
            add_pair(obj, key, value);
        }
        token = strtok(NULL, "}");
    }

    printf("Name: %s\n", get_value(obj, "name"));
    printf("Age: %s\n", get_value(obj, "age"));
    printf("City: %s\n", get_value(obj, "city"));

    for (i = 0; i < obj->num_pairs; i++) {
        printf("Key: %s, Value: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }

    return 0;
}