//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STR_LEN 256
#define MAX_ARR_LEN 100

// Struct for JSON object      
typedef struct {
    char* key;
    char* value;
} object;

// Struct for JSON array
typedef struct {
    char* values[MAX_ARR_LEN];
    int length;
} array;

// Helper function to skip white space
void skip_space(char** str) {
    while(isspace(**str)) {
        (*str)++;
    }
}

// Function to parse JSON object
object* parse_object(char** str) {
    object* obj = malloc(sizeof(object));
    obj->key = NULL;
    obj->value = NULL;
    
    skip_space(str); // Skip leading white space
    
    // Check for empty object
    if(**str == '}') {
        (*str)++;
        return obj;
    }

    // Loop through object
    while(**str != '}') {
        // Extract key name
        char key[MAX_STR_LEN] = {0};
        int i = 0;
        while(**str != ':') {
            key[i++] = **str;
            (*str)++;
        }
        (*str)++; // Skip colon
        obj->key = strdup(key); // Store key name
        
        // Extract value
        char value[MAX_STR_LEN] = {0};
        i = 0;
        while(**str != ',' && **str != '}') {
            value[i++] = **str;
            (*str)++;
        }
        obj->value = strdup(value); // Store value
        
        if(**str == ',') {
            (*str)++; // Move to next key-value pair
        }
    }
    
    return obj;
}

// Function to parse JSON array
array* parse_array(char** str) {
    array* arr = malloc(sizeof(array));
    arr->length = 0;
    
    skip_space(str); // Skip leading white space
    
    // Check for empty array
    if(**str == ']') {
        (*str)++;
        return arr;
    }

    // Loop through array
    while(**str != ']') {
        // Extract value
        char value[MAX_STR_LEN] = {0};
        int i = 0;
        while(**str != ',' && **str != ']') {
            value[i++] = **str;
            (*str)++;
        }
        arr->values[arr->length++] = strdup(value); // Store value
        
        if(**str == ',') {
            (*str)++; // Move to next value
        }
    }
    
    return arr;
}

// Function to parse JSON value
void* parse_value(char** str) {
    skip_space(str); // Skip leading white space
    
    if(**str == '{') { // Check for object
        (*str)++;
        return parse_object(str);
    }
    else if(**str == '[') { // Check for array
        (*str)++;
        return parse_array(str);
    }
    else { // Assume string value
        char value[MAX_STR_LEN] = {0};
        int i = 0;
        while(!isspace(**str) && **str != ',' && **str != '}' && **str != ']') {
            value[i++] = **str;
            (*str)++;
        }
        return strdup(value); // Return string value
    }
}

// Function to print JSON object
void print_object(object* obj) {
    printf("{ ");
    printf("%s: %s ", obj->key, obj->value);
    printf("}\n");
}

// Function to print JSON array
void print_array(array* arr) {
    printf("[ ");
    for(int i = 0; i < arr->length; i++) {
        printf("%s ", arr->values[i]);
    }
    printf("]\n");
}

int main() {
    char json[] = "{ name: \"John\", age: 27, city: \"New York\", hobbies: [\"reading\", \"drawing\"], job: { title: \"Software Engineer\", salary: 100000 } }";
    char* json_ptr = json;
    object* obj = parse_object(&json_ptr);
    
    print_object(obj);
    print_array((array*)obj->value);
    print_object((object*)((array*)obj->value)->values[0]);
    printf("%s\n", ((object*)((array*)obj->value)->values[0])->value);
    
    free(obj->key);
    free(obj->value);
    free(obj);
    return 0;
}