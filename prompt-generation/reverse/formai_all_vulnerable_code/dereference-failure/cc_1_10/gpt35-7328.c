//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { 
    JSON_STRING, 
    JSON_ARRAY, 
    JSON_OBJECT 
} json_type;

typedef struct json_object {
    json_type type;
    char* key;
    void* value;
    struct json_object* next;
} json_object;

void parse_value(json_object** parent, char** json_str);

void parse_string(json_object** parent, char** json_str) {
    char* string_start = *json_str + 1; 
    char* string_end = strchr(string_start, '\"');
    if (!string_end) {
        printf("Error: Invalid JSON.\n");
        exit(1);
    }
    int length = string_end - string_start;
    char* value = malloc(length + 1); 
    strncpy(value, string_start, length);
    value[length] = '\0'; 
    (*json_str) = string_end + 1; 
    json_object* obj = malloc(sizeof(json_object)); 
    obj->type = JSON_STRING; 
    obj->value = value; 
    obj->key = NULL;
    obj->next = NULL;
    (*parent) = obj;
}

void parse_array(json_object** parent, char** json_str) {
    json_object* obj = malloc(sizeof(json_object)); 
    obj->type = JSON_ARRAY; 
    obj->key = NULL;
    obj->next = NULL;
    (*json_str)++; 
    obj->value = NULL; 
    json_object** current = &obj->value; 
    while (**json_str != ']') { 
        parse_value(current, json_str); 
        if (**json_str == ',') { 
            (*json_str)++; 
        } else if (**json_str != ']') { 
            printf("Error: Invalid JSON.\n");
            exit(1);
        }
    }
    (*json_str)++; 
    (*parent) = obj;
}

void parse_object(json_object** parent, char** json_str) {
    json_object* obj = malloc(sizeof(json_object));
    obj->type = JSON_OBJECT; 
    obj->key = NULL;
    obj->next = NULL;
    (*json_str)++; 
    obj->value = NULL; 
    json_object** current = &obj->value; 
    while (**json_str != '}') { 
        if (**json_str != '\"') { 
            printf("Error: Invalid JSON.\n");
            exit(1);
        }
        char* key_start = (*json_str) + 1; 
        char* key_end = strchr(key_start, '\"'); 
        if (!key_end) {
            printf("Error: Invalid JSON.\n");
            exit(1);
        }
        int length = key_end - key_start; 
        char* key = malloc(length + 1); 
        strncpy(key, key_start, length);
        key[length] = '\0'; 
        (*json_str) = key_end + 1; 
        if (**json_str != ':') { 
            printf("Error: Invalid JSON.\n");
            exit(1);
        }
        (*json_str)++; 
        parse_value(current, json_str); 
        current = &(*current)->next; 
        if (**json_str == ',') { 
            (*json_str)++; 
        } else if (**json_str != '}') { 
            printf("Error: Invalid JSON.\n");
            exit(1);
        }
    }
    (*json_str)++; 
    (*parent) = obj;
}

void parse_value(json_object** parent, char** json_str) {
    while (isspace(**json_str)) { 
        (*json_str)++; 
    }

    switch (**json_str) {
        case '\"':
            parse_string(parent, json_str);
            break;
        case '[':
            parse_array(parent, json_str);
            break;
        case '{':
            parse_object(parent, json_str);
            break;
        default:
            printf("Error: Invalid JSON.\n");
            exit(1);
            break;
    }
}

json_object* parse_json(char* json_str) {
    json_object* root = NULL; 
    parse_value(&root, &json_str); 
    return root;
}

void print_json_object(json_object* obj) {
    if (obj == NULL) {
        printf("null");
        return;
    }

    switch (obj->type) {
        case JSON_STRING:
            printf("\"%s\"", (char*)obj->value);
            break;
        case JSON_ARRAY:
            printf("[");
            for (json_object* o = obj->value; o != NULL; o = o->next) {
                print_json_object(o);
                if (o->next != NULL) {
                    printf(", ");
                }
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            for (json_object* o = obj->value; o != NULL; o = o->next) {
                printf("\"%s\": ", o->key);
                print_json_object(o);
                if (o->next != NULL) {
                    printf(", ");
                }
            }
            printf("}");
            break;
    }
}

int main() {
    char* json_str = "{\"name\":\"John Doe\",\"age\":30,\"hobbies\":[\"reading\",\"writing\",\"coding\"],\"address\":{\"street\":\"123 Main St\",\"city\":\"Boston\",\"state\":\"MA\"}}";
    json_object* root = parse_json(json_str);
    print_json_object(root);
    printf("\n");

    return 0;
}