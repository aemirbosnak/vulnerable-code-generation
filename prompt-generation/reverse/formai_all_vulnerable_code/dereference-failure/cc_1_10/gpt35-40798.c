//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the structure for the JSON object
typedef struct json {
    char *key;
    char *value;
    struct json *next;
} JSON;

// define the callback function for handling JSON objects
typedef void(*JSON_CALLBACK)(JSON*);

// function to parse the JSON string
void parse_json_string(char* json_string, JSON_CALLBACK callback) {
    JSON *head = NULL;
    JSON *current = NULL;

    // skip leading whitespace
    while(*json_string == ' ' || *json_string == '\t' || *json_string == '\n' || *json_string == '\r') {
        json_string++;
    }

    // check if it's an object or an array
    if(*json_string == '{') {
        json_string++;

        // parse the key value pairs
        while(*json_string != '}') {
            JSON *json_obj = (JSON*)malloc(sizeof(JSON));
            json_obj->key = NULL;
            json_obj->value = NULL;
            json_obj->next = NULL;

            // parse the key
            if(*json_string == '\"') {
                json_string++;
                char *key_start = json_string;
                while(*json_string != '\"') {
                    json_string++;
                }
                int key_len = json_string - key_start;
                json_obj->key = (char*)malloc(key_len + 1);
                strncpy(json_obj->key, key_start, key_len);
                json_obj->key[key_len] = '\0';
            }

            // skip whitespace
            while(*json_string == ' ' || *json_string == '\t' || *json_string == '\n' || *json_string == '\r' || *json_string == ':') {
                json_string++;
            }

            // parse the value
            if(*json_string == '\"') {
                json_string++;
                char *value_start = json_string;
                while(*json_string != '\"') {
                    json_string++;
                }
                int value_len = json_string - value_start;
                json_obj->value = (char*)malloc(value_len + 1);
                strncpy(json_obj->value, value_start, value_len);
                json_obj->value[value_len] = '\0';
            }

            // add the object to the list
            if(head == NULL) {
                head = json_obj;
            }
            else {
                current->next = json_obj;
            }
            current = json_obj;

            // skip whitespace
            while(*json_string == ' ' || *json_string == '\t' || *json_string == '\n' || *json_string == '\r') {
                json_string++;
            }

            // check if there is another key value pair
            if(*json_string == ',') {
                json_string++;
            }
        }
    }

    // iterate over the list and call the callback function for each object
    JSON *ptr = head;
    while(ptr != NULL) {
        (*callback)(ptr);
        ptr = ptr->next;
    }
}

// example callback function to handle JSON objects
void handle_json_object(JSON *json_obj) {
    printf("Key: %s\nValue: %s\n", json_obj->key, json_obj->value);
}

int main() {
    // example JSON string to parse
    char *json_string = "{\"name\":\"John\",\"age\":\"30\",\"city\":\"New York\"}";

    // parse the JSON string asynchronously and call the handle_json_object function for each object
    parse_json_string(json_string, handle_json_object);

    return 0;
}