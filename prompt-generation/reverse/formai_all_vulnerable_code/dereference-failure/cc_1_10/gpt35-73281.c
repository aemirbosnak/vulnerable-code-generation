//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LEN 256
#define DEFAULT_ARRAY_SIZE 10

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} json_type;

typedef struct json_value_t {
    json_type type;
    union {
        char *string_val;
        double number_val;
        int bool_val;
        struct json_value_t *array_val;
        struct json_pair_t *object_val;
    } value;
} json_value;

typedef struct json_pair_t {
    char *key;
    struct json_value_t *value;
} json_pair;

json_value *parse_json(char *input);
json_value *parse_object(char *input);
json_pair *parse_pair(char *input);
void parse_whitespace(char **input);
char *parse_string(char **input);
double parse_number(char **input);
int parse_bool(char **input);
void parse_null(char **input);
json_value **parse_array(char **input, int *size);
void free_json(json_value *json);

int main() {
    // Example usage:
    char input[] = "{\"name\": \"John Doe\", \"age\": 30, \"married\": true}";
    json_value *json = parse_json(input);
    printf("Name: %s\nAge: %.0f\nMarried: %s\n", json->value.object_val[0].value->value.string_val,
           json->value.object_val[1].value->value.number_val, json->value.object_val[2].value->value.bool_val ? "true" : "false");
    free_json(json);
    return 0;
}

json_value *parse_json(char *input) {
    parse_whitespace(&input);
    if (*input == '{') {
        return parse_object(input);
    } else if (*input == '[') {
        json_value *json = malloc(sizeof(json_value));
        json->type = JSON_ARRAY;
        json->value.array_val = (json_value *) malloc(DEFAULT_ARRAY_SIZE * sizeof(json_value));
        int count = 0;
        input++;
        parse_whitespace(&input);
        while (*input != ']') {
            if (count >= DEFAULT_ARRAY_SIZE) {
                json->value.array_val = (json_value *) realloc(json->value.array_val, count * sizeof(json_value) * 2);
            }
            json->value.array_val[count] = *parse_json(input++);
            count++;
            parse_whitespace(&input);
            if (*input == ',') {
                input++;
                parse_whitespace(&input);
            }
        }
        json->value.array_val = (json_value *) realloc(json->value.array_val, count * sizeof(json_value));
        return json;
    } else {
        printf("Invalid input!\n");
        exit(1);
    }
}

json_value *parse_object(char *input) {
    json_value *json = malloc(sizeof(json_value));
    json->type = JSON_OBJECT;
    json->value.object_val = (json_pair *) malloc(DEFAULT_ARRAY_SIZE * sizeof(json_pair));
    int count = 0;
    input++;
    parse_whitespace(&input);
    while (*input != '}') {
        if (count >= DEFAULT_ARRAY_SIZE) {
            json->value.object_val = (json_pair *) realloc(json->value.object_val, count * sizeof(json_pair) * 2);
        }
        json_pair *pair = parse_pair(input);
        json->value.object_val[count] = *pair;
        free(pair);
        count++;
        parse_whitespace(&input);
        if (*input == ',') {
            input++;
            parse_whitespace(&input);
        }
    }
    json->value.object_val = (json_pair *) realloc(json->value.object_val, count * sizeof(json_pair));
    return json;
}

json_pair *parse_pair(char *input) {
    json_pair *pair = malloc(sizeof(json_pair));
    pair->key = parse_string(&input);
    parse_whitespace(&input);
    if (*input != ':') {
        printf("Invalid input!\n");
        exit(1);
    }
    input++;
    parse_whitespace(&input);
    pair->value = parse_json(input);
    return pair;
}

void parse_whitespace(char **input) {
    while (**input && isspace(**input)) {
        (*input)++;
    }
}

char *parse_string(char **input) {
    char *output = malloc(MAX_STRING_LEN);
    int count = 0;
    input++;
    while (**input && **input != '\"' && count < MAX_STRING_LEN - 1) {
        if (**input == '\\') {
            input++;
            switch (**input) {
                case '\"':
                    output[count] = '\"';
                    break;
                case '\\':
                    output[count] = '\\';
                    break;
                case '/':
                    output[count] = '/';
                    break;
                case 'b':
                    output[count] = '\b';
                    break;
                case 'f':
                    output[count] = '\f';
                    break;
                case 'n':
                    output[count] = '\n';
                    break;
                case 'r':
                    output[count] = '\r';
                    break;
                case 't':
                    output[count] = '\t';
                    break;
                default:
                    printf("Invalid escape character!\n");
                    exit(1);
            }
        } else {
            output[count] = **input;
        }
        count++;
        (*input)++;
    }
    output[count] = '\0';
    return output;
}

double parse_number(char **input) {
    char *endptr;
    double result = strtod(*input, &endptr);
    *input = endptr;
    return result;
}

int parse_bool(char **input) {
    if (strncmp(*input, "true", 4) == 0) {
        *input += 4;
        return 1;
    } else if (strncmp(*input, "false", 5) == 0) {
        *input += 5;
        return 0;
    } else {
        printf("Invalid input!\n");
        exit(1);
    }
}

void parse_null(char **input) {
    if (strncmp(*input, "null", 4) != 0) {
        printf("Invalid input!\n");
        exit(1);
    }
    *input += 4;
}

json_value **parse_array(char **input, int *size) {
    json_value **array = malloc(DEFAULT_ARRAY_SIZE * sizeof(json_value *));
    int count = 0;
    input++;
    parse_whitespace(&input);
    while (**input != ']') {
        if (count >= DEFAULT_ARRAY_SIZE) {
            array = (json_value **) realloc(array, count * sizeof(json_value *) * 2);
        }
        array[count] = parse_json(input);
        count++;
        parse_whitespace(&input);
        if (**input == ',') {
            input++;
            parse_whitespace(&input);
        }
    }
    *size = count;
    array = (json_value **) realloc(array, count * sizeof(json_value *));
    return array;
}

void free_json(json_value *json) {
    if (json->type == JSON_OBJECT) {
        for (int i = 0; json->value.object_val[i].key; i++) {
            free(json->value.object_val[i].key);
            free_json(json->value.object_val[i].value);
        }
        free(json->value.object_val);
    } else if (json->type == JSON_ARRAY) {
        for (int i = 0; json->value.array_val[i].type != JSON_NULL; i++) {
            free_json(&json->value.array_val[i]);
        }
        free(json->value.array_val);
    } else if (json->type == JSON_STRING) {
        free(json->value.string_val);
    }
    free(json);
}