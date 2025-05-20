//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_TYPE_NUMBER,
    JSON_TYPE_STRING,
    JSON_TYPE_ARRAY,
    JSON_TYPE_OBJECT,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL,
    JSON_TYPE_INVALID
} json_type_t;

typedef struct json_value {
    json_type_t type;
    union {
        double number;
        char *string;
        struct json_value *array;
        struct json_object *object;
        int boolean;
    } value;
} json_value_t;

typedef struct json_object {
    char *name;
    json_value_t *value;
    struct json_object *next;
} json_object_t;

void parse_object(json_value_t *parent, char **json_str);
void parse_array(json_value_t *parent, char **json_str);
void parse_string(json_value_t *parent, char **json_str);
void parse_number(json_value_t *parent, char **json_str);
void parse_boolean(json_value_t *parent, char **json_str);
void parse_null(json_value_t *parent, char **json_str);

json_value_t *parse_json(char *json_str) {
    json_value_t *root = (json_value_t *) malloc(sizeof(json_value_t));
    char **json_ptr = &json_str;
    memset(root, 0, sizeof(json_value_t));
    parse_object(root, json_ptr);
    return root;
}

void parse_object(json_value_t *parent, char **json_str) {
    json_object_t *obj = NULL;
    char *name = NULL;
    json_value_t *val = NULL;
    while (**json_str != '}' && **json_str != '\0') {
        // find property name
        parse_string(parent, json_str);
        name = strdup(parent->value.string);
        // skip over colon
        (*json_str)++;
        // find property value
        switch (**json_str) {
            case '{':
                val = (json_value_t *) malloc(sizeof(json_value_t));
                memset(val, 0, sizeof(json_value_t));
                val->type = JSON_TYPE_OBJECT;
                parse_object(val, json_str);
                break;
            case '[':
                val = (json_value_t *) malloc(sizeof(json_value_t));
                memset(val, 0, sizeof(json_value_t));
                val->type = JSON_TYPE_ARRAY;
                parse_array(val, json_str);
                break;
            case '\"':
                val = (json_value_t *) malloc(sizeof(json_value_t));
                memset(val, 0, sizeof(json_value_t));
                val->type = JSON_TYPE_STRING;
                parse_string(val, json_str);
                break;
            case 't':
            case 'f':
                val = (json_value_t *) malloc(sizeof(json_value_t));
                memset(val, 0, sizeof(json_value_t));
                val->type = JSON_TYPE_BOOLEAN;
                parse_boolean(val, json_str);
                break;
            case 'n':
                val = (json_value_t *) malloc(sizeof(json_value_t));
                memset(val, 0, sizeof(json_value_t));
                val->type = JSON_TYPE_NULL;
                parse_null(val, json_str);
                break;
            default:
                val = (json_value_t *) malloc(sizeof(json_value_t));
                memset(val, 0, sizeof(json_value_t));
                val->type = JSON_TYPE_NUMBER;
                parse_number(val, json_str);
                break;
        }
        // add property to object
        if (obj == NULL) {
            parent->type = JSON_TYPE_OBJECT;
            obj = (json_object_t *) malloc(sizeof(json_object_t));
            obj->next = NULL;
            obj->name = name;
            obj->value = val;
            parent->value.object = obj;
        } else {
            obj->next = (json_object_t *) malloc(sizeof(json_object_t));
            obj = obj->next;
            obj->next = NULL;
            obj->name = name;
            obj->value = val;
        }
        // check for comma or end of object
        if (**json_str == ',') {
            (*json_str)++;
        }
    }
    (*json_str)++;
}

void parse_array(json_value_t *parent, char **json_str) {
    json_value_t *val = NULL;
    int size = 0;
    // count the number of elements in the array
    while (**json_str != ']' && **json_str != '\0') {
        if (**json_str == ',') {
            (*json_str)++;
        }
        size++;
    }
    (*json_str)++; // skip over closing bracket
    // allocate array
    val = (json_value_t *) malloc(sizeof(json_value_t) * size);
    memset(val, 0, sizeof(json_value_t) * size);
    parent->value.array = val;
    parent->type = JSON_TYPE_ARRAY;
    // parse each element
    for (int i = 0; i < size; i++) {
        switch (**json_str) {
            case '{':
                val[i].type = JSON_TYPE_OBJECT;
                parse_object(&val[i], json_str);
                break;
            case '[':
                val[i].type = JSON_TYPE_ARRAY;
                parse_array(&val[i], json_str);
                break;
            case '\"':
                val[i].type = JSON_TYPE_STRING;
                parse_string(&val[i], json_str);
                break;
            case 't':
            case 'f':
                val[i].type = JSON_TYPE_BOOLEAN;
                parse_boolean(&val[i], json_str);
                break;
            case 'n':
                val[i].type = JSON_TYPE_NULL;
                parse_null(&val[i], json_str);
                break;
            default:
                val[i].type = JSON_TYPE_NUMBER;
                parse_number(&val[i], json_str);
                break;
        }
        // check for comma or end of array
        if (i < size - 1) {
            (*json_str)++;
        }
    }
}

void parse_number(json_value_t *parent, char **json_str) {
    char num_str[64] = { 0 };
    int i = 0;
    while (**json_str != ',' && **json_str != '}' && **json_str != ']' && **json_str != '\0') {
        num_str[i++] = **json_str;
        (*json_str)++;
    }
    num_str[i] = '\0';
    parent->value.number = atof(num_str);
}

void parse_string(json_value_t *parent, char **json_str) {
    char str[256] = { 0 };
    int i = 0;
    (*json_str)++;
    while (**json_str != '\"' && **json_str != '\0') {
        str[i++] = **json_str;
        (*json_str)++;
    }
    (*json_str)++;
    parent->value.string = strdup(str);
}

void parse_boolean(json_value_t *parent, char **json_str) {
    if (**json_str == 't') {
        parent->value.boolean = 1;
        *json_str += 4; // skip over 'true'
    } else {
        parent->value.boolean = 0;
        *json_str += 5; // skip over 'false'
    }
}

void parse_null(json_value_t *parent, char **json_str) {
    parent->value.string = NULL;
    *json_str += 4; // skip over 'null'
}

int main() {
    char *json_str = "{\"name\":\"John Smith\",\"age\":30,\"isMarried\":true,\"address\":{\"street\":\"123 Main St\",\"city\":\"Anytown\",\"state\":\"CA\",\"zip\":\"12345\"},\"children\":[\"Sally\",\"Billy\"]}";
    json_value_t *json = parse_json(json_str);
    // Handle the parsed JSON data here...
    return 0;
}