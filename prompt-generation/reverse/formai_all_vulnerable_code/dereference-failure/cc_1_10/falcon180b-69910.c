//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1000

// Struct to hold JSON data
typedef struct {
    char* key;
    char* value;
} JSON_Data;

// Struct to hold JSON object
typedef struct {
    JSON_Data* data;
    int count;
} JSON_Object;

// Function to initialize JSON object
JSON_Object* json_object_init() {
    JSON_Object* obj = (JSON_Object*)malloc(sizeof(JSON_Object));
    obj->data = NULL;
    obj->count = 0;
    return obj;
}

// Function to add data to JSON object
void json_object_add(JSON_Object* obj, char* key, char* value) {
    JSON_Data* data = (JSON_Data*)malloc(sizeof(JSON_Data));
    data->key = strdup(key);
    data->value = strdup(value);
    obj->data = (JSON_Data*)realloc(obj->data, sizeof(JSON_Data) * (obj->count + 1));
    obj->data[obj->count] = *data;
    obj->count++;
}

// Function to print JSON object
void json_object_print(JSON_Object* obj) {
    for (int i = 0; i < obj->count; i++) {
        printf("%s: %s\n", obj->data[i].key, obj->data[i].value);
    }
}

// Function to free JSON object
void json_object_free(JSON_Object* obj) {
    for (int i = 0; i < obj->count; i++) {
        free(obj->data[i].key);
        free(obj->data[i].value);
    }
    free(obj->data);
    free(obj);
}

// Function to parse JSON string
JSON_Object* json_parse(char* json_str) {
    JSON_Object* obj = json_object_init();
    char* key = NULL;
    char* value = NULL;
    char* tmp = strdup(json_str);
    char* token = strtok(tmp, " \t\r\n{}[],:");

    while (token!= NULL) {
        if (token[0] == '{') {
            // Start of JSON object
            obj->count = 0;
        } else if (token[0] == '}') {
            // End of JSON object
            break;
        } else if (token[0] == '\"') {
            // Key-value pair
            key = strdup(token + 1);
            value = strtok(NULL, "\"\r\n");
            json_object_add(obj, key, value);
        }
        token = strtok(NULL, " \t\r\n{}[],:");
    }

    free(tmp);
    return obj;
}

// Main function
int main() {
    char* json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JSON_Object* obj = json_parse(json_str);
    json_object_print(obj);
    json_object_free(obj);
    return 0;
}