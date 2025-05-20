//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    enum { JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } type;
    union {
        int boolean;
        double number;
        char *string;
        struct JsonValue *array; // pointer to first element of array
        struct {
            char **keys;
            struct JsonValue *values;
            size_t size;
        } object;
    } value;
} JsonValue;

JsonValue *parse_json(const char *json);
void free_json(JsonValue *value);
void print_json(const JsonValue *value, int indent);

static const char *current_pos;

// Function to read whitespace
void skip_whitespace() {
    while (isspace(*current_pos)) {
        current_pos++;
    }
}

// Function to parse a null value
JsonValue *parse_null() {
    if (strncmp(current_pos, "null", 4) != 0) {
        return NULL;
    }
    current_pos += 4;

    JsonValue *val = malloc(sizeof(JsonValue));
    val->type = JSON_NULL;
    return val;
}

// Function to parse a boolean value
JsonValue *parse_bool() {
    JsonValue *val = malloc(sizeof(JsonValue));
    
    if (strncmp(current_pos, "true", 4) == 0) {
        current_pos += 4;
        val->type = JSON_BOOL;
        val->value.boolean = 1;
    } else if (strncmp(current_pos, "false", 5) == 0) {
        current_pos += 5;
        val->type = JSON_BOOL;
        val->value.boolean = 0;
    } else {
        free(val);
        return NULL;
    }
    return val;
}

// Function to parse a number
JsonValue *parse_number() {
    char *end;
    JsonValue *val = malloc(sizeof(JsonValue));
    
    val->value.number = strtod(current_pos, &end);
    if (current_pos == end) {
        free(val);
        return NULL;
    }
    
    val->type = JSON_NUMBER;
    current_pos = end;
    return val;
}

// Function to parse a string
JsonValue *parse_string() {
    JsonValue *val = malloc(sizeof(JsonValue));
    if (*current_pos != '\"') {
        free(val);
        return NULL;
    }
    current_pos++;
    const char *start = current_pos;
    
    while (*current_pos && *current_pos != '\"') {
        if (*current_pos == '\\') {
            current_pos++; // skipping escape character
        }
        current_pos++;
    }
    
    if (*current_pos != '\"') {
        free(val);
        return NULL;
    }

    size_t length = current_pos - start;
    val->value.string = malloc(length + 1);
    strncpy(val->value.string, start, length);
    val->value.string[length] = '\0';
    
    val->type = JSON_STRING;
    current_pos++;
    return val;
}

// Function to parse an array
JsonValue *parse_array() {
    if (*current_pos != '[') {
        return NULL;
    }
    current_pos++;

    JsonValue *array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->value.array = NULL; // Placeholder till we fill it later

    size_t count = 0;
    JsonValue **values = NULL;

    skip_whitespace();
    
    while (*current_pos != ']') {
        JsonValue *value = parse_json(current_pos);
        if (!value) {
            free(array);
            return NULL;
        }

        values = realloc(values, sizeof(JsonValue *) * (count + 1));
        values[count++] = value;

        skip_whitespace();
        if (*current_pos == ',') {
            current_pos++;
        } else if (*current_pos == ']') {
            break;
        } else {
            free(array);
            return NULL;
        }

        skip_whitespace();
    }

    current_pos++; // Skip past ']'

    array->value.array = values;
    return array;
}

// Function to parse an object
JsonValue *parse_object() {
    if (*current_pos != '{') {
        return NULL;
    }
    current_pos++;
    
    JsonValue *object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->value.object.size = 0;
    object->value.object.keys = NULL;
    object->value.object.values = NULL;

    size_t count = 0;

    skip_whitespace();

    while (*current_pos != '}') {
        if (*current_pos != '\"') {
            free(object);
            return NULL;
        }

        JsonValue *key = parse_string();
        if (!key) {
            free(object);
            return NULL;
        }

        skip_whitespace();
        if (*current_pos != ':') {
            free(key->value.string);
            free(key);
            free(object);
            return NULL;
        }
        current_pos++; // Skip past ':'

        JsonValue *value = parse_json(current_pos);
        if (!value) {
            free(key->value.string);
            free(key);
            free(object);
            return NULL;
        }

        object->value.object.keys = realloc(object->value.object.keys, sizeof(char *) * (count + 1));
        object->value.object.values = realloc(object->value.object.values, sizeof(JsonValue) * (count + 1));
        
        object->value.object.keys[count] = key->value.string;
        object->value.object.values[count] = *value;
        count++;

        skip_whitespace();
        if (*current_pos == ',') {
            current_pos++;
        } else if (*current_pos == '}') {
            break;
        } else {
            free(key->value.string);
            free(key);
            free(value);
            free(object);
            return NULL;
        }

        skip_whitespace();
    }

    current_pos++; // Skip past '}'
    object->value.object.size = count;
    return object;
}

// Main JSON parser function
JsonValue *parse_json(const char *json) {
    current_pos = json;
    skip_whitespace();

    if (*current_pos == '\0') {
        return NULL; // Empty input
    }
    
    JsonValue *value = NULL;
    if (*current_pos == 'n') {
        value = parse_null();
    } else if (*current_pos == 't' || *current_pos == 'f') {
        value = parse_bool();
    } else if (isdigit(*current_pos) || *current_pos == '-') {
        value = parse_number();
    } else if (*current_pos == '\"') {
        value = parse_string();
    } else if (*current_pos == '[') {
        value = parse_array();
    } else if (*current_pos == '{') {
        value = parse_object();
    }

    skip_whitespace();
    return value;
}

// Function to free allocated JSON
void free_json(JsonValue *value) {
    if (!value) return;
    
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            // Assuming array is a pointer to first element
            // You should deallocate each element of this array before freeing the array itself
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < value->value.object.size; i++) {
                free(value->value.object.keys[i]);
                free_json(&value->value.object.values[i]);
            }
            free(value->value.object.keys);
            free(value->value.object.values);
            break;
        case JSON_NUMBER:
        case JSON_BOOL:
        case JSON_NULL:
            break;
    }
    free(value);
}

// Function to print JSON as a string
void print_json(const JsonValue *value, int indent) {
    if (!value) {
        printf("null");
        return;
    }

    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf(value->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%lf", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_ARRAY: {
            printf("[\n");
            for (size_t i = 0; i < sizeof(value->value.array) / sizeof(JsonValue); i++) {
                print_json(&value->value.array[i], indent + 2);
                if (i < sizeof(value->value.array) / sizeof(JsonValue) - 1) {
                    printf(",\n");
                }
            }
            printf("\n]");
            break;
        }
        case JSON_OBJECT: {
            printf("{\n");
            for (size_t i = 0; i < value->value.object.size; i++) {
                for (int j = 0; j < indent + 1; j++) printf(" ");
                printf("\"%s\": ", value->value.object.keys[i]);
                print_json(&value->value.object.values[i], indent + 2);
                if (i < value->value.object.size - 1) {
                    printf(",\n");
                }
            }
            printf("\n}");
            break;
        }
    }
}

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";

    JsonValue *json_value = parse_json(json_string);
    if (json_value) {
        print_json(json_value, 0);
        printf("\n");
        free_json(json_value);
    }

    return 0;
}