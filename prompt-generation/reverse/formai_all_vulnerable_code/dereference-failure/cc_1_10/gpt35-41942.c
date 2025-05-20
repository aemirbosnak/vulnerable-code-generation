//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef enum {
    NULL_TYPE,
    BOOLEAN_TYPE,
    NUMBER_TYPE,
    STRING_TYPE,
    ARRAY_TYPE,
    OBJECT_TYPE
} json_type_t;

typedef struct jsonval {
    json_type_t type;
    union {
        int boolean_value;
        double number_value;
        char string_value[BUFFER_SIZE];
        struct jsonval* array_value;
        struct jsonpair* object_value;
    } data;
    struct jsonval* next;
} jsonval;

typedef struct jsonpair {
    char key[BUFFER_SIZE];
    struct jsonval* value;
    struct jsonpair* next;
} jsonpair;

jsonval* parse_value(const char** input);
jsonpair* parse_pair(const char** input);

jsonval* parse_array(const char** input) {
    jsonval* head = NULL;
    jsonval** tail = &head;
    (*input)++;
    while (**input != ']') {
        jsonval* val = parse_value(input);
        if (!val) {
            printf("Error: invalid array value.\n");
            return NULL;
        }
        *tail = val;
        tail = &val->next;
        if (**input == ',') {
            (*input)++;
        } else if (**input != ']') {
            printf("Error: expected ',' or ']', got '%c'\n", **input);
            return NULL;
        }
    }
    (*input)++;
    return head;
}

jsonval* parse_object(const char** input) {
    jsonpair* head = NULL;
    jsonpair** tail = &head;
    (*input)++;
    while (**input != '}') {
        jsonpair* pair = parse_pair(input);
        if (!pair) {
            printf("Error: invalid object pair.\n");
            return NULL;
        }
        *tail = pair;
        tail = &pair->next;
        if (**input == ',') {
            (*input)++;
        } else if (**input != '}') {
            printf("Error: expected ',' or '}', got '%c'\n", **input);
            return NULL;
        }
    }
    (*input)++;
    jsonval* obj = malloc(sizeof(jsonval));
    obj->type = OBJECT_TYPE;
    obj->data.object_value = head;
    return obj;
}

jsonval* parse_string(const char** input) {
    char str[BUFFER_SIZE] = "";
    (*input)++;
    char* ptr = str;
    while (**input != '"') {
        if (**input == '\\') {
            (*input)++;
            switch (**input) {
                case '\\':
                    *ptr++ = '\\';
                    break;
                case '"':
                    *ptr++ = '"';
                    break;
                case 'n':
                    *ptr++ = '\n';
                    break;
                default:
                    printf("Error: invalid escape character.\n");
                    return NULL;
            }
        } else {
            *ptr++ = **input;
        }
        (*input)++;
    }
    (*input)++;
    jsonval* str_val = malloc(sizeof(jsonval));
    str_val->type = STRING_TYPE;
    strcpy(str_val->data.string_value, str);
    return str_val;
}

jsonval* parse_number(const char** input) {
    char num[BUFFER_SIZE] = "";
    char* ptr = num;
    while (**input >= '0' && **input <= '9') {
        *ptr++ = **input;
        (*input)++;
    }
    if (**input == '.') {
        *ptr++ = '.';
        (*input)++;
        while (**input >= '0' && **input <= '9') {
            *ptr++ = **input;
            (*input)++;
        }
    }
    if (**input == 'e' || **input == 'E') {
        *ptr++ = **input;
        (*input)++;
        if (**input == '+' || **input == '-') {
            *ptr++ = **input;
            (*input)++;
        }
        while (**input >= '0' && **input <= '9') {
            *ptr++ = **input;
            (*input)++;
        }
    }
    jsonval* num_val = malloc(sizeof(jsonval));
    num_val->type = NUMBER_TYPE;
    num_val->data.number_value = strtod(num, NULL);
    return num_val;
}

jsonval* parse_boolean(const char** input) {
    jsonval* bool_val = malloc(sizeof(jsonval));
    bool_val->type = BOOLEAN_TYPE;
    if (**input == 't') {
        bool_val->data.boolean_value = 1;
        (*input) += 4;
    } else if (**input == 'f') {
        bool_val->data.boolean_value = 0;
        (*input) += 5;
    } else {
        printf("Error: invalid boolean value.\n");
        free(bool_val);
        return NULL;
    }
    return bool_val;
}

jsonval* parse_null(const char** input) {
    jsonval* null_val = malloc(sizeof(jsonval));
    null_val->type = NULL_TYPE;
    (*input) += 4;
    return null_val;
}

jsonval* parse_value(const char** input) {
    while (**input == ' ' || **input == '\t' || **input == '\n' || **input == '\r') {
        (*input)++;
    }
    switch (**input) {
        case '[':
            return parse_array(input);
        case '{':
            return parse_object(input);
        case '"':
            return parse_string(input);
        case '-':
        case '0' ... '9': // C99 feature
            return parse_number(input);
        case 't':
        case 'f':
            return parse_boolean(input);
        case 'n':
            return parse_null(input);
        default:
            printf("Error: invalid value.\n");
            return NULL;
    }
}

jsonpair* parse_pair(const char** input) {
    jsonpair* pair = malloc(sizeof(jsonpair));
    pair->value = NULL;
    (*input)++;
    char* ptr = pair->key;
    while (**input != '"') {
        *ptr++ = **input;
        (*input)++;
    }
    *ptr = '\0';
    (*input)++;
    if (**input != ':') {
        printf("Error: expected ':'.\n");
        free(pair);
        return NULL;
    }
    (*input)++;
    pair->value = parse_value(input);
    if (!pair->value) {
        free(pair);
        return NULL;
    }
    return pair;
}

void print_jsonval(jsonval* val, int depth) {
    switch (val->type) {
        case NULL_TYPE:
            printf("null");
            break;
        case BOOLEAN_TYPE:
            printf(val->data.boolean_value ? "true" : "false");
            break;
        case NUMBER_TYPE:
            printf("%f", val->data.number_value);
            break;
        case STRING_TYPE:
            printf("\"%s\"", val->data.string_value);
            break;
        case ARRAY_TYPE:
            printf("[");
            if (val->data.array_value) {
                print_jsonval(val->data.array_value, depth + 1);
                jsonval* curr = val->data.array_value->next;
                while (curr) {
                    printf(", ");
                    print_jsonval(curr, depth + 1);
                    curr = curr->next;
                }
            }
            printf("]");
            break;
        case OBJECT_TYPE:
            printf("{\n");
            if (val->data.object_value) {
                jsonpair* curr = val->data.object_value;
                while (curr) {
                    printf("%*s\"%s\": ", depth * 4, "", curr->key);
                    print_jsonval(curr->value, depth + 1);
                    if (curr->next) {
                        printf(",");
                    }
                    printf("\n");
                    curr = curr->next;
                }
            }
            printf("%*s}", (depth - 1) * 4, "");
            break;
    }
}

int main(void) {
    const char* input = "{\"name\":\"John Doe\",\"age\":42,\"is_male\":true,\"titles\":[\"Mr.\",\"Dr.\"]}";
    jsonval* root = parse_value(&input);
    if (root) {
        print_jsonval(root, 0);
        printf("\n");
    }
    return 0;
}