//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LENGTH 10000

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct json_value {
    json_type type;
    union {
        char *string_value;
        double number_value;
        struct json_object *object_value;
        struct json_array *array_value;
    } value;
} json_value;

typedef struct json_object {
    int size;
    int capacity;
    char **keys;
    json_value **values;
} json_object;

typedef struct json_array {
    int size;
    int capacity;
    json_value **values;
} json_array;

char *parse_string(char **json) {
    char *string = malloc(sizeof(char) * MAX_JSON_LENGTH);
    int i = 0;
    (*json)++; // skip initial double quote
    while (**json != '"') {
        if (**json == '\\') {
            (*json)++;
            switch (**json) {
                case 'b':
                    string[i++] = '\b';
                    break;
                case 'f':
                    string[i++] = '\f';
                    break;
                case 'n':
                    string[i++] = '\n';
                    break;
                case 'r':
                    string[i++] = '\r';
                    break;
                case 't':
                    string[i++] = '\t';
                    break;
                case '\\':
                case '/':
                case '\"':
                    string[i++] = **json;
                    break;
                default:
                    free(string);
                    return NULL;
            }
        } else {
            string[i++] = **json;
        }
        (*json)++;
    }
    (*json)++; // skip final double quote
    string[i] = '\0';
    return string;
}

double parse_number(char **json) {
    double number = 0.0;
    int sign = 1;
    if (**json == '-') {
        sign = -1;
        (*json)++;
    }
    while (isdigit(**json)) {
        number *= 10.0;
        number += **json - '0';
        (*json)++;
    }
    if (**json == '.') {
        double fraction = 0.0;
        double base = 0.1;
        (*json)++;
        while (isdigit(**json)) {
            fraction += (**json - '0') * base;
            base /= 10.0;
            (*json)++;
        }
        number += fraction;
    }
    if (**json == 'e' || **json == 'E') {
        int exponent = 0;
        int sign = 1;
        (*json)++;
        if (**json == '-' || **json == '+') {
            if (**json == '-') sign = -1;
            (*json)++;
        }
        while (isdigit(**json)) {
            exponent *= 10;
            exponent += **json - '0';
            (*json)++;
        }
        number *= pow(10, sign * exponent);
    }
    return sign == 1 ? number : -number;
}

json_object *parse_object(char **json);

json_value *parse_value(char **json) {
    json_value *value = malloc(sizeof(json_value));
    switch (**json) {
        case '"':
            value->type = JSON_STRING;
            value->value.string_value = parse_string(json);
            break;
        case '-':
        case '0'...'9':
            value->type = JSON_NUMBER;
            value->value.number_value = parse_number(json);
            break;
        case '{':
            value->type = JSON_OBJECT;
            value->value.object_value = parse_object(json);
            break;
        case '[': {
            value->type = JSON_ARRAY;
            json_array *array = malloc(sizeof(json_array));
            array->size = 0;
            array->capacity = 10;
            array->values = malloc(sizeof(json_value*) * array->capacity);
            (*json)++; // skip initial array bracket
            while (**json != ']') {
                if (array->size == array->capacity) {
                    array->capacity *= 2;
                    array->values = realloc(array->values, sizeof(json_value*) * array->capacity);
                }
                array->values[array->size++] = parse_value(json);
                while (isspace(**json)) (*json)++;
                if (**json == ',') (*json)++;
            }
            (*json)++; // skip final array bracket
            value->value.array_value = array;
            break;
        }
        case 't':
            value->type = JSON_TRUE;
            (*json) += 4; // skip "true"
            break;
        case 'f':
            value->type = JSON_FALSE;
            (*json) += 5; // skip "false"
            break;
        case 'n':
            value->type = JSON_NULL;
            (*json) += 4; // skip "null"
            break;
        default:
            free(value);
            return NULL;
    }
    return value;
}

json_object *parse_object(char **json) {
    json_object *object = malloc(sizeof(json_object));
    object->size = 0;
    object->capacity = 10;
    object->keys = malloc(sizeof(char*) * object->capacity);
    object->values = malloc(sizeof(json_value*) * object->capacity);
    (*json)++; // skip initial object bracket
    while (**json != '}') {
        if (object->size == object->capacity) {
            object->capacity *= 2;
            object->keys = realloc(object->keys, sizeof(char*) * object->capacity);
            object->values = realloc(object->values, sizeof(json_value*) * object->capacity);
        }
        while (isspace(**json)) (*json)++;
        object->keys[object->size] = parse_string(json);
        while (isspace(**json)) (*json)++;
        if (**json != ':') {
            free(object);
            return NULL;
        }
        (*json)++; // skip colon
        while (isspace(**json)) (*json)++;
        object->values[object->size] = parse_value(json);
        object->size++;
        while (isspace(**json)) (*json)++;
        if (**json == ',') {
            (*json)++;
        } else if (**json != '}') {
            free(object);
            return NULL;
        }
    }
    (*json)++; // skip final object bracket
    return object;
}

json_object *parse_json(char *json_string) {
    char *json = json_string;
    while (isspace(*json)) json++;
    return parse_object(&json);
}

void print_json(json_value *value) {
    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"", value->value.string_value);
            break;
        case JSON_NUMBER:
            printf("%g", value->value.number_value);
            break;
        case JSON_OBJECT:
            printf("{");
            for (int i = 0; i < value->value.object_value->size; i++) {
                if (i > 0) printf(",");
                printf("\"%s\":", value->value.object_value->keys[i]);
                print_json(value->value.object_value->values[i]);
            }
            printf("}");
            break;
        case JSON_ARRAY:
            printf("[");
            for (int i = 0; i < value->value.array_value->size; i++) {
                if (i > 0) printf(",");
                print_json(value->value.array_value->values[i]);
            }
            printf("]");
            break;
        case JSON_TRUE:
            printf("true");
            break;
        case JSON_FALSE:
            printf("false");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }
}

int main() {
    char json_string[] = "{\"name\":\"John Smith\",\"age\":30,\"city\":\"New York\",\"isMarried\":false,\"hobbies\":[\"reading\",\"swimming\",\"traveling\"]}";
    json_object *obj = parse_json(json_string);
    for (int i = 0; i < obj->size; i++) {
        printf("%s: ", obj->keys[i]);
        print_json(obj->values[i]);
        printf("\n");
    }
    return 0;
}