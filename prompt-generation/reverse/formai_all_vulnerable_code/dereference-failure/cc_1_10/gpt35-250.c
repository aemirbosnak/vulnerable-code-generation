//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { 
    JSON_NULL, 
    JSON_BOOLEAN, 
    JSON_NUMBER, 
    JSON_STRING, 
    JSON_ARRAY, 
    JSON_OBJECT 
} json_type;

typedef struct json_value json_value;
typedef struct json_array json_array;
typedef struct json_object json_object;
typedef struct json_element json_element;

struct json_value{
    json_type type;
    union{
        int boolean;
        double number;
        char* string;
        json_array* array;
        json_object* object;
    } u;
};

struct json_array{
    int size;
    json_value **values;
};

struct json_element{
    char *key;
    json_value *value;
};

struct json_object{
    int size;
    json_element **elements;
};

char* string_copy(char* str){
    int length = strlen(str) + 1;
    char* copy = (char*) malloc(length);
    memcpy(copy, str, length);
    return copy;
}

void skip_space(const char **json){
    while (isspace(**json))
        (*json)++;
}


json_value* parse_value(const char** json);

json_value* parse_string(const char **json){
    char *string = (char*) malloc(256);
    (*json)++;
    int index = 0;
    while (**json != '"'){
        if (**json == '\\'){
            (*json)++;
            switch (**json){
                case '\"':
                case '\\':
                case '/':
                    string[index++] = **json;
                    break;
                case 'b':
                    string[index++] = '\b';
                    break;
                case 'f':
                    string[index++] = '\f';
                    break;
                case 'n':
                    string[index++] = '\n';
                    break;
                case 'r':
                    string[index++] = '\r';
                    break;
                case 't':
                    string[index++] = '\t';
                    break;
            }
        }
        else{
            string[index++] = **json;
        }
        (*json)++;
    }
    string[index] = '\0';
    (*json)++;
    json_value* value = (json_value*) malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->u.string = string;
    return value;
}

json_value* parse_number(const char **json){
    int integer = 0, decimal = 0;
    int decimal_flag = 0, decimal_pow = 1, sign = 1;
    if (**json == '-'){
        sign = -1;
        (*json)++;
    }
    while (isdigit(**json)){
        integer = integer * 10 + (**json - '0');
        (*json)++;
    }
    if (**json == '.'){
        decimal_flag = 1;
        (*json)++;
    }
    while (isdigit(**json) && decimal_flag){
        decimal = decimal * 10 + (**json - '0');
        decimal_pow *= 10;
        (*json)++;
    }
    json_value* value = (json_value*) malloc(sizeof(json_value));
    value->type = JSON_NUMBER;
    value->u.number = sign * (integer + (double) decimal / decimal_pow);
    return value;
}

json_value* parse_array(const char **json){
    (*json)++;
    skip_space(json);
    json_array* array = (json_array*) malloc(sizeof(json_array));
    array->size = 0;
    array->values = NULL;
    while (**json != ']'){
        json_value* value = parse_value(json);
        array->size++;
        array->values = (json_value**) realloc(array->values, array->size * sizeof(json_value*));
        array->values[array->size - 1] = value;
        skip_space(json);
        if (**json == ','){
            (*json)++;
            skip_space(json);
        }
    }
    (*json)++;
    json_value* value = (json_value*) malloc(sizeof(json_value));
    value->type = JSON_ARRAY;
    value->u.array = array;
    return value;
}

json_value* parse_object(const char **json){
    (*json)++;
    skip_space(json);
    json_object* object = (json_object*) malloc(sizeof(json_object));
    object->size = 0;
    object->elements = NULL;
    while (**json != '}'){
        json_element* element = (json_element*) malloc(sizeof(json_element));
        element->key = parse_string(json)->u.string;
        skip_space(json);
        if (**json != ':'){
            fprintf(stderr, "Expected ':'\n");
            exit(1);
        }
        (*json)++;
        skip_space(json);
        element->value = parse_value(json);
        object->size++;
        object->elements = (json_element**) realloc(object->elements, object->size * sizeof(json_element*));
        object->elements[object->size-1] = element;
        skip_space(json);
        if (**json == ','){
            (*json)++;
            skip_space(json);
        }
    }
    (*json)++;
    json_value* value = (json_value*) malloc(sizeof(json_value));
    value->type = JSON_OBJECT;
    value->u.object = object;
    return value;
}

json_value* parse_true(const char **json){
    (*json)++;
    if ((*json)[0] == 'r' && (*json)[1] == 'u' && (*json)[2] == 'e'){
        json_value* value = (json_value*) malloc(sizeof(json_value));
        value->type = JSON_BOOLEAN;
        value->u.boolean = 1;
        (*json) += 3;
        return value;
    }
    else{
        fprintf(stderr, "Expected 'true'\n");
        exit(1);
    }
}

json_value* parse_false(const char **json){
    (*json)++;
    if ((*json)[0] == 'a' && (*json)[1] == 'l' && (*json)[2] == 's' && (*json)[3] == 'e'){
        json_value* value = (json_value*) malloc(sizeof(json_value));
        value->type = JSON_BOOLEAN;
        value->u.boolean = 0;
        (*json) += 4;
        return value;
    }
    else{
        fprintf(stderr, "Expected 'false'\n");
        exit(1);
    }
}

json_value* parse_null(const char **json){
    (*json)++;
    if ((*json)[0] == 'u' && (*json)[1] == 'l' && (*json)[2] == 'l'){
        json_value* value = (json_value*) malloc(sizeof(json_value));
        value->type = JSON_NULL;
        (*json) += 3;
        return value;
    }
    else{
        fprintf(stderr, "Expected 'null'\n");
        exit(1);
    }
}

json_value* parse_value(const char **json){
    skip_space(json);
    switch (**json){
        case 'n':
            return parse_null(json);
        case 't':
            return parse_true(json);
        case 'f':
            return parse_false(json);
        case '\"':
            return parse_string(json);
        case '-':
        case '0'...'9':
            return parse_number(json);
        case '[':
            return parse_array(json);
        case '{':
            return parse_object(json);
        default:
            fprintf(stderr, "Invalid JSON format\n");
            exit(1);
    }
}

void print_json(json_value *value, int deep){
    int i, j;
    switch(value->type){
        case JSON_BOOLEAN:
            printf("%s", value->u.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", value->u.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->u.string);
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (i = 0; i < value->u.array->size; i++){
                for (j = 0; j < deep + 1; j++){ printf("\t"); }
                printf("%d: ", i + 1);
                print_json(value->u.array->values[i], deep + 1);
                if (i < value->u.array->size - 1){
                    printf(",\n");
                }
                else{
                    printf("\n");
                }
            }
            for (i = 0; i < deep; i++){ printf("\t"); }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (i = 0; i < value->u.object->size; i++){
                for (j = 0; j < deep + 1; j++){ printf("\t"); }
                printf("\"%s\": ", value->u.object->elements[i]->key);
                print_json(value->u.object->elements[i]->value, deep + 1);
                if (i < value->u.object->size - 1){
                    printf(",\n");
                }
                else{
                    printf("\n");
                }
            }
            for (i = 0; i < deep; i++){ printf("\t"); }
            printf("}");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }
}

int main(){

    char *json_string = "\"name\":\"Albert Einstein\", \"occupation\":\"Scientist\", \"born\":\"14 March 1879\", \"died\":\"18 April 1955\"";
    const char *json = json_string;
    json_value* value = parse_object(&json);

    printf("Input: %s\n", json_string);
    printf("Result: ");
    print_json(value, 0);
    printf("\n");
    
    return 0;
}