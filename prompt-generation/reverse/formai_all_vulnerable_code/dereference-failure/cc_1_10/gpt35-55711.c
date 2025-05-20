//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
    JSON_OBJECT_START,
    JSON_OBJECT_END,
    JSON_ARRAY_START,
    JSON_ARRAY_END
} json_type;

typedef struct {
    json_type type;
    char *value;
} json_element;

int get_json_string_length(char *json, int start) {
    int length = 0;
    int i = start + 1;
    while (json[i] != '\"') {
        length++;
        i++;
    }
    return length;
}

char *get_json_string(char *json, int start) {
    int length = get_json_string_length(json, start);
    char *value = (char*) malloc(sizeof(char) * length + 1);
    int i = start + 1;
    int j = 0;
    while (json[i] != '\"') {
        value[j] = json[i];
        i++;
        j++;
    }
    value[length] = '\0';
    return value;
}

json_element *parse_json_element(char *json, int *i) {
    json_element *element = (json_element*) malloc(sizeof(json_element));
    switch (json[*i]) {
        case '\"':
            element->type = JSON_STRING;
            element->value = get_json_string(json, *i);
            *i = *i + get_json_string_length(json, *i) + 2;
            break;
        case 't':
            element->type = JSON_TRUE;
            element->value = "true";
            *i = *i + 4;
            break;
        case 'f':
            element->type = JSON_FALSE;
            element->value = "false";
            *i = *i + 5;
            break;
        case 'n':
            element->type = JSON_NULL;
            element->value = "null";
            *i = *i + 4;
            break;
        case '[':
            element->type = JSON_ARRAY_START;
            element->value = "[";
            *i = *i + 1;
            break;
        case ']':
            element->type = JSON_ARRAY_END;
            element->value = "]";
            *i = *i + 1;
            break;
        case '{':
            element->type = JSON_OBJECT_START;
            element->value = "{";
            *i = *i + 1;
            break;
        case '}':
            element->type = JSON_OBJECT_END;
            element->value = "}";
            *i = *i + 1;
            break;
        default:
            element->type = JSON_NUMBER;
            int length = 0;
            while (json[*i + length] != ',' && json[*i + length] != ']' 
                   && json[*i + length] != '}' && json[*i + length] != '\0') {
                length++;
            }
            element->value = (char*) malloc(sizeof(char) * length + 1);
            int j = 0;
            while (j < length) {
                element->value[j] = json[*i + j];
                j++;
            }
            element->value[length] = '\0';
            *i = *i + length;
    }
    return element;
}

json_element **parse_json(char *json, int *length) {
    json_element **elements = (json_element**) malloc(sizeof(json_element*));
    int i = 0;
    *length = 0;
    while (json[i] != '\0') {
        if (json[i] == ',' || json[i] == '{' || json[i] == '}'
            || json[i] == '[' || json[i] == ']') {
            *length = *length + 1;
            elements = (json_element**) realloc(elements, 
                    sizeof(json_element*) * (*length));
            elements[*length - 1] = parse_json_element(json, &i);
        }
        i++;
    }
    return elements;
}

int main() {
    char json[] = "{\"name\":\"John Smith\",\"age\":30,\"gender\":\"male\"}";

    int length;
    json_element **elements = parse_json(json, &length);

    for (int i = 0; i < length; i++) {
        printf("Element %d: type=%d, value=%s\n", i+1, elements[i]->type, 
                elements[i]->value);
    }

    return 0;
}