//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
// JSON Parser Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100 // Maximum size of stack

typedef enum {
    OBJECT, // JSON object
    ARRAY, // JSON array
    STRING, // JSON string
    NUMBER, // JSON number
    TRUE, // JSON true
    FALSE, // JSON false
    NULL_VALUE, // JSON null value
    END_OF_FILE // End of file
} json_type;

typedef struct {
    json_type type; // Type of the JSON value
    union {
        char *string_value; // String value
        double number_value; // Number value
    } value;
} json_value;

typedef struct {
    json_value *values[MAX_STACK_SIZE]; // Array of JSON values
    int index; // Top of stack
} json_stack;

// Initialize JSON stack
void init_stack(json_stack *stack) {
    stack->index = -1;
}

// Push a JSON value onto the top of the stack
void push(json_stack *stack, json_value *value) {
    if (stack->index >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(EXIT_FAILURE);
    }

    stack->values[++stack->index] = value;
}

// Pop a JSON value from the top of the stack
json_value* pop(json_stack *stack) {
    if (stack->index == -1) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }

    return stack->values[stack->index--];
}

// Parse a JSON string value
json_value* parse_string(char *str) {
    json_value *value = (json_value*) malloc(sizeof(json_value));

    value->type = STRING;
    value->value.string_value = (char*) malloc(strlen(str) + 1);
    strcpy(value->value.string_value, str);

    return value;
}

// Parse a JSON number value
json_value* parse_number(double number) {
    json_value *value = (json_value*) malloc(sizeof(json_value));

    value->type = NUMBER;
    value->value.number_value = number;

    return value;
}

// Parse a JSON object
json_value* parse_object(char *json) {
    json_stack stack;
    json_value *value = (json_value*) malloc(sizeof(json_value));
    init_stack(&stack);

    int i = 0;
    char ch = json[i++];

    while (ch != '}') {
        if (ch == '\"') {
            char *key = (char*) malloc(256 * sizeof(char));
            char *val = (char*) malloc(256 * sizeof(char));
            int j = 0;

            // Parse key
            ch = json[i++];
            while (ch != '\"') {
                key[j++] = ch;
                ch = json[i++];
            }
            key[j] = '\0';

            // Skip :
            ch = json[i++];

            // Parse value
            j = 0;
            ch = json[i++];
            while (ch != '\"' && ch != ',' && ch != '}') {
                val[j++] = ch;
                ch = json[i++];
            }
            val[j] = '\0';

            json_value *obj_value;
            if (strcmp(val, "true") == 0) {
                obj_value = (json_value*) malloc(sizeof(json_value));
                obj_value->type = TRUE;
            } else if (strcmp(val, "false") == 0) {
                obj_value = (json_value*) malloc(sizeof(json_value));
                obj_value->type = FALSE;
            } else if (strcmp(val, "null") == 0) {
                obj_value = (json_value*) malloc(sizeof(json_value));
                obj_value->type = NULL_VALUE;
            } else if (isdigit(val[0]) || val[0] == '-') {
                obj_value = parse_number(strtod(val, NULL));
            } else if (val[0] == '\"') {
                obj_value = parse_string(val);
            } else {
                obj_value = NULL;
            }
            
            push(&stack, obj_value);
        }
        ch = json[i++];
    }

    value->type = OBJECT;
    while (stack.index > -1) {
        pop(&stack);
    }

    return value;
}

int main() {
    char json[] = "{"
                  "  \"name\": \"John Doe\","
                  "  \"age\": 28,"
                  "  \"is_active\": true,"
                  "  \"skills\": ["
                  "    \"C\", \"C++\", \"Python\""
                  "  ]"
                  "}";
                  
    json_value *root = parse_object(json);

    printf("JSON object has type %d\n", root->type);

    return 0;
}