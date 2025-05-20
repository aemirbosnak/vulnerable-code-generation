//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000000

enum json_types {
    JSON_OBJECT = 1,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
};

#define MAX_KEY_SIZE 200
#define MAX_VALUE_SIZE 200

struct json {
    int type;
    char *key;
    char *value;
    struct json *next;
    struct json *child;
};

// The following recursive function parses a JSON object and returns a tree of json objects
struct json *parse_object(char **json);

// The following recursive function parses a JSON array and returns a linked list of json objects
struct json *parse_array(char **json);

// The following function parses a JSON string and returns the string value
char *parse_string(char **json);

// The following function parses a JSON number and returns the numeric value
char *parse_number(char **json);

// The following function parses a JSON boolean and returns the boolean value
int parse_boolean(char **json);

// The following function parses a JSON null value and returns null
char *parse_null(char **json);

// A utility function to create a new JSON object
struct json *new_json(int type, char *key, char *value);

// The following function prints a JSON tree in a pretty format
void print_json(struct json *json_object, int indent);

int main()
{
    char json_str[MAX_JSON_SIZE];
    printf("Enter the JSON string:\n");
    fgets(json_str, MAX_JSON_SIZE, stdin);
    char *json = json_str;

    struct json *json_tree = parse_object(&json);

    printf("The JSON Tree:\n");
    print_json(json_tree, 0);
}

struct json *parse_object(char **json)
{
    struct json *json_object = new_json(JSON_OBJECT, NULL, NULL);
    (*json)++; // Skip the opening brace

    // Parse the key-value pairs
    while (**json != '}') {
        // Parse the key
        char *key = parse_string(json);
        (*json)++; // Skip the colon

        // Parse the value
        struct json *value = NULL;
        switch (**json) {
            case '{':
                value = parse_object(json);
                break;
            case '[':
                value = parse_array(json);
                break;
            case '\"':
                value = new_json(JSON_STRING, NULL, parse_string(json));
                break;
            case 't':
            case 'f':
                value = new_json(JSON_BOOLEAN, NULL, parse_boolean(json));
                break;
            case 'n':
                value = new_json(JSON_NULL, NULL, parse_null(json));
                break;
            default:
                value = new_json(JSON_NUMBER, NULL, parse_number(json));
                break;
        }

        // Add the key-value pair to the JSON object
        value->key = key;
        if (json_object->child != NULL) {
            json_object->child->next = value;
        } else {
            json_object->child = value;
        }

        // If there is a comma, skip it
        (*json)++;
        if (**json == ',') {
            (*json)++;
        }
    }

    (*json)++; // Skip the closing brace
    return json_object;
}

struct json *parse_array(char **json)
{
    struct json *json_list = new_json(JSON_ARRAY, NULL, NULL);
    (*json)++; // Skip the opening bracket

    // Parse the array elements
    while (**json != ']') {
        struct json *value = NULL;
        switch (**json) {
            case '{':
                value = parse_object(json);
                break;
            case '[':
                value = parse_array(json);
                break;
            case '\"':
                value = new_json(JSON_STRING, NULL, parse_string(json));
                break;
            case 't':
            case 'f':
                value = new_json(JSON_BOOLEAN, NULL, parse_boolean(json));
                break;
            case 'n':
                value = new_json(JSON_NULL, NULL, parse_null(json));
                break;
            default:
                value = new_json(JSON_NUMBER, NULL, parse_number(json));
                break;
        }

        // Add the value to the linked list
        if (json_list->child != NULL) {
            json_list->child->next = value;
        } else {
            json_list->child = value;
        }

        // If there is a comma, skip it
        (*json)++;
        if (**json == ',') {
            (*json)++;
        }
    }

    (*json)++; // Skip the closing bracket
    return json_list;
}

char *parse_string(char **json)
{
    char *string = (char*) malloc(MAX_VALUE_SIZE * sizeof(char));
    (*json)++; // Skip the opening quote
    int i = 0;
    while (**json != '\"') {
        string[i++] = **json;
        (*json)++;
    }
    string[i] = '\0';
    (*json)++; // Skip the closing quote
    return string;
}

char *parse_number(char **json)
{
    char *number = (char*) malloc(MAX_VALUE_SIZE * sizeof(char));
    int i = 0;
    while (**json >= '0' && **json <= '9') {
        number[i++] = **json;
        (*json)++;
    }
    if (**json == '.') {
        number[i++] = **json;
        (*json)++;
        while (**json >= '0' && **json <= '9') {
            number[i++] = **json;
            (*json)++;
        }
    }
    number[i] = '\0';
    return number;
}

int parse_boolean(char **json)
{
    if (**json == 't') {
        (*json) += 4; // Skip the "true" value
        return 1;
    } else {
        (*json) += 5; // Skip the "false" value
        return 0;
    }
}

char *parse_null(char **json)
{
    (*json) += 4; // Skip the "null" value
    return NULL;
}

struct json *new_json(int type, char *key, char *value)
{
    struct json *json_object = (struct json*) malloc(sizeof(struct json));
    json_object->type = type;
    json_object->key = key;
    json_object->value = value;
    json_object->next = NULL;
    json_object->child = NULL;
    return json_object;
}

void print_json(struct json *json_object, int indent)
{
    while (json_object != NULL) {
        if (json_object->key != NULL) {
            printf("%*s\"%s\": ", indent, "", json_object->key);
        }
        switch (json_object->type) {
            case JSON_OBJECT:
                printf("{\n");
                print_json(json_object->child, indent + 4);
                printf("%*s}", indent, "");
                break;
            case JSON_ARRAY:
                printf("[\n");
                print_json(json_object->child, indent + 4);
                printf("%*s]", indent, "");
                break;
            case JSON_STRING:
                printf("\"%s\"", json_object->value);
                break;
            case JSON_NUMBER:
                printf("%s", json_object->value);
                break;
            case JSON_BOOLEAN:
                printf("%s", json_object->value ? "true" : "false");
                break;
            default:
                printf("null");
                break;
        }
        if (json_object->next != NULL) {
            printf(",");
        }
        printf("\n");
        json_object = json_object->next;
    }
}