//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_object json_object;
struct json_object {
    char *key;
    char *value;
    json_object *next;
};

int parse_json(char *json, json_object **head) {
    char *p = json;
    while (*p != '\0') {
        json_object *new_obj = malloc(sizeof(json_object));
        new_obj->key = NULL;
        new_obj->value = NULL;
        new_obj->next = NULL;

        // Find key
        if (*p++ == '\"') {
            char *start = p;
            while (*p != '\"') {
                if (*p == '\\') p++;  // Skip escaped characters
                p++;
            }
            new_obj->key = malloc(p - start + 1);
            strncpy(new_obj->key, start, p - start);
            new_obj->key[p - start] = '\0';
            p++;  // Skip end quote
        }

        // Find value
        if (*p++ == ':') {
            char *start = p;
            while (*p != ',' && *p != '\0') {
                p++;
            }
            new_obj->value = malloc(p - start + 1);
            strncpy(new_obj->value, start, p - start);
            new_obj->value[p - start] = '\0';
        }

        // Add object to linked list
        if (*head == NULL) {
            *head = new_obj;
        } else {
            json_object *tail = *head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = new_obj;
        }

        // Move to next object
        if (*p == ',') p++;
    }

    return 0;
}

int main() {
    char *json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    json_object *head = NULL;
    if (parse_json(json, &head) == 0) {
        // Print linked list of objects
        json_object *cur = head;
        while (cur != NULL) {
            printf("%s: %s\n", cur->key, cur->value);
            cur = cur->next;
        }
    }

    return 0;
}