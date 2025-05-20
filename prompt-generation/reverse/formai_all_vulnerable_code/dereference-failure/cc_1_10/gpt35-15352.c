//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON structure
typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} JSONType;

typedef struct JSON {
    JSONType type;
    union {
        struct JSONObject {
            char **keys;
            struct JSON **values;
            int length;
        } object;

        struct JSONArray {
            struct JSON **values;
            int length;
        } array;

        char *string;

        double number;

        int boolean;

        char *null;
    } data;
} JSON;

// Define parsing functions
JSON *parse_json_object(char *);
JSON *parse_json_array(char *);
JSON *parse_json_string(char *);
JSON *parse_json_number(char *);
JSON *parse_json_bool(char *);
JSON *parse_json_null(char *);
void trim_spaces(char **);

// Define utility functions
void error(char *);
void free_json(JSON *);
void print_json(JSON *);
void print_tabs(int);

int main() {
    char json_string[] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    JSON *json = parse_json_object(json_string);
    printf("Parsed JSON Object:\n");
    print_json(json);
    free_json(json);

    char json_string2[] = "[\"apple\", \"banana\", \"cherry\"]";
    json = parse_json_array(json_string2);
    printf("\nParsed JSON Array:\n");
    print_json(json);
    free_json(json);

    char json_string3[] = "10.5";
    json = parse_json_number(json_string3);
    printf("\nParsed JSON Number:\n");
    print_json(json);
    free_json(json);

    char json_string4[] = "true";
    json = parse_json_bool(json_string4);
    printf("\nParsed JSON Boolean:\n");
    print_json(json);
    free_json(json);

    char json_string5[] = "null";
    json = parse_json_null(json_string5);
    printf("\nParsed JSON Null:\n");
    print_json(json);
    free_json(json);

    return 0;
}

JSON *parse_json_object(char *json_string) {
    JSON *json = malloc(sizeof(JSON));
    json->type = JSON_OBJECT;

    // Remove { and } characters
    json_string++;
    json_string[strlen(json_string) - 1] = '\0';

    // Get the keys and values
    trim_spaces(&json_string);
    if (*json_string == '}') {
        json->data.object.keys = NULL;
        json->data.object.values = NULL;
        json->data.object.length = 0;
        return json;
    }

    int num_keys = 1;
    for (char *c = json_string; *c != '\0'; c++) {
        if (*c == ',') {
            num_keys++;
        }
    }

    char **keys = malloc(sizeof(char *) * num_keys);
    JSON **values = malloc(sizeof(JSON *) * num_keys);
    int current_key = 0;
    while (*json_string != '\0') {
        trim_spaces(&json_string);
        if (*json_string == '}') {
            break;
        }
        if (*json_string == ',') {
            json_string++;
            trim_spaces(&json_string);
        }

        // Get the key
        char *key_start = json_string;
        while (*json_string != ':') {
            json_string++;
        }
        *json_string = '\0';
        keys[current_key] = malloc(sizeof(char) * (strlen(key_start) + 1));
        strcpy(keys[current_key], key_start);
        json_string++;

        // Get the value
        trim_spaces(&json_string);
        int type = *json_string == '"' ? JSON_STRING : JSON_NUMBER;
        if (*json_string == '{') {
            values[current_key] = parse_json_object(json_string);
        }
        else if (*json_string == '[') {
            values[current_key] = parse_json_array(json_string);
        }
        else if (type == JSON_STRING) {
            values[current_key] = parse_json_string(json_string);
        }
        else {
            values[current_key] = parse_json_number(json_string);
        }

        current_key++;
    }

    json->data.object.keys = keys;
    json->data.object.values = values;
    json->data.object.length = num_keys;
    return json;
}

JSON *parse_json_array(char *json_string) {
    JSON *json = malloc(sizeof(JSON));
    json->type = JSON_ARRAY;

    // Remove [ and ] characters
    json_string++;
    json_string[strlen(json_string) - 1] = '\0';

    // Get the values
    trim_spaces(&json_string);
    if (*json_string == ']') {
        json->data.array.values = NULL;
        json->data.array.length = 0;
        return json;
    }

    int num_values = 1;
    for (char *c = json_string; *c != '\0'; c++) {
        if (*c == ',') {
            num_values++;
        }
    }

    JSON **values = malloc(sizeof(JSON *) * num_values);
    int current_value = 0;
    while (*json_string != '\0') {
        trim_spaces(&json_string);
        if (*json_string == ']') {
            break;
        }
        if (*json_string == ',') {
            json_string++;
            trim_spaces(&json_string);
        }

        // Get the value
        int type = *json_string == '"' ? JSON_STRING : JSON_NUMBER;
        if (*json_string == '{') {
            values[current_value] = parse_json_object(json_string);
        }
        else if (*json_string == '[') {
            values[current_value] = parse_json_array(json_string);
        }
        else if (type == JSON_STRING) {
            values[current_value] = parse_json_string(json_string);
        }
        else {
            values[current_value] = parse_json_number(json_string);
        }

        current_value++;
    }

    json->data.array.values = values;
    json->data.array.length = num_values;
    return json;
}

JSON *parse_json_string(char *json_string) {
    JSON *json = malloc(sizeof(JSON));
    json->type = JSON_STRING;

    // Remove quotes
    json_string++;
    json_string[strlen(json_string) - 1] = '\0';

    // Copy the string
    char *value = malloc(sizeof(char) * (strlen(json_string) + 1));
    strcpy(value, json_string);
    json->data.string = value;

    return json;
}

JSON *parse_json_number(char *json_string) {
    JSON *json = malloc(sizeof(JSON));
    json->type = JSON_NUMBER;

    json->data.number = atof(json_string);

    return json;
}

JSON *parse_json_bool(char *json_string) {
    JSON *json = malloc(sizeof(JSON));
    json->type = JSON_BOOL;

    if (strcmp(json_string, "true") == 0) {
        json->data.boolean = 1;
    }
    else if (strcmp(json_string, "false") == 0) {
        json->data.boolean = 0;
    }
    else {
        error("Invalid JSON boolean");
    }

    return json;
}

JSON *parse_json_null(char *json_string) {
    JSON *json = malloc(sizeof(JSON));
    json->type = JSON_NULL;

    json->data.null = malloc(sizeof(char) * 5);
    strcpy(json->data.null, "null");

    return json;
}

void trim_spaces(char **str) {
    while (**str == ' ' || **str == '\t' || **str == '\n') {
        (*str)++;
    }
}

void error(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

void free_json(JSON *json) {
    switch (json->type) {
        case JSON_OBJECT:
            for (int i = 0; i < json->data.object.length; i++) {
                free_json(json->data.object.values[i]);
                free(json->data.object.keys[i]);
            }
            free(json->data.object.keys);
            free(json->data.object.values);
            break;

        case JSON_ARRAY:
            for (int i = 0; i < json->data.array.length; i++) {
                free_json(json->data.array.values[i]);
            }
            free(json->data.array.values);
            break;

        case JSON_STRING:
            free(json->data.string);
            break;

        case JSON_NUMBER:
            break;

        case JSON_BOOL:
            break;

        case JSON_NULL:
            free(json->data.null);
            break;

        default:
            break;
    }
    free(json);
}

void print_json(JSON *json) {
    switch (json->type) {
        case JSON_OBJECT:
            printf("{\n");
            for (int i = 0; i < json->data.object.length; i++) {
                print_tabs(1);
                printf("\"%s\": ", json->data.object.keys[i]);
                print_json(json->data.object.values[i]);
                if (i != json->data.object.length - 1) {
                    printf(",");
                }
                printf("\n");
            }
            print_tabs(0);
            printf("}");
            break;

        case JSON_ARRAY:
            printf("[\n");
            for (int i = 0; i < json->data.array.length; i++) {
                print_tabs(1);
                print_json(json->data.array.values[i]);
                if (i != json->data.array.length - 1) {
                    printf(",");
                }
                printf("\n");
            }
            print_tabs(0);
            printf("]");
            break;

        case JSON_STRING:
            printf("\"%s\"", json->data.string);
            break;

        case JSON_NUMBER:
            printf("%.1f", json->data.number);
            break;

        case JSON_BOOL:
            printf("%s", json->data.boolean ? "true" : "false");
            break;

        case JSON_NULL:
            printf("null");
            break;

        default:
            break;
    }
}

void print_tabs(int num) {
    for (int i = 0; i < num; i++) {
        printf("\t");
    }
}