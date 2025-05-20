//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_JSON_SIZE 10000

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    union value {
        char* string_val;
        double number_val;
        bool boolean_val;
        void* object_val;
        void* array_val;
    } value;
} json_node;

json_node* parse_json(char* json, int* pos);

json_node* parse_string(char* json, int* pos) {
    int start = *pos + 1;
    char current_char = json[start];
    char* string_val = malloc(sizeof(char) * MAX_JSON_SIZE);
    int i = 0;

    while (current_char != '"') {
        string_val[i] = current_char;
        i++;
        current_char = json[start + i];
    }

    string_val[i] = '\0';
    *pos += i + 1;

    json_node* node = malloc(sizeof(json_node));
    node->type = JSON_STRING;
    node->value.string_val = string_val;
    return node;
}

json_node* parse_number(char* json, int* pos) {
    int start = *pos;
    char current_char = json[start];
    char* number_val = malloc(sizeof(char) * MAX_JSON_SIZE);
    int i = 0;

    while (isdigit(current_char) || current_char == '.' || current_char == '-') {
        number_val[i] = current_char;
        i++;
        current_char = json[start + i];
    }

    number_val[i] = '\0';
    *pos += i;

    json_node* node = malloc(sizeof(json_node));
    node->type = JSON_NUMBER;
    node->value.number_val = atof(number_val);
    return node;
}

json_node* parse_boolean(char* json, int* pos) {
    int start = *pos;
    char current_char = json[start];
    char* boolean_val = malloc(sizeof(char) * MAX_JSON_SIZE);
    int i = 0;

    while (isalpha(current_char)) {
        boolean_val[i] = current_char;
        i++;
        current_char = json[start + i];
    }

    boolean_val[i] = '\0';
    *pos += i;

    json_node* node = malloc(sizeof(json_node));
    node->type = JSON_BOOLEAN;
    node->value.boolean_val = strcmp(boolean_val, "true") == 0;
    return node;
}

json_node* parse_null(char* json, int* pos) {
    *pos += 4;

    json_node* node = malloc(sizeof(json_node));
    node->type = JSON_NULL;
    node->value.string_val = NULL;
    return node;
}

json_node* parse_value(char* json, int* pos) {
    char current_char = json[*pos];

    if (current_char == '"') {
        return parse_string(json, pos);
    } else if (isdigit(current_char) || current_char == '.') {
        return parse_number(json, pos);
    } else if (current_char == 't' || current_char == 'f') {
        return parse_boolean(json, pos);
    } else if (current_char == 'n') {
        return parse_null(json, pos);
    }

    return NULL;
}

json_node* parse_array(char* json, int* pos) {
    json_node** array_vals = malloc(sizeof(json_node*) * MAX_JSON_SIZE);
    int index = 0;

    *pos += 1;

    while (json[*pos] != ']') {
        if (json[*pos] == ',') {
            *pos += 1;
        }

        array_vals[index] = parse_value(json, pos);
        index++;
    }

    *pos += 1;

    json_node* node = malloc(sizeof(json_node));
    node->type = JSON_ARRAY;
    node->value.array_val = array_vals;
    return node;
}

json_node* parse_object(char* json, int* pos) {
    char current_char = json[*pos];
    char* key;
    json_node* value;
    json_node** object_vals = malloc(sizeof(json_node*) * MAX_JSON_SIZE);
    int index = 0;

    *pos += 1;

    while (current_char != '}') {
        if (current_char == ',') {
            *pos += 1;
            current_char = json[*pos];
        }

        key = parse_string(json, pos)->value.string_val;

        *pos += 1;
        value = parse_value(json, pos);

        object_vals[index] = malloc(sizeof(json_node));
        object_vals[index]->value.object_val = value;
        object_vals[index]->type = JSON_OBJECT;
        index++;

        current_char = json[*pos];
    }

    *pos += 1;

    json_node* node = malloc(sizeof(json_node));
    node->type = JSON_OBJECT;
    node->value.object_val = object_vals;
    return node;
}

json_node* parse_json(char* json, int* pos) {
    char current_char = json[*pos];

    while (current_char != '\0') {
        if (current_char == '{') {
            return parse_object(json, pos);
        } else if (current_char == '[') {
            return parse_array(json, pos);
        }

        *pos += 1;
        current_char = json[*pos];
    }

    return NULL;
}

int main() {
    char* json_string = "{\"name\": \"John Smith\", \"age\": 32, \"is_active\": true, \"hobbies\": [\"football\", \"reading\"]}";
    int pos = 0;

    json_node* root = parse_json(json_string, &pos);

    printf("Name: %s\n", ((json_node**)root->value.object_val)[0]->value.string_val);
    printf("Age: %.f\n", ((json_node**)root->value.object_val)[1]->value.number_val);
    printf("Active: %s\n", ((json_node**)root->value.object_val)[2]->value.boolean_val ? "true" : "false");
    printf("Hobbies: %s, %s\n", ((json_node**)((json_node**)root->value.object_val)[3]->value.array_val)[0]->value.string_val, ((json_node**)((json_node**)root->value.object_val)[3]->value.array_val)[1]->value.string_val);

    return 0;
}