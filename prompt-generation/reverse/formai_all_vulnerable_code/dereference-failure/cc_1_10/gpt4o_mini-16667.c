//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 100
#define MAX_STRING_SIZE 1024

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        char *string_value;
        double number_value;
        struct JsonValue *array_value;
        struct JsonValue *object_value;
    };
    size_t size;  // for arrays and objects
} JsonValue;

typedef struct JsonParser {
    const char *json;
    size_t position;
} JsonParser;

static JsonValue* json_parse_value(JsonParser *parser);
static JsonValue* json_parse_string(JsonParser *parser);
static JsonValue* json_parse_number(JsonParser *parser);
static JsonValue* json_parse_array(JsonParser *parser);
static JsonValue* json_parse_object(JsonParser *parser);
static void json_skip_whitespace(JsonParser *parser);
static void json_free_value(JsonValue *value);

JsonValue* json_parse(const char *json) {
    JsonParser parser = { json, 0 };
    return json_parse_value(&parser);
}

static JsonValue* json_parse_value(JsonParser *parser) {
    json_skip_whitespace(parser);
    char current_char = parser->json[parser->position];
    
    if (current_char == '"') {
        return json_parse_string(parser);
    } else if ((current_char >= '0' && current_char <= '9') || current_char == '-') {
        return json_parse_number(parser);
    } else if (current_char == '[') {
        return json_parse_array(parser);
    } else if (current_char == '{') {
        return json_parse_object(parser);
    } else if (strncmp(parser->json + parser->position, "true", 4) == 0) {
        parser->position += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_TRUE;
        return value;
    } else if (strncmp(parser->json + parser->position, "false", 5) == 0) {
        parser->position += 5;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_FALSE;
        return value;
    } else if (strncmp(parser->json + parser->position, "null", 4) == 0) {
        parser->position += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    }
    
    return NULL; // Unexpected character
}

static JsonValue* json_parse_string(JsonParser *parser) {
    parser->position++; // Skip the opening quote
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    value->string_value = malloc(MAX_STRING_SIZE);
    
    size_t index = 0;
    
    while (parser->json[parser->position] != '"') {
        if (parser->json[parser->position] == '\\') {
            parser->position++;
            if (parser->json[parser->position] == 'n') {
                value->string_value[index++] = '\n';
            } else if (parser->json[parser->position] == 't') {
                value->string_value[index++] = '\t';
            } else {
                value->string_value[index++] = parser->json[parser->position];
            }
        } else {
            value->string_value[index++] = parser->json[parser->position];
        }
        parser->position++;
    }
    
    value->string_value[index] = '\0';
    parser->position++; // Skip closing quote
    return value;
}

static JsonValue* json_parse_number(JsonParser *parser) {
    char *end_ptr;
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_NUMBER;
    value->number_value = strtod(parser->json + parser->position, &end_ptr);
    parser->position = end_ptr - parser->json; // Update position
    return value;
}

static JsonValue* json_parse_array(JsonParser *parser) {
    parser->position++; // Skip the opening '['
    
    JsonValue *array_value = malloc(sizeof(JsonValue));
    array_value->type = JSON_ARRAY;
    array_value->size = 0;
    array_value->array_value = malloc(MAX_DEPTH * sizeof(JsonValue)); // Allocate initial space
     
    while (parser->json[parser->position] != ']') {
        json_skip_whitespace(parser);
        if (array_value->size >= MAX_DEPTH) {
            // Resize not implemented in this example
            fprintf(stderr, "Array too large\n");
            json_free_value(array_value);
            return NULL;
        }
        
        array_value->array_value[array_value->size++] = *json_parse_value(parser);
        
        json_skip_whitespace(parser);
        if (parser->json[parser->position] == ',') {
            parser->position++; // Skip the comma
        }
    }
    
    parser->position++; // Skip the closing ']'
    return array_value;
}

static JsonValue* json_parse_object(JsonParser *parser) {
    parser->position++; // Skip the opening '{'

    JsonValue *object_value = malloc(sizeof(JsonValue));
    object_value->type = JSON_OBJECT;
    object_value->size = 0;
    object_value->object_value = malloc(MAX_DEPTH * sizeof(JsonValue)); // Allocate initial space
    
    while (parser->json[parser->position] != '}') {
        json_skip_whitespace(parser);
        JsonValue *key = json_parse_string(parser);
        json_skip_whitespace(parser);

        if (parser->json[parser->position] != ':') {
            json_free_value(key);
            fprintf(stderr, "Expected ':' after key\n");
            json_free_value(object_value);
            return NULL;
        }

        parser->position++; // Skip the ':'
        JsonValue *value = json_parse_value(parser);
        
        // For simplicity, we store the key-value pair in the object
        // In a full implementation, you would use a proper dictionary structure
        object_value->object_value[object_value->size++] = *key;
        object_value->object_value[object_value->size++] = *value;
        
        json_skip_whitespace(parser);
        if (parser->json[parser->position] == ',') {
            parser->position++; // Skip the comma
        }
        
        json_free_value(key);
        json_free_value(value);
    }

    parser->position++; // Skip the closing '}'
    return object_value;
}

static void json_skip_whitespace(JsonParser *parser) {
    while (parser->json[parser->position] == ' ' || parser->json[parser->position] == '\n' ||
           parser->json[parser->position] == '\t' || parser->json[parser->position] == '\r') {
        parser->position++;
    }
}

static void json_free_value(JsonValue *value) {
    if (value) {
        switch (value->type) {
            case JSON_STRING:
                free(value->string_value);
                break;
            case JSON_ARRAY:
                for (size_t i = 0; i < value->size; i++) {
                    json_free_value(&value->array_value[i]);
                }
                free(value->array_value);
                break;
            case JSON_OBJECT:
                for (size_t i = 0; i < value->size; i += 2) {
                    json_free_value(&value->object_value[i]); // Free key
                    json_free_value(&value->object_value[i + 1]); // Free value
                }
                free(value->object_value);
                break;
            default:
                break;
        }
        free(value);
    }
}

int main() {
    const char *json_test = "{\"key1\":\"value1\",\"key2\":100,\"key3\":true,\"key4\":[1,2,3]}";

    JsonValue *parsed_json = json_parse(json_test);
    if (parsed_json != NULL) {
        printf("JSON parsed successfully!\n");
        json_free_value(parsed_json);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}