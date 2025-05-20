//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT_START,
    JSON_OBJECT_END,
    JSON_ARRAY_START,
    JSON_ARRAY_END,
    JSON_NULL,
    JSON_BOOLEAN
} json_type_t;

typedef struct {
    json_type_t type;
    union {
        char *str_val;
        int num_val;
        struct {
            char *key;
            void *val;
        } map_val;
        struct {
            void **arr;
            int size;
        } arr_val;
        int bool_val;
    } data;
} json_value_t;

// Helper functions

char *read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char *buffer = NULL;
    long length;

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(length + 1);

    if (!buffer) {
        fclose(file);
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, length, file);
    fclose(file);
    buffer[length] = '\0';

    return buffer;
}

// Main program

json_value_t parse_json(char *json) {
    json_value_t result;
    memset(&result, 0, sizeof(json_value_t));

    if (json[0] == '[') {
        // Parse array
        int i = 1;
        result.type = JSON_ARRAY_START;
        result.data.arr_val.arr = malloc(sizeof(void *) * 10);
        result.data.arr_val.size = 0;

        while (json[i] != ']') {
            if (json[i] == ',') {
                i++;
            }

            json_value_t val = parse_json(&json[i]);

            result.data.arr_val.arr[result.data.arr_val.size++] = &val;

            i++;
        }

        result.type = JSON_ARRAY_END;
    } else if (json[0] == '{') {
        // Parse object
        int i = 1;
        result.type = JSON_OBJECT_START;

        while (json[i] != '}') {
            // Parse key
            int start = i + 1;
            while (json[i] != ':') {
                i++;
            }

            json_value_t key = parse_json(strndup(&json[start], i - start));

            // Parse value
            i++;
            
            json_value_t val = parse_json(&json[i]);

            // Add to map
            json_value_t *map = malloc(sizeof(json_value_t) * 2);
            map[0] = key;
            map[1] = val;
            result.data.map_val.key = strdup(key.data.str_val);
            result.data.map_val.val = map;

            i++;
        }

        result.type = JSON_OBJECT_END;
    } else {
        // Parse primitive value
        char *end_ptr;

        if (json[0] == '"') {
            result.type = JSON_STRING;
            result.data.str_val = strdup(strtok(json, "\""));
        } else if (json[0] == 't' || json[0] == 'f') {
            result.type = JSON_BOOLEAN;
            result.data.bool_val = json[0] == 't' ? 1 : 0;
        } else if (json[0] == 'n') {
            result.type = JSON_NULL;
        } else if ((json[0] >= '0' && json[0] <= '9') || json[0] == '-') {
            result.type = JSON_NUMBER;
            result.data.num_val = (int) strtol(json, &end_ptr, 10);
        } else {
            printf("Unknown type: %c\n", json[0]);
            exit(EXIT_FAILURE);
        }
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <json-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *json = read_file(argv[1]);
    json_value_t val = parse_json(json);

    printf("Value type: %d\n", val.type);

    return 0;
}