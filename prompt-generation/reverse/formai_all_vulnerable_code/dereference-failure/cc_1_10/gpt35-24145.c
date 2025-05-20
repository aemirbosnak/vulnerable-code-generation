//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: excited
// Welcome to the exciting world of JSON parsing in C!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000

// Let's create a struct for our JSON object
typedef struct {
    char* key;
    char* value;
} Property;

// And another struct for the JSON object itself
typedef struct {
    int num_properties;
    Property* properties;
} JSONObject;

// Function to extract a string property from a JSON object
char* get_string_property(JSONObject* obj, char* key) {
    for (int i = 0; i < obj->num_properties; i++) {
        if (strcmp(obj->properties[i].key, key) == 0) {
            return obj->properties[i].value;
        }
    }
    return NULL;
}

// Now for the exciting part - our JSON parser!
JSONObject* parse_json(char* json_string) {
    JSONObject* obj = malloc(sizeof(JSONObject));
    obj->num_properties = 0;
    int current_index = 0;
    char current_char = json_string[current_index];
    while (current_char != '\0') {
        if (current_char == '{') {
            // Start of JSON object, do nothing for now
        } else if (current_char == '\"') {
            // Start of property key, mark current position
            int start_index = current_index + 1;
            current_index++; // Move past opening quote
            current_char = json_string[current_index];
            while (current_char != '\"') {
                current_index++; // Move to next character
                current_char = json_string[current_index];
            }
            int end_index = current_index;
            char* key = malloc(end_index - start_index + 1);
            strncpy(key, json_string + start_index, end_index - start_index);
            key[end_index - start_index] = '\0';
            
            // Now get the value
            current_index++; // Move past closing quote
            current_char = json_string[current_index];
            while (current_char == ' ' || current_char == ':') {
                current_index++;
                current_char = json_string[current_index];
            }
            start_index = current_index;
            if (current_char == '\"') {
                // Value is a string
                current_index++; // Move past opening quote
                current_char = json_string[current_index];
                while (current_char != '\"') {
                    current_index++; // Move to next character
                    current_char = json_string[current_index];
                }
                end_index = current_index;
                char* value = malloc(end_index - start_index + 1);
                strncpy(value, json_string + start_index, end_index - start_index);
                value[end_index - start_index] = '\0';
                obj->num_properties++;
                obj->properties = realloc(obj->properties, sizeof(Property) * obj->num_properties);
                obj->properties[obj->num_properties - 1].key = key;
                obj->properties[obj->num_properties - 1].value = value;
            } else {
                // Value is a number, not supported in this parser
                printf("Error: JSON parser only supports string properties.\n");
                exit(1);
            }
        } else if (current_char == '}') {
            // End of JSON object, we're done
            break;
        }
        current_index++; // Move to next character
        current_char = json_string[current_index];
    }
    return obj;
}

int main() {
    printf("Welcome to the JSON parser!\n");
    char* json_string = "{\"name\":\"John\",\"age\":\"42\"}";
    JSONObject* obj = parse_json(json_string);
    char* name = get_string_property(obj, "name");
    char* age = get_string_property(obj, "age");
    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    return 0;
}