//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Defining the maximum size of the JSON object
#define MAX_JSON_SIZE 10000

// Defining enum to identify JSON object types
enum json_type {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL,
};

// Defining the JSON value structure
typedef struct {
    enum json_type type;
    union {
        int int_value;
        double double_value;
        char bool_value;
        char* str_value;
        struct json_object* object_value;
        struct json_array* array_value;
    } value;
} json_value;

// Defining the JSON object structure
typedef struct json_object {
    char* key;
    json_value value;
    struct json_object* next;
} json_object;

// Defining the JSON array structure
typedef struct json_array {
    json_value value;
    struct json_array* next;
} json_array;

// Function to parse JSON string recursively
int parse_json(char* json_str, int pos, json_value* value);

// Function to create JSON object with given key and value
json_object* create_json_object(char* key, json_value value) {
    json_object* object = (json_object*) malloc(sizeof(json_object));
    object->key = key;
    object->value = value;
    object->next = NULL;
    return object;
}

// Function to create JSON array with given value
json_array* create_json_array(json_value value) {
    json_array* array = (json_array*) malloc(sizeof(json_array));
    array->value = value;
    array->next = NULL;
    return array;
}

// Function to skip whitespaces in JSON string
int skip_whitespace(char* json_str, int pos) {
    while(isspace(json_str[pos])) {
        pos++;
    }
    return pos;
}

// Function to parse JSON string recursively
int parse_json(char* json_str, int pos, json_value* value) {
    
    pos = skip_whitespace(json_str, pos);
    
    // Check if JSON object starts with '{'
    if(json_str[pos] == '{') {
        
        // Create JSON object type value
        value->type = JSON_OBJECT;
        json_object* head_obj = NULL;
        json_object* curr_obj = NULL;
        
        // Parse JSON object and add to head object
        pos = skip_whitespace(json_str, pos + 1);
        while(json_str[pos] != '}') {
            curr_obj = (json_object*) malloc(sizeof(json_object));
            curr_obj->key = NULL;
            curr_obj->value.type = JSON_NULL;
            curr_obj->next = NULL;
            if(head_obj == NULL) {
                head_obj = curr_obj;
            } else {
                curr_obj = head_obj;
                while(curr_obj->next != NULL) {
                    curr_obj = curr_obj->next;
                }
                curr_obj->next = (json_object*) malloc(sizeof(json_object));
                curr_obj = curr_obj->next;
                curr_obj->key = NULL;
                curr_obj->value.type = JSON_NULL;
                curr_obj->next = NULL;
            }
            pos = skip_whitespace(json_str, pos);
            if(json_str[pos] == '}') {
                break;
            } else if(json_str[pos] == '"') {
                // Get key of the object
                pos = skip_whitespace(json_str, pos + 1);
                char* key = (char*) malloc(100 * sizeof(char));
                int i = 0;
                while(json_str[pos] != '"') {
                    key[i++] = json_str[pos++];
                }
                curr_obj->key = (char*) malloc((i + 1) * sizeof(char));
                strncpy(curr_obj->key, key, i);
                curr_obj->key[i] = '\0'; 
                pos = skip_whitespace(json_str, pos + 1);
            }
            pos = skip_whitespace(json_str, pos);
            // Get value of the object recursively
            if(json_str[pos] == ':') {
                pos = skip_whitespace(json_str, pos + 1);
                parse_json(json_str, pos, &curr_obj->value);
                pos = skip_whitespace(json_str, pos);
            }
            // Check for continuation of JSON object
            if(json_str[pos] == ',') {
                pos = skip_whitespace(json_str, pos + 1);
            } else {
                break;
            }
        }
        // Add head object to JSON value
        value->value.object_value = head_obj;
    }
    // Check if JSON array starts with '['
    else if(json_str[pos] == '[') {
        
        // Create JSON array type value
        value->type = JSON_ARRAY;
        json_array* head_arr = NULL;
        json_array* curr_arr = NULL;
        
        // Parse JSON array and add to head array
        pos = skip_whitespace(json_str, pos + 1);
        while(json_str[pos] != ']') {
            curr_arr = (json_array*) malloc(sizeof(json_array));
            curr_arr->value.type = JSON_NULL;
            curr_arr->next = NULL;
            if(head_arr == NULL) {
                head_arr = curr_arr;
            } else {
                curr_arr = head_arr;
                while(curr_arr->next != NULL) {
                    curr_arr = curr_arr->next;
                }
                curr_arr->next = (json_array*) malloc(sizeof(json_array));
                curr_arr = curr_arr->next;
                curr_arr->value.type = JSON_NULL;
                curr_arr->next = NULL;
            }
            parse_json(json_str, pos, &curr_arr->value);
            pos = skip_whitespace(json_str, pos);
            if(json_str[pos] == ',') {
                pos = skip_whitespace(json_str, pos + 1);
            } else {
                break;
            }
        }
        // Add head array to JSON value
        value->value.array_value = head_arr;
    }
    // Check if JSON string starts with '"'
    else if(json_str[pos] == '"') {
        
        // Create JSON string type value
        value->type = JSON_STRING;
        pos++;
        char* str = (char*) malloc(100 * sizeof(char));
        int i = 0;
        while(json_str[pos] != '"') {
            str[i++] = json_str[pos++];
        }
        value->value.str_value = (char*) malloc((i + 1) * sizeof(char));
        strncpy(value->value.str_value, str, i);
        value->value.str_value[i] = '\0';
    }
    // Check if JSON number starts with number digit or '-'
    else if(json_str[pos] == '-' || isdigit(json_str[pos])) {
        
        // Create JSON number type value
        value->type = JSON_NUMBER;
        char* num = (char*) malloc(100 * sizeof(char));
        int i = 0;
        while(isdigit(json_str[pos]) || json_str[pos] == '.') {
            num[i++] = json_str[pos++];
        }
        if(strchr(num, '.') != NULL) {
            value->value.double_value = atof(num);
        } else {
            value->value.int_value = atoi(num);
        }
    }
    // Check if JSON boolean starts with 't' or 'f'
    else if(json_str[pos] == 't' || json_str[pos] == 'f') {
        
        // Create JSON boolean type value
        value->type = JSON_BOOL;
        if(json_str[pos] == 't') {
            value->value.bool_value = '1';
        } else {
            value->value.bool_value = '0';
        }
        pos += 4; // For true or false
    }
    // Check if JSON null starts with 'n'
    else if(json_str[pos] == 'n') {
        
        // Create JSON null type value
        value->type = JSON_NULL;
        pos += 3; // For null
    }
    
    // Return the position of next JSON object or array
    return pos + 1;
}

// Test the JSON parser
int main() {
    char* json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\",\"phone\":[1234567890, 9876543210], \"address\":{\"line1\":\"123 Main St\",\"line2\":\"Apt 4B\",\"city\":\"New York\",\"state\":\"NY\",\"zip\":\"10001\"},\"active\":true}";
    json_value value;
    parse_json(json_str, 0, &value);
    return 0;
}