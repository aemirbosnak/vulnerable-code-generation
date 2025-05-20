//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* structure for representing a JSON object */
typedef struct json_object {
    char *key;
    char *value;
} json_object;

/* function to parse JSON object from a string */
json_object* parse_json(char *json_str) {
    char *key = "", *value = "";
    int key_start = 0, key_end = 0, value_start = 0, value_end = 0;
    int i = 0, len = strlen(json_str);
    json_object *obj = (json_object*) malloc(sizeof(json_object));

    /* iterate over the string and extract key-value pairs */
    while (i < len) {
        /* look for start of key */
        if (json_str[i] == '\"' && json_str[i-1] != '\\') {
            key_start = i + 1;
        }
        /* look for end of key */
        else if (json_str[i] == '\"' && json_str[i-1] != '\\' && key_start) {
            key_end = i;
            /* extract the key */
            key = (char*) malloc((key_end - key_start + 1) * sizeof(char));
            strncpy(key, json_str + key_start, key_end - key_start);
            key[key_end - key_start] = '\0';
        }
        /* look for start of value */
        else if (json_str[i] == ':' && key_end) {
            value_start = i + 1;
        }
        /* look for end of value */
        else if ((json_str[i] == ',' || json_str[i] == '}') && value_start) {
            value_end = i;
            /* extract the value */
            value = (char*) malloc((value_end - value_start + 1) * sizeof(char));
            strncpy(value, json_str + value_start, value_end - value_start);
            value[value_end - value_start] = '\0';
            /* add the key-value pair to the JSON object */
            obj->key = key;
            obj->value = value;
            break;
        }
        i++;
    }
    return obj;
}

int main() {
    char json_str[BUFFER_SIZE] = "{\"name\":\"John Doe\",\"age\":30,\"city\":\"New York\"}";
    json_object *obj = parse_json(json_str);
    printf("Parsed JSON object: {\"%s\":\"%s\"}\n", obj->key, obj->value);
    return 0;
}