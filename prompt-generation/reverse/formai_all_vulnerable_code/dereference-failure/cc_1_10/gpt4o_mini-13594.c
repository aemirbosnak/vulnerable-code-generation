//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonObject {
    JsonValue *head;
} JsonObject;

// Function prototypes
JsonObject *createJsonObject();
void addJsonKeyValue(JsonObject *obj, const char *key, const char *value);
void freeJsonObject(JsonObject *obj);
void printJsonObject(JsonObject *obj);
JsonObject *parseJson(const char *json_string);
char *stripWhitespace(const char *str);
char *extractKey(const char **str_ptr);
char *extractValue(const char **str_ptr);
int isJsonChar(char c);

// Main function
int main() {
    const char *json_string = "{\"name\":\"John Doe\", \"age\":\"30\", \"city\":\"New York\"}";
    
    JsonObject *json_obj = parseJson(json_string);
    
    if (json_obj) {
        printJsonObject(json_obj);
        freeJsonObject(json_obj);
    } else {
        fprintf(stderr, "Failed to parse JSON\n");
    }
    
    return 0;
}

// Function to create a new JsonObject
JsonObject *createJsonObject() {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

// Function to add key-value pair to JsonObject
void addJsonKeyValue(JsonObject *obj, const char *key, const char *value) {
    JsonValue *new_pair = (JsonValue *)malloc(sizeof(JsonValue));
    new_pair->key = strdup(key);
    new_pair->value = strdup(value);
    new_pair->next = obj->head;
    obj->head = new_pair;
}

// Function to free JsonObject memory
void freeJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    JsonValue *next_pair;

    while (current) {
        next_pair = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next_pair;
    }
    free(obj);
}

// Function to print JsonObject
void printJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    printf("{\n");
    while (current) {
        printf("  \"%s\": \"%s\",\n", current->key, current->value);
        current = current->next;
    }
    printf("}\n");
}

// Function to parse JSON string into JsonObject
JsonObject *parseJson(const char *json_string) {
    JsonObject *obj = createJsonObject();
    const char *ptr = json_string;
    
    while (*ptr) {
        ptr = stripWhitespace(ptr);
        if (*ptr == '{') {
            ptr++; // Skip the opening brace
            continue;
        }
        
        if (*ptr == '}') {
            break; // End of object
        }

        char *key = extractKey(&ptr);
        if (!key) return NULL;

        ptr = stripWhitespace(ptr);
        if (*ptr != ':') {
            free(key);
            return NULL; // Invalid JSON format
        }
        ptr++; // Skip the colon

        char *value = extractValue(&ptr);
        if (!value) {
            free(key);
            return NULL;
        }

        addJsonKeyValue(obj, key, value);
        free(key);
        free(value);

        ptr = stripWhitespace(ptr);
        if (*ptr == ',') {
            ptr++; // Skip the comma
        } else if (*ptr == '}') {
            break; // End of object
        } else {
            return NULL; // Invalid JSON format
        }
    }
    
    return obj;
}

// Function to strip whitespace from start of string
char *stripWhitespace(const char *str) {
    while (isspace((unsigned char)*str)) str++;
    return (char *)str;
}

// Function to extract the key from JSON string
char *extractKey(const char **str_ptr) {
    const char *ptr = *str_ptr;
    if (*ptr != '\"') return NULL; // Key must start with "
    ptr++; // Skip opening quote

    const char *start = ptr;
    while (*ptr && *ptr != '\"') {
        ptr++;
    }
    
    if (*ptr != '\"') return NULL; // Key must end with "
    size_t length = ptr - start;
    char *key = (char *)malloc(length + 1);
    strncpy(key, start, length);
    key[length] = '\0';
    
    *str_ptr = ptr + 1; // Move past the closing quote
    return key;
}

// Function to extract the value from JSON string
char *extractValue(const char **str_ptr) {
    const char *ptr = *str_ptr;
    if (*ptr != '\"') return NULL; // Value must start with "
    ptr++; // Skip opening quote

    const char *start = ptr;
    while (*ptr && *ptr != '\"') {
        ptr++;
    }

    if (*ptr != '\"') return NULL; // Value must end with "
    size_t length = ptr - start;
    char *value = (char *)malloc(length + 1);
    strncpy(value, start, length);
    value[length] = '\0';

    *str_ptr = ptr + 1; // Move past the closing quote
    return value;
}

// Function to check if the character is valid JSON character
int isJsonChar(char c) {
    return (isalnum(c) || c == '\"' || c == '{' || c == '}' || c == ':' || c == ',');
}