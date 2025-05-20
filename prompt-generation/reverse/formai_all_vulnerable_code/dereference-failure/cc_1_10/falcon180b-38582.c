//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

typedef struct {
    char *key;
    char *value;
} key_value_pair;

typedef struct {
    int size;
    key_value_pair *pairs;
} json_object;

json_object* create_json_object() {
    json_object *obj = (json_object*)malloc(sizeof(json_object));
    obj->size = 0;
    obj->pairs = (key_value_pair*)malloc(sizeof(key_value_pair) * MAX_SIZE);
    return obj;
}

void add_key_value_pair(json_object *obj, char *key, char *value) {
    if (obj->size >= MAX_SIZE) {
        printf("Error: JSON object is full.\n");
        return;
    }
    obj->pairs[obj->size].key = strdup(key);
    obj->pairs[obj->size].value = strdup(value);
    obj->size++;
}

void print_json_object(json_object *obj) {
    for (int i = 0; i < obj->size; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }
}

void free_json_object(json_object *obj) {
    for (int i = 0; i < obj->size; i++) {
        free(obj->pairs[i].key);
        free(obj->pairs[i].value);
    }
    free(obj->pairs);
    free(obj);
}

int main() {
    char input[MAX_SIZE];
    char *token;
    char *key = NULL;
    char *value = NULL;
    json_object *obj = create_json_object();

    printf("Enter JSON data:\n");
    fgets(input, MAX_SIZE, stdin);

    token = strtok(input, " \t\r\n");
    while (token!= NULL) {
        if (key == NULL) {
            key = strdup(token);
        } else if (value == NULL) {
            value = strdup(token);
        } else {
            add_key_value_pair(obj, key, value);
            key = NULL;
            value = NULL;
        }
        token = strtok(NULL, " \t\r\n");
    }

    if (key!= NULL && value!= NULL) {
        add_key_value_pair(obj, key, value);
    }

    print_json_object(obj);

    free_json_object(obj);

    return 0;
}