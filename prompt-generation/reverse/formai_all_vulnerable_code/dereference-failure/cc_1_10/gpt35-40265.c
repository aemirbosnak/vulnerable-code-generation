//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to parse JSON string and return JSON object
char* parse_json(char* json_str) {
    char* key = malloc(sizeof(char) * 20);
    char* value = malloc(sizeof(char) * 20);
    char* json_object = malloc(sizeof(char) * 100);
    int key_count = 0;
    int value_count = 0;
    int i = 0;
    while (json_str[i] != '\0') {
        if (json_str[i] == '\"') {
            i++;
            while (json_str[i] != '\"') {
                key[key_count] = json_str[i];
                key_count += 1;
                i++;
            }
            key[key_count] = '\0';
            i += 3; // to skip ":<space>
            while (json_str[i] != ',' && json_str[i] != '}') {
                value[value_count] = json_str[i];
                value_count += 1;
                i++;
            }
            value[value_count] = '\0';
            strcat(json_object, key);
            strcat(json_object, ": ");
            strcat(json_object, value);
            strcat(json_object, "\n");
            key_count = 0;
            value_count = 0;
            if (json_str[i] == '}') {
                break;
            }
        }
        i++;
    }
    free(key);
    free(value);
    return json_object;
}

int main() {
    char* json_str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    char* json_object = parse_json(json_str);
    printf("%s", json_object);
    free(json_object);
    return 0;
}