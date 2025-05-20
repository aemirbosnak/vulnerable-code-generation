//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct json_value {
    enum { JSON_NULL, JSON_BOOLEAN, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } type;
    union {
        int boolean;
        double number;
        char* string;
        struct json_object* object;
        struct json_array* array;
    } value;
} json_value;

typedef struct json_object {
    char* key;
    json_value* value;
    struct json_object* next;
} json_object;

typedef struct json_array {
    json_value* value;
    struct json_array* next;
} json_array;

json_value* parse_json(const char* json);
void free_json(json_value* value);
void print_json(json_value* value, int indent);

char* skip_whitespace(const char* json) {
    while (isspace(*json)) json++;
    return (char*)json;
}

json_value* parse_value(const char** json);

json_value* parse_object(const char** json) {
    json_value* obj = malloc(sizeof(json_value));
    obj->type = JSON_OBJECT;
    obj->value.object = NULL;

    (*json)++; // Skip '{'
    *json = skip_whitespace(*json);

    while (**json != '}') {
        if (**json == '"') {
            (*json)++; // Skip opening quote
            const char* start = *json;
            while (**json != '"' && **json) (*json)++; // Find closing quote
            size_t key_length = *json - start;
            char* key = strndup(start, key_length);
            (*json)++; // Skip closing quote
            *json = skip_whitespace(*json);
            (*json)++; // Skip ':'
            *json = skip_whitespace(*json);
            json_value* value = parse_value(json);

            json_object* entry = malloc(sizeof(json_object));
            entry->key = key;
            entry->value = value;
            entry->next = obj->value.object;
            obj->value.object = entry;

            *json = skip_whitespace(*json);
            if (**json == ',') {
                (*json)++; // Skip ',' to continue
            }
        }
    }
    (*json)++; // Skip '}'
    return obj;
}

json_value* parse_array(const char** json) {
    json_value* arr = malloc(sizeof(json_value));
    arr->type = JSON_ARRAY;
    arr->value.array = NULL;

    (*json)++; // Skip '['
    *json = skip_whitespace(*json);

    while (**json != ']') {
        json_value* value = parse_value(json);
        json_array* entry = malloc(sizeof(json_array));
        entry->value = value;
        entry->next = arr->value.array;
        arr->value.array = entry;

        *json = skip_whitespace(*json);
        if (**json == ',') {
            (*json)++; // Skip ',' to continue
        }
    }
    (*json)++; // Skip ']'
    return arr;
}

json_value* parse_string(const char** json) {
    (*json)++; // Skip opening quote
    const char* start = *json;

    while (**json != '"' && **json) (*json)++; // Find closing quote
    size_t str_length = *json - start;
    char* str_value = strndup(start, str_length);

    json_value* val = malloc(sizeof(json_value));
    val->type = JSON_STRING;
    val->value.string = str_value;

    (*json)++; // Skip closing quote
    return val;
}

json_value* parse_number(const char** json) {
    const char* start = *json;

    while (isdigit(**json) || **json == '.' || **json == '-') (*json)++;

    size_t number_length = *json - start;
    char* number_str = strndup(start, number_length);
    json_value* val = malloc(sizeof(json_value));
    val->type = JSON_NUMBER;
    val->value.number = atof(number_str);

    free(number_str);
    return val;
}

json_value* parse_boolean(const char** json) {
    json_value* val = malloc(sizeof(json_value));
    if (strncmp(*json, "true", 4) == 0) {
        val->type = JSON_BOOLEAN;
        val->value.boolean = 1;
        *json += 4; // Skip "true"
    } else {
        val->type = JSON_BOOLEAN;
        val->value.boolean = 0;
        *json += 5; // Skip "false"
    }
    return val;
}

json_value* parse_null(const char** json) {
    json_value* val = malloc(sizeof(json_value));
    val->type = JSON_NULL;
    *json += 4; // Skip "null"
    return val;
}

json_value* parse_value(const char** json) {
    *json = skip_whitespace(*json);
    if (**json == '{') {
        return parse_object(json);
    } else if (**json == '[') {
        return parse_array(json);
    } else if (**json == '"') {
        return parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    } else if (strncmp(*json, "true", 4) == 0 || strncmp(*json, "false", 5) == 0) {
        return parse_boolean(json);
    } else if (strncmp(*json, "null", 4) == 0) {
        return parse_null(json);
    }
    return NULL;
}

json_value* parse_json(const char* json) {
    const char* p = json;
    json_value* value = parse_value(&p);
    return value;
}

void free_json(json_value* value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_OBJECT: {
            json_object* obj = value->value.object;
            while (obj) {
                free(obj->key);
                free_json(obj->value);
                json_object* next = obj->next;
                free(obj);
                obj = next;
            }
            break;
        }
        case JSON_ARRAY: {
            json_array* arr = value->value.array;
            while (arr) {
                free_json(arr->value);
                json_array* next = arr->next;
                free(arr);
                arr = next;
            }
            break;
        }
        default:
            break;
    }
    free(value);
}

void print_json(json_value* value, int indent) {
    if (!value) return;
    for (int i = 0; i < indent; i++) printf("  ");
    switch (value->type) {
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_BOOLEAN:
            printf(value->value.boolean ? "true\n" : "false\n");
            break;
        case JSON_NUMBER:
            printf("%f\n", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"\n", value->value.string);
            break;
        case JSON_OBJECT: {
            printf("{\n");
            json_object* obj = value->value.object;
            while (obj) {
                printf("\"%s\": ", obj->key);
                print_json(obj->value, indent + 1);
                obj = obj->next;
                if (obj) for (int i = 0; i < indent; i++) printf("  ");
            }
            printf("}\n");
            break;
        }
        case JSON_ARRAY: {
            printf("[\n");
            json_array* arr = value->value.array;
            while (arr) {
                print_json(arr->value, indent + 1);
                arr = arr->next;
                if (arr) for (int i = 0; i < indent; i++) printf("  ");
            }
            printf("]\n");
            break;
        }
    }
}

int main() {
    const char* json_example = "{\"name\":\"John\", \"age\":30, \"is_student\":false, \"courses\":[\"Math\", \"Science\"], \"address\":null}";
    json_value* parsed_json = parse_json(json_example);
    printf("Parsed JSON:\n");
    print_json(parsed_json, 0);
    free_json(parsed_json);
    return 0;
}