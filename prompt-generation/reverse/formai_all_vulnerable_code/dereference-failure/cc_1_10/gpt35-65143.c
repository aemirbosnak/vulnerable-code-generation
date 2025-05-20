//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_STRING_SIZE 1024

typedef enum { FALSE, TRUE } Bool;

typedef struct {
    char* key;
    char* value;
} JsonKeyValuePair;

typedef struct {
    int num_pairs;
    JsonKeyValuePair* pairs;
} JsonObject;

int parse_json_string(char* json_string, JsonObject* json_object);
int parse_json_object(char* json_string, int start_index, JsonObject* json_object);
int parse_json_keyvaluepair(char* json_string, int start_index, JsonKeyValuePair* kv);

int main() {
    char json_string[MAX_JSON_STRING_SIZE] = "{\"key\": \"value\"}";

    JsonObject json_object;
    if (parse_json_string(json_string, &json_object) == TRUE) {
        printf("Parsed JSON object: %s\n", json_object.pairs[0].value);
    } else {
        printf("Failed to parse JSON string.\n");
    }

    return 0;
}

int parse_json_string(char* json_string, JsonObject* json_object) {
    if (json_string == NULL || json_object == NULL) {
        return FALSE;
    }

    int start_index = 0;
    if (json_string[start_index] == '{') {
        start_index++;
    } else {
        return FALSE;
    }

    json_object->num_pairs = 0;
    json_object->pairs = calloc(1, sizeof(JsonKeyValuePair));

    while (json_string[start_index] != '\0') {
        JsonKeyValuePair kv;
        if (parse_json_keyvaluepair(json_string, start_index, &kv) == TRUE) {
            json_object->num_pairs++;
            json_object->pairs = realloc(json_object->pairs, json_object->num_pairs * sizeof(JsonKeyValuePair));
            json_object->pairs[json_object->num_pairs - 1] = kv;
        }
        
        // Check for end of JSON object
        start_index += strlen(kv.key) + strlen(kv.value) + 4;
        if (json_string[start_index] == '}') {
            return TRUE;
        } else if (json_string[start_index] == ',') {
            start_index++;
        } else {
            return FALSE;
        }
    }

    return FALSE;
}

int parse_json_object(char* json_string, int start_index, JsonObject* json_object) {
    // TODO
    return FALSE;
}

int parse_json_keyvaluepair(char* json_string, int start_index, JsonKeyValuePair* kv) {
    if (json_string == NULL || kv == NULL) {
        return FALSE;
    }

    // Find key
    char* key_start = strchr(json_string + start_index, '\"');
    if (key_start == NULL) {
        return FALSE;
    }
    key_start++;
    char* key_end = strchr(key_start, '\"');
    if (key_end == NULL) {
        return FALSE;
    }
    int key_length = key_end - key_start;
    kv->key = calloc(key_length + 1, sizeof(char));
    strncpy(kv->key, key_start, key_length);
    kv->key[key_length] = '\0';

    // Find value
    char* value_start = strchr(key_end + 1, ':');
    if (value_start == NULL) {
        free(kv->key);
        return FALSE;
    }
    value_start++;
    char* value_end = strchr(value_start, ',');
    if (value_end == NULL) {
        value_end = strchr(value_start, '}');
        if (value_end == NULL) {
            free(kv->key);
            return FALSE;
        }
    }
    int value_length = value_end - value_start;
    kv->value = calloc(value_length + 1, sizeof(char));
    strncpy(kv->value, value_start, value_length);
    kv->value[value_length] = '\0';

    return TRUE;
}