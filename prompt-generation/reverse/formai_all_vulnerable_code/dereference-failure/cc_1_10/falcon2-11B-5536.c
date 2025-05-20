//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
/* JSON Parser Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_LENGTH 1000

typedef struct {
    char *key;
    char *value;
} JSON_Value;

typedef struct {
    JSON_Value *values;
    int size;
    int capacity;
} JSON_Object;

JSON_Object *json_object_create() {
    JSON_Object *obj = malloc(sizeof(JSON_Object));
    obj->values = malloc(sizeof(JSON_Value) * JSON_MAX_LENGTH);
    obj->size = 0;
    obj->capacity = JSON_MAX_LENGTH;
    return obj;
}

void json_object_destroy(JSON_Object *obj) {
    free(obj->values);
    free(obj);
}

void json_object_append_key_value(JSON_Object *obj, const char *key, const char *value) {
    JSON_Value *value_obj = malloc(sizeof(JSON_Value));
    value_obj->key = strdup(key);
    value_obj->value = strdup(value);
    obj->values[obj->size] = *value_obj;
    obj->size++;
}

void json_object_append_value(JSON_Object *obj, const char *value) {
    JSON_Value *value_obj = malloc(sizeof(JSON_Value));
    value_obj->key = NULL;
    value_obj->value = strdup(value);
    obj->values[obj->size] = *value_obj;
    obj->size++;
}

const char *json_object_get_key(const JSON_Object *obj, int index) {
    return obj->values[index].key;
}

const char *json_object_get_value(const JSON_Object *obj, int index) {
    return obj->values[index].value;
}

void json_object_get_all_keys(const JSON_Object *obj, int *keys) {
    int i;
    for (i = 0; i < obj->size; i++) {
        keys[i] = i;
    }
}

int json_object_get_size(const JSON_Object *obj) {
    return obj->size;
}

void json_object_free_all_keys(const JSON_Object *obj, int *keys, int size) {
    for (int i = 0; i < size; i++) {
        free(obj->values[keys[i]].key);
    }
    free(keys);
}

int main() {
    JSON_Object *obj = json_object_create();
    json_object_append_key_value(obj, "name", "John");
    json_object_append_key_value(obj, "age", "25");
    json_object_append_value(obj, "address");
    json_object_append_value(obj, "phone");

    const char *name = json_object_get_key(obj, 0);
    const char *age = json_object_get_key(obj, 1);
    const char *address = json_object_get_value(obj, 2);
    const char *phone = json_object_get_value(obj, 3);

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("Address: %s\n", address);
    printf("Phone: %s\n", phone);

    json_object_free_all_keys(obj, (int*)&(obj->size), obj->size);
    json_object_destroy(obj);

    return 0;
}