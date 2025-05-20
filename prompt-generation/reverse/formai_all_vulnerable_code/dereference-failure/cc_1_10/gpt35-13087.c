//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_INVALID
} json_type;

typedef struct {
    json_type type;
    char value[MAX_LEN];
} json_token;

typedef struct json_object json_object;
typedef struct json_array json_array;

struct json_object {
    int num_fields;
    char** fields;
    json_token* values;
};

struct json_array {
    int num_elements;
    json_token* elements;
};

void error(char* msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) error("Could not open file");

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    char* buffer = (char*)malloc(size + 1);

    size_t result = fread(buffer, 1, size, fp);
    if (result != size) error("Error reading file");

    fclose(fp);

    buffer[size] = '\0';
    return buffer;
}

void print_json_token(json_token* token) {
    switch (token->type) {
        case JSON_STRING:
            printf("STRING: %s\n", token->value);
            break;
        case JSON_NUMBER:
            printf("NUMBER: %s\n", token->value);
            break;
        case JSON_TRUE:
            printf("TRUE\n");
            break;
        case JSON_FALSE:
            printf("FALSE\n");
            break;
        case JSON_NULL:
            printf("NULL\n");
            break;
        case JSON_OBJECT:
            printf("OBJECT:\n");
            for (int i = 0; i < ((json_object*)(token->value))->num_fields; i++) {
                printf("%s : ", ((json_object*)(token->value))->fields[i]);
                print_json_token(&(((json_object*)(token->value))->values[i]));
            }
            break;
        case JSON_ARRAY:
            printf("ARRAY:\n");
            for (int i = 0; i < ((json_array*)(token->value))->num_elements; i++) {
                print_json_token(&(((json_array*)(token->value))->elements[i]));
            }
            break;
        case JSON_INVALID:
            printf("INVALID\n");
            break;
    }
}

json_token parse_json_value(char* buffer, int* idx);

json_token parse_json_string(char* buffer, int* idx) {
    char result[MAX_LEN] = "";
    (*idx)++;
    while (buffer[*idx] != '\"' && buffer[*idx] != '\0') {
        strncat(result, &buffer[*idx], 1);
        (*idx)++;
    }
    if (buffer[*idx] != '\"') error("Unterminated string");
    (*idx)++;
    return (json_token){JSON_STRING, result};
}

json_token parse_json_number(char* buffer, int* idx) {
    char result[MAX_LEN] = "";
    int i = 0;
    while (isdigit(buffer[*idx]) || buffer[*idx] == '.') {
        result[i++] = buffer[*idx];
        (*idx)++;
    }
    return (json_token){JSON_NUMBER, result};
}

json_token parse_json_true(char* buffer, int* idx) {
    (*idx) += 4;
    return (json_token){JSON_TRUE, ""};
}

json_token parse_json_false(char* buffer, int* idx) {
    (*idx) += 5;
    return (json_token){JSON_FALSE, ""};
}

json_token parse_json_null(char* buffer, int* idx) {
    (*idx) += 4;
    return (json_token){JSON_NULL, ""};
}

json_array* parse_json_array(char* buffer, int* idx) {
    (*idx)++;
    json_array* result = (json_array*)malloc(sizeof(json_array));
    result->num_elements = 0;
    result->elements = (json_token*)malloc(sizeof(json_token));
    while (buffer[*idx] != ']' && buffer[*idx] != '\0') {
        if (buffer[*idx] == ',') (*idx)++;
        json_token token = parse_json_value(buffer, idx);
        result->num_elements++;
        result->elements = (json_token*)realloc(result->elements, result->num_elements * sizeof(json_token));
        result->elements[result->num_elements - 1] = token;
    }
    if (buffer[*idx] != ']') error("Unterminated array");
    (*idx)++;
    return result;
}

json_object* parse_json_object(char* buffer, int* idx) {
    (*idx)++;
    json_object* result = (json_object*)malloc(sizeof(json_object));
    result->num_fields = 0;
    result->fields = (char**)malloc(sizeof(char));
    result->values = (json_token*)malloc(sizeof(json_token));
    while (buffer[*idx] != '}' && buffer[*idx] != '\0') {
        if (buffer[*idx] == ',') (*idx)++;
        json_token field_token = parse_json_string(buffer, idx);
        (*idx)++; // consume colon
        json_token value_token = parse_json_value(buffer, idx);
        result->num_fields++;
        result->fields = (char**)realloc(result->fields, result->num_fields * sizeof(char*));
        result->values = (json_token*)realloc(result->values, result->num_fields * sizeof(json_token));
        result->fields[result->num_fields - 1] = strdup(field_token.value);
        result->values[result->num_fields - 1] = value_token;
    }
    if (buffer[*idx] != '}') error("Unterminated object");
    (*idx)++;
    return result;
}

json_token parse_json_value(char* buffer, int* idx) {
    while (isspace(buffer[*idx])) (*idx)++; // consume whitespace
    switch (buffer[*idx]) {
        case '\"':
            return parse_json_string(buffer, idx);
        case '-':
        case '0' ... '9':
            return parse_json_number(buffer, idx);
        case 't':
            return parse_json_true(buffer, idx);
        case 'f':
            return parse_json_false(buffer, idx);
        case 'n':
            return parse_json_null(buffer, idx);
        case '{':
            return (json_token){JSON_OBJECT, parse_json_object(buffer, idx)};
        case '[':
            return (json_token){JSON_ARRAY, parse_json_array(buffer, idx)};
        default:
            return (json_token){JSON_INVALID, ""};
    }
}

json_token parse_json(char* buffer) {
    int idx = 0;
    json_token result = parse_json_value(buffer, &idx);
    while (isspace(buffer[idx])) idx++; // consume whitespace
    if (buffer[idx] != '\0') error("Extra characters found after JSON");
    return result;
}

int main() {
    char* buffer = read_file("example.json");
    if (buffer == NULL) error("Could not read file");

    json_token token = parse_json(buffer);
    print_json_token(&token);

    free(buffer);
    return 0;
}