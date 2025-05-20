//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} JsonObject;

int json_parse(char *json, JsonObject *result) {
    int key_length = 0;
    int value_length = 0;
    int comma_count = 0;
    int i = 0;

    result->key = NULL;
    result->value = NULL;

    while (json[i]!= '\0') {
        if (json[i] == '"') {
            comma_count++;
            while (json[i]!= '"') {
                if (json[i] == ',') {
                    comma_count++;
                }
                if (comma_count == 1) {
                    result->key = malloc(strlen(json + i + 1) + 1);
                    strcpy(result->key, json + i + 1);
                    key_length = strlen(result->key);
                }
                if (comma_count == 2) {
                    result->value = malloc(strlen(json + i + 1) + 1);
                    strcpy(result->value, json + i + 1);
                    value_length = strlen(result->value);
                }
                i += 1;
            }
            comma_count = 0;
        } else if (json[i] == ':') {
            result->key = realloc(result->key, (key_length + 1) * sizeof(char));
            strcat(result->key, ":");
        } else if (json[i] == ',' || json[i] == '\0') {
            result->value = realloc(result->value, (value_length + 1) * sizeof(char));
            strcat(result->value, ",");
        }
        i++;
    }

    return 1;
}

int main() {
    char json[] = "{\"key1\": \"value1\", \"key2\": \"value2\"}";
    JsonObject result;
    json_parse(json, &result);
    printf("key1: %s\n", result.key);
    printf("value1: %s\n", result.value);
    printf("key2: %s\n", result.key);
    printf("value2: %s\n", result.value);
    return 0;
}