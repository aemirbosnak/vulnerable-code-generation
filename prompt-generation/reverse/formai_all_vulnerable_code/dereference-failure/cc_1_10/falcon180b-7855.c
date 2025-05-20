//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000000
#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct {
    char *key;
    char *value;
} json_pair_t;

typedef struct {
    json_pair_t *pairs;
    int num_pairs;
} json_object_t;

json_object_t *parse_json(char *json_str) {
    int i = 0;
    json_object_t *obj = NULL;
    char *cur_pair = json_str;
    char *key = NULL;
    char *value = NULL;

    obj = (json_object_t *) malloc(sizeof(json_object_t));
    obj->pairs = (json_pair_t *) malloc(sizeof(json_pair_t));
    obj->num_pairs = 0;

    while (i < MAX_JSON_SIZE) {
        key = strtok(cur_pair, ":");
        value = strtok(NULL, ",");

        if (key == NULL || value == NULL) {
            break;
        }

        json_pair_t *pair = (json_pair_t *) malloc(sizeof(json_pair_t));
        pair->key = key;
        pair->value = value;

        obj->pairs[obj->num_pairs] = *pair;
        obj->num_pairs++;

        cur_pair = NULL;
        i++;
    }

    return obj;
}

void print_object(json_object_t *obj) {
    int i;
    for (i = 0; i < obj->num_pairs; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }
}

int main() {
    char *json_str = "name: John, age: 30, city: New York";
    json_object_t *obj = parse_json(json_str);
    print_object(obj);

    free(obj->pairs);
    free(obj);

    return 0;
}