//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    enum { JSON_NULL, JSON_BOOLEAN, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } type;
    union {
        int boolean; // 1 for true, 0 for false
        double number;
        char *string;
        struct JsonValue *array;
        struct JsonValue *object;
    } value;
    struct JsonValue *next; // for linked lists of arrays/objects
} JsonValue;

void skipWhitespace(const char **p) {
    while (isspace(**p)) (*p)++;
}

JsonValue *jsonParse(const char **p);

JsonValue *jsonParseNull(const char **p) {
    if (strncmp(*p, "null", 4) == 0) {
        *p += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    }
    return NULL;
}

JsonValue *jsonParseBoolean(const char **p) {
    if (strncmp(*p, "true", 4) == 0) {
        *p += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_BOOLEAN;
        value->value.boolean = 1;
        return value;
    } else if (strncmp(*p, "false", 5) == 0) {
        *p += 5;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_BOOLEAN;
        value->value.boolean = 0;
        return value;
    }
    return NULL;
}

JsonValue *jsonParseNumber(const char **p) {
    char *endPtr;
    double number = strtod(*p, &endPtr);
    if (endPtr != *p) {
        *p = endPtr;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = number;
        return value;
    }
    return NULL;
}

JsonValue *jsonParseString(const char **p) {
    if (**p == '"') {
        (*p)++;
        const char *start = *p;
        while (**p != '"' && **p != '\0') {
            if (**p == '\\') (*p)++; // skip escape characters
            (*p)++;
        }
        if (**p == '"') {
            size_t length = *p - start;
            JsonValue *value = malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = strndup(start, length);
            (*p)++;
            return value;
        }
    }
    return NULL;
}

JsonValue *jsonParseArray(const char **p) {
    JsonValue *array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->next = NULL;
    
    if (**p != '[') {
        free(array);
        return NULL;
    }
    (*p)++; // skip '['

    JsonValue *current = NULL;
    while (1) {
        skipWhitespace(p);
        if (**p == ']') {
            (*p)++;
            return array;
        }
        JsonValue *value = jsonParse(p);
        if (!value) {
            free(array);
            return NULL; // Error
        }

        if (current) {
            current->next = value; // link the last value
        } else {
            array->value.array = value; // set the first value
        }
        current = value;

        skipWhitespace(p);
        if (**p == ',') {
            (*p)++; // skip comma
        } else if (**p == ']') {
            (*p)++;
            return array;
        } else {
            free(array);
            return NULL; // Error
        }
    }
}

JsonValue *jsonParse(const char **p) {
    skipWhitespace(p);
    JsonValue *value = jsonParseNull(p);
    if (value) return value;

    value = jsonParseBoolean(p);
    if (value) return value;

    value = jsonParseNumber(p);
    if (value) return value;

    value = jsonParseString(p);
    if (value) return value;

    value = jsonParseArray(p);
    if (value) return value;

    return NULL;
}

void freeJsonValue(JsonValue *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            freeJsonValue(value->value.array);
            break;
        // Implement additional cleanup for objects if included
        default:
            break;
    }
    free(value);
}

int main() {
    const char *json = "[\"Hello\", true, null, 123.456]";
    const char *p = json;

    JsonValue *data = jsonParse(&p);
    if (data) {
        printf("Parsed JSON successfully!\n");
        // Further processing of data
    } else {
        printf("Failed to parse JSON.\n");
    }
    
    freeJsonValue(data);
    return 0;
}