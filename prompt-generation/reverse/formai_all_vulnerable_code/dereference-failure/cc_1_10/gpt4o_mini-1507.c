//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    enum { JSON_STRING, JSON_NUMBER, JSON_BOOLEAN, JSON_NULL, JSON_OBJECT, JSON_ARRAY } type;
    union {
        char *stringValue;
        double numberValue;
        int booleanValue; // 0 for false, 1 for true
        struct JsonValue **arrayValue; // For JSON arrays
        struct KeyValuePair *objectValue; // For JSON objects
    } value;
    struct JsonValue *next; // To link to next item for arrays
} JsonValue;

typedef struct KeyValuePair {
    char *key;
    JsonValue *value;
    struct KeyValuePair *next; // To link to next key-value pair
} KeyValuePair;

void freeJsonValue(JsonValue *value);
JsonValue *parseJson(const char *json);
JsonValue *parseValue(const char **json);
JsonValue *parseString(const char **json);
JsonValue *parseNumber(const char **json);
JsonValue *parseBoolean(const char **json);
JsonValue *parseNull(const char **json);
JsonValue *parseObject(const char **json);
JsonValue *parseArray(const char **json);
void skipWhitespace(const char **json);
void printJsonValue(JsonValue *value, int indent);

int main() {
    const char *jsonText = "{ \"name\": \"John\", \"age\": 30, \"isStudent\": false, \"subjects\": [\"Math\", \"Science\"], \"address\": { \"street\": \"123 Main St\", \"city\": \"Anytown\" }, \"nullField\": null }";
    JsonValue *result = parseJson(jsonText);
    
    if (result) {
        printf("Parsed JSON:\n");
        printJsonValue(result, 0);
        freeJsonValue(result);
    } else {
        printf("Failed to parse JSON.\n");
    }
    
    return 0;
}

void printJsonValue(JsonValue *value, int indent) {
    if (!value) return;
    
    for (int i = 0; i < indent; i++) printf("  ");
    
    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"\n", value->value.stringValue);
            break;
        case JSON_NUMBER:
            printf("%f\n", value->value.numberValue);
            break;
        case JSON_BOOLEAN:
            printf("%s\n", value->value.booleanValue ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_ARRAY: {
            printf("[\n");
            JsonValue *item = value->next;
            while (item) {
                printJsonValue(item, indent + 1);
                item = item->next;
                if (item) for (int i = 0; i < indent; i++) printf("  ");
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("]\n");
            break;
        }
        case JSON_OBJECT: {
            printf("{\n");
            KeyValuePair *pair = value->value.objectValue;
            while (pair) {
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("\"%s\": ", pair->key);
                printJsonValue(pair->value, indent + 1);
                pair = pair->next;
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("}\n");
            break;
        }
    }
}

void skipWhitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

JsonValue *parseJson(const char *json) {
    JsonValue *result = parseValue(&json);
    skipWhitespace(&json);
    return result && *json == '\0' ? result : NULL; // All input must be consumed
}

JsonValue *parseValue(const char **json) {
    skipWhitespace(json);
    if (**json == '"') return parseString(json);
    if (isdigit(**json) || **json == '-') return parseNumber(json);
    if (strncmp(*json, "true", 4) == 0) return parseBoolean(json);
    if (strncmp(*json, "false", 5) == 0) return parseBoolean(json);
    if (strncmp(*json, "null", 4) == 0) return parseNull(json);
    if (**json == '{') return parseObject(json);
    if (**json == '[') return parseArray(json);
    return NULL; // Invalid
}

JsonValue *parseString(const char **json) {
    const char *start = ++(*json); // Skip opening quote
    while (**json && **json != '"') {
        if (**json == '\\') (*json)++; // Handle escape sequences
        (*json)++;
    }
    if (**json != '"') return NULL; // Closing quote not found
    size_t length = *json - start; // Length of the string
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    value->value.stringValue = strndup(start, length); // Duplicate the string
    (*json)++; // Skip closing quote
    return value;
}

JsonValue *parseNumber(const char **json) {
    char *end;
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_NUMBER;
    value->value.numberValue = strtod(*json, &end);
    *json = end; // Update json pointer
    return value;
}

JsonValue *parseBoolean(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_BOOLEAN;
    if (strncmp(*json, "true", 4) == 0) {
        value->value.booleanValue = 1;
        *json += 4; // Skip "true"
    } else {
        value->value.booleanValue = 0;
        *json += 5; // Skip "false"
    }
    return value;
}

JsonValue *parseNull(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_NULL;
    *json += 4; // Skip "null"
    return value;
}

JsonValue *parseObject(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_OBJECT;
    value->value.objectValue = NULL;
    KeyValuePair **pair = &value->value.objectValue;

    (*json)++; // Skip '{'
    skipWhitespace(json);
    while (**json && **json != '}') {
        KeyValuePair *newPair = malloc(sizeof(KeyValuePair));
        newPair->next = NULL;

        if (**json != '"') return NULL; // Expect a key (string)
        newPair->key = parseString(json)->value.stringValue;

        skipWhitespace(json);
        if (**json != ':') return NULL; // Expect ':'
        (*json)++; // Skip ':'

        newPair->value = parseValue(json);
        *pair = newPair;
        pair = &newPair->next;

        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip ','
        skipWhitespace(json);
    }
    (*json)++; // Skip '}'
    return value;
}

JsonValue *parseArray(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_ARRAY;
    value->next = NULL;

    (*json)++; // Skip '['
    skipWhitespace(json);
    JsonValue *lastItem = NULL;

    while (**json && **json != ']') {
        JsonValue *newItem = parseValue(json);
        if (!newItem) return NULL; // Error in parsing item

        if (lastItem) {
            lastItem->next = newItem; // Link the new item
        } else {
            value->next = newItem; // First item in array
        }
        lastItem = newItem;

        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip ','
        skipWhitespace(json);
    }
    (*json)++; // Skip ']'
    return value;
}

void freeJsonValue(JsonValue *value) {
    if (!value) return;

    switch (value->type) {
        case JSON_STRING:
            free(value->value.stringValue);
            break;
        case JSON_ARRAY: {
            JsonValue *item = value->next;
            while (item) {
                JsonValue *nextItem = item->next;
                freeJsonValue(item);
                item = nextItem;
            }
            break;
        }
        case JSON_OBJECT: {
            KeyValuePair *pair = value->value.objectValue;
            while (pair) {
                KeyValuePair *nextPair = pair->next;
                free(pair->key); // Free the key
                freeJsonValue(pair->value); // Free the value
                free(pair);
                pair = nextPair;
            }
            break;
        }
        default:
            break;
    }
    free(value); // Free main value structure
}