//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for storing key-value pairs
typedef struct {
    char *key;
    char *value;
} KeyValue;

// Structure for storing JSON objects
typedef struct {
    KeyValue *pairs;
    int num_pairs;
    char *json_string;
} JsonObject;

// Function for parsing a JSON string and returning a JsonObject
JsonObject* parse_json(char *json_string) {
    // Create a new JsonObject and initialize its pairs and num_pairs values
    JsonObject *json_obj = (JsonObject*) malloc(sizeof(JsonObject));
    json_obj->pairs = NULL;
    json_obj->num_pairs = 0;
    json_obj->json_string = json_string;

    // Strip whitespace from the beginning and end of the JSON string
    while (isspace(*json_string))
        json_string++;
    char *end = json_string + strlen(json_string) - 1;
    while (end > json_string && isspace(*end))
        end--;
    *(end + 1) = 0;

    // Check if the JSON string begins with a { character
    if (*json_string != '{') {
        printf("Error: JSON string must begin with '{'\n");
        return NULL;
    }

    // Loop through each character in the JSON string
    char *ptr = json_string + 1;
    while (*ptr != '\0') {
        // Skip whitespace
        while (isspace(*ptr))
            ptr++;

        // Check if we've reached the end of the JSON object
        if (*ptr == '}') {
            ptr++;
            break;
        }

        // Parse the key
        char *key = NULL;
        if (*ptr == '"') {
            ptr++;
            char *start = ptr;
            while (*ptr != '\0' && *ptr != '"')
                ptr++;
            if (*ptr == '\0') {
                printf("Error: Unterminated key\n");
                return NULL;
            }
            key = (char*) malloc(ptr - start + 1);
            strncpy(key, start, ptr - start);
            key[ptr - start] = '\0';
            ptr++;
        } else {
            printf("Error: Expected key to begin with '\"'\n");
            return NULL;
        }

        // Skip whitespace after the key
        while (isspace(*ptr))
            ptr++;

        // Check for the colon between the key and value
        if (*ptr == ':') {
            ptr++;
        } else {
            printf("Error: Expected ':' after key\n");
            return NULL;
        }

        // Skip whitespace after the colon
        while (isspace(*ptr))
            ptr++;

        // Parse the value
        char *value = NULL;
        if (*ptr == '{') {
            // Recursively parse nested object
            int depth = 1;
            char *start = ptr;
            ptr++;
            while (*ptr != '\0') {
                if (*ptr == '{') {
                    depth++;
                } else if (*ptr == '}') {
                    depth--;
                    if (depth == 0)
                        break;
                }
                ptr++;
            }
            if (*ptr == '\0') {
                printf("Error: Unterminated object within value\n");
                return NULL;
            }
            value = (char*) malloc(ptr - start + 2);
            strncpy(value, start, ptr - start + 1);
            value[ptr - start + 1] = '\0';
            ptr++;
        } else if (*ptr == '"') {
            // Parse string value
            ptr++;
            char *start = ptr;
            while (*ptr != '\0' && *ptr != '"')
                ptr++;
            if (*ptr == '\0') {
                printf("Error: Unterminated string\n");
                return NULL;
            }
            value = (char*) malloc(ptr - start + 1);
            strncpy(value, start, ptr - start);
            value[ptr - start] = '\0';
            ptr++;
        } else if (isdigit(*ptr) || *ptr == '-') {
            // Parse numerical value
            char *start = ptr;
            while (*ptr != '\0' && (*ptr == '-' || isdigit(*ptr)))
                ptr++;
            value = (char*) malloc(ptr - start + 1);
            strncpy(value, start, ptr - start);
            value[ptr - start] = '\0';
        } else if (*ptr == 't' || *ptr == 'f' || *ptr == 'n') {
            // Parse boolean or null value
            int len;
            if (*ptr == 't' || *ptr == 'f') {
                len = (*ptr == 't') ? 4 : 5;
            } else if (*ptr == 'n') {
                len = 4;
            }
            if (strncmp(ptr, "true", len) == 0 || strncmp(ptr, "false", len) == 0 || strncmp(ptr, "null", len) == 0) {
                value = (char*) malloc(len + 1);
                strncpy(value, ptr, len);
                value[len] = '\0';
                ptr += len;
            } else {
                printf("Error: Unrecognized boolean or null value\n");
                return NULL;
            }
        } else {
            printf("Error: Unrecognized value type\n");
            return NULL;
        }

        // Create a new KeyValue pair and initialize its key and value
        KeyValue *pair = (KeyValue*) malloc(sizeof(KeyValue));
        pair->key = key;
        pair->value = value;

        // Add the new KeyValue pair to the JsonObject's pairs array
        json_obj->num_pairs++;
        json_obj->pairs = (KeyValue*) realloc(json_obj->pairs, sizeof(KeyValue) * json_obj->num_pairs);
        json_obj->pairs[json_obj->num_pairs - 1] = *pair;
    }
    return json_obj;
}

int main() {
    char *json_string = "{\"name\": \"Jane Doe\", \"age\": 35, \"address\": {\"street\": \"123 Main St\", \"city\": \"Anytown\", \"state\": \"CA\"}, \"isMarried\": true, \"favNumbers\": [3, 7, 22]}";
    JsonObject *json_obj = parse_json(json_string);
    if (json_obj != NULL) {
        printf("JSON object:\n");
        printf("{\n");
        for (int i = 0; i < json_obj->num_pairs; i++) {
            printf("    \"%s\": ", json_obj->pairs[i].key);
            if (strncmp(json_obj->pairs[i].value, "{", 1) == 0) {
                printf("%s", json_obj->pairs[i].value);
            } else if (strncmp(json_obj->pairs[i].value, "[", 1) == 0) {
                printf("%s", json_obj->pairs[i].value);
            } else if (strncmp(json_obj->pairs[i].value, "true", 4) == 0) {
                printf("true");
            } else if (strncmp(json_obj->pairs[i].value, "false", 5) == 0) {
                printf("false");
            } else if (strncmp(json_obj->pairs[i].value, "null", 4) == 0) {
                printf("null");
            } else {
                printf("\"%s\"", json_obj->pairs[i].value);
            }
            printf(",\n");
        }
        printf("}\n");
    }
    for (int i = 0; i < json_obj->num_pairs; i++) {
        free(json_obj->pairs[i].key);
        free(json_obj->pairs[i].value);
    }
    free(json_obj->pairs);
    free(json_obj);
    return 0;
}