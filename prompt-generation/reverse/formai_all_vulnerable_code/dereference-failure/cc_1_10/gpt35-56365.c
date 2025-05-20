//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024 // Maximum buffer size for reading JSON file

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    union {
        char *str_value;
        double num_value;
        struct json_object *obj_value;
        struct json_array *arr_value;
    } value;
} json_element;

typedef struct json_object {
    char *key;
    json_element *element;
    struct json_object *next;
} json_object;

typedef struct json_array {
    json_element **elements;
    int size;
} json_array;

json_element *parse_value(const char *json_string, int *pos);

char *read_json_file(const char *filename) {
    char *buffer = NULL;
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        fseek(fp, 0L, SEEK_END);
        long file_size = ftell(fp);
        if (file_size <= MAX_BUFFER_SIZE) {
            rewind(fp);
            buffer = (char*)malloc((file_size + 1) * sizeof(char));
            if (buffer != NULL) {
                fread(buffer, sizeof(char), file_size, fp);
                buffer[file_size] = '\0';
            }
        }
        fclose(fp);
    }
    return buffer;
}

void free_json_object(json_object *obj) {
    json_object *temp;
    while (obj != NULL) {
        free(obj->key);
        free(obj->element);
        temp = obj;
        obj = obj->next;
        free(temp);
    }
}

void free_json_array(json_array *arr) {
    int i;
    for (i = 0; i < arr->size; i++) {
        free(arr->elements[i]);
    }
    free(arr->elements);
    free(arr);
}

int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

void skip_whitespace(const char *json_string, int *pos) {
    while (is_whitespace(json_string[*pos])) {
        (*pos)++;
    }
}

char *parse_string(const char *json_string, int *pos) {
    char *buffer = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
    int index = 0;
    char c = json_string[(*pos)++];
    while (c != '\"' && index < MAX_BUFFER_SIZE - 1) {
        if (c == '\\') {
            c = json_string[(*pos)++];
            switch (c) {
                case '\"':
                    buffer[index++] = '\"';
                    break;
                case '\\':
                    buffer[index++] = '\\';
                    break;
                case '/':
                    buffer[index++] = '/';
                    break;
                case 'b':
                    buffer[index++] = '\b';
                    break;
                case 'f':
                    buffer[index++] = '\f';
                    break;
                case 'n':
                    buffer[index++] = '\n';
                    break;
                case 'r':
                    buffer[index++] = '\r';
                    break;
                case 't':
                    buffer[index++] = '\t';
                    break;
                default:
                    // Invalid escape character
                    free(buffer);
                    return NULL;
            }
        } else {
            buffer[index++] = c;
        }
        c = json_string[(*pos)++];
    }
    buffer[index] = '\0';
    return buffer;
}

double parse_number(const char *json_string, int *pos) {
    long long mantissa = 0;
    int exponent = 0;
    int sign = 1;
    char c = json_string[*pos];
    if (c == '-') {
        sign = -1;
        c = json_string[++(*pos)];
    }
    while (is_digit(c)) {
        mantissa = mantissa * 10 + (c - '0');
        c = json_string[++(*pos)];
    }
    if (c == '.') {
        c = json_string[++(*pos)];
        while (is_digit(c)) {
            mantissa = mantissa * 10 + (c - '0');
            exponent--;
            c = json_string[++(*pos)];
        }
    }
    if (c == 'e' || c == 'E') {
        c = json_string[++(*pos)];
        int exp_sign = 1;
        if (c == '+' || c == '-') {
            if (c == '-') {
                exp_sign = -1;
            }
            c = json_string[++(*pos)];
        }
        int exp_mantissa = 0;
        while (is_digit(c)) {
            exp_mantissa = exp_mantissa * 10 + (c - '0');
            c = json_string[++(*pos)];
        }
        exponent += exp_sign * exp_mantissa;
    }
    double result = (double)mantissa * sign;
    if (exponent > 0) {
        while (exponent > 0) {
            result *= 10;
            exponent--;
        }
    } else if (exponent < 0) {
        while (exponent < 0) {
            result /= 10;
            exponent++;
        }
    }
    return result;
}

json_object *parse_object(const char *json_string, int *pos) {
    json_object *obj = NULL;
    char *key;
    json_element *value;
    char c = json_string[(*pos)++];
    if (c != '{') {
        // Incorrect object format
        return NULL;
    }
    skip_whitespace(json_string, pos);
    c = json_string[*pos];
    if (c == '}') {
        // Empty object
        (*pos)++;
        return NULL;
    }
    while (1) {
        if (c != '\"') {
            // Invalid key format
            free_json_object(obj);
            return NULL;
        }
        key = parse_string(json_string, pos);
        if (key == NULL) {
            // Invalid key format
            free_json_object(obj);
            return NULL;
        }
        skip_whitespace(json_string, pos);
        if (json_string[(*pos)++] != ':') {
            // Invalid object format
            free(key);
            free_json_object(obj);
            return NULL;
        }
        skip_whitespace(json_string, pos);
        value = parse_value(json_string, pos);
        if (value == NULL) {
            // Invalid object format
            free(key);
            free_json_object(obj);
            return NULL;
        }
        json_object *new_obj = (json_object*)malloc(sizeof(json_object));
        new_obj->key = key;
        new_obj->element = value;
        new_obj->next = NULL;
        if (obj != NULL) {
            json_object *last_obj = obj;
            while (last_obj->next != NULL) {
                last_obj = last_obj->next;
            }
            last_obj->next = new_obj;
        } else {
            obj = new_obj;
        }
        skip_whitespace(json_string, pos);
        c = json_string[(*pos)++];
        if (c == '}') {
            // End of object
            return obj;
        } else if (c != ',') {
            // Invalid object format
            free_json_object(obj);
            return NULL;
        }
        skip_whitespace(json_string, pos);
        c = json_string[*pos];
    }
}

json_array *parse_array(const char *json_string, int *pos) {
    json_array *arr = (json_array*)malloc(sizeof(json_array));
    arr->elements = (json_element**)malloc(10 * sizeof(json_element*));
    arr->size = 0;
    char c = json_string[(*pos)++];
    if (c != '[') {
        // Incorrect array format
        free_json_array(arr);
        return NULL;
    }
    skip_whitespace(json_string, pos);
    c = json_string[*pos];
    if (c == ']') {
        // Empty array
        (*pos)++;
        return arr;
    }
    while (1) {
        json_element *value = parse_value(json_string, pos);
        if (value == NULL) {
            // Invalid array format
            free_json_array(arr);
            return NULL;
        }
        arr->elements[arr->size++] = value;
        skip_whitespace(json_string, pos);
        c = json_string[(*pos)++];
        if (c == ']') {
            // End of array
            return arr;
        } else if (c != ',') {
            // Invalid array format
            free_json_array(arr);
            return NULL;
        }
        // Expand array if necessary
        if (arr->size % 10 == 0) {
            arr->elements = (json_element**)realloc(arr->elements, (arr->size + 10) * sizeof(json_element*));
        }
        skip_whitespace(json_string, pos);
        c = json_string[*pos];
    }
}

json_element *parse_value(const char *json_string, int *pos) {
    skip_whitespace(json_string, pos);
    char c = json_string[*pos];
    if (c == '\"') {
        char *str = parse_string(json_string, pos);
        if (str != NULL) {
            json_element *element = (json_element*)malloc(sizeof(json_element));
            element->type = JSON_STRING;
            element->value.str_value = str;
            return element;
        }
    } else if (c == '-' || is_digit(c)) {
        double num = parse_number(json_string, pos);
        json_element *element = (json_element*)malloc(sizeof(json_element));
        element->type = JSON_NUMBER;
        element->value.num_value = num;
        return element;
    } else if (c == '{') {
        json_object *obj = parse_object(json_string, pos);
        if (obj != NULL) {
            json_element *element = (json_element*)malloc(sizeof(json_element));
            element->type = JSON_OBJECT;
            element->value.obj_value = obj;
            return element;
        }
    } else if (c == '[') {
        json_array *arr = parse_array(json_string, pos);
        if (arr != NULL) {
            json_element *element = (json_element*)malloc(sizeof(json_element));
            element->type = JSON_ARRAY;
            element->value.arr_value = arr;
            return element;
        }
    } else if (c == 't') {
        if (strncmp(json_string + *pos, "true", 4) == 0) {
            (*pos) += 4;
            json_element *element = (json_element*)malloc(sizeof(json_element));
            element->type = JSON_TRUE;
            return element;
        }
    } else if (c == 'f') {
        if (strncmp(json_string + *pos, "false", 5) == 0) {
            (*pos) += 5;
            json_element *element = (json_element*)malloc(sizeof(json_element));
            element->type = JSON_FALSE;
            return element;
        }
    } else if (c == 'n') {
        if (strncmp(json_string + *pos, "null", 4) == 0) {
            (*pos) += 4;
            json_element *element = (json_element*)malloc(sizeof(json_element));
            element->type = JSON_NULL;
            return element;
        }
    }
    return NULL;
}

int main() {
    char *json_string = read_json_file("example.json");
    if (json_string != NULL) {
        int pos = 0;
        json_element *element = parse_value(json_string, &pos);
        if (element != NULL) {
            // Do something with valid JSON element
            free(element);
        }
        free(json_string);
    }
    return 0;
}