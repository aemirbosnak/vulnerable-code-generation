//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_STRING "{\
                        \"name\": \"John\",\
                        \"age\": 30,\
                        \"married\": false,\
                        \"address\": {\
                            \"street\": \"123 Main St\",\
                            \"city\": \"Anytown\",\
                            \"state\": \"CA\",\
                            \"zip\": \"12345\"\
                        },\
                        \"phone_numbers\": [\
                            \"555-555-1234\",\
                            \"555-555-5678\"\
                        ]\
                    }"

#define MAX_BUFFER_SIZE 1024

enum json_type {
    JSON_TYPE_STRING, 
    JSON_TYPE_NUMBER, 
    JSON_TYPE_BOOL, 
    JSON_TYPE_OBJECT, 
    JSON_TYPE_ARRAY
};

struct json_value {
    enum json_type type;
    char *value;
    struct json_value *next;
};

/* Function to parse a string */
char *parse_string(char *buffer, int index) {
    char *string = malloc(MAX_BUFFER_SIZE * sizeof(char));
    int i = 0;

    while (buffer[index] != '\"') {
        string[i] = buffer[index];
        i++;
        index++;
    }

    string[i] = '\0';

    return string;
}

/* Function to parse a number */
char *parse_number(char *buffer, int index) {
    char *number = malloc(MAX_BUFFER_SIZE * sizeof(char));
    int i = 0;

    while ((buffer[index] >= '0' && buffer[index] <= '9') || buffer[index] == '.') {
        number[i] = buffer[index];
        i++;
        index++;
    }

    number[i] = '\0';

    return number;
}

/* Function to parse a boolean */
char *parse_bool(char *buffer, int index) {
    char *boolean = malloc(6 * sizeof(char));

    if (buffer[index] == 't') {
        boolean = "true";
    } else {
        boolean = "false";
    }

    return boolean;
}

/* Function to parse a value */
struct json_value *parse_value(char *buffer, int *index);

/* Function to parse an object */
struct json_value *parse_object(char *buffer, int *index) {
    struct json_value *object = malloc(sizeof(struct json_value));
    object->type = JSON_TYPE_OBJECT;

    struct json_value *current_key = NULL;
    struct json_value *current_value = NULL;

    while (buffer[*index] != '}') {
        /* Parse key */
        if (buffer[*index] == '\"') {
            *index += 1;
            char *key_string = parse_string(buffer, *index);
            current_key = malloc(sizeof(struct json_value));
            current_key->type = JSON_TYPE_STRING;
            current_key->value = key_string;
        }

        *index += 1;

        /* Parse value */
        current_value = parse_value(buffer, index);

        /* Add key-value pair to object */
        if (object->next == NULL) {
            object->next = current_key;
            current_key->next = current_value;
        } else {
            current_key->next = current_value;
        }

        if (buffer[*index] == ',') {
            *index += 1;
        }
    }

    return object;
}

/* Function to parse an array */
struct json_value *parse_array(char *buffer, int *index) {
    struct json_value *array = malloc(sizeof(struct json_value));
    array->type = JSON_TYPE_ARRAY;

    struct json_value *current_value = NULL;
    struct json_value *tail = array;

    while (buffer[*index] != ']') {
        current_value = parse_value(buffer, index);

        tail->next = current_value;
        tail = current_value;

        if (buffer[*index] == ',') {
            *index += 1;
        }
    }

    return array;
}

/* Function to parse a value */
struct json_value *parse_value(char *buffer, int *index) {
    struct json_value *value = malloc(sizeof(struct json_value));
    char current_char = buffer[*index];
    value->next = NULL;

    if (current_char == '\"') { /* String */
        value->type = JSON_TYPE_STRING;
        value->value = parse_string(buffer, *index + 1);
    } else if ((current_char >= '0' && current_char <= '9') || current_char == '-') { /* Number */
        value->type = JSON_TYPE_NUMBER;
        value->value = parse_number(buffer, *index);
    } else if (current_char == 't' || current_char == 'f') { /* Boolean */
        value->type = JSON_TYPE_BOOL;
        value->value = parse_bool(buffer, *index);
    } else if (current_char == '[') { /* Array */
        value->type = JSON_TYPE_ARRAY;
        *index += 1;
        value->next = parse_array(buffer, index);
        return value;
    } else if (current_char == '{') { /* Object */
        value->type = JSON_TYPE_OBJECT;
        *index += 1;
        value->next = parse_object(buffer, index);
        return value;
    }

    return value;
}

/* Main function */
int main() {
    /* Parsing JSON string */
    int index = 0;
    struct json_value *root = parse_object(JSON_STRING, &index);

    /* Traversing JSON tree */
    struct json_value *current = root->next;

    printf("Printing JSON:\n");

    while (current != NULL) {
        printf("%s: ", current->value);

        if (current->next->type == JSON_TYPE_STRING) {
            printf("%s\n", current->next->value);
        } else if (current->next->type == JSON_TYPE_NUMBER) {
            printf("%s\n", current->next->value);
        } else if (current->next->type == JSON_TYPE_BOOL) {
            printf("%s\n", current->next->value);
        } else if (current->next->type == JSON_TYPE_ARRAY) {
            printf("[\n");

            struct json_value *array_current = current->next->next;

            while (array_current != NULL) {
                printf("%s, ", array_current->value);
                array_current = array_current->next;
            }

            printf("]\n");
        } else if (current->next->type == JSON_TYPE_OBJECT) {
            printf("{\n");

            struct json_value *object_current = current->next->next;

            while (object_current != NULL) {
                printf("%s: ", object_current->value);

                if (object_current->next->type == JSON_TYPE_STRING) {
                    printf("%s\n", object_current->next->value);
                } else if (object_current->next->type == JSON_TYPE_NUMBER) {
                    printf("%s\n", object_current->next->value);
                } else if (object_current->next->type == JSON_TYPE_BOOL) {
                    printf("%s\n", object_current->next->value);
                } else if (object_current->next->type == JSON_TYPE_ARRAY) {
                    printf("[\n");

                    struct json_value *object_array_current = object_current->next->next;

                    while (object_array_current != NULL) {
                        printf("%s, ", object_array_current->value);
                        object_array_current = object_array_current->next;
                    }

                    printf("]\n");
                }

                object_current = object_current->next->next;
            }

            printf("}\n");
        }

        current = current->next->next;
    }

    printf("JSON printed successfully!\n");

    return 0;
}