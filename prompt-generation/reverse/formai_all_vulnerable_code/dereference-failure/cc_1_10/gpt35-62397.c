//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef enum {JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_NUMBER, JSON_BOOLEAN, JSON_NULL} json_type;

typedef struct {
    json_type type;
    union {
        char object_name[MAX_STRING_LENGTH];
        char *string;
        double number;
        int boolean;
    } data;
} json_value;

typedef struct json_object {
    json_value value;
    struct json_object *next;
} json_object;

void handle_error(char *error_message) {
    printf("Error: %s", error_message);
    exit(1);
}

char *parse_string(char *json_string) {
    char *result = calloc(MAX_STRING_LENGTH, sizeof(char));
    int position = 0;
    int length = strlen(json_string);
    
    if(json_string[position++] != '\"') {
        handle_error("Invalid string format: does not start with '\"'");
    }
    
    while(position < length && json_string[position] != '\"') {
        result[position - 1] = json_string[position];
        position++;
    }
    
    if(json_string[position++] != '\"') {
        handle_error("Invalid string format: does not end with '\"'");
    }
    
    return result;
}

double parse_number(char *json_string) {
    return atof(json_string);
}

int parse_boolean(char *json_string) {
    if(strcmp(json_string, "true") == 0) {
        return 1;
    } else if(strcmp(json_string, "false") == 0) {
        return 0;
    } else {
        handle_error("Invalid boolean value");
    }
}

void print_json_object(json_object *object) {
    if(object) {
        switch(object->value.type) {
            case JSON_OBJECT:
                printf("{");
                print_json_object(object->next);
                printf("}");
                break;
            case JSON_ARRAY:
                printf("[");
                print_json_object(object->next);
                printf("]");
                break;
            case JSON_STRING:
                printf("%s", object->value.data.string);
                break;
            case JSON_NUMBER:
                printf("%f", object->value.data.number);
                break;
            case JSON_BOOLEAN:
                printf("%d", object->value.data.boolean);
                break;
            case JSON_NULL:
                printf("null");
                break;
            default:
                handle_error("Invalid JSON type");
        }
        
        if(object->next) {
            printf(",");
            print_json_object(object->next);
        }
    }
}

json_object *parse_json(char *json_string) {
    json_object *result = NULL;
    int position = 0;
    int length = strlen(json_string);
    char object_name[MAX_STRING_LENGTH];
    
    while(position < length) {
        char current_char = json_string[position++];
        
        if(current_char == '{') {
            json_object *new_object = malloc(sizeof(json_object));
            new_object->value.type = JSON_OBJECT;
            new_object->next = parse_json(json_string + position);
            
            if(!result) {
                result = new_object;
            }
            
            if(json_string[position + 1] == '\"') {
                position++;
                new_object->value.data.string = parse_string(json_string + position);
                
                while(json_string[position] != ':') {
                    position++;
                }
                
                position++;
            }
            
        } else if(current_char == '}') {
            return result;
        } else if(current_char == '[') {
            json_object *new_object = malloc(sizeof(json_object));
            new_object->value.type = JSON_ARRAY;
            new_object->next = parse_json(json_string + position);
            
            if(!result) {
                result = new_object;
            }
        } else if(current_char == ']') {
            return result;
        } else if(current_char == '\"') {
            json_object *new_object = malloc(sizeof(json_object));
            new_object->value.type = JSON_STRING;
            new_object->value.data.string = parse_string(json_string + position);
            
            if(!result) {
                result = new_object;
            }
        } else if(current_char == '-') {
            char number_string[MAX_STRING_LENGTH];
            number_string[0] = '-';
            int number_position = 1;
            
            while(position < length && isdigit(json_string[position])) {
                number_string[number_position++] = json_string[position++];
            }
            
            json_object *new_object = malloc(sizeof(json_object));
            new_object->value.type = JSON_NUMBER;
            new_object->value.data.number = parse_number(number_string);
            
            if(!result) {
                result = new_object;
            }
        } else if(isdigit(current_char)) {
            char number_string[MAX_STRING_LENGTH];
            number_string[0] = current_char;
            int number_position = 1;
            
            while(position < length && isdigit(json_string[position])) {
                number_string[number_position++] = json_string[position++];
            }
            
            json_object *new_object = malloc(sizeof(json_object));
            new_object->value.type = JSON_NUMBER;
            new_object->value.data.number = parse_number(number_string);
            
            if(!result) {
                result = new_object;
            }
        } else if(current_char == 't' || current_char == 'f') {
            char boolean_string[MAX_STRING_LENGTH];
            boolean_string[0] = current_char;
            int boolean_position = 1;
            
            while(position < length && isalpha(json_string[position])) {
                boolean_string[boolean_position++] = json_string[position++];
            }
            
            json_object *new_object = malloc(sizeof(json_object));
            new_object->value.type = JSON_BOOLEAN;
            new_object->value.data.boolean = parse_boolean(boolean_string);
            
            if(!result) {
                result = new_object;
            }
        } else if(current_char == 'n') {
            char *null_string = "null";
            if(strncmp(json_string + position - 1, null_string, strlen(null_string)) != 0) {
                handle_error("Invalid null value");
            }
            
            json_object *new_object = malloc(sizeof(json_object));
            new_object->value.type = JSON_NULL;
            
            if(!result) {
                result = new_object;
            }
            position += strlen(null_string) - 1;
        }
    }
    
    return result;
}

int main() {
    char *json_string = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    json_object *json_object = parse_json(json_string);
    print_json_object(json_object);
    return 0;
}