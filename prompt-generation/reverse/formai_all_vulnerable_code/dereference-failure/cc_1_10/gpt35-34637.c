//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 100000

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct JSONValue {
    json_type type;
    char* key;
    union {
        char* string_val;
        double number_val;
        struct JSONValue* object_val;
        struct JSONValue* array_val;
    } u;
    struct JSONValue* next; // used for linked list
} JSONValue;

JSONValue* parse_json(char* json);
JSONValue* parse_object(char** cur_pos);
JSONValue* parse_array(char** cur_pos);
JSONValue* parse_value(char** cur_pos);

char* read_file(char* filename);

int main() {
    char* json = read_file("example.json");
    JSONValue* root = parse_json(json);
    // do something with the root JSONValue
    return 0;
}

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char* buffer = (char*) malloc(MAX_JSON_SIZE * sizeof(char));
    size_t n = fread(buffer, 1, MAX_JSON_SIZE, fp);
    buffer[n] = '\0';

    fclose(fp);

    return buffer;
}

JSONValue* parse_json(char* json) {
    char* cur_pos = json;
    return parse_value(&cur_pos);
}

JSONValue* parse_object(char** cur_pos) {
    JSONValue* head = NULL;
    JSONValue* curr = NULL;
    char* key = NULL;

    // skip opening brace
    (*cur_pos)++;

    while (**cur_pos != '}') {
        // skip whitespace
        while (**cur_pos == ' ' || **cur_pos == '\t' || **cur_pos == '\n') {
            (*cur_pos)++;
        }

        // parse key
        if (**cur_pos == '"') {
            (*cur_pos)++; // skip opening quote
            int len = strcspn(*cur_pos, "\"");
            key = strndup(*cur_pos, len);
            (*cur_pos) += len + 1; // skip closing quote and colon
        } else {
            printf("Error parsing JSON object key\n");
            exit(1);
        }

        // parse value
        JSONValue* val = parse_value(cur_pos);
        val->key = key;
        key = NULL;

        // add to linked list
        if (head == NULL) {
            head = curr = val;
        } else {
            curr->next = val;
            curr = val;
        }

        // skip whitespace
        while (**cur_pos == ' ' || **cur_pos == '\t' || **cur_pos == '\n') {
            (*cur_pos)++;
        }

        if (**cur_pos == ',') {
            (*cur_pos)++; // skip comma
        } else if (**cur_pos == '}') {
            break;
        } else {
            printf("Error parsing JSON object\n");
            exit(1);
        }
    }

    (*cur_pos)++; // skip closing brace

    return head;
}

JSONValue* parse_array(char** cur_pos) {
    JSONValue* head = NULL;
    JSONValue* curr = NULL;

    // skip opening bracket
    (*cur_pos)++;

    while (**cur_pos != ']') {
        // skip whitespace
        while (**cur_pos == ' ' || **cur_pos == '\t' || **cur_pos == '\n') {
            (*cur_pos)++;
        }

        // parse value
        JSONValue* val = parse_value(cur_pos);

        // add to linked list
        if (head == NULL) {
            head = curr = val;
        } else {
            curr->next = val;
            curr = val;
        }

        // skip whitespace
        while (**cur_pos == ' ' || **cur_pos == '\t' || **cur_pos == '\n') {
            (*cur_pos)++;
        }

        if (**cur_pos == ',') {
            (*cur_pos)++; // skip comma
        } else if (**cur_pos == ']') {
            break;
        } else {
            printf("Error parsing JSON array\n");
            exit(1);
        }
    }

    (*cur_pos)++; // skip closing bracket

    return head;
}

JSONValue* parse_value(char** cur_pos) {
    JSONValue* val = (JSONValue*) malloc(sizeof(JSONValue));
    val->key = NULL;
    val->next = NULL;

    // skip whitespace
    while (**cur_pos == ' ' || **cur_pos == '\t' || **cur_pos == '\n') {
        (*cur_pos)++;
    }

    // parse value based on first character
    switch (**cur_pos) {
        case '"':
            {
                (*cur_pos)++; // skip opening quote
                int len = strcspn(*cur_pos, "\"");
                val->type = JSON_STRING;
                val->u.string_val = strndup(*cur_pos, len);
                (*cur_pos) += len + 1; // skip closing quote
                break;
            }
        case '-':
        case '0'...'9':
            {
                char* endptr;
                val->type = JSON_NUMBER;
                val->u.number_val = strtod(*cur_pos, &endptr);
                (*cur_pos) = endptr;
                break;
            }
        case '{':
            {
                val->type = JSON_OBJECT;
                val->u.object_val = parse_object(cur_pos);
                break;
            }
        case '[':
            {
                val->type = JSON_ARRAY;
                val->u.array_val = parse_array(cur_pos);
                break;
            }
        case 't':
            {
                val->type = JSON_TRUE;
                val->u.string_val = "true";
                (*cur_pos) += 4;
                break;
            }
        case 'f':
            {
                val->type = JSON_FALSE;
                val->u.string_val = "false";
                (*cur_pos) += 5;
                break;
            }
        case 'n':
            {
                val->type = JSON_NULL;
                val->u.string_val = "null";
                (*cur_pos) += 4;
                break;
            }
        default:
            {
                printf("Error parsing JSON value\n");
                exit(1);
            }
    }

    return val;
}