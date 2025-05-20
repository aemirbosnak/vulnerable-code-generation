//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 50
#define MAX_JSON_LENGTH 1024

typedef enum {
    JSON_NULL, 
    JSON_OBJECT, 
    JSON_ARRAY, 
    JSON_STRING, 
    JSON_NUMBER, 
    JSON_BOOLEAN
} json_type;

typedef struct json_value {
    json_type type;
    union {
        void* data;
        char* string_value;
        double number_value;
        int boolean_value;
        struct json_object* object_value;
        struct json_array* array_value;
    } value;
} json_value;

typedef struct json_object {
    char* key;
    json_value* value;
    struct json_object* next;
} json_object;

typedef struct json_array {
    json_value** values;
    int length;
} json_array;

typedef struct json_parser {
    char* json_string;
    int index;
    int length;
} json_parser;

json_object* parse_object(json_parser* parser);
json_array* parse_array(json_parser* parser);
char* parse_string(json_parser* parser);
double parse_number(json_parser* parser);
int parse_boolean(json_parser* parser);
void parse_whitespace(json_parser* parser);
char parse_char(json_parser* parser);
json_value* parse_value(json_parser* parser);

json_object* parse_object(json_parser* parser) {
    char c = parse_char(parser);
    json_object* root = NULL;
    json_object* current = NULL;

    if (c == '{') {
        c = parse_char(parser);
    } else {
        printf("Error: Expected '{' in parse_object, got %c\n", c);
        exit(1);
    }

    while (1) {
        parse_whitespace(parser);
        char* key = parse_string(parser);
        parse_whitespace(parser);
        if (parse_char(parser) != ':') {
            printf("Error: Expected ':' in parse_object\n");
            exit(1);
        }
        parse_whitespace(parser);

        json_value* value = parse_value(parser);
        json_object* object = malloc(sizeof(json_object));
        object->key = key;
        object->value = value;
        object->next = NULL;

        if (current == NULL) {
            root = object;
            current = object;
        } else {
            current->next = object;
            current = current->next;
        }

        if (parse_char(parser) == '}') {
            break;
        }
    }

    return root;
}

json_array* parse_array(json_parser* parser) {
    char c = parse_char(parser);
    json_array* array = malloc(sizeof(json_array));
    array->values = malloc(sizeof(json_value*));
    array->length = 0;

    if (c == '[') {
        c = parse_char(parser);
    } else {
        printf("Error: Expected '[' in parse_array, got %c\n", c);
        exit(1);
    }

    while (1) {
        parse_whitespace(parser);
        json_value* value = parse_value(parser);
        array->values = realloc(array->values, sizeof(json_value*) * (array->length + 1));
        array->values[array->length] = value;
        array->length++;

        if (parse_char(parser) == ']') {
            break;
        }
    }

    return array;
}

char* parse_string(json_parser* parser) {
    char c = parse_char(parser);
    char* str = malloc(sizeof(char) * MAX_KEY_LENGTH);
    int i = 0;

    if (c == '\"') {
        c = parse_char(parser);
        while (c != '\"' && i < MAX_KEY_LENGTH - 1) {
            str[i] = c;
            i++;
            c = parse_char(parser);
        }
        str[i] = '\0';
    } else {
        printf("Error: Expected '\"' in parse_string\n");
        exit(1);
    }

    return str;
}

double parse_number(json_parser* parser) {
    char* num_str = malloc(sizeof(char) * MAX_VALUE_LENGTH);
    int i = 0;

    while (isdigit(parser->json_string[parser->index]) || parser->json_string[parser->index] == '.') {
        num_str[i] = parser->json_string[parser->index];
        i++;
        parser->index++;
    }
    num_str[i] = '\0';

    double number = atof(num_str);
    free(num_str);

    return number;
}

int parse_boolean(json_parser* parser) {
    if (parser->json_string[parser->index] == 't') {
        parser->index += 4;
        return 1;
    } else if (parser->json_string[parser->index] == 'f') {
        parser->index += 5;
        return 0;
    } else {
        printf("Error: Expected 't' or 'f' in parse_boolean\n");
        exit(1);
    }
}

void parse_whitespace(json_parser* parser) {
    while (isspace(parser->json_string[parser->index])) {
        parser->index++;
    }
}

char parse_char(json_parser* parser) {
    parse_whitespace(parser);
    char c = parser->json_string[parser->index];
    parser->index++;
    return c;
}

json_value* parse_value(json_parser* parser) {
    json_value* value = malloc(sizeof(json_value));

    switch (parser->json_string[parser->index]) {
        case '{':
            parser->index++;
            parse_whitespace(parser);
            value->type = JSON_OBJECT;
            value->value.object_value = parse_object(parser);
            break;
        case '[':
            parser->index++;
            parse_whitespace(parser);
            value->type = JSON_ARRAY;
            value->value.array_value = parse_array(parser);
            break;
        case '\"':
            parser->index++;
            value->type = JSON_STRING;
            value->value.string_value = parse_string(parser);
            break;
        case '-':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            value->type = JSON_NUMBER;
            value->value.number_value = parse_number(parser);
            break;
        case 't':
        case 'f':
            value->type = JSON_BOOLEAN;
            value->value.boolean_value = parse_boolean(parser);
            break;
        case 'n':
            parser->index += 4;
            value->type = JSON_NULL;
            value->value.data = NULL;
            break;
        default:
            printf("Error: Invalid JSON value type\n");
            exit(1);
    }

    return value;
}

int main() {
    char* json_str = "{\"name\": \"John Doe\", \"age\": 25, \"is_student\": true, \"favorite_foods\": [\"pizza\", \"sushi\"], \"address\": {\"street\": \"123 Main St\", \"city\": \"Anytown\", \"state\": \"NY\"}}";
    printf("JSON String: %s\n", json_str);

    json_parser* parser = malloc(sizeof(json_parser));
    parser->json_string = json_str;
    parser->index = 0;
    parser->length = strlen(json_str);

    json_value* root = parse_value(parser);
    if (root->type != JSON_OBJECT) {
        printf("Error: Root JSON value must be an object\n");
        exit(1);
    }

    json_object* obj = (json_object*) root->value.object_value;
    while (obj != NULL) {
        printf("%s: ", obj->key);

        switch (obj->value->type) {
            case JSON_STRING:
                printf("%s\n", obj->value->value.string_value);
                break;
            case JSON_NUMBER:
                printf("%f\n", obj->value->value.number_value);
                break;
            case JSON_BOOLEAN:
                printf("%s\n", obj->value->value.boolean_value ? "true" : "false");
                break;
            case JSON_ARRAY:
                printf("[");
                for (int i = 0; i < obj->value->value.array_value->length; i++) {
                    json_value* val = obj->value->value.array_value->values[i];
                    switch (val->type) {
                        case JSON_STRING:
                            printf("%s", val->value.string_value);
                            break;
                        case JSON_NUMBER:
                            printf("%f", val->value.number_value);
                            break;
                        case JSON_BOOLEAN:
                            printf("%s", val->value.boolean_value ? "true" : "false");
                            break;
                        default:
                            printf("null");
                            break;
                    }
                    if (i < obj->value->value.array_value->length - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;
            case JSON_OBJECT:
                printf("{\n");
                json_object* nested_obj = (json_object*) obj->value->value.object_value;
                while (nested_obj != NULL) {
                    printf("\t%s: ", nested_obj->key);

                    switch (nested_obj->value->type) {
                        case JSON_STRING:
                            printf("%s\n", nested_obj->value->value.string_value);
                            break;
                        case JSON_NUMBER:
                            printf("%f\n", nested_obj->value->value.number_value);
                            break;
                        case JSON_BOOLEAN:
                            printf("%s\n", nested_obj->value->value.boolean_value ? "true" : "false");
                            break;
                        default:
                            printf("null\n");
                            break;
                    }

                    nested_obj = nested_obj->next;
                }
                printf("}\n");
                break;
            default:
                printf("null\n");
                break;
        }

        obj = obj->next;
    }

    return 0;
}