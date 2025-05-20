//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef enum {
    JSON_INVALID,
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
        char* str;
        double num;
    } value;
    json_value* next;
};

json_value* parse_json(char*);
json_value* parse_obj(char*);
json_value* parse_arr(char*);
json_value* parse_val(char*);

int main() {
    char json_data[MAX_LENGTH] = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    json_value* json = parse_json(json_data);

    printf("Name: %s\n", json->value.str);
    printf("Age: %.0f\n", json->next->value.num);
    printf("City: %s\n", json->next->next->value.str);

    return 0;
}

json_value* parse_json(char* json_data) {
    if (json_data[0] == '{') {
        return parse_obj(json_data);
    } else if (json_data[0] == '[') {
        return parse_arr(json_data);
    } else {
        printf("Invalid JSON data\n");
        return NULL;
    }
}

json_value* parse_obj(char* obj_data) {
    json_value* obj = (json_value*) malloc(sizeof(json_value));
    obj->type = JSON_OBJECT;
    obj->next = NULL;

    obj_data++; // Skip over opening brace

    while (obj_data[0] != '}') {
        char* key = strtok(obj_data, ":");
        obj_data = key + strlen(key) + 1;

        json_value* value = parse_val(obj_data);
        if (value == NULL) {
            return NULL;
        }

        value->next = obj->next;
        obj->next = value;

        if (obj_data[0] == ',') {
            obj_data++;
        }
    }

    obj_data++; // Skip over closing brace

    return obj;
}

json_value* parse_arr(char* arr_data) {
    json_value* arr = (json_value*) malloc(sizeof(json_value));
    arr->type = JSON_ARRAY;
    arr->next = NULL;

    arr_data++; // Skip over opening bracket

    while (arr_data[0] != ']') {
        json_value* value = parse_val(arr_data);
        if (value == NULL) {
            return NULL;
        }

        value->next = arr->next;
        arr->next = value;

        if (arr_data[0] == ',') {
            arr_data++;
        }
    }

    arr_data++; // Skip over closing bracket

    return arr;
}

json_value* parse_val(char* val_data) {
    json_value* val = (json_value*) malloc(sizeof(json_value));
    val->next = NULL;

    if (val_data[0] == '\"') {
        val->type = JSON_STRING;
        val_data++;

        int len = 0;
        while (val_data[len] != '\"') {
            len++;
        }

        val->value.str = (char*) malloc(len + 1);
        strncpy(val->value.str, val_data, len);
        val->value.str[len] = '\0';

        return val;
    } else if (val_data[0] == '-' || (val_data[0] >= '0' && val_data[0] <= '9')) {
        val->type = JSON_NUMBER;

        char* endptr;
        val->value.num = strtod(val_data, &endptr);

        return val;
    } else if (strncmp(val_data, "true", 4) == 0) {
        val->type = JSON_TRUE;

        return val;
    } else if (strncmp(val_data, "false", 5) == 0) {
        val->type = JSON_FALSE;

        return val;
    } else if (strncmp(val_data, "null", 4) == 0) {
        val->type = JSON_NULL;

        return val;
    } else if (val_data[0] == '{') {
        val->type = JSON_OBJECT;

        json_value* obj = parse_obj(val_data);
        val->value.str = obj->value.str;
        val->next = obj->next;

        return val;
    } else if (val_data[0] == '[') {
        val->type = JSON_ARRAY;

        json_value* arr = parse_arr(val_data);
        val->value.str = arr->value.str;
        val->next = arr->next;

        return val;
    } else {
        printf("Invalid JSON value\n");
        return NULL;
    }
}