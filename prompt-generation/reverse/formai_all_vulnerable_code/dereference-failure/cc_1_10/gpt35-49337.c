//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef enum { 
    JSON_OBJECT, 
    JSON_ARRAY, 
    JSON_STRING, 
    JSON_NUMBER, 
    JSON_TRUE, 
    JSON_FALSE, 
    JSON_NULL 
} json_type;

typedef struct {
    json_type type;
    char *key;
    void *value;
} json_item;

json_item *parse_json(char *json_str);

int main() {
    char json_str[] = "{\"name\":\"John Doe\",\"age\":30,\"city\":\"New York\"}";
    json_item *parsed_json = parse_json(json_str);

    printf("Name: %s\n", (char *)parsed_json[0].value);
    printf("Age: %d\n", *(int *)parsed_json[1].value);
    printf("City: %s\n", (char *)parsed_json[2].value);

    return 0;
}

json_item *parse_json(char *json_str) {
    json_item *parsed_items = malloc(sizeof(json_item) * MAX_JSON_SIZE);

    int i = 0;
    while(json_str[i] != '\0') {
        if(json_str[i] == '{') {
            parsed_items[i].type = JSON_OBJECT;
        } else if(json_str[i] == '[') {
            parsed_items[i].type = JSON_ARRAY;
        } else if(json_str[i] == '\"') {
            parsed_items[i].type = JSON_STRING;

            char *key = malloc(sizeof(char) * MAX_JSON_SIZE);
            int j = 0;
            i++; /* ignore opening quote */
            while(json_str[i] != '\"') {
                key[j++] = json_str[i++];
            }
            key[j] = '\0';

            parsed_items[i].key = key;
            parsed_items[i].value = NULL;
        } else if(json_str[i] == '-') {
            parsed_items[i].type = JSON_NUMBER;

            int *value = malloc(sizeof(int));
            sscanf(json_str+i, "%d", value);

            parsed_items[i].value = value;
        } else if(json_str[i] >= '0' && json_str[i] <= '9') {
            parsed_items[i].type = JSON_NUMBER;

            int *value = malloc(sizeof(int));
            sscanf(json_str+i, "%d", value);

            parsed_items[i].value = value;
        } else if(json_str[i] == 't') {
            parsed_items[i].type = JSON_TRUE;
            parsed_items[i].value = NULL;
        } else if(json_str[i] == 'f') {
            parsed_items[i].type = JSON_FALSE;
            parsed_items[i].value = NULL;
        } else if(json_str[i] == 'n') {
            parsed_items[i].type = JSON_NULL;
            parsed_items[i].value = NULL;
        }
        i++;
    }
    return parsed_items;
}