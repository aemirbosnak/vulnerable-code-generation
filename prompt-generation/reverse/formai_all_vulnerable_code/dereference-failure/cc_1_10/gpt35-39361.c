//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_OBJECTS 1024

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type_t;

typedef struct JSON_Object JSON_Object;
typedef struct JSON_Array JSON_Array;

struct JSON_Object {
    char *key;
    json_type_t type;
    void *value;
};

struct JSON_Array {
    json_type_t type;
    void **values;
    int num_values;
};

void *parse_json(char *json_str);
JSON_Object *parse_object(char **json_str);
JSON_Array *parse_array(char **json_str);
char *parse_string(char **json_str);
double parse_number(char **json_str);
int parse_boolean(char **json_str);
void parse_null(char **json_str);
void parse_whitespace(char **json_str);

int main(void) {
    char *json_str = "{ \"name\": \"John\", \"age\": 30, \"isMarried\": false, \"hobbies\": [\"Reading\", \"Gaming\", \"Cooking\"] }";
    JSON_Object *root = parse_object(&json_str);
    printf("Parsed root JSON object:\n");
    printf("name: %s\n", (char*)root->value);
    printf("age: %.0f\n", *((double*) root->value + 1));
    printf("isMarried: %d\n", *((int*) root->value + 1));
    printf("hobbies: ");
    JSON_Array *hobbies = (JSON_Array*) root->value + 2;
    for (int i = 0; i < hobbies->num_values; i++) {
        printf("%s", (char*)*(hobbies->values + i));
        if (i != hobbies->num_values - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}

void *parse_json(char *json_str) {
    return parse_object(&json_str);
}

JSON_Object *parse_object(char **json_str) {
    parse_whitespace(json_str);
    if (**json_str != '{') {
        fprintf(stderr, "Error: not a valid JSON object\n");
        exit(1);
    }

    JSON_Object *new_object = malloc(sizeof(JSON_Object));
    new_object->key = NULL;
    new_object->type = JSON_OBJECT;
    JSON_Object **objects = malloc(sizeof(JSON_Object*) * MAX_JSON_OBJECTS);
    void **values = malloc(sizeof(void*) * MAX_JSON_OBJECTS);
    int num_objects = 0;
    int num_values = 0;

    (*json_str)++;
    parse_whitespace(json_str);
    while (**json_str != '}') {
        JSON_Object *new_property = malloc(sizeof(JSON_Object));
        char *key = parse_string(json_str);
        new_property->key = key;

        parse_whitespace(json_str);
        if (**json_str != ':') {
            fprintf(stderr, "Error: not a valid JSON object\n");
            exit(1);
        }

        (*json_str)++;
        parse_whitespace(json_str);
        if (**json_str == '{') {
            JSON_Object *value = parse_object(json_str);
            new_property->type = JSON_OBJECT;
            new_property->value = value;
            objects[num_objects++] = new_property;
            values[num_values++] = value;
        } else if (**json_str == '[') {
            JSON_Array *value = parse_array(json_str);
            new_property->type = JSON_ARRAY;
            new_property->value = value;
            values[num_values++] = value;
        } else if (**json_str == '"') {
            char *value = parse_string(json_str);
            new_property->type = JSON_STRING;
            new_property->value = value;
            values[num_values++] = value;
        } else if ((**json_str >= '0' && **json_str <= '9') || **json_str == '-') {
            double value = parse_number(json_str);
            new_property->type = JSON_NUMBER;
            void *value_ptr = malloc(sizeof(double));
            memcpy(value_ptr, &value, sizeof(double));
            new_property->value = value_ptr;
            values[num_values++] = value_ptr;
        } else if (**json_str == 't' || **json_str == 'f') {
            int value = parse_boolean(json_str);
            new_property->type = JSON_BOOLEAN;
            void *value_ptr = malloc(sizeof(int));
            memcpy(value_ptr, &value, sizeof(int));
            new_property->value = value_ptr;
            values[num_values++] = value_ptr;
        } else if (**json_str == 'n') {
            parse_null(json_str);
            new_property->type = JSON_NULL;
            new_property->value = NULL;
        } else {
            fprintf(stderr, "Error: not a valid JSON object\n");
            exit(1);
        }

        parse_whitespace(json_str);
        if (**json_str == ',') {
            (*json_str)++;
            parse_whitespace(json_str);
        } else if (**json_str != '}') {
            fprintf(stderr, "Error: not a valid JSON object\n");
            exit(1);
        }
    }

    (*json_str)++;
    JSON_Object **trimmed_objects = realloc(objects, sizeof(JSON_Object*) * num_objects);
    void **trimmed_values = realloc(values, sizeof(void*) * num_values);
    new_object->value = malloc(sizeof(JSON_Object*) * (num_objects + num_values));
    memcpy(new_object->value, trimmed_objects, sizeof(JSON_Object*) * num_objects);
    memcpy(new_object->value + num_objects, trimmed_values, sizeof(void*) * num_values);
    free(trimmed_objects);
    free(trimmed_values);

    return new_object;
}

JSON_Array *parse_array(char **json_str) {
    parse_whitespace(json_str);
    if (**json_str != '[') {
        fprintf(stderr, "Error: not a valid JSON array\n");
        exit(1);
    }

    JSON_Array *new_array = malloc(sizeof(JSON_Array));
    new_array->type = JSON_ARRAY;
    void **values = malloc(sizeof(void*) * MAX_JSON_OBJECTS);
    int num_values = 0;

    (*json_str)++;
    parse_whitespace(json_str);
    while (**json_str != ']') {
        void *value;

        parse_whitespace(json_str);
        if (**json_str == '{') {
            value = parse_object(json_str);
        } else if (**json_str == '[') {
            value = parse_array(json_str);
        } else if (**json_str == '"') {
            value = parse_string(json_str);
        } else if ((**json_str >= '0' && **json_str <= '9') || **json_str == '-') {
            double number = parse_number(json_str);
            void *number_ptr = malloc(sizeof(double));
            memcpy(number_ptr, &number, sizeof(double));
            value = number_ptr;
        } else if (**json_str == 't' || **json_str == 'f') {
            int boolean = parse_boolean(json_str);
            void *boolean_ptr = malloc(sizeof(int));
            memcpy(boolean_ptr, &boolean, sizeof(int));
            value = boolean_ptr;
        } else if (**json_str == 'n') {
            parse_null(json_str);
            value = NULL;
        } else {
            fprintf(stderr, "Error: not a valid JSON array\n");
            exit(1);
        }

        parse_whitespace(json_str);
        if (**json_str == ',') {
            (*json_str)++;
            parse_whitespace(json_str);
        } else if (**json_str != ']') {
            fprintf(stderr, "Error: not a valid JSON array\n");
            exit(1);
        }

        values[num_values++] = value;
    }

    (*json_str)++;
    void **trimmed_values = realloc(values, sizeof(void*) * num_values);
    new_array->num_values = num_values;
    new_array->values = malloc(sizeof(void*) * num_values);
    memcpy(new_array->values, trimmed_values, sizeof(void*) * num_values);
    free(trimmed_values);

    return new_array;
}

char *parse_string(char **json_str) {
    parse_whitespace(json_str);
    if (**json_str != '"') {
        fprintf(stderr, "Error: not a valid JSON string\n");
        exit(1);
    }

    char *new_string = malloc(sizeof(char) * 1024);
    int i = 0;

    (*json_str)++;
    while (**json_str != '"') {
        if (i >= 1023) {
            fprintf(stderr, "Error: JSON string too long (max length 1024)\n");
            exit(1);
        }

        if (**json_str == '\\') {
            (*json_str)++;
            switch (**json_str) {
                case 'n':
                    *(new_string + i++) = '\n';
                    break;
                case 'r':
                    *(new_string + i++) = '\r';
                    break;
                case 't':
                    *(new_string + i++) = '\t';
                    break;
                case 'b':
                    *(new_string + i++) = '\b';
                    break;
                case 'f':
                    *(new_string + i++) = '\f';
                    break;
                case '\\':
                    *(new_string + i++) = '\\';
                    break;
                case '/':
                    *(new_string + i++) = '/';
                    break;
                case '\"':
                    *(new_string + i++) = '\"';
                    break;
                default:
                    fprintf(stderr, "Error: invalid JSON string escape character\n");
                    exit(1);
            }
        } else {
            *(new_string + i++) = **json_str;
        }

        (*json_str)++;
    }

    (*json_str)++;
    *(new_string + i) = '\0';

    return new_string;
}

double parse_number(char **json_str) {
    parse_whitespace(json_str);
    char *endptr;
    double parsed_number = strtod(*json_str, &endptr);
    if (*json_str == endptr) {
        fprintf(stderr, "Error: not a valid JSON number\n");
        exit(1);
    }
    *json_str = endptr;
    return parsed_number;
}

int parse_boolean(char **json_str) {
    parse_whitespace(json_str);
    char *endptr = *json_str;
    if (strncmp(*json_str, "true", 4) == 0) {
        endptr += 4;
        *json_str = endptr;
        return 1;
    } else if (strncmp(*json_str, "false", 5) == 0) {
        endptr += 5;
        *json_str = endptr;
        return 0;
    } else {
        fprintf(stderr, "Error: not a valid JSON boolean\n");
        exit(1);
    }
}

void parse_null(char **json_str) {
    parse_whitespace(json_str);
    if (strncmp(*json_str, "null", 4) != 0) {
        fprintf(stderr, "Error: not a valid JSON null\n");
        exit(1);
    }
    *json_str += 4;
}

void parse_whitespace(char **json_str) {
    while (**json_str == ' ' || **json_str == '\t' || **json_str == '\n' || **json_str == '\r') {
        (*json_str)++;
    }
}