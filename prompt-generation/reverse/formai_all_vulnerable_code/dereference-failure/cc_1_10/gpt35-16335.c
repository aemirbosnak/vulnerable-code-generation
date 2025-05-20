//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_value_type;

typedef struct {
    json_value_type type;
    void *value;
} json_value;

typedef struct {
    char *data;
    int position;
} json_parser;

char *json_strip_whitespace(char *string);
json_value *json_parse_value(json_parser *parser);
json_value *json_parse_object(json_parser *parser);
json_value *json_parse_array(json_parser *parser);
json_value *json_parse_string(json_parser *parser);
json_value *json_parse_number(json_parser *parser);
long json_parse_long(json_parser *parser);
double json_parse_double(json_parser *parser);
char *json_parse_string_data(json_parser *parser);
char json_peek(json_parser *parser);
char json_pop(json_parser *parser);

char *json_strip_whitespace(char *string) {
    int length = strlen(string);
    char *output = (char *) malloc(sizeof(char) * length + 1);

    int j = 0;

    for (int i = 0; i < length; i++) {
        if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t' && string[i] != '\r') {
            output[j] = string[i];
            j++;
        }
    }

    output[j] = 0;

    return output;
}

json_value *json_parse_value(json_parser *parser) {
    char c = json_peek(parser);

    if (c == '{') {
        return json_parse_object(parser);
    } else if (c == '[') {
        return json_parse_array(parser);
    } else if (c == '"') {
        return json_parse_string(parser);
    } else if (c >= '0' && c <= '9') {
        return json_parse_number(parser);
    } else if (c == 't') {
        char *expected = "true";
        for (int i = 0; i < 4; i++) {
            if (json_pop(parser) != expected[i]) {
                printf("Error: Expected '%c' got '%c'\n", expected[i], c);
                exit(1);
            }
        }
        json_value *value = (json_value *) malloc(sizeof(json_value));
        value->type = JSON_TRUE;
        value->value = (int *) malloc(sizeof(int));
        *(int *) value->value = 1;
        return value;
    } else if (c == 'f') {
        char *expected = "false";
        for (int i = 0; i < 5; i++) {
            if (json_pop(parser) != expected[i]) {
                printf("Error: Expected '%c' got '%c'\n", expected[i], c);
                exit(1);
            }
        }
        json_value *value = (json_value *) malloc(sizeof(json_value));
        value->type = JSON_FALSE;
        value->value = (int *) malloc(sizeof(int));
        *(int *) value->value = 0;
        return value;
    } else if (c == 'n') {
        char *expected = "null";
        for (int i = 0; i < 4; i++) {
            if (json_pop(parser) != expected[i]) {
                printf("Error: Expected '%c' got '%c'\n", expected[i], c);
                exit(1);
            }
        }
        json_value *value = (json_value *) malloc(sizeof(json_value));
        value->type = JSON_NULL;
        value->value = (void *) NULL;
        return value;
    } else {
        printf("Error: Unexpected character '%c'\n", c);
        exit(1);
    }
}

json_value *json_parse_object(json_parser *parser) {
    // Your code here
}

json_value *json_parse_array(json_parser *parser) {
    // Your code here
}

json_value *json_parse_string(json_parser *parser) {
    // Your code here
}

json_value *json_parse_number(json_parser *parser) {
    // Your code here
}

long json_parse_long(json_parser *parser) {
    // Your code here
}

double json_parse_double(json_parser *parser) {
    // Your code here
}

char *json_parse_string_data(json_parser *parser) {
    // Your code here
}

char json_peek(json_parser *parser) {
    // Your code here
}

char json_pop(json_parser *parser) {
    // Your code here
}

int main() {
    json_parser parser;
    parser.data = "{\"name\": \"John\", \"age\": 25}";
    parser.position = 0;

    json_value *value = json_parse_object(&parser);

    printf("Type: %d\n", value->type);

    return 0;
}