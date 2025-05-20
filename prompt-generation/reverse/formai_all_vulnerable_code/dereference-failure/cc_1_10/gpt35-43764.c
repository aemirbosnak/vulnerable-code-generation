//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 100
#define MAX_OBJECT_SIZE 1000

/* JSON object structure */
typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} json_object;

/* Function to parse JSON object */
int parse_json(char *json_string, json_object *json_arrays, int max_array_size) {

    int current_array_size = 0;
    int current_key_position = 0;
    int current_value_position = 0;
    bool is_parsing_key = true;
    bool is_parsing_value = false;
    char current_char;

    for (int i = 0; i < strlen(json_string); i++) {

        current_char = json_string[i];

        /* Ignore white spaces and new lines */
        if (isspace(current_char))
            continue;

        if (current_char == '"') {
            /* Start Parsing key */
            if (is_parsing_key) {
                current_key_position = 0;
                is_parsing_key = false;
                is_parsing_value = true;
                continue;
            }
            /* End Parsing value */
            if (is_parsing_value) {
                current_value_position = 0;
                is_parsing_key = true;
                is_parsing_value = false;
                current_array_size++; // Move to next JSON object
                continue;
            }
        }

        /* Parsing Key */
        if (is_parsing_key && current_key_position < MAX_KEY_SIZE) {
            json_arrays[current_array_size].key[current_key_position++] = current_char;
        }

        /* Parsing Value */
        if (is_parsing_value && current_value_position < MAX_VALUE_SIZE) {
            json_arrays[current_array_size].value[current_value_position++] = current_char;
        }
    }

    return current_array_size; // Return Total JSON objects parsed
}

int main() {

    printf("Welcome to my funny JSON Parser Program!\n");

    printf("Enter your JSON string: ");

    char json_string[MAX_OBJECT_SIZE];
    fgets(json_string, MAX_OBJECT_SIZE, stdin);

    /* Creating array to store JSON objects */
    json_object json_objects[10];

    /* Parse JSON objects */
    int total_objects = parse_json(json_string, json_objects, 10);

    printf("\nParsed JSON Objects:\n\n");

    /* Print Parsed JSON objects */
    for (int i = 0; i < total_objects; i++) {
        printf("Key: %s\nValue: %s\n\n", json_objects[i].key, json_objects[i].value);
    }

    printf("Thanks for using my JSON Parser Program!");

    return 0;
}