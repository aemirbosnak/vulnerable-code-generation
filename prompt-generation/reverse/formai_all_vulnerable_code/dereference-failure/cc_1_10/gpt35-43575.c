//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_OBJECTS 100
#define MAX_JSON_ARRAYS 50
#define MAX_JSON_NESTING 20
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 500

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct json_node {
    json_type type;
    char key[MAX_KEY_LENGTH];
    union {
        char string_value[MAX_VALUE_LENGTH];
        double number_value;
        int boolean_value;
        struct json_node *node_ptr;
    } value;
} json_node;

int current_object = 0, current_array = 0, current_nesting = 0;
json_node objects[MAX_JSON_OBJECTS];
json_node arrays[MAX_JSON_ARRAYS];
json_node nesting[MAX_JSON_NESTING];

// Function to create a new JSON object
json_node* create_object(char *key, json_type type) {
    json_node *new_object = malloc(sizeof(json_node));
    new_object->type = type;
    strcpy(new_object->key, key);
    return new_object;
}

void append_key(char *key, char c) {
    int len = strlen(key);
    key[len] = c;
    key[len+1] = '\0';
}

// Function to parse the JSON input and fill out the corresponding objects and arrays
void parse_json(char *input) {
    int i = 0;
    char c = input[i];
    while(c != '\0') {
        if(c == '{') {
            char key[MAX_KEY_LENGTH] = "";
            json_node *new_object = create_object(key, JSON_OBJECT);
            nesting[current_nesting++] = *new_object;
            objects[current_object++] = *new_object;
        } else if(c == '[') {
            char key[MAX_KEY_LENGTH] = "";
            json_node *new_array = create_object(key, JSON_ARRAY);
            nesting[current_nesting++] = *new_array;
            arrays[current_array++] = *new_array;
        } else if(c == '}') {
            current_nesting--;
        } else if(c == ']') {
            current_nesting--;
        } else if(c == '\"') {
            char key[MAX_KEY_LENGTH] = "";
            i++;
            c = input[i];
            while(c != '\"') {
                append_key(key, c);
                i++;
                c = input[i];
            }
            json_node *new_string = create_object(key, JSON_STRING);
            new_string->value.node_ptr = &nesting[current_nesting-1];
            nesting[current_nesting-1] = *new_string;
        } else if(c == '-' || (c >= '0' && c <= '9')) {
            char key[MAX_KEY_LENGTH] = "";
            int is_float = 0;
            while((c >= '0' && c <= '9') || c == '.') {
                if(c == '.') is_float = 1;
                append_key(key, c);
                i++;
                c = input[i];
            }
            if(is_float) {
                json_node *new_number = create_object(key, JSON_NUMBER);
                new_number->value.number_value = strtod(key, NULL);
                nesting[current_nesting-1] = *new_number;
            } else {
                json_node *new_number = create_object(key, JSON_NUMBER);
                new_number->value.number_value = strtol(key, NULL, 10);
                nesting[current_nesting-1] = *new_number;
            }
        } else if(c == 't' || c == 'f') {
            char key[MAX_KEY_LENGTH] = "";
            if(c == 't') {
                append_key(key, c);
                i += 3;
                json_node *new_boolean = create_object(key, JSON_BOOLEAN);
                new_boolean->value.boolean_value = 1;
                nesting[current_nesting-1] = *new_boolean;
            } else {
                append_key(key, c);
                i += 4;
                json_node *new_boolean = create_object(key, JSON_BOOLEAN);
                new_boolean->value.boolean_value = 0;
                nesting[current_nesting-1] = *new_boolean;
            }
        } else if(c == 'n') {
            char key[MAX_KEY_LENGTH] = "";
            append_key(key, c);
            i += 3;
            json_node *new_null = create_object(key, JSON_NULL);
            nesting[current_nesting-1] = *new_null;
        }
        i++;
        c = input[i];
    }
}

int main() {
    char json_input[] = "{ \"name\": \"Tom\", \"age\": 25, \"isMarried\": false, \"hobbies\": [\"Swimming\", \"Gardening\", \"Cooking\"], \"address\": {\"street\": \"123 Main St\", \"city\": \"Austin\", \"state\": \"TX\"}, \"purchases\": [{\"item\": \"Book\", \"price\": 10.99}, {\"item\": \"Shirt\", \"price\": 22.50}]}";
    parse_json(json_input);
    return 0;
}