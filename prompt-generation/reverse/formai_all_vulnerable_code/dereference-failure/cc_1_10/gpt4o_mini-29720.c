//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define JSON_MAX_LENGTH 1024

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonObject {
    JsonValue *head;
    int count;
} JsonObject;

// Function prototypes
JsonObject *create_json_object();
void parse_json(const char *json_str, JsonObject *json_obj);
void trim_whitespace(char *str);
void free_json_object(JsonObject *json_obj);
void print_json_object(const JsonObject *json_obj);
char *extract_key_value(char **input);

int main() {
    const char *json_str = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    JsonObject *json_obj = create_json_object();

    printf("Parsing JSON: %s\n", json_str);
    parse_json(json_str, json_obj);
    
    printf("\nParsed JSON Object:\n");
    print_json_object(json_obj);
    
    free_json_object(json_obj);
    return 0;
}

JsonObject *create_json_object() {
    JsonObject *json_obj = (JsonObject *)malloc(sizeof(JsonObject));
    json_obj->head = NULL;
    json_obj->count = 0;
    return json_obj;
}

void parse_json(const char *json_str, JsonObject *json_obj) {
    char *input = strdup(json_str);
    char *key_value;

    // Remove surrounding braces
    char *start = strstr(input, "{");
    char *end = strstr(input, "}");
    if (start != NULL && end != NULL) {
        start += 1; // Move past the '{'
        *end = '\0'; // Null terminate at '}'
    }

    while (*start) {
        key_value = extract_key_value(&start);
        if (key_value != NULL) {
            JsonValue *new_value = (JsonValue *)malloc(sizeof(JsonValue));
            new_value->key = strdup(key_value);
            
            start = strstr(start, ":");
            if (start != NULL) {
                start += 1; // Move past the ':'
                trim_whitespace(start);
                
                char *end_value = strstr(start, ",");
                if (end_value == NULL) {
                    end_value = strstr(start, "}");
                }
                if (end_value != NULL) {
                    *end_value = '\0'; // Null terminate value
                }

                new_value->value = strdup(start);
                start = end_value + 1; // Move past the ','
            } else {
                free(new_value->key);
                free(new_value);
                free(key_value);
                break;
            }
            
            new_value->next = json_obj->head;
            json_obj->head = new_value;
            json_obj->count++;
        } else {
            break;
        }
    }

    free(input);
}

char *extract_key_value(char **input) {
    char *key_start = *input;
    while (*key_start && (*key_start == ' ' || *key_start == '\"' || *key_start == '{')) key_start++;
    
    char *key_end = key_start;
    while (*key_end && *key_end != ':') key_end++;
    
    if (*key_end != ':') return NULL;
    
    *key_end = '\0';
    *input = key_end;
    return key_start;
}

void trim_whitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

void print_json_object(const JsonObject *json_obj) {
    JsonValue *current = json_obj->head;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

void free_json_object(JsonObject *json_obj) {
    JsonValue *current = json_obj->head;
    JsonValue *next;
    while (current) {
        next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(json_obj);
}