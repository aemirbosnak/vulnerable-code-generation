//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// function declarations
void parse_json(char *json);

int main() {
    char json[BUFFER_SIZE] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    parse_json(json);
    return 0;
}

void parse_json(char *json) {
    char *name, *value;
    int in_string = 0, in_name = 0;
    printf("JSON object: %s\n", json);
    printf("Parsing JSON object...\n");
    while (*json != '\0') {
        if (*json == '\"') {
            if (in_string) {
                in_string = 0;
                printf("Value: %s\n", value);
                free(value);
            } else {
                in_string = 1;
                if (in_name) {
                    name = realloc(name, strlen(name) + 1);
                    name[strlen(name)] = '\0';
                    printf("Name: %s\n", name);
                    in_name = 0;
                } else {
                    value = malloc(BUFFER_SIZE);
                    value[0] = '\0';
                }
            }
        } else {
            if (in_string) {
                value = realloc(value, strlen(value) + 2);
                value[strlen(value)] = *json;
                value[strlen(value) + 1] = '\0';
            } else {
                if (*json == ':') {
                    in_name = 1;
                    name = malloc(BUFFER_SIZE);
                    name[0] = '\0';
                } else if (*json == ',') {
                    in_name = 1;
                } else if (*json == '}') {
                    printf("Parsing complete.\n");
                    return;
                }
            }
        }
        json++;
    }
}