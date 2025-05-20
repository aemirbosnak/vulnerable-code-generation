//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_LEN 10000

typedef struct json_node {
    char *key;
    char *value;
    struct json_node *next;
} json_node;

json_node *json_parse(char *input) {
    json_node *head = NULL;
    json_node *current = NULL;

    char buf[JSON_MAX_LEN];
    char *ptr = strtok_r(input, ",", &buf);

    while (ptr!= NULL) {
        json_node *new_node = (json_node *) malloc(sizeof(json_node));
        if (new_node == NULL) {
            return NULL;
        }
        new_node->key = strdup(ptr);
        ptr = strtok_r(NULL, ",", &buf);
        if (ptr!= NULL) {
            new_node->value = strdup(ptr);
            current->next = new_node;
            current = new_node;
        } else {
            free(new_node->key);
            free(new_node->value);
            free(new_node);
            return NULL;
        }
    }

    return head;
}

int main() {
    char *input = "\"name\":\"John\",\"age\":30,\"city\":\"New York\"";
    json_node *head = json_parse(input);
    if (head!= NULL) {
        json_node *current = head;
        while (current!= NULL) {
            printf("Key: %s, Value: %s\n", current->key, current->value);
            current = current->next;
        }
        free(head);
    } else {
        printf("Error parsing JSON\n");
    }
    return 0;
}