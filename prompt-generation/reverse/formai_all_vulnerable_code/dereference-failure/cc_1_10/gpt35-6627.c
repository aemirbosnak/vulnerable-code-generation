//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define maximum number of characters in JSON strings */
#define MAX_STRING_SIZE 100

/* define JSON object */
typedef struct json {
    char *key;
    char *value;
    struct json *next;
} json_t;

/* function to parse JSON string */
json_t* parse_json(const char *str) {
    /* allocate memory for JSON object */
    json_t *json = (json_t*) malloc(sizeof(json_t));
    /* initialize key and value pointer */
    json->key = NULL;
    json->value = NULL;
    /* initialize next pointer */
    json->next = NULL;
    /* copy string for manipulation */
    char *buffer = (char*) malloc(strlen(str) + 1);
    strcpy(buffer, str);
    /* isolate first key-value pair */
    char *token = strtok(buffer, ",");
    /* iterate through each key-value pair */
    while (token != NULL) {
        /* isolate key and value */
        char *key = strtok(token, ":");
        char *value = strtok(NULL, ":");
        /* remove double quotes from key */
        key++;
        key[strlen(key)-1] = '\0';
        /* remove double quotes from value */
        value++;
        value[strlen(value)-1] = '\0';
        /* allocate memory for new JSON object */
        json_t *new_node = (json_t*) malloc(sizeof(json_t));
        /* set key and value */
        new_node->key = (char*) malloc(strlen(key) + 1);
        new_node->value = (char*) malloc(strlen(value) + 1);
        strcpy(new_node->key, key);
        strcpy(new_node->value, value);
        /* append new node to linked list */
        new_node->next = json->next;
        json->next = new_node;
        /* move to next key-value pair */
        token = strtok(NULL, ",");
    }
    /* free memory for buffer */
    free(buffer);
    /* return JSON object */
    return json;
}

/* test program */
int main() {
    /* sample JSON string */
    char *str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    /* parse JSON string */
    json_t *json = parse_json(str);
    /* print JSON object */
    json_t *ptr = json->next;
    while (ptr != NULL) {
        printf("%s: %s\n", ptr->key, ptr->value);
        ptr = ptr->next;
    }
    /* free memory */
    ptr = json;
    while (ptr != NULL) {
        json_t *next = ptr->next;
        free(ptr->key);
        free(ptr->value);
        free(ptr);
        ptr = next;
    }
    /* return success */
    return 0;
}