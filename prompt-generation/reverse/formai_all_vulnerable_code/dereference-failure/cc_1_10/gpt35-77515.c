//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10
#define MAX_STR_LEN 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
    JSON_UNKNOWN
} json_type_t;

typedef struct json_value {
    json_type_t type;
    union {
        char* string_val;
        double number_val;
        struct json_value* sub_obj;
        struct json_value* sub_arr;
    } value;
} json_value_t;

json_value_t* parse_json_str(char* json_str);
json_value_t* parse_json_obj(char** json_str_p, int depth);
json_value_t* parse_json_array(char** json_str_p, int depth);
json_value_t* parse_json_value(char** json_str_p, int depth);
char* parse_json_string(char** json_str_p);
double parse_json_number(char** json_str_p);
json_type_t get_json_type(char** json_str_p);

int main(void) {
    char *json_str = "{ \"name\": \"John\", \"age\": 42, \"isStudent\": true, \"grades\": [88, 92, 99, 94] }";
    json_value_t *parsed_json = parse_json_str(json_str);

    printf("Parsed JSON object:\n");
    printf("Name: %s\n", parsed_json->value.sub_obj[0].value.string_val);
    printf("Age: %f\n", parsed_json->value.sub_obj[1].value.number_val);
    printf("IsStudent: %s\n", parsed_json->value.sub_obj[2].type == JSON_TRUE ? "true" : "false");
    printf("Grades: %f %f %f %f\n", 
            parsed_json->value.sub_obj[3].value.sub_arr[0].value.number_val,
            parsed_json->value.sub_obj[3].value.sub_arr[1].value.number_val,
            parsed_json->value.sub_obj[3].value.sub_arr[2].value.number_val,
            parsed_json->value.sub_obj[3].value.sub_arr[3].value.number_val);

    return EXIT_SUCCESS;
}

json_value_t* parse_json_str(char* json_str) {
    char* json_str_p = json_str;
    return parse_json_obj(&json_str_p, 0);
}

json_value_t* parse_json_obj(char** json_str_p, int depth) {
    json_value_t* obj = malloc(sizeof(json_value_t));
    obj->type = JSON_OBJECT;

    // skip the opening brace
    (*json_str_p)++;
    
    // check if the object is empty (closed right after the opening brace)
    if (**json_str_p == '}') {
        (*json_str_p)++;
        obj->value.sub_obj = NULL;
        return obj;
    }

    int num_keys = 0;
    json_value_t* sub_obj_arr = malloc(MAX_DEPTH * sizeof(json_value_t));
    
    while (**json_str_p) {
        sub_obj_arr[num_keys].value.string_val = parse_json_string(json_str_p);
        // skip the colon
        (*json_str_p)++;
        sub_obj_arr[num_keys].type = get_json_type(json_str_p);
        sub_obj_arr[num_keys].value.sub_obj = NULL;

        if (sub_obj_arr[num_keys].type == JSON_OBJECT) {
            if (depth == MAX_DEPTH - 1) {
                printf("Max object depth of %d exceeded!\n", MAX_DEPTH);
                exit(EXIT_FAILURE);
            }

            sub_obj_arr[num_keys].value.sub_obj = parse_json_obj(json_str_p, depth + 1);
        } else if (sub_obj_arr[num_keys].type == JSON_ARRAY) {
            if (depth == MAX_DEPTH - 1) {
                printf("Max object depth of %d exceeded!\n", MAX_DEPTH);
                exit(EXIT_FAILURE);
            }

            sub_obj_arr[num_keys].value.sub_arr = parse_json_array(json_str_p, depth + 1);
        } else if (sub_obj_arr[num_keys].type == JSON_STRING) {
            sub_obj_arr[num_keys].value.string_val = parse_json_string(json_str_p);
        } else if (sub_obj_arr[num_keys].type == JSON_NUMBER) {
            sub_obj_arr[num_keys].value.number_val = parse_json_number(json_str_p);
        }

        // check if there are any more fields 
        if (**json_str_p == ',') {
            (*json_str_p)++;
        } else if (**json_str_p == '}') {
            (*json_str_p)++;
            break;
        } else {
            printf("Unexpected character '%c' found in object!\n", **json_str_p);
            exit(EXIT_FAILURE);
        }

        num_keys++;
    }

    obj->value.sub_obj = malloc(num_keys * sizeof(json_value_t));
    
    for (int i = 0; i < num_keys; i++) {
        obj->value.sub_obj[i] = sub_obj_arr[i];
    }

    return obj;
}

json_value_t* parse_json_array(char** json_str_p, int depth) {
    json_value_t* arr = malloc(sizeof(json_value_t));
    arr->type = JSON_ARRAY;

    // skip the opening bracket
    (*json_str_p)++;
    
    // check if the array is empty (closed right after the opening bracket)
    if (**json_str_p == ']') {
        (*json_str_p)++;
        arr->value.sub_arr = NULL;
        return arr;
    }

    int num_elems = 0;
    json_value_t* sub_arr = malloc(MAX_DEPTH * sizeof(json_value_t));
    
    while (**json_str_p) {
        sub_arr[num_elems].type = get_json_type(json_str_p);
        sub_arr[num_elems].value.sub_obj = NULL;

        if (sub_arr[num_elems].type == JSON_OBJECT) {
            if (depth == MAX_DEPTH - 1) {
                printf("Max object depth of %d exceeded!\n", MAX_DEPTH);
                exit(EXIT_FAILURE);
            }

            sub_arr[num_elems].value.sub_obj = parse_json_obj(json_str_p, depth + 1);
        } else if (sub_arr[num_elems].type == JSON_ARRAY) {
            if (depth == MAX_DEPTH - 1) {
                printf("Max object depth of %d exceeded!\n", MAX_DEPTH);
                exit(EXIT_FAILURE);
            }

            sub_arr[num_elems].value.sub_arr = parse_json_array(json_str_p, depth + 1);
        } else if (sub_arr[num_elems].type == JSON_STRING) {
            sub_arr[num_elems].value.string_val = parse_json_string(json_str_p);
        } else if (sub_arr[num_elems].type == JSON_NUMBER) {
            sub_arr[num_elems].value.number_val = parse_json_number(json_str_p);
        }

        // check if there are any more elements 
        if (**json_str_p == ',') {
            (*json_str_p)++;
        } else if (**json_str_p == ']') {
            (*json_str_p)++;
            break;
        } else {
            printf("Unexpected character '%c' found in array!\n", **json_str_p);
            exit(EXIT_FAILURE);
        }

        num_elems++;
    }

    arr->value.sub_arr = malloc(num_elems * sizeof(json_value_t));
    
    for (int i = 0; i < num_elems; i++) {
        arr->value.sub_arr[i] = sub_arr[i];
    }

    return arr;
}

json_value_t* parse_json_value(char** json_str_p, int depth) {
    json_type_t type = get_json_type(json_str_p);

    if (type == JSON_OBJECT) {
        return parse_json_obj(json_str_p, depth);
    } else if (type == JSON_ARRAY) {
        return parse_json_array(json_str_p, depth);
    } else if (type == JSON_STRING) {
        json_value_t* str_val = malloc(sizeof(json_value_t));
        str_val->type = JSON_STRING;
        str_val->value.string_val = parse_json_string(json_str_p);
        return str_val;
    } else if (type == JSON_NUMBER) {
        json_value_t* num_val = malloc(sizeof(json_value_t));
        num_val->type = JSON_NUMBER;
        num_val->value.number_val = parse_json_number(json_str_p);
        return num_val;
    } else if (type == JSON_TRUE) {
        json_value_t* true_val = malloc(sizeof(json_value_t));
        true_val->type = JSON_TRUE;
        return true_val;
    } else if (type == JSON_FALSE) {
        json_value_t* false_val = malloc(sizeof(json_value_t));
        false_val->type = JSON_FALSE;
        return false_val;
    } else if (type == JSON_NULL) {
        json_value_t* null_val = malloc(sizeof(json_value_t));
        null_val->type = JSON_NULL;
        return null_val;
    } else {
        printf("Unknown JSON type!\n");
        exit(EXIT_FAILURE);
    }
}

char* parse_json_string(char** json_str_p) {
    int str_len = strcspn((*json_str_p) + 1, "\"");
    char* str_val = malloc((str_len + 1) * sizeof(char));
    strncpy(str_val, (*json_str_p) + 1, str_len);
    str_val[str_len] = '\0';
    (*json_str_p) += str_len + 1;
    return str_val;
}

double parse_json_number(char** json_str_p) {
    char* end_ptr;
    double num_val = strtod(*json_str_p, &end_ptr);
    (*json_str_p) = end_ptr;
    return num_val;
}

json_type_t get_json_type(char** json_str_p) {
    switch (**json_str_p) {
        case '{': return JSON_OBJECT;
        case '[': return JSON_ARRAY;
        case '\"': return JSON_STRING;
        case 't': return JSON_TRUE;
        case 'f': return JSON_FALSE;
        case 'n': return JSON_NULL;
        default: return JSON_NUMBER;
    }
}