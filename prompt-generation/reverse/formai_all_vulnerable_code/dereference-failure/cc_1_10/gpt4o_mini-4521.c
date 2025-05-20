//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL, JSON_BOOLEAN, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;           // for boolean values
        double number;         // for number values
        char* string;          // for string values
        struct JsonValue* array; // for array values
        struct JsonObject* object; // for object values
    } value;
    struct JsonValue* next; // for linked list of objects / arrays
} JsonValue;

typedef struct JsonObject {
    char* key;
    JsonValue* value;
    struct JsonObject* next;
} JsonObject;

// Function prototypes
JsonValue* parse_json(const char* json);
JsonValue* parse_value(const char** json);
JsonValue* parse_string(const char** json);
JsonValue* parse_number(const char** json);
JsonValue* parse_object(const char** json);
JsonValue* parse_array(const char** json);
void skip_whitespace(const char** json);
void free_json(JsonValue* value);
void print_json(const JsonValue* value);
char* copy_string(const char* start, const char* end);

// Main function
int main() {
    const char* json_data = "{\"name\": \"John\", \"age\": 30, \"isEmployed\": true, \"jobTitles\": [\"Developer\", \"Designer\"]}";
    
    JsonValue* json_value = parse_json(json_data);
    if (json_value != NULL) {
        print_json(json_value);
        free_json(json_value);
    } else {
        fprintf(stderr, "Failed to parse JSON.\n");
    }

    return 0;
}

// Function implementations
JsonValue* parse_json(const char* json) {
    const char* current = json;
    skip_whitespace(&current);
    JsonValue* value = parse_value(&current);
    skip_whitespace(&current);
    
    if (*current != '\0') {
        free_json(value);
        return NULL;
    }
    return value;
}

JsonValue* parse_value(const char** json) {
    if (**json == '"') {
        return parse_string(json);
    } else if (**json == '{') {
        return parse_object(json);
    } else if (**json == '[') {
        return parse_array(json);
    } else if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    } else if (strncmp(*json, "true", 4) == 0) {
        (*json) += 4;
        JsonValue* value = malloc(sizeof(JsonValue));
        value->type = JSON_BOOLEAN;
        value->value.boolean = 1;
        return value;
    } else if (strncmp(*json, "false", 5) == 0) {
        (*json) += 5;
        JsonValue* value = malloc(sizeof(JsonValue));
        value->type = JSON_BOOLEAN;
        value->value.boolean = 0;
        return value;
    } else if (strncmp(*json, "null", 4) == 0) {
        (*json) += 4;
        JsonValue* value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    }
    return NULL;
}

JsonValue* parse_string(const char** json) {
    const char* start = ++(*json);
    while (**json != '"' && **json != '\0') {
        if (**json == '\\') (*json)++; // Skip escape character
        (*json)++;
    }
    
    if (**json == '\0') return NULL; // Unclosed string

    JsonValue* value = malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    value->value.string = copy_string(start, *json);
    (*json)++; // Skip closing quote
    return value;
}

JsonValue* parse_number(const char** json) {
    char* end;
    JsonValue* value = malloc(sizeof(JsonValue));
    
    value->type = JSON_NUMBER;
    value->value.number = strtod(*json, &end);
    *json = end;
    return value;
}

JsonValue* parse_object(const char** json) {
    JsonValue* value = malloc(sizeof(JsonValue));
    value->type = JSON_OBJECT;
    value->value.object = NULL;

    (*json)++; // Skip '{'
    skip_whitespace(json);

    while (**json != '}') {
        JsonObject* object = malloc(sizeof(JsonObject));
        JsonValue* key = parse_string(json);
        if (!key) {
            free(value);
            return NULL; 
        }

        skip_whitespace(json);
        if (**json != ':') {
            free(key);
            free(value);
            return NULL;
        }
        (*json)++; // Skip ':'
        skip_whitespace(json);
        
        JsonValue* json_value = parse_value(json);
        if (!json_value) {
            free(key);
            free(value);
            return NULL;
        }

        object->key = key->value.string;
        object->value = json_value;
        object->next = value->value.object;
        value->value.object = object;

        skip_whitespace(json);
        if (**json == ',') (*json)++; // Skip ',' if present
        skip_whitespace(json);
    }

    (*json)++; // Skip '}'
    return value;
}

JsonValue* parse_array(const char** json) {
    JsonValue* value = malloc(sizeof(JsonValue));
    value->type = JSON_ARRAY;
    value->value.array = NULL;

    (*json)++; // Skip '['
    skip_whitespace(json);

    while (**json != ']') {
        JsonValue* json_value = parse_value(json);
        if (!json_value) {
            free(value);
            return NULL;
        }
        json_value->next = value->value.array;
        value->value.array = json_value;

        skip_whitespace(json);
        if (**json == ',') (*json)++; // Skip ',' if present
        skip_whitespace(json);
    }

    (*json)++; // Skip ']'
    return value;
}

void skip_whitespace(const char** json) {
    while (isspace(**json)) (*json)++;
}

void free_json(JsonValue* value) {
    if (!value) return;

    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_OBJECT: {
            JsonObject* obj = value->value.object;
            while (obj) {
                free(obj->key);
                free_json(obj->value);
                JsonObject* temp = obj;
                obj = obj->next;
                free(temp);
            }
            break;
        }
        case JSON_ARRAY: {
            JsonValue* arr = value->value.array;
            while (arr) {
                JsonValue* temp = arr;
                arr = arr->next;
                free_json(temp);
            }
            break;
        }
        default:
            break;
    }
    free(value);
}

char* copy_string(const char* start, const char* end) {
    size_t length = end - start;
    char* string = malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    return string;
}

void print_json(const JsonValue* value) {
    if (!value) return;
    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOLEAN:
            printf(value->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_ARRAY:
            printf("[");
            for (JsonValue* item = value->value.array; item != NULL; item = item->next) {
                print_json(item);
                if (item->next) printf(", ");
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            for (JsonObject* obj = value->value.object; obj != NULL; obj = obj->next) {
                printf("\"%s\": ", obj->key);
                print_json(obj->value);
                if (obj->next) printf(", ");
            }
            printf("}");
            break;
    }
}