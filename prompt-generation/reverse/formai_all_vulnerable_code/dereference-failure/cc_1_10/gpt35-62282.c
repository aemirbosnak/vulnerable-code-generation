//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL
} json_type_t;

typedef struct {
    json_type_t type;
    union {
        char *string_value;
        double number_value;
        struct {
            char **keys;
            void **values;
            int size;
        } object_value;
        struct {
            void **values;
            int size;
        } array_value;
        int boolean_value;
    } data;
} json_value_t;

json_value_t *parse_json_string(char *json_string);

json_value_t *parse_json_number(char *json_string);

json_value_t *parse_json_boolean(char *json_string);

json_value_t *parse_json_null(char *json_string);

json_value_t *parse_json_object(char *json_string);

json_value_t *parse_json_array(char *json_string);

char *get_value(char *json_string);

char *get_key(char *json_string);

void skip_white_space(char **p_str);

char *get_object(char **p_str);

char *get_array(char **p_str);

char *get_string(char **p_str);

int main() {
    char *json_string = "{\"name\":\"John\",\"age\":30,\"car\":{\"make\":\"Toyota\",\"model\": \"Camry\"},\"pets\":[\"dog\",\"cat\",\"bird\"],\"isMarried\": true,\"address\": null}";
    json_value_t *root_object = parse_json_string(json_string);
    printf("Root type: %d\n", root_object->type);
    printf("Root object size: %d\n", root_object->data.object_value.size);
    for(int i=0; i<root_object->data.object_value.size; i++) {
        printf("Key: %s, Value Type: %d\n", root_object->data.object_value.keys[i], ((json_value_t *)root_object->data.object_value.values[i])->type);
    }
    return 0;
}

json_value_t *parse_json_string(char *json_string) {
    json_value_t *json_value = NULL;
    skip_white_space(&json_string);
    if(json_string[0] == '{') {
        json_value = parse_json_object(json_string);
    }
    return json_value;
}

json_value_t *parse_json_number(char *json_string) {
    json_value_t *json_value = (json_value_t *)malloc(sizeof(json_value_t));
    json_value->type = JSON_TYPE_NUMBER;
    json_value->data.number_value = strtod(json_string, NULL);
    return json_value;
}

json_value_t *parse_json_boolean(char *json_string) {
    json_value_t *json_value = (json_value_t *)malloc(sizeof(json_value_t));
    json_value->type = JSON_TYPE_BOOLEAN;
    if(strncmp(json_string, "true", 4) == 0) {
        json_value->data.boolean_value = 1;
    }
    else if(strncmp(json_string, "false", 5) == 0) {
        json_value->data.boolean_value = 0;
    }
    return json_value;
}

json_value_t *parse_json_null(char *json_string) {
    json_value_t *json_value = (json_value_t *)malloc(sizeof(json_value_t));
    json_value->type = JSON_TYPE_NULL;
    return json_value;
}

json_value_t *parse_json_object(char *json_string) {
    json_value_t *json_value = (json_value_t *)malloc(sizeof(json_value_t));
    json_value->type = JSON_TYPE_OBJECT;
    json_value->data.object_value.size = 8;
    json_value->data.object_value.keys = (char **)malloc(sizeof(char *) * json_value->data.object_value.size);
    json_value->data.object_value.values = (void **)malloc(sizeof(void *) * json_value->data.object_value.size);
    int index = 0;  
    json_string++;
    skip_white_space(&json_string);
    while(json_string[0] != '}') {
        json_value_t *key_value = parse_json_string(json_string);
        json_value->data.object_value.keys[index] = key_value->data.string_value;
        json_string = get_value(json_string);
        json_value_t *value = parse_json_string(json_string);
        json_value->data.object_value.values[index] = value;
        skip_white_space(&json_string);
        if(json_string[0] == ',') {
            json_string++;
            skip_white_space(&json_string);
            index++;
        }
    }
    return json_value;
}

json_value_t *parse_json_array(char *json_string) {
    json_value_t *json_value = (json_value_t *)malloc(sizeof(json_value_t));
    json_value->type = JSON_TYPE_ARRAY;
    json_string = get_array(&json_string);
    json_value->data.array_value.size = 4;
    json_value->data.array_value.values = (void **)malloc(sizeof(void *) * json_value->data.array_value.size);
    int index = 0;
    skip_white_space(&json_string);
    while(json_string[0] != ']') {
        json_value_t *value = parse_json_string(json_string);
        json_value->data.array_value.values[index] = value;
        skip_white_space(&json_string);
        if(json_string[0] == ',') {
            json_string++;
            skip_white_space(&json_string);
            index++;
        }
    }
    return json_value;
}

char *get_value(char *json_string) {
    skip_white_space(&json_string);
    int count = 0;
    while(json_string[count] != ':') {
        count++;
    }
    return json_string + count + 1;
}

char *get_key(char *json_string) {
    skip_white_space(&json_string);
    int count = 0;
    while(json_string[count] != '\"') {
        count++;
    }
    return json_string + count + 1;
}

void skip_white_space(char **p_str) {
    while((*p_str)[0] == ' ' || (*p_str)[0] == '\t' || (*p_str)[0] == '\n' || (*p_str)[0] == '\r') {
        (*p_str)++;
    }
}

char *get_object(char **p_str) {
    skip_white_space(p_str);
    int count = 0;
    while((*p_str)[count] != '}') {
        count++;
    }
    count++;
    return *p_str + count;
}

char *get_array(char **p_str) {
    skip_white_space(p_str);
    int count = 0;
    while((*p_str)[count] != ']') {
        count++;
    }
    count++;
    return *p_str + count;
}

char *get_string(char **p_str) {
    char *string = NULL;
    skip_white_space(p_str);
    int count = 1;
    while((*p_str)[count] != '\"') {
        count++;
    }
    string = (char *)malloc(sizeof(char) * count);
    strncpy(string, (*p_str) + 1, count - 1);
    string[count - 1] = '\0';
    count++;
    return *p_str + count;
}