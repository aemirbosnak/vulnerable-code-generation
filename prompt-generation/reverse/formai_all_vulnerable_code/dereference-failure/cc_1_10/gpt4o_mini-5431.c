//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024
#define MAX_TOKEN_LENGTH 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
    JSON_INVALID
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        char *string;
        double number;
        struct JsonValue *array;
        struct JsonValue *object;
    } value;
    struct JsonValue *next;
} JsonValue;

void free_json(JsonValue *json) {
    if (!json) return;
    
    if (json->type == JSON_STRING) {
        free(json->value.string);
    } else if (json->type == JSON_ARRAY || json->type == JSON_OBJECT) {
        JsonValue *child = json->value.array;
        while (child) {
            JsonValue *tmp = child;
            child = child->next;
            free_json(tmp);
        }
    }
    
    free(json);
}

JsonValue* create_json_value(JsonType type) {
    JsonValue *value = (JsonValue*)malloc(sizeof(JsonValue));
    value->type = type;
    value->next = NULL;
    return value;
}

void parse_string(const char **input, JsonValue *json_value) {
    const char *start = *input + 1; // skip initial '"'
    const char *end = strchr(start, '"');
    
    if (end) {
        json_value->type = JSON_STRING;
        json_value->value.string = strndup(start, end - start);
        *input = end + 1; // move past closing '"'
    } else {
        json_value->type = JSON_INVALID;
    }
}

void parse_number(const char **input, JsonValue *json_value) {
    char *end;
    json_value->type = JSON_NUMBER;
    json_value->value.number = strtod(*input, &end);
    *input = end;
}

void parse_json_value(const char **input, JsonValue *json_value);

// Function to parse JSON objects
void parse_object(const char **input, JsonValue *json_value) {
    json_value->type = JSON_OBJECT;
    json_value->value.object = NULL;
    JsonValue *last_child = NULL;

    (*input)++; // skip '{'
    while (**input != '}') {
        if (**input == ',') (*input)++; // skip comma
        JsonValue *key = create_json_value(JSON_STRING);
        parse_string(input, key);
        
        if (key->type == JSON_INVALID) {
            free_json(key);
            break;
        }
        
        JsonValue *colon = create_json_value(JSON_INVALID);
        if (**input == ':') {
            (*input)++;
            JsonValue *value = create_json_value(JSON_INVALID);
            parse_json_value(input, value);
            if (last_child) {
                last_child->next = value;
            } else {
                json_value->value.object = value;
            }
            last_child = value;
            value->next = NULL;
        } else {
            free_json(key);
            break;
        }
    }
    (*input)++; // skip '}'
}

void parse_array(const char **input, JsonValue *json_value) {
    json_value->type = JSON_ARRAY;
    json_value->value.array = NULL;
    JsonValue *last_child = NULL;

    (*input)++; // skip '['
    while (**input != ']') {
        if (**input == ',') (*input)++; // skip comma
        JsonValue *value = create_json_value(JSON_INVALID);
        parse_json_value(input, value);
        if (last_child) {
            last_child->next = value;
        } else {
            json_value->value.array = value;
        }
        last_child = value;
        value->next = NULL;
    }
    (*input)++; // skip ']'
}

void parse_json_value(const char **input, JsonValue *json_value) {
    switch (**input) {
        case '{':
            parse_object(input, json_value);
            break;
        case '[':
            parse_array(input, json_value);
            break;
        case '"':
            parse_string(input, json_value);
            break;
        case 't':
            if (strncmp(*input, "true", 4) == 0) {
                json_value->type = JSON_TRUE;
                *input += 4;
            }
            break;
        case 'f':
            if (strncmp(*input, "false", 5) == 0) {
                json_value->type = JSON_FALSE;
                *input += 5;
            }
            break;
        case 'n':
            if (strncmp(*input, "null", 4) == 0) {
                json_value->type = JSON_NULL;
                *input += 4;
            }
            break;
        default:
            if ((**input >= '0' && **input <= '9') || **input == '-') {
                parse_number(input, json_value);
            } else {
                json_value->type = JSON_INVALID;
            }
    }
}

JsonValue* parse_json(const char *input) {
    JsonValue *json_value = create_json_value(JSON_INVALID);
    parse_json_value(&input, json_value);
    return json_value;
}

void print_json_value(JsonValue *json_value) {
    if (!json_value) return;

    switch (json_value->type) {
        case JSON_OBJECT:
            printf("{");
            for (JsonValue *child = json_value->value.object; child; child = child->next) {
                print_json_value(child);
                if (child->next) printf(",");
            }
            printf("}");
            break;
        case JSON_ARRAY:
            printf("[");
            for (JsonValue *child = json_value->value.array; child; child = child->next) {
                print_json_value(child);
                if (child->next) printf(",");
            }
            printf("]");
            break;
        case JSON_STRING:
            printf("\"%s\"", json_value->value.string);
            break;
        case JSON_NUMBER:
            printf("%lf", json_value->value.number);
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
        case JSON_INVALID:
            printf("invalid");
            break;
    }
}

int main() {
    const char *json_input = "{ \"name\": \"John\", \"age\": 30, \"is_student\": false, \"friends\": [\"Jane\", \"Doe\"] }";
    JsonValue *parsed_json = parse_json(json_input);

    printf("Parsed JSON:\n");
    print_json_value(parsed_json);
    printf("\n");

    free_json(parsed_json);

    return 0;
}