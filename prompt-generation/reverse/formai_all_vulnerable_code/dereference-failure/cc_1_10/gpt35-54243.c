//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* key;
    char* value;
} json_key_value_pair;

typedef struct {
    json_key_value_pair* data;
    int size;
} json_object;

void parse_json(char* json_string, json_object* output) {
    // This is a curious JSON parser that can only handle objects with string keys and values
    if (json_string[0] != '{' || json_string[strlen(json_string) - 1] != '}') {
        printf("Invalid JSON format\n");
        return;
    }

    char* current_position = json_string + 1;
    output->size = 0;

    while (*current_position != '\0') {
        // Looking for key
        char* start_position = strchr(current_position, '\"');
        char* end_position = strchr(start_position + 1, '\"');
        if (start_position == NULL || end_position == NULL) {
            printf("Invalid JSON format\n");
            return;
        }

        *end_position = '\0';
        current_position = end_position + 1;

        // Looking for colon
        if (*current_position != ':') {
            printf("Invalid JSON format\n");
            return;
        }

        current_position++;

        // Looking for value
        start_position = strchr(current_position, '\"');
        end_position = strchr(start_position + 1, '\"');
        if (start_position == NULL || end_position == NULL) {
            printf("Invalid JSON format\n");
            return;
        }

        *end_position = '\0';
        current_position = end_position + 1;

        // Adding key-value pair to output
        json_key_value_pair pair;
        pair.key = start_position;
        pair.value = start_position + strlen(start_position) + 1;

        output->data = realloc(output->data, (output->size + 1) * sizeof(json_key_value_pair));
        output->data[output->size] = pair;
        output->size++;

        // Looking for comma or end of object
        if (*current_position == ',') {
            current_position++;
        }
    }
}

int main() {
    char* json_string = "{\"name\":\"John Doe\",\"age\":\"25\",\"city\":\"New York\"}";

    json_object output;
    output.data = NULL;
    output.size = 0;

    parse_json(json_string, &output);

    for (int i = 0; i < output.size; i++) {
        printf("%s: %s\n", output.data[i].key, output.data[i].value);
    }

    free(output.data);

    return 0;
}