//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The wasteland is a harsh place, but we can still parse JSON.
// Here's a post-apocalyptic JSON parser.

// The JSON parser is a scavenger, searching for valuable data amidst the ruins.
typedef struct scavenger {
    char *data;
    int length;
    int index;
} scavenger_t;

// The scavenger roams the wasteland, looking for a specific type of data.
typedef enum data_type {
    DATA_TYPE_STRING,
    DATA_TYPE_NUMBER,
    DATA_TYPE_OBJECT,
    DATA_TYPE_ARRAY,
    DATA_TYPE_BOOLEAN,
    DATA_TYPE_NULL
} data_type_t;

// The scavenger has a set of tools to help it parse the data.
typedef struct tools {
    char *key;
    data_type_t type;
    union {
        char *string;
        double number;
        struct tools *object;
        struct tools *array;
        int boolean;
    } value;
} tools_t;

// The scavenger's journey begins here.
int main(int argc, char **argv) {
    // The scavenger initializes its data.
    scavenger_t scavenger;
    scavenger.data = argv[1];
    scavenger.length = strlen(scavenger.data);
    scavenger.index = 0;

    // The scavenger creates a set of tools.
    tools_t tools;
    tools.key = NULL;
    tools.type = DATA_TYPE_NULL;

    // The scavenger begins its journey.
    while (scavenger.index < scavenger.length) {
        // The scavenger encounters a character.
        char character = scavenger.data[scavenger.index];

        // The scavenger decides what to do with the character.
        switch (character) {
            case '{':
                // The scavenger has found an object.
                tools.type = DATA_TYPE_OBJECT;
                break;
            case '[':
                // The scavenger has found an array.
                tools.type = DATA_TYPE_ARRAY;
                break;
            case '"':
                // The scavenger has found a string.
                tools.type = DATA_TYPE_STRING;
                scavenger.index++;
                tools.value.string = &scavenger.data[scavenger.index];
                while (scavenger.data[scavenger.index] != '"') {
                    scavenger.index++;
                }
                scavenger.data[scavenger.index] = '\0';
                tools.value.string = strdup(tools.value.string);
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                // The scavenger has found a number.
                tools.type = DATA_TYPE_NUMBER;
                scavenger.index++;
                while (scavenger.data[scavenger.index] != ',' && scavenger.data[scavenger.index] != '}' && scavenger.data[scavenger.index] != ']') {
                    scavenger.index++;
                }
                scavenger.data[scavenger.index] = '\0';
                tools.value.number = atof(tools.value.string);
                break;
            case ':':
                // The scavenger has found a key-value separator.
                tools.key = strdup(tools.value.string);
                break;
            case ',':
                // The scavenger has found a value separator.
                scavenger.index++;
                while (scavenger.data[scavenger.index] == ' ' || scavenger.data[scavenger.index] == '\n' || scavenger.data[scavenger.index] == '\t') {
                    scavenger.index++;
                }
                break;
            case '}':
                // The scavenger has found the end of an object.
                tools.type = DATA_TYPE_NULL;
                break;
            case ']':
                // The scavenger has found the end of an array.
                tools.type = DATA_TYPE_NULL;
                break;
            case 't':
                // The scavenger has found a boolean value (true).
                tools.type = DATA_TYPE_BOOLEAN;
                tools.value.boolean = 1;
                break;
            case 'f':
                // The scavenger has found a boolean value (false).
                tools.type = DATA_TYPE_BOOLEAN;
                tools.value.boolean = 0;
                break;
            case 'n':
                // The scavenger has found a null value.
                tools.type = DATA_TYPE_NULL;
                break;
            default:
                // The scavenger has found an unknown character.
                break;
        }

        // The scavenger moves to the next character.
        scavenger.index++;
    }

    // The scavenger has finished its journey.
    // The scavenger prints the data it has found.
    printf("{\"%s\": %s}\n", tools.key, tools.value.string);

    // The scavenger frees the memory it has allocated.
    free(tools.key);
    free(tools.value.string);

    return 0;
}