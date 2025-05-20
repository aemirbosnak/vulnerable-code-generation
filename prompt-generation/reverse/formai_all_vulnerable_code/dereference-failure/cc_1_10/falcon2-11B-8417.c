//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_JSON_SIZE 1024

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

typedef struct {
    int status;
    char *message;
} Response;

typedef struct {
    int status;
    char *message;
} Error;

typedef struct {
    char *json_string;
    char **json_array;
    int json_array_size;
    bool is_valid;
} JSON_Parser;

int parse_json(JSON_Parser *parser) {
    char *token = strtok(parser->json_string, ",");
    int count = 0;

    while (token!= NULL) {
        if (count == 0) {
            parser->json_array[count] = malloc(strlen(token) + 1);
            strcpy(parser->json_array[count], token);
            count++;
        } else {
            if (strcmp(token, "}") == 0) {
                break;
            }
        }
        token = strtok(NULL, ",");
        count++;
    }

    if (count > 0) {
        parser->is_valid = true;
        return 1;
    } else {
        parser->is_valid = false;
        return 0;
    }
}

int main() {
    JSON_Parser parser;
    char json_string[MAX_JSON_SIZE];

    printf("Enter JSON data: ");
    fgets(json_string, MAX_JSON_SIZE, stdin);

    parser.json_string = json_string;
    parser.json_array_size = 0;

    if (parse_json(&parser)) {
        printf("JSON is valid.\n");
    } else {
        printf("JSON is not valid.\n");
    }

    return 0;
}