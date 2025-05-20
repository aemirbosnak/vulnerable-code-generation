//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    enum { JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } type;
    union {
        double number;
        char *string;
        struct JsonObject *object;
        struct JsonArray *array;
    } as;
} JsonValue;

typedef struct JsonKeyValue {
    char *key;
    JsonValue *value;
    struct JsonKeyValue *next;
} JsonKeyValue;

typedef struct JsonObject {
    JsonKeyValue *head;
} JsonObject;

typedef struct JsonArray {
    JsonValue **values;
    size_t size;
} JsonArray;

// Function to validate whitespace characters
void skipWhitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

// Function to parse JSON string
char *parseString(const char **json) {
    const char *start = ++(*json);
    while (**json != '"' && **json) {
        if (**json == '\\') (*json)++; // Skip escaped characters
        (*json)++;
    }
    size_t length = *json - start;
    char *string = (char *)malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    (*json)++; // Skip closing quote
    return string;
}

// Function to parse numbers
double parseNumber(const char **json) {
    char *end;
    double number = strtod(*json, &end);
    *json = end; // Move past the number
    return number;
}

// Function to parse JSON values
JsonValue *parseValue(const char **json);

// Function to parse arrays
JsonArray *parseArray(const char **json) {
    JsonArray *array = (JsonArray *)malloc(sizeof(JsonArray));
    array->size = 0;
    array->values = (JsonValue **)malloc(sizeof(JsonValue *) * 16);
    (*json)++; // Skip the opening bracket

    while (1) {
        skipWhitespace(json);
        if (**json == ']') {
            (*json)++;
            break;
        }
        else if (array->size >= 16) {
            array->values = (JsonValue **)realloc(array->values, sizeof(JsonValue *) * (array->size + 16));
        }
        array->values[array->size++] = parseValue(json);

        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip comma
    }
    return array;
}

// Function to parse objects
JsonObject *parseObject(const char **json) {
    JsonObject *object = (JsonObject *)malloc(sizeof(JsonObject));
    object->head = NULL;
    (*json)++; // Skip the opening brace

    while (1) {
        skipWhitespace(json);
        if (**json == '}') {
            (*json)++;
            break;
        }

        // Parse key
        char *key = parseString(json);
        
        skipWhitespace(json);
        (*json)++; // Skip colon
        
        JsonValue *value = parseValue(json);

        // Create new key-value pair
        JsonKeyValue *newKeyValue = (JsonKeyValue *)malloc(sizeof(JsonKeyValue));
        newKeyValue->key = key;
        newKeyValue->value = value;
        newKeyValue->next = object->head;
        object->head = newKeyValue;

        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip comma
    }
    return object;
}

// Function to parse the JSON value
JsonValue *parseValue(const char **json) {
    skipWhitespace(json);
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));

    if (**json == 'n') {
        value->type = JSON_NULL;
        *json += 4; // Skip "null"
    }
    else if (**json == 't') {
        value->type = JSON_TRUE;
        *json += 4; // Skip "true"
    }
    else if (**json == 'f') {
        value->type = JSON_FALSE;
        *json += 5; // Skip "false"
    }
    else if (**json == '"') {
        value->type = JSON_STRING;
        value->as.string = parseString(json);
    }
    else if (isdigit(**json) || **json == '-') {
        value->type = JSON_NUMBER;
        value->as.number = parseNumber(json);
    }
    else if (**json == '{') {
        value->type = JSON_OBJECT;
        value->as.object = parseObject(json);
    }
    else if (**json == '[') {
        value->type = JSON_ARRAY;
        value->as.array = parseArray(json);
    }

    return value;
}

// Function to free the allocated JSON value
void freeJsonValue(JsonValue *value) {
    if (value->type == JSON_STRING) {
        free(value->as.string);
    }
    else if (value->type == JSON_OBJECT) {
        JsonKeyValue *kv = value->as.object->head;
        while (kv) {
            free(kv->key);
            freeJsonValue(kv->value);
            JsonKeyValue *temp = kv;
            kv = kv->next;
            free(temp);
        }
        free(value->as.object);
    }
    else if (value->type == JSON_ARRAY) {
        for (size_t i = 0; i < value->as.array->size; i++) {
            freeJsonValue(value->as.array->values[i]);
        }
        free(value->as.array->values);
        free(value->as.array);
    }
    free(value);
}

// Function to parse JSON from string
JsonValue *parseJson(const char *json) {
    const char *p = json;
    JsonValue *value = parseValue(&p);
    return value;
}

// Main Function
int main() {
    const char *json_test = "{\"name\": \"John\", \"age\": 30, \"is_student\": false, \"subjects\": [\"Math\", \"Science\"]}";
    
    JsonValue *value = parseJson(json_test);
    if (value) {
        printf("Parsed JSON successfully!\n");
        // Implement print function to display the JSON structure
        // Free the JSON value
        freeJsonValue(value);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}