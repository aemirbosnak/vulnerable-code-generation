//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_FIELDS 10
#define MAX_FIELD_LENGTH 50
#define MAX_JSON_LENGTH 1000

typedef struct {
    char* field_names[MAX_NUM_FIELDS];
    char* field_values[MAX_NUM_FIELDS];
    int num_fields;
} json_object;

char* parse_string(char* ptr) {
    char* start = strchr(ptr, '"') + 1;
    char* end = strchr(start, '"');
    int length = end - start;
    char* value = malloc(length + 1);
    strncpy(value, start, length);
    value[length] = '\0';
    return value;
}

int parse_value(char* ptr, char* end, json_object* obj) {
    if (*ptr == '{') {
        return 0;
    } else if (*ptr == '"') {
        char* name = parse_string(ptr);
        ptr = strchr(ptr, ':') + 1;
        char* value = parse_string(ptr);
        obj->field_names[obj->num_fields] = name;
        obj->field_values[obj->num_fields] = value;
        obj->num_fields++;
        return 1;
    } else {
        return 0;
    }
}

json_object* parse_json(char* json_str) {
    json_object* obj = malloc(sizeof(json_object));
    obj->num_fields = 0;
    char* ptr = json_str;
    while (*ptr != '\0') {
        if (*ptr == ',') {
            ptr++;
        } else if (*ptr == '{') {
            ptr++;
        } else if (*ptr == '}') {
            return obj;
        } else {
            int parsed = parse_value(ptr, strchr(ptr, '}'), obj);
            if (!parsed) {
                printf("Error: Failed to parse JSON\n");
                return NULL;
            }
            ptr = strchr(ptr, ',') + 1;
        }
    }
    return obj;
}

int main() {
    printf("Please enter a JSON string (max length %d): \n", MAX_JSON_LENGTH);
    char* json_str = malloc(MAX_JSON_LENGTH);
    fgets(json_str, MAX_JSON_LENGTH, stdin);
    json_object* obj = parse_json(json_str);
    if (obj != NULL) {
        printf("Parsed JSON object:\n");
        for (int i = 0; i < obj->num_fields; i++) {
            printf("%s: %s\n", obj->field_names[i], obj->field_values[i]);
        }
        free(obj);
    }
    free(json_str);
    return 0;
}