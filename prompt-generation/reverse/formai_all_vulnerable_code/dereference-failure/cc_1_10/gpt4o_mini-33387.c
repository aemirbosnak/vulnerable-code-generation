//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024
#define MAX_JSON_LENGTH 8192

typedef enum { JSON_NULL, JSON_FALSE, JSON_TRUE, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char* string;
        struct JsonValue* array;  // Array of JsonValue
        struct JsonObject* object; // Pointer to JsonObject if needed
    } value;
    size_t size; // For arrays and objects
} JsonValue;

typedef struct JsonObject {
    char* key;
    JsonValue value;
    struct JsonObject* next; // For linked list implementation
} JsonObject;

void freeJsonValue(JsonValue* value);
void freeJsonObject(JsonObject* object);
JsonValue* parse_json(const char* json);
char* trim_whitespace(char* str);
JsonValue* parse_value(const char** json);
JsonValue* parse_object(const char** json);
JsonValue* parse_array(const char** json);
JsonValue* parse_string(const char** json);
JsonValue* parse_number(const char** json);

int main() {
    const char* json_example = "{\"name\": \"John\", \"age\": 30, \"is_student\": false, \"courses\": [\"Math\", \"Science\"]}";
    JsonValue* parsed_json = parse_json(json_example);

    // Print the parsed JSON value (Example usage)
    if (parsed_json && parsed_json->type == JSON_OBJECT) {
        JsonObject* object = (JsonObject*)parsed_json->value.object;
        while (object) {
            printf("Key: %s, Type: %d\n", object->key, object->value.type);
            object = object->next;
        }
    }

    freeJsonValue(parsed_json);
    return 0;
}

JsonValue* parse_json(const char* json) {
    const char* json_ptr = trim_whitespace((char*)json);
    return parse_value(&json_ptr);
}

char* trim_whitespace(char* str) {
    while (isspace(*str)) str++;
    return str;
}

JsonValue* parse_value(const char** json) {
    if (**json == '{') return parse_object(json);
    else if (**json == '[') return parse_array(json);
    else if (**json == '\"') return parse_string(json);
    else if (isdigit(**json) || **json == '-') return parse_number(json);
    return NULL;
}

JsonValue* parse_object(const char** json) {
    JsonValue* object_value = (JsonValue*)malloc(sizeof(JsonValue));
    object_value->type = JSON_OBJECT;
    object_value->value.object = NULL;

    (*json)++; // Skip '{'
    
    while (**json && **json != '}') {
        while (isspace(**json)) (*json)++; // Skip whitespace

        char* key = parse_string(json);
        if (!key) break;

        JsonValue value;
        value = *(parse_value(json));
        JsonObject* obj = (JsonObject*)malloc(sizeof(JsonObject));
        
        obj->key = key;
        obj->value = value;
        obj->next = object_value->value.object;
        object_value->value.object = obj;

        while (isspace(**json)) (*json)++; // Skip whitespace
        if (**json == ',') (*json)++; // Skip comma
    }

    (*json)++; // Skip '}'
    return object_value;
}

JsonValue* parse_array(const char** json) {
    // Implementation for arrays will be similar to objects
    return NULL; // This should return parsed array
}

JsonValue* parse_string(const char** json) {
    (*json)++; // Skip initial "
    char buffer[MAX_STRING_LENGTH] = {0};
    size_t index = 0;

    while (**json != '\"' && **json != '\0') {
        if (index < MAX_STRING_LENGTH - 1) {
            buffer[index++] = **json;
        }
        (*json)++;
    }
    (*json)++; // Skip final "
    buffer[index] = '\0';

    char* string_value = (char*)malloc(strlen(buffer) + 1);
    strcpy(string_value, buffer);
    return string_value;
}

JsonValue* parse_number(const char** json) {
    // Simple number parsing implementation can be added here
    return NULL; // This should return parsed number
}

void freeJsonValue(JsonValue* value) {
    if (value) {
        if (value->type == JSON_STRING) {
            free(value->value.string);
        } else if (value->type == JSON_OBJECT) {
            freeJsonObject(value->value.object);
        }
        free(value);
    }
}

void freeJsonObject(JsonObject* object) {
    while (object) {
        JsonObject* next = object->next;
        free(object->key);
        freeJsonValue(&object->value);
        free(object);
        object = next;
    }
}