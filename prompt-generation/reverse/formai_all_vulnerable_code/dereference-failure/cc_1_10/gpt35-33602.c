//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum json_type {
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL
} json_type;

typedef struct json_value json_value;

struct json_value {
    json_type type;
    union {
        char *string_val;
        double number_val;
        struct {
            char **keys;
            json_value **values;
            size_t size;
        } object_val;
        struct {
            json_value **values;
            size_t size;
        } array_val;
        int boolean_val;
    };
};

json_value *json_parse(char *json);
json_value *parse_object(char *json, size_t *index);
json_value *parse_array(char *json, size_t *index);
json_value *parse_string(char *json, size_t *index);
json_value *parse_number(char *json, size_t *index);
json_value *parse_boolean(char *json, size_t *index);
json_value *parse_null(char *json, size_t *index);
void parse_whitespace(char *json, size_t *index);
char *parse_string_value(char *json, size_t *index);
char *next_key(char *json, size_t *index);
char *next_value(char *json, size_t *index);
void print_json(json_value *val);
void print_object(json_type type, void *val);
void print_array(size_t size, json_value **values);

int main() {
    char *json = "{ \"name\": \"John Doe\", "
                 "\"age\": 25, "
                 "\"married\": false, "
                 "\"hobbies\": [\"reading\", \"writing\", \"coding\"], "
                 "\"education\": {\"degree\": \"Masters\", \"field\": \"Computer Science\"} }";

    json_value *val = json_parse(json);
    print_json(val);
    free(val);
    return 0;
}

json_value *json_parse(char *json) {
    size_t index = 0;
    parse_whitespace(json, &index);
    if (json[index] == '{') {
        return parse_object(json, &index);
    } else if (json[index] == '[') {
        return parse_array(json, &index);
    }
    return NULL;
}

json_value *parse_object(char *json, size_t *index) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_TYPE_OBJECT;
    (*index)++;
    size_t size = 0;
    parse_whitespace(json, index);
    while (json[*index] && json[*index] != '}') {
        if (size > 0) {
            if (json[(*index)++] != ',') {
                printf("Invalid JSON syntax\n");
                free(val);
                return NULL;
            }
            parse_whitespace(json, index);
        }

        char *key = next_key(json, index);
        parse_whitespace(json, index);
        if (json[*index] == ':') {
            (*index)++;
            parse_whitespace(json, index);
            json_value *value = parse_object(json, index);
            if (value == NULL) {
                printf("Invalid JSON syntax\n");
                free(val);
                free(key);
                return NULL;
            }
            size++;
            val->object_val.keys = realloc(val->object_val.keys, size * sizeof(char *));
            val->object_val.values = realloc(val->object_val.values, size * sizeof(json_value *));
            val->object_val.keys[size - 1] = key;
            val->object_val.values[size - 1] = value;
        } else {
            printf("Invalid JSON syntax\n");
            free(val);
            free(key);
            return NULL;
        }
    }
    (*index)++;
    val->object_val.size = size;
    return val;
}

json_value *parse_array(char *json, size_t *index) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_TYPE_ARRAY;
    (*index)++;
    size_t size = 0;
    parse_whitespace(json, index);
    while (json[*index] && json[*index] != ']') {
        if (size > 0) {
            if (json[(*index)++] != ',') {
                printf("Invalid JSON syntax\n");
                free(val);
                return NULL;
            }
            parse_whitespace(json, index);
        }

        json_value *value = parse_object(json, index);
        if (value == NULL) {
            printf("Invalid JSON syntax\n");
            free(val);
            return NULL;
        }
        size++;
        val->array_val.values = realloc(val->array_val.values, size * sizeof(json_value *));
        val->array_val.values[size - 1] = value;
        parse_whitespace(json, index);
    }
    (*index)++;
    val->array_val.size = size;
    return val;
}

json_value *parse_string(char *json, size_t *index) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_TYPE_STRING;
    val->string_val = parse_string_value(json, index);
    return val;
}

char *parse_string_value(char *json, size_t *index) {
    char *str = malloc(1);
    size_t size = 0;
    (*index)++;
    while (json[*index] && json[*index] != '\"') {
        if (json[*index] == '\\') {
            (*index)++;
        }
        size++;
        str = realloc(str, size + 1);
        str[size - 1] = json[*index];
        (*index)++;
    }
    str[size] = '\0';
    (*index)++;
    return str;
}

json_value *parse_number(char *json, size_t *index) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_TYPE_NUMBER;
    char *end;
    val->number_val = strtod(json + *index, &end);
    *index += end - (json + *index);
    return val;
}

json_value *parse_boolean(char *json, size_t *index) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_TYPE_BOOLEAN;
    if (strncmp(json + *index, "true", 4) == 0) {
        val->boolean_val = 1;
        *index += 4;
    } else if (strncmp(json + *index, "false", 5) == 0) {
        val->boolean_val = 0;
        *index += 5;
    } else {
        free(val);
        return NULL;
    }
    return val;
}

json_value *parse_null(char *json, size_t *index) {
    json_value *val = malloc(sizeof(json_value));
    val->type = JSON_TYPE_NULL;
    if (strncmp(json + *index, "null", 4) == 0) {
        *index += 4;
    } else {
        free(val);
        return NULL;
    }
    return val;
}

void parse_whitespace(char *json, size_t *index) {
    while (json[*index] && (json[*index] == ' ' || json[*index] == '\n' || json[*index] == '\t' || json[*index] == '\r')) {
        (*index)++;
    }
}

char *next_key(char *json, size_t *index) {
    return parse_string_value(json, index);
}

char *next_value(char *json, size_t *index) {
    char *value = malloc(1);
    size_t size = 0;
    while (json[*index] && json[*index] != ',' && json[*index] != '}') {
        size++;
        value = realloc(value, size + 1);
        value[size - 1] = json[*index];
        (*index)++;
    }
    value[size] = '\0';
    return value;
}

void print_json(json_value *val) {
    if (val->type == JSON_TYPE_OBJECT) {
        print_object(val->type, &(val->object_val));
    } else if (val->type == JSON_TYPE_ARRAY) {
        print_array(val->array_val.size, val->array_val.values);
    } else if (val->type == JSON_TYPE_STRING) {
        printf("\"%s\"\n", val->string_val);
    } else if (val->type == JSON_TYPE_NUMBER) {
        printf("%f\n", val->number_val);
    } else if (val->type == JSON_TYPE_BOOLEAN) {
        printf("%s\n", val->boolean_val ? "true" : "false");
    } else {
        printf("null\n");
    }
}

void print_object(json_type type, void *val) {
    printf("{\n");
    json_value **values = ((struct { char **keys; json_value **values; size_t size; }*)val)->values;
    char **keys = ((struct { char **keys; json_value **values; size_t size; }*)val)->keys;
    size_t size = ((struct { char **keys; json_value **values; size_t size; }*)val)->size;
    for (size_t i = 0; i < size; i++) {
        printf("\"%s\": ", keys[i]);
        print_json(values[i]);
    }
    printf("}\n");
}

void print_array(size_t size, json_value **values) {
    printf("[\n");
    for (size_t i = 0; i < size; i++) {
        print_json(values[i]);
    }
    printf("]\n");
}