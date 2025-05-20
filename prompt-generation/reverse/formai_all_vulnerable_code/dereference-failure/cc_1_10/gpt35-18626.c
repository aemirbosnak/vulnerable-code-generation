//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024

typedef enum {
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_BOOL,
    JSON_TYPE_NULL,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY
} json_type;

typedef struct json_value {
    json_type type;
    union {
        char* string_value;
        double number_value;
        int bool_value;
        struct json_object* object_value;
        struct json_array* array_value;
    } value;
    struct json_value* next;
} json_value;

typedef struct json_object {
    char* key;
    struct json_value* value;
    struct json_object* next;
} json_object;

typedef struct json_array {
    struct json_value* value;
    struct json_array* next;
} json_array;

char* json_string;
int json_position;

void json_skip_whitespace() {
    while (json_string[json_position] == ' ' || json_string[json_position] == '\n' ||
            json_string[json_position] == '\r' || json_string[json_position] == '\t') {
        json_position++;
    }
}

char json_peek() {
    json_skip_whitespace();
    return json_string[json_position];
}

void json_parse_error(char* error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(EXIT_FAILURE);
}

json_value* json_parse_value();

json_object* json_parse_object() {
    json_object* obj = malloc(sizeof(json_object));
    obj->key = NULL;
    obj->value = NULL;
    obj->next = NULL;

    if (json_peek() != '{') {
        json_parse_error("JSON object must start with '{'");
    }
    json_position++;

    json_skip_whitespace();

    if (json_peek() == '}') {
        json_position++;
        return obj;  // empty object
    }

    json_value* cur_value;
    json_value* prev_value = NULL;
    while (1) {
        if (json_peek() != '"') {
            json_parse_error("JSON key must be a string surrounded by double quotes");
        }
        json_position++;

        char* key_str = malloc(MAX_JSON_LENGTH * sizeof(char));
        int i = 0;
        while (json_string[json_position] != '"' && i < MAX_JSON_LENGTH - 1) {
            key_str[i++] = json_string[json_position++];
        }
        key_str[i] = '\0';
        json_position++;  // skip the closing quote

        json_skip_whitespace();

        if (json_peek() != ':') {
            json_parse_error("JSON object key-value pair must be separated by a colon");
        }
        json_position++;

        json_skip_whitespace();

        cur_value = json_parse_value();
        cur_value->next = NULL;

        if (obj->key == NULL) {
            obj->key = key_str;
            obj->value = cur_value;
        }
        else {
            json_object* cur_obj = obj;
            while (cur_obj->next != NULL) {
                cur_obj = cur_obj->next;
            }

            cur_obj->next = malloc(sizeof(json_object));
            cur_obj = cur_obj->next;
            cur_obj->key = key_str;
            cur_obj->value = cur_value;
            cur_obj->next = NULL;
        }

        json_skip_whitespace();

        if (json_peek() == ',') {
            json_position++;
            continue;
        }
        else if (json_peek() == '}') {
            json_position++;
            break;
        }
        else {
            json_parse_error("JSON object must contain key-value pairs separated by commas and end with a closing brace");
        }
    }

    return obj;
}

json_array* json_parse_array() {
    json_array* arr = malloc(sizeof(json_array));
    arr->value = NULL;
    arr->next = NULL;

    if (json_peek() != '[') {
        json_parse_error("JSON array must start with '['");
    }
    json_position++;

    json_skip_whitespace();

    if (json_peek() == ']') {
        json_position++;
        return arr;  // empty array
    }

    json_value* cur_value;
    json_value* prev_value = NULL;
    while (1) {
        cur_value = json_parse_value();
        cur_value->next = NULL;

        if (arr->value == NULL) {
            arr->value = cur_value;
        }
        else {
            json_array* cur_arr = arr;
            while (cur_arr->next != NULL) {
                cur_arr = cur_arr->next;
            }

            cur_arr->next = malloc(sizeof(json_array));
            cur_arr = cur_arr->next;
            cur_arr->value = cur_value;
            cur_arr->next = NULL;
        }

        json_skip_whitespace();

        if (json_peek() == ',') {
            json_position++;
            continue;
        }
        else if (json_peek() == ']') {
            json_position++;
            break;
        }
        else {
            json_parse_error("JSON array must contain values separated by commas and end with a closing bracket");
        }
    }

    return arr;
}

json_value* json_parse_value() {
    json_value* value = malloc(sizeof(json_value));
    if (json_peek() == '"') {
        json_position++;
        char* str = malloc(MAX_JSON_LENGTH * sizeof(char));
        int i = 0;
        while (json_string[json_position] != '"' && i < MAX_JSON_LENGTH - 1) {
            str[i++] = json_string[json_position++];
        }
        str[i] = '\0';
        json_position++;  // skip the closing quote

        value->type = JSON_TYPE_STRING;
        value->value.string_value = str;
    }
    else if (json_peek() == '-' || (json_peek() >= '0' && json_peek() <= '9')) {
        char* end_ptr;
        double num = strtod(&json_string[json_position], &end_ptr);

        if (&json_string[json_position] == end_ptr) {
            json_parse_error("JSON number is malformed");
        }

        json_position += end_ptr - &json_string[json_position];

        value->type = JSON_TYPE_NUMBER;
        value->value.number_value = num;
    }
    else if (json_peek() == 't' || json_peek() == 'f') {
        if (json_string[json_position] == 't') {
            value->type = JSON_TYPE_BOOL;
            value->value.bool_value = 1;
            json_position += 4;
        }
        else {
            value->type = JSON_TYPE_BOOL;
            value->value.bool_value = 0;
            json_position += 5;
        }
    }
    else if (json_peek() == 'n') {
        value->type = JSON_TYPE_NULL;
        json_position += 4;
    }
    else if (json_peek() == '{') {
        value->type = JSON_TYPE_OBJECT;
        value->value.object_value = json_parse_object();
    }
    else if (json_peek() == '[') {
        value->type = JSON_TYPE_ARRAY;
        value->value.array_value = json_parse_array();
    }
    else {
        json_parse_error("Unrecognized JSON type");
    }

    return value;
}

json_value* json_parse(char* input) {
    json_string = input;
    json_position = 0;

    json_value* value = json_parse_value();

    json_skip_whitespace();
    if (json_position != strlen(json_string)) {
        json_parse_error("JSON has extraneous characters after end of root element");
    }

    return value;
}

void json_print_value(json_value* value) {
    switch (value->type) {
        case JSON_TYPE_STRING:
            printf("\"%s\"", value->value.string_value);
            break;
        case JSON_TYPE_NUMBER:
            printf("%f", value->value.number_value);
            break;
        case JSON_TYPE_BOOL:
            if (value->value.bool_value) {
                printf("true");
            }
            else {
                printf("false");
            }
            break;
        case JSON_TYPE_NULL:
            printf("null");
            break;
        case JSON_TYPE_OBJECT:
            printf("{");
            json_object* cur_obj = value->value.object_value;
            while (cur_obj != NULL) {
                printf("\"%s\": ", cur_obj->key);
                json_print_value(cur_obj->value);
                if (cur_obj->next != NULL) {
                    printf(", ");
                }
                cur_obj = cur_obj->next;
            }
            printf("}");
            break;
        case JSON_TYPE_ARRAY:
            printf("[");
            json_array* cur_arr = value->value.array_value;
            while (cur_arr != NULL) {
                json_print_value(cur_arr->value);
                if (cur_arr->next != NULL) {
                    printf(", ");
                }
                cur_arr = cur_arr->next;
            }
            printf("]");
            break;
    }
}

int main() {
    char* input = "{\"name\": \"John Smith\", \"age\": 30, \"friends\": [\"Alice\", \"Bob\", \"Charlie\"]}";
    json_value* value = json_parse(input);
    json_print_value(value);

    return 0;
}