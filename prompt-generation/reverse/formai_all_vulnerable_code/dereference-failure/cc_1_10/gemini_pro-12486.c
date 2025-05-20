//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} JSONKeyValuePair;

typedef struct {
    JSONKeyValuePair *pairs;
    int num_pairs;
} JSONObject;

static int parse_string(char *input, char **output) {
    int length = strlen(input);
    if (length < 2 || input[0] != '"' || input[length - 1] != '"') {
        return -1;
    }
    *output = malloc(length - 1);
    memcpy(*output, input + 1, length - 2);
    (*output)[length - 2] = '\0';
    return 0;
}

static int parse_key_value_pair(char *input, JSONKeyValuePair *output) {
    char *delimiter = strchr(input, ':');
    if (delimiter == NULL) {
        return -1;
    }
    *delimiter = '\0';
    if (parse_string(input, &output->key) != 0) {
        free(input);
        return -1;
    }
    if (parse_string(delimiter + 1, &output->value) != 0) {
        free(input);
        free(output->key);
        return -1;
    }
    free(input);
    return 0;
}

static int parse_object(char *input, JSONObject *output) {
    char *current_char = input;
    output->num_pairs = 0;
    while (*current_char != '\0') {
        if (*current_char == '{') {
            current_char++;
            while (*current_char != '}') {
                JSONKeyValuePair pair;
                if (parse_key_value_pair(current_char, &pair) != 0) {
                    free(input);
                    free(output->pairs);
                    return -1;
                }
                output->pairs = realloc(output->pairs, (output->num_pairs + 1) * sizeof(JSONKeyValuePair));
                output->pairs[output->num_pairs++] = pair;
                current_char += strlen(pair.key) + strlen(pair.value) + 2;
            }
            current_char++;
        } else {
            current_char++;
        }
    }
    return 0;
}

static void print_key_value_pair(JSONKeyValuePair pair) {
    printf("  \"%s\": \"%s\"\n", pair.key, pair.value);
}

static void print_object(JSONObject object) {
    printf("{\n");
    for (int i = 0; i < object.num_pairs; i++) {
        print_key_value_pair(object.pairs[i]);
    }
    printf("}\n");
}

int main() {
    char input[JSON_MAX_LENGTH];
    printf("Enter a JSON object:\n");
    fgets(input, JSON_MAX_LENGTH, stdin);

    JSONObject object;
    if (parse_object(input, &object) != 0) {
        printf("Error parsing JSON object.\n");
        return 1;
    }

    print_object(object);

    for (int i = 0; i < object.num_pairs; i++) {
        free(object.pairs[i].key);
        free(object.pairs[i].value);
    }
    free(object.pairs);

    return 0;
}