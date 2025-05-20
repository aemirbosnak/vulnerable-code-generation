//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for holding JSON values
typedef struct {
    char* key;
    char* value;
} JSONValue;

// Define a struct for holding JSON objects
typedef struct {
    int size;
    JSONValue* values;
} JSONObject;

// Define a struct for holding JSON arrays
typedef struct {
    int size;
    JSONValue* values;
} JSONArray;

// Define a function for parsing a JSON object
JSONObject* parse_object(char* json) {
    JSONObject* object = malloc(sizeof(JSONObject));
    object->size = 0;
    
    int length = strlen(json);
    int index = 1; // Ignore the opening brace
    
    // Parse each key-value pair
    while (index < length) {
        char* key = strtok(json + index, "\"");
        index += strlen(key) + 2; // Ignore the opening and closing quotes
        
        index++; // Ignore the colon
        
        char* value = strtok(json + index, ",");
        index += strlen(value) + 1; // Ignore the comma
        
        // Add the key-value pair to the object
        object->size++;
        object->values = realloc(object->values, object->size * sizeof(JSONValue));
        object->values[object->size - 1].key = key;
        object->values[object->size - 1].value = value;
    }
    
    return object;
}

// Define a function for parsing a JSON array
JSONArray* parse_array(char* json) {
    JSONArray* array = malloc(sizeof(JSONArray));
    array->size = 0;
    
    int length = strlen(json);
    int index = 1; // Ignore the opening bracket
    
    // Parse each value
    while (index < length) {
        char* value = strtok(json + index, ",");
        index += strlen(value) + 1; // Ignore the comma
        
        // Add the value to the array
        array->size++;
        array->values = realloc(array->values, array->size * sizeof(JSONValue));
        array->values[array->size - 1].key = NULL;
        array->values[array->size - 1].value = value;
    }
    
    return array;
}

// Define a function for printing a JSON object
void print_object(JSONObject* object) {
    printf("{");
    for (int i = 0; i < object->size; i++) {
        printf("\"%s\": \"%s\"", object->values[i].key, object->values[i].value);
        if (i < object->size - 1) {
            printf(", ");
        }
    }
    printf("}");
}

// Define a function for printing a JSON array
void print_array(JSONArray* array) {
    printf("[");
    for (int i = 0; i < array->size; i++) {
        printf("\"%s\"", array->values[i].value);
        if (i < array->size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int main() {
    // Example JSON strings
    char* object_json = "{\"name\": \"John\", \"age\": 30}";
    char* array_json = "[\"apple\", \"banana\", \"cherry\"]";
    
    // Parse the JSON strings
    JSONObject* object = parse_object(object_json);
    JSONArray* array = parse_array(array_json);
    
    // Print the parsed JSON objects
    print_object(object); // Output: {"name": "John", "age": "30"}
    print_array(array); // Output: ["apple", "banana", "cherry"]
    
    // Free the memory used by the parsed JSON objects
    for (int i = 0; i < object->size; i++) {
        free(object->values[i].key);
        free(object->values[i].value);
    }
    free(object->values);
    free(object);
    
    for (int i = 0; i < array->size; i++) {
        free(array->values[i].value);
    }
    free(array->values);
    free(array);
    
    return 0;
}