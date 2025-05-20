//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_JSON_DEPTH 50

typedef enum Type {
    INTEGER,
    STRING,
    ARRAY,
    OBJECT
} Type;

typedef struct Value {
    Type type;
    union {
        int integer_value;
        char string_value[MAX_STRING_LENGTH];
        struct Value *array_value;
        struct Object *object_value;
    } data;
} Value;

typedef struct Object {
    char key[MAX_STRING_LENGTH];
    Value value;
} Object;

char *json_string;
int json_index = 0;
int json_depth = 0;

void parse_object(Object *object);
void parse_array(Value *array);

void parse_string(char *string) {
    char current_char = json_string[json_index++];
    int string_index = 0;

    while (current_char != '\"' && string_index < MAX_STRING_LENGTH - 1) {
        string[string_index++] = current_char;
        current_char = json_string[json_index++];
    }

    string[string_index] = '\0';
}

void parse_integer(int *integer) {
    char current_char = json_string[json_index++];
    int integer_value = 0;
    int sign = 1;

    if (current_char == '-') {
        sign = -1;
        current_char = json_string[json_index++];
    }

    while (current_char >= '0' && current_char <= '9') {
        integer_value = integer_value * 10 + (current_char - '0');
        current_char = json_string[json_index++];
    }

    *integer = sign * integer_value;
}

void parse_value(Value *value) {
    char current_char = json_string[json_index++];

    switch (current_char) {
        case '{':
            value->type = OBJECT;
            value->data.object_value = malloc(sizeof(Object));
            parse_object(value->data.object_value);
            break;

        case '[':
            value->type = ARRAY;
            value->data.array_value = malloc(sizeof(Value));
            parse_array(value->data.array_value);
            break;

        case '\"':
            value->type = STRING;
            parse_string(value->data.string_value);
            break;

        default:
            if (current_char >= '0' && current_char <= '9') {
                json_index--;
                value->type = INTEGER;
                parse_integer(&value->data.integer_value);
            }
            break;
    }
}

void parse_object(Object *object) {
    json_depth++;
    if (json_depth > MAX_JSON_DEPTH) {
        printf("Error: JSON depth too large.\n");
        exit(1);
    }

    char current_char = json_string[json_index++];
    while (current_char != '}') {
        if (current_char == '\"') {
            parse_string(object->key);
        }
        else if (current_char == ':') {
            parse_value(&object->value);
        }

        current_char = json_string[json_index++];
        if (current_char == ',') {
            current_char = json_string[json_index++];
        }
    }
    json_depth--;
}

void parse_array(Value *array) {
    json_depth++;
    if (json_depth > MAX_JSON_DEPTH) {
        printf("Error: JSON depth too large.\n");
        exit(1);
    }

    char current_char = json_string[json_index++];
    int i = 0;
    while (current_char != ']') {
        parse_value(&array[i++]);
        current_char = json_string[json_index++];
        if (current_char == ',') {
            current_char = json_string[json_index++];
        }
    }

    array[i].type = INTEGER;
    array[i].data.integer_value = -1;
    json_depth--;
}

int main() {
    json_string = "{\"name\": \"John Doe\", \"age\": 30, \"friends\": [\"Jane\", \"Bob\", \"Anna\"]}";
    Value root_value;
    Object root_object;

    json_index = 0;
    parse_value(&root_value);

    if (root_value.type == OBJECT) {
        root_object.key[0] = '\0';
        root_object.value = root_value;
    }

    printf("Name: %s\n", root_object.value.data.object_value[0].value.data.string_value);
    printf("Age: %d\n", root_object.value.data.object_value[1].value.data.integer_value);

    Value *friends_array = root_object.value.data.object_value[2].value.data.array_value;
    printf("Friends: ");
    for (int i = 0; friends_array[i].type != INTEGER; i++) {
        printf("%s ", friends_array[i].data.string_value);
    }
    printf("\n");

    return 0;
}