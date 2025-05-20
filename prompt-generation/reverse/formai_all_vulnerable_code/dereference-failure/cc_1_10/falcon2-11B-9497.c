//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct json_object {
    char *key;
    char *value;
} json_object;

json_object *parse_json(char *json_str) {
    json_object *json_obj = NULL;
    char *ptr = strtok(json_str, "{");
    json_obj = malloc(sizeof(json_object));
    json_obj->key = strdup("");
    json_obj->value = strdup("");
    while (ptr!= NULL) {
        if (strcmp(ptr, "{") == 0) {
            ptr = strtok(NULL, "}");
            json_obj->key = strdup(ptr);
            ptr = strtok(NULL, ":");
            json_obj->value = strdup(ptr);
            ptr = strtok(NULL, ",");
        } else if (strcmp(ptr, "}") == 0) {
            break;
        } else if (strcmp(ptr, ",") == 0) {
            ptr = strtok(NULL, ":");
            json_obj->value = strdup(ptr);
            ptr = strtok(NULL, ",");
        } else if (strcmp(ptr, ":") == 0) {
            ptr = strtok(NULL, ":");
            json_obj->key = strdup(ptr);
            ptr = strtok(NULL, ",");
        } else if (strcmp(ptr, "\n") == 0) {
            ptr = strtok(NULL, ":");
            json_obj->value = strdup(ptr);
            ptr = strtok(NULL, ",");
        } else if (strcmp(ptr, "\n")!= 0) {
            ptr = strtok(NULL, ":");
            json_obj->value = strdup(ptr);
            ptr = strtok(NULL, ",");
        }
    }
    return json_obj;
}

int main() {
    char json_str[] = "{ \"name\": \"John\", \"age\": 30 }";
    json_object *json_obj = parse_json(json_str);
    if (json_obj!= NULL) {
        printf("Key: %s, Value: %s\n", json_obj->key, json_obj->value);
        free(json_obj->key);
        free(json_obj->value);
        free(json_obj);
    }
    return 0;
}