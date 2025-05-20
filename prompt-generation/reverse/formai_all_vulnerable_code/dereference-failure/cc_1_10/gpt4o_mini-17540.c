//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} JsonType;

typedef struct JsonValue {
    JsonType type;
    char key[MAX_KEY_LENGTH];
    union {
        char string_value[MAX_VALUE_LENGTH];
        double number_value;
        int bool_value;
    } value;
    struct JsonValue* next;
} JsonValue;

typedef struct JsonEntry {
    JsonValue* value;
    struct JsonEntry* next;
} JsonEntry;

typedef struct {
    JsonEntry* head;
} JsonObject;

void trim_whitespace(char** str) {
    while (isspace((unsigned char)**str)) (*str)++;
    char* end = *str + strlen(*str) - 1;
    while (end > *str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

int parse_string(char** json, JsonValue* value) {
    (*json)++; // Skip opening quote
    char* start = *json;
    while (**json && **json != '"') (*json)++;
    if (**json != '"') return -1; // Missing closing quote
    size_t length = *json - start;
    memcpy(value->value.string_value, start, length);
    value->value.string_value[length] = '\0';
    value->type = JSON_STRING;
    (*json)++; // Skip closing quote
    return 0;
}

int parse_number(char** json, JsonValue* value) {
    char* start = *json;
    while (isdigit(**json) || **json == '.' || **json == '-') (*json)++;
    size_t length = *json - start;
    char number[MAX_VALUE_LENGTH];
    memcpy(number, start, length);
    number[length] = '\0';
    value->value.number_value = atof(number);
    value->type = JSON_NUMBER;
    return 0;
}

int parse_bool(char** json, JsonValue* value) {
    if (strncmp(*json, "true", 4) == 0) {
        value->value.bool_value = 1;
        value->type = JSON_BOOL;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->value.bool_value = 0;
        value->type = JSON_BOOL;
        *json += 5;
    } else {
        return -1; // Invalid boolean
    }
    return 0;
}

int parse_null(char** json, JsonValue* value) {
    if (strncmp(*json, "null", 4) == 0) {
        value->type = JSON_NULL;
        *json += 4;
    } else {
        return -1; // Invalid null
    }
    return 0;
}

int parse_value(char** json, JsonValue* value) {
    trim_whitespace(json);
    if (**json == '"') {
        return parse_string(json, value);
    } else if (isdigit(**json) || **json == '-') {
        return parse_number(json, value);
    } else if (strncmp(*json, "true", 4) == 0 || strncmp(*json, "false", 5) == 0) {
        return parse_bool(json, value);
    } else if (strncmp(*json, "null", 4) == 0) {
        return parse_null(json, value);
    }
    return -1; // Invalid value
}

JsonObject* parse_json(const char* json_str) {
    JsonObject* object = malloc(sizeof(JsonObject));
    object->head = NULL;
    JsonEntry* current_entry = NULL;
    char* json = strdup(json_str);
    char* ptr = json;

    while (*ptr) {
        trim_whitespace(&ptr);
        if (*ptr == '{') {
            ptr++;
            continue;
        }
        JsonValue* value = malloc(sizeof(JsonValue));
        if (parse_value(&ptr, value) != 0) {
            free(value);
            break; // Error parsing
        }
        if (current_entry == NULL) {
            object->head = malloc(sizeof(JsonEntry));
            current_entry = object->head;
        } else {
            current_entry->next = malloc(sizeof(JsonEntry));
            current_entry = current_entry->next;
        }
        current_entry->value = value;
        current_entry->next = NULL;

        trim_whitespace(&ptr);
        if (*ptr == ',') {
            ptr++;
        } else if (*ptr == '}') {
            ptr++;
            break;
        }
    }
    
    free(json);
    return object;
}

void free_json(JsonObject* object) {
    JsonEntry* current = object->head;
    while (current != NULL) {
        JsonEntry* next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(object);
}

void print_json(JsonObject* object) {
    JsonEntry* current = object->head;
    while (current != NULL) {
        if (current->value->type == JSON_STRING) {
            printf("Key: %s, Value: %s\n", current->value->key, current->value->value.string_value);
        } else if (current->value->type == JSON_NUMBER) {
            printf("Key: %s, Value: %f\n", current->value->key, current->value->value.number_value);
        } else if (current->value->type == JSON_BOOL) {
            printf("Key: %s, Value: %s\n", current->value->key, current->value->value.bool_value ? "true" : "false");
        } else if (current->value->type == JSON_NULL) {
            printf("Key: %s, Value: null\n", current->value->key);
        }
        current = current->next;
    }
}

int main() {
    const char* json_str = "{\"name\": \"John\", \"age\": 30, \"is_student\": false, \"car\": null}";
    JsonObject* json_object = parse_json(json_str);
    print_json(json_object);
    free_json(json_object);
    return 0;
}