//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_STRING,
    JSON_NUMBER,
    JSON_ARRAY,
    JSON_OBJECT
} json_type;

typedef struct json_value {
    json_type type;
    union {
        bool boolean;
        char* string;
        double number;
        struct json_value* array;
        struct json_object* object;
        void* null;
    } value;
    struct json_value* next;
} json_value;

typedef struct json_object {
    char* key;
    struct json_value* value;
    struct json_object* next;
} json_object;

json_value* parse_value(char** buffer);

json_value* parse_string(char** buffer) {
    (*buffer)++; //skip opening quote
    char* start = *buffer;
    char* end = NULL;
    bool escaped = false;
    while (**buffer != '\0') {
        if (**buffer == '"' && !escaped)
            break;
        if (**buffer == '\\' && !escaped)
            escaped = true;
        else
            escaped = false;
        (*buffer)++;
    }
    end = *buffer;
    (*buffer)++; //skip closing quote
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->next = NULL;
    value->value.string = malloc(end - start);
    strncpy(value->value.string, start, end - start);
    value->value.string[end - start] = '\0';
    return value;
}

json_value* parse_number(char** buffer) {
    char* end;
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_NUMBER;
    value->next = NULL;
    value->value.number = strtod(*buffer, &end);
    *buffer = end;
    return value;
}

json_value* parse_array(char** buffer) {
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_ARRAY;
    value->next = NULL;
    json_value* current = value;
    (*buffer)++; //skip opening bracket
    while (**buffer != ']') {
        if (**buffer == '\0') {
            printf("Error: unexpected end of input, expected closing bracket\n");
            exit(1);
        }
        json_value* next = parse_value(buffer);
        current->next = next;
        current = current->next;
        if (**buffer == ',')
            (*buffer)++;
    }
    (*buffer)++; //skip closing bracket
    return value;
}

json_value* parse_object(char** buffer) {
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_OBJECT;
    value->next = NULL;
    json_object* current = NULL;
    (*buffer)++; //skip opening brace
    while (**buffer != '}') {
        if (**buffer == '\0') {
            printf("Error: unexpected end of input, expected closing brace\n");
            exit(1);
        }
        json_value* key = parse_string(buffer);
        if (**buffer != ':') {
            printf("Error: expected colon after key in object\n");
            exit(1);
        }
        (*buffer)++; //skip colon
        json_value* val = parse_value(buffer);

        if (current == NULL) {
            current = malloc(sizeof(json_object));
            current->key = key->value.string;
            current->value = val;
            current->next = NULL;
            value->value.object = current;
        } else {
            json_object* next = malloc(sizeof(json_object));
            next->key = key->value.string;
            next->value = val;
            next->next = NULL;
            current->next = next;
            current = next;
        }
        if (**buffer == ',')
            (*buffer)++;
    }
    (*buffer)++; //skip closing brace
    return value;
}

json_value* parse_value(char** buffer) {
    while (**buffer == ' ' || **buffer == '\t' || **buffer == '\n')
        (*buffer)++;
    if (**buffer == '\0')
        return NULL;
    if (**buffer == '"')
        return parse_string(buffer);
    if (**buffer == '-' || (**buffer >= '0' && **buffer <= '9'))
        return parse_number(buffer);
    if (**buffer == '[')
        return parse_array(buffer);
    if (**buffer == '{')
        return parse_object(buffer);
    if (strncmp(*buffer, "true", 4) == 0) {
        (*buffer) += 4;
        json_value* value = malloc(sizeof(json_value));
        value->type = JSON_BOOL;
        value->next = NULL;
        value->value.boolean = true;
        return value;
    }
    if (strncmp(*buffer, "false", 5) == 0) {
        (*buffer) += 5;
        json_value* value = malloc(sizeof(json_value));
        value->type = JSON_BOOL;
        value->next = NULL;
        value->value.boolean = false;
        return value;
    }
    if (strncmp(*buffer, "null", 4) == 0) {
        (*buffer) += 4;
        json_value* value = malloc(sizeof(json_value));
        value->type = JSON_NULL;
        value->next = NULL;
        value->value.null = NULL;
        return value;
    }
    printf("Error: unexpected character '%c' encountered\n", **buffer);
    exit(1);
}

int main() {
    char* buffer = "{"
                   "   \"name\": \"John Smith\","
                   "   \"age\": 32,"
                   "   \"married\": true,"
                   "   \"address\": {"
                   "        \"street\": \"123 Main St\","
                   "        \"city\": \"Anytown\","
                   "        \"state\": \"CA\""
                   "    },"
                   "   \"children\": ["
                   "        \"Sally\","
                   "        \"Bob\""
                   "    ]"
                   "}";
    json_value* value = parse_value(&buffer);
    printf("Parsed JSON:\n");
    while (value) {
        switch (value->type) {
            case JSON_NULL:
                printf("null");
                break;
            case JSON_BOOL:
                printf("%s", value->value.boolean ? "true" : "false");
                break;
            case JSON_STRING:
                printf("\"%s\"", value->value.string);
                break;
            case JSON_NUMBER:
                printf("%lf", value->value.number);
                break;
            case JSON_ARRAY:
                printf("[ ");
                for (json_value* iter = value->value.array; iter != NULL; iter = iter->next)
                    printf("%s ", iter->value.string);
                printf("]");
                break;
            case JSON_OBJECT:
                printf("{ ");
                for (json_object* iter = value->value.object; iter != NULL; iter = iter->next)
                    printf("%s: %s ", iter->key, iter->value->value.string);
                printf("}");
                break;
        }
        printf("\n");
        value = value->next;
    }
    return 0;
}