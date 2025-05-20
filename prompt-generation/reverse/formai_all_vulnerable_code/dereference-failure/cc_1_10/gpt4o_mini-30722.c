//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum json_value_type { JSON_UNKNOWN, JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY, JSON_BOOLEAN, JSON_NULL };

typedef struct json_value {
    enum json_value_type type;
    union {
        char *string_value;
        double number_value;
        struct json_value **array_value; // To hold an array of json_values
        struct json_key_value_pair {
            char *key; 
            struct json_value *value;
        } *object_value; // To hold key-value pairs of objects
    } data;
    size_t array_size;
    size_t object_size;
} json_value;

// Function prototypes
json_value *parse_json(const char *json_str);
json_value *parse_value(const char **json_str);
void skip_whitespace(const char **json_str);
json_value *parse_string(const char **json_str);
json_value *parse_number(const char **json_str);
json_value *parse_object(const char **json_str);
json_value *parse_array(const char **json_str);
void free_json_value(json_value *value);
void print_json(json_value *value, int indent_level);

int main() {
    const char *json_example = "{\"name\":\"John\", \"age\":30, \"isStudent\":false, \"courses\":[\"Math\", \"Science\"], \"address\":{\"city\":\"New York\", \"zip\":\"10001\"}}";

    json_value *parsed_json = parse_json(json_example);
    if (parsed_json != NULL) {
        print_json(parsed_json, 0);
        free_json_value(parsed_json);
    } else {
        printf("Failed to parse JSON\n");
    }

    return 0;
}

json_value *parse_json(const char *json_str) {
    const char *p = json_str;
    skip_whitespace(&p);
    json_value *value = parse_value(&p);
    skip_whitespace(&p);
    if (*p != '\0') {
        free_json_value(value);
        return NULL; // Extra characters at the end of the JSON string
    }
    return value;
}

json_value *parse_value(const char **json_str) {
    skip_whitespace(json_str);
    if (**json_str == '\"') {
        return parse_string(json_str);
    } else if (isdigit(**json_str) || **json_str == '-') {
        return parse_number(json_str);
    } else if (**json_str == '{') {
        return parse_object(json_str);
    } else if (**json_str == '[') {
        return parse_array(json_str);
    } else if (strncmp(*json_str, "true", 4) == 0) {
        *json_str += 4;
        json_value *val = malloc(sizeof(json_value));
        val->type = JSON_BOOLEAN;
        return val;
    } else if (strncmp(*json_str, "false", 5) == 0) {
        *json_str += 5;
        json_value *val = malloc(sizeof(json_value));
        val->type = JSON_BOOLEAN;
        return val;
    } else if (strncmp(*json_str, "null", 4) == 0) {
        *json_str += 4;
        json_value *val = malloc(sizeof(json_value));
        val->type = JSON_NULL;
        return val;
    }
    return NULL; // Invalid or unsupported value
}

void skip_whitespace(const char **json_str) {
    while (isspace(**json_str)) {
        (*json_str)++;
    }
}

json_value *parse_string(const char **json_str) {
    const char *start = ++(*json_str); // Skip starting quote
    while (**json_str != '\"' && **json_str != '\0') {
        (*json_str)++;
    }
    if (**json_str == '\0') return NULL; // Unterminated string
    size_t length = *json_str - start;
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_STRING;
    val->data.string_value = malloc(length + 1);
    strncpy(val->data.string_value, start, length);
    val->data.string_value[length] = '\0';
    (*json_str)++; // Skip ending quote
    return val;
}

json_value *parse_number(const char **json_str) {
    char *end;
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_NUMBER;
    val->data.number_value = strtod(*json_str, &end);
    *json_str = end; // Move pointer to the end of the number
    return val;
}

json_value *parse_object(const char **json_str) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_OBJECT;
    val->data.object_value = NULL;
    val->object_size = 0;

    (*json_str)++; // Skip '{'
    skip_whitespace(json_str);
    while (**json_str != '}') {
        // Allocate memory for new key-value pair
        val->object_size++;
        val->data.object_value = realloc(val->data.object_value, sizeof(*(val->data.object_value)) * val->object_size);
        
        json_value *key_value_pair = parse_string(json_str);
        if (!key_value_pair) {
            free_json_value(val);
            return NULL; // Failed to parse key
        }
        
        // Expect colon
        skip_whitespace(json_str);
        if (**json_str != ':') {
            free_json_value(val);
            return NULL; // Missing colon
        }
        (*json_str)++;
        
        // Parse value
        json_value *value = parse_value(json_str);
        if (!value) {
            free_json_value(val);
            return NULL; // Failed to parse value
        }

        // Assign parsed key and value
        val->data.object_value[val->object_size - 1].key = key_value_pair->data.string_value;
        val->data.object_value[val->object_size - 1].value = value;

        skip_whitespace(json_str);
        if (**json_str == ',') (*json_str)++; // Advance past comma
        skip_whitespace(json_str);
    }
    
    (*json_str)++; // Skip '}'
    return val;
}

json_value *parse_array(const char **json_str) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_ARRAY;
    val->data.array_value = NULL;
    val->array_size = 0;

    (*json_str)++; // Skip '['
    skip_whitespace(json_str);
    while (**json_str != ']') {
        // Allocate memory for new array element
        val->array_size++;
        val->data.array_value = realloc(val->data.array_value, sizeof(*(val->data.array_value)) * val->array_size);
        
        // Parse value
        json_value *value = parse_value(json_str);
        if (!value) {
            free_json_value(val);
            return NULL; // Failed to parse value
        }

        val->data.array_value[val->array_size - 1] = value;

        skip_whitespace(json_str);
        if (**json_str == ',') (*json_str)++; // Advance past comma
        skip_whitespace(json_str);
    }
    
    (*json_str)++; // Skip ']'
    return val;
}

void free_json_value(json_value *value) {
    if (!value) return;
    
    switch (value->type) {
        case JSON_STRING:
            free(value->data.string_value);
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < value->object_size; ++i) {
                free(value->data.object_value[i].key);
                free_json_value(value->data.object_value[i].value);
            }
            free(value->data.object_value);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < value->array_size; ++i) {
                free_json_value(value->data.array_value[i]);
            }
            free(value->data.array_value);
            break;
        case JSON_NUMBER:
        case JSON_BOOLEAN:
        case JSON_NULL:
        case JSON_UNKNOWN:
        default:
            break; // Do nothing
    }
    free(value);
}

void print_json(json_value *value, int indent_level) {
    if (!value) return;
    
    for (int i = 0; i < indent_level; i++) printf("  ");
    
    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"\n", value->data.string_value);
            break;
        case JSON_NUMBER:
            printf("%f\n", value->data.number_value);
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (size_t i = 0; i < value->object_size; ++i) {
                printf("%s: ", value->data.object_value[i].key);
                print_json(value->data.object_value[i].value, indent_level + 1);
            }
            for (int i = 0; i < indent_level; i++) printf("  ");
            printf("}\n");
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (size_t i = 0; i < value->array_size; ++i) {
                print_json(value->data.array_value[i], indent_level + 1);
            }
            for (int i = 0; i < indent_level; i++) printf("  ");
            printf("]\n");
            break;
        case JSON_BOOLEAN:
            printf("true\n");
            break;
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_UNKNOWN:
        default:
            break; // Unknown type
    }
}