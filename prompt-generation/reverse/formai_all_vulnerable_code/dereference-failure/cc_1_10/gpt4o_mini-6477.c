//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} json_type;

typedef struct JsonValue {
    json_type type;
    union {
        char *string_value;  // For JSON STRING
        double number_value; // For JSON NUMBER
        struct JsonObject *object_value; // For JSON OBJECT
        struct JsonArray *array_value;   // For JSON ARRAY
    };
} JsonValue;

typedef struct JsonPair {
    char *key;
    JsonValue value;
} JsonPair;

typedef struct JsonObject {
    JsonPair *pairs;
    size_t size;
} JsonObject;

typedef struct JsonArray {
    JsonValue *values;
    size_t size;
} JsonArray;

void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

JsonValue parse_value(const char **json);

JsonValue parse_string(const char **json) {
    JsonValue value;
    value.type = JSON_STRING;
    const char *start = ++(*json);

    while (**json != '"') {
        if (**json == '\0') {
            fprintf(stderr, "Unexpected end of string\n");
            exit(EXIT_FAILURE);
        }
        (*json)++;
    }

    size_t length = *json - start;
    value.string_value = malloc(length + 1);
    strncpy(value.string_value, start, length);
    value.string_value[length] = '\0';
    (*json)++; // skip the closing quote

    return value;
}

JsonValue parse_number(const char **json) {
    JsonValue value;
    value.type = JSON_NUMBER;
    char *end_ptr;
    value.number_value = strtod(*json, &end_ptr);
    *json = end_ptr; // advance the pointer
    return value;
}

JsonValue parse_literal(const char **json) {
    JsonValue value;
    if (strncmp(*json, "null", 4) == 0) {
        value.type = JSON_NULL;
        *json += 4;
    } else if (strncmp(*json, "true", 4) == 0) {
        value.type = JSON_TRUE;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value.type = JSON_FALSE;
        *json += 5;
    } else {
        fprintf(stderr, "Unexpected literal\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

JsonValue parse_array(const char **json) {
    JsonValue value;
    value.type = JSON_ARRAY;
    JsonArray *array = malloc(sizeof(JsonArray));
    array->size = 0;
    array->values = malloc(10 * sizeof(JsonValue)); // starting capacity

    (*json)++; // skip '['
    skip_whitespace(json);

    while (**json != ']') {
        if (array->size >= 10) {
            array->values = realloc(array->values, (array->size + 10) * sizeof(JsonValue));
        }
        array->values[array->size++] = parse_value(json);
        skip_whitespace(json);
        if (**json == ',') (*json)++;
        skip_whitespace(json);
    }

    (*json)++; // skip ']'
    value.array_value = array;
    return value;
}

JsonPair parse_pair(const char **json) {
    JsonPair pair;

    pair.key = parse_string(json).string_value; // allocate memory for key
    skip_whitespace(json);

    if (**json != ':') {
        fprintf(stderr, "Expected ':' after key\n");
        exit(EXIT_FAILURE);
    }
    (*json)++; // skip ':'
    skip_whitespace(json);
    pair.value = parse_value(json);
    return pair;
}

JsonObject parse_object(const char **json) {
    JsonObject object;
    object.size = 0;
    object.pairs = malloc(10 * sizeof(JsonPair)); // starting capacity

    (*json)++; // skip '{'
    skip_whitespace(json);

    while (**json != '}') {
        if (object.size >= 10) {
            object.pairs = realloc(object.pairs, (object.size + 10) * sizeof(JsonPair));
        }
        object.pairs[object.size++] = parse_pair(json);
        skip_whitespace(json);
        if (**json == ',') (*json)++;
        skip_whitespace(json);
    }

    (*json)++; // skip '}'
    return object;
}

JsonValue parse_value(const char **json) {
    JsonValue value;
    skip_whitespace(json);
    
    if (**json == '"') {
        return parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    } else if (strncmp(*json, "null", 4) == 0 || 
               strncmp(*json, "true", 4) == 0 || 
               strncmp(*json, "false", 5) == 0) {
        return parse_literal(json);
    } else if (**json == '[') {
        return parse_array(json);
    } else if (**json == '{') {
        JsonObject obj = parse_object(json);
        value.object_value = malloc(sizeof(JsonObject));
        *value.object_value = obj;
        value.type = JSON_OBJECT;
        return value;
    }

    fprintf(stderr, "Invalid JSON value\n");
    exit(EXIT_FAILURE);
}

void cleanup(JsonValue value) {
    switch(value.type) {
        case JSON_STRING:
            free(value.string_value);
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < value.object_value->size; i++) {
                free(value.object_value->pairs[i].key);
                cleanup(value.object_value->pairs[i].value);
            }
            free(value.object_value->pairs);
            free(value.object_value);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < value.array_value->size; i++) {
                cleanup(value.array_value->values[i]);
            }
            free(value.array_value->values);
            free(value.array_value);
            break;
        default:
            break;
    }
}

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": 30, \"is_student\": false, \"courses\": [\"Math\", \"Science\"]}";
    const char *json_ptr = json_string;

    JsonValue json_value = parse_value(&json_ptr);
    printf("Parsing completed successfully!\n");

    cleanup(json_value);
    return 0;
}