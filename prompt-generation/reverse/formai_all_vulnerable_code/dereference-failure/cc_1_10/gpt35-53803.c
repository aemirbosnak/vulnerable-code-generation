//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LEN 10000

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type_t;

typedef struct json_value {
    json_type_t type;

    union value {
        char* string_val;
        double number_val;
        int boolean_val;
        struct json_object* object_val;
        struct json_array* array_val;
    } value;
} json_value_t;

typedef struct json_object {
    json_value_t** keyval_pairs;
    int num_pairs;
} json_object_t;

typedef struct json_array {
    json_value_t** values;
    int num_values;
} json_array_t;

void skip_space(char** ptr) {
    while(isspace(**ptr))
        (*ptr)++;
}

char* get_string(char** ptr) {
    int len = 0;
    char* ret = (char*)malloc(MAX_JSON_LEN+1);

    while(**ptr != '\"' && **ptr != '\0') {
        ret[len++] = **ptr;
        (*ptr)++;
    }

    if(**ptr == '\"')
        (*ptr)++;

    ret[len] = '\0';
    return ret;
}

json_value_t* parse_value(char** ptr) {
    skip_space(ptr);

    switch(**ptr) {
        case '{': {
            json_object_t* obj = (json_object_t*)malloc(sizeof(json_object_t));
            obj->num_pairs = 0;
            obj->keyval_pairs = (json_value_t**)malloc(sizeof(json_value_t*)*MAX_JSON_LEN);

            (*ptr)++;
            skip_space(ptr);

            while(**ptr != '\0' && **ptr != '}') {
                json_value_t* key = parse_value(ptr);
                skip_space(ptr);
                (*ptr)++;

                json_value_t* value = parse_value(ptr);
                obj->keyval_pairs[obj->num_pairs++] = key;
                obj->keyval_pairs[obj->num_pairs++] = value;

                skip_space(ptr);

                if(**ptr == ',') {
                    (*ptr)++;
                    skip_space(ptr);
                }
            }

            if(**ptr == '}')
                (*ptr)++;

            json_value_t* ret = (json_value_t*)malloc(sizeof(json_value_t));
            ret->type = JSON_OBJECT;
            ret->value.object_val = obj;
            return ret;
        }

        case '[': {
            json_array_t* arr = (json_array_t*)malloc(sizeof(json_array_t));
            arr->num_values = 0;
            arr->values = (json_value_t**)malloc(sizeof(json_value_t*)*MAX_JSON_LEN);

            (*ptr)++;
            skip_space(ptr);

            while(**ptr != '\0' && **ptr != ']') {
                json_value_t* value = parse_value(ptr);
                arr->values[arr->num_values++] = value;

                skip_space(ptr);

                if(**ptr == ',') {
                    (*ptr)++;
                    skip_space(ptr);
                }
            }

            if(**ptr == ']')
                (*ptr)++;

            json_value_t* ret = (json_value_t*)malloc(sizeof(json_value_t));
            ret->type = JSON_ARRAY;
            ret->value.array_val = arr;
            return ret;
        }

        case '\"': {
            char* str = get_string(ptr);
            json_value_t* ret = (json_value_t*)malloc(sizeof(json_value_t));
            ret->type = JSON_STRING;
            ret->value.string_val = str;
            return ret;
        }

        case 't': {
            (*ptr)++;
            if(**ptr == 'r' && *((*ptr)+1) == 'u' && *((*ptr)+2) == 'e') {
                json_value_t* ret = (json_value_t*)malloc(sizeof(json_value_t));
                ret->type = JSON_BOOLEAN;
                ret->value.boolean_val = 1;
                (*ptr) += 3;
                return ret;
            }
            break;
        }

        case 'f': {
            (*ptr)++;
            if(**ptr == 'a' && *((*ptr)+1) == 'l' && *((*ptr)+2) == 's' && *((*ptr)+3) == 'e') {
                json_value_t* ret = (json_value_t*)malloc(sizeof(json_value_t));
                ret->type = JSON_BOOLEAN;
                ret->value.boolean_val = 0;
                (*ptr) += 4;
                return ret;
            }
            break;
        }

        case 'n': {
            (*ptr)++;
            if(**ptr == 'u' && *((*ptr)+1) == 'l' && *((*ptr)+2) == 'l') {
                json_value_t* ret = (json_value_t*)malloc(sizeof(json_value_t));
                ret->type = JSON_NULL;
                (*ptr) += 3;
                return ret;
            }
            break;
        }

        default: {
            int idx = 0;
            char* num_str = (char*)malloc(MAX_JSON_LEN+1);
            while(isdigit(**ptr) || **ptr == '.' || **ptr == '-') {
                num_str[idx++] = **ptr;
                (*ptr)++;
            }
            num_str[idx] = '\0';

            json_value_t* ret = (json_value_t*)malloc(sizeof(json_value_t));
            ret->type = JSON_NUMBER;
            ret->value.number_val = atof(num_str);
            return ret;
        }

    }

    return NULL;
}

int main() {
    char* json_str = "{\"name\":\"John Doe\",\"age\":25,\"address\":{\"street\":\"1st Street\",\"city\":\"New York\"},\"is_student\":true}";
    printf("Parsing JSON string: %s\n", json_str);

    char* ptr = json_str;
    json_value_t* root = parse_value(&ptr);

    printf("Parsed JSON:\n");
    printf("Name: %s\n", ((json_object_t*)root->value.object_val->keyval_pairs[0]->value.string_val));
    printf("Age: %f\n", root->value.object_val->keyval_pairs[1]->value.number_val);
    printf("Street: %s\n", root->value.object_val->keyval_pairs[2]->value.object_val->keyval_pairs[0]->value.string_val);
    printf("City: %s\n", root->value.object_val->keyval_pairs[2]->value.object_val->keyval_pairs[1]->value.string_val);
    printf("is_student: %s\n", root->value.object_val->keyval_pairs[3]->value.boolean_val ? "true" : "false");
    
    return 0;
}