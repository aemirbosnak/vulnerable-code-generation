//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct json_value json_value;

struct json_value {
    json_type type;
    union {
        char *string_value;
        double number_value;
        struct {
            char **keys;
            json_value **values;
            size_t size;
        } object_value;
        struct {
            json_value **values;
            size_t size;
        } array_value;
    } value;
};

char *parse_string(char *json, size_t *index);
double parse_number(char *json, size_t *index);
json_value *parse_object(char *json, size_t *index);
json_value *parse_array(char *json, size_t *index);
json_value *parse_value(char *json, size_t *index);

char *parse_string(char *json, size_t *index) {
    char *string = NULL;
    size_t length = 0;
    int escaped = 0;
    (*index)++;
    while (json[*index] != '\0') {
        if (json[*index] == '\\' && !escaped) {
            escaped = 1;
        } else if (json[*index] == '"' && !escaped) {
            (*index)++;
            string[length] = '\0';
            return string;
        } else {
            escaped = 0;
            string = realloc(string, length + 1);
            string[length++] = json[*index];
        }
        (*index)++;
    }
    return NULL;
}

double parse_number(char *json, size_t *index) {
    char *end;
    double number = strtod(json + *index, &end);
    *index += end - (json + *index);
    return number;
}

json_value *parse_object(char *json, size_t *index) {
    json_value *object = malloc(sizeof(json_value));
    object->type = JSON_OBJECT;
    object->value.object_value.keys = NULL;
    object->value.object_value.values = NULL;
    object->value.object_value.size = 0;
    (*index)++;
    while (json[*index] != '\0') {
        if (json[*index] == '}') {
            (*index)++;
            return object;
        } else if (json[*index] == ',') {
            (*index)++;
        } else {
            char *key = parse_string(json, index);
            object->value.object_value.keys = realloc(object->value.object_value.keys, (object->value.object_value.size + 1) * sizeof(char *));
            object->value.object_value.keys[object->value.object_value.size] = key;
            while (json[*index] != ':') (*index)++;
            (*index)++;
            json_value *value = parse_value(json, index);
            object->value.object_value.values = realloc(object->value.object_value.values, (object->value.object_value.size + 1) * sizeof(json_value *));
            object->value.object_value.values[object->value.object_value.size] = value;
            object->value.object_value.size++;
        }
    }
    free(object);
    return NULL;
}

json_value *parse_array(char *json, size_t *index) {
    json_value *array = malloc(sizeof(json_value));
    array->type = JSON_ARRAY;
    array->value.array_value.values = NULL;
    array->value.array_value.size = 0;
    (*index)++;
    while (json[*index] != '\0') {
        if (json[*index] == ']') {
            (*index)++;
            return array;
        } else if (json[*index] == ',') {
            (*index)++;
        } else {
            json_value *value = parse_value(json, index);
            array->value.array_value.values = realloc(array->value.array_value.values, (array->value.array_value.size + 1) * sizeof(json_value *));
            array->value.array_value.values[array->value.array_value.size] = value;
            array->value.array_value.size++;
        }
    }
    free(array);
    return NULL;
}

json_value *parse_value(char *json, size_t *index) {
    json_value *value = malloc(sizeof(json_value));
    switch (json[*index]) {
        case '"' :
            value->type = JSON_STRING;
            value->value.string_value = parse_string(json, index);
            break;
        case '-' :
        case '0' ... '9' :
            value->type = JSON_NUMBER;
            value->value.number_value = parse_number(json, index);
            break;
        case '{' :
            value = parse_object(json, index);
            break;
        case '[' :
            value = parse_array(json, index);
            break;
        case 't' :
            value->type = JSON_TRUE;
            (*index) += 4;
            break;
        case 'f' :
            value->type = JSON_FALSE;
            (*index) += 5;
            break;
        case 'n' :
            value->type = JSON_NULL;
            (*index) += 4;
            break;
        default :
            free(value);
            return NULL;
    }
    return value;
}

int main(int argc, char *argv[]) {
    char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"isAdmin\": false, \"favoriteFoods\": [ \"Pizza\", \"Tacos\", \"Burgers\" ], \"address\": { \"street\": \"123 Main St\", \"city\": \"Anytown\", \"state\": \"TX\", \"zip\": \"12345\" } }";
    size_t index = 0;
    json_value *value = parse_value(json, &index);
    printf("The name is %s and they are %f years old.\n", value->value.object_value.values[0]->value.string_value, value->value.object_value.values[1]->value.number_value);
    printf("They live in %s, %s, %s %s.\n", value->value.object_value.values[4]->value.object_value.values[0]->value.string_value, value->value.object_value.values[4]->value.object_value.values[1]->value.string_value, value->value.object_value.values[4]->value.object_value.values[2]->value.string_value, value->value.object_value.values[4]->value.object_value.values[3]->value.string_value);
    printf("Their favorite foods are %s, %s, and %s.\n", value->value.object_value.values[3]->value.array_value.values[0]->value.string_value, value->value.object_value.values[3]->value.array_value.values[1]->value.string_value, value->value.object_value.values[3]->value.array_value.values[2]->value.string_value);
    free(value);
    return 0;
}