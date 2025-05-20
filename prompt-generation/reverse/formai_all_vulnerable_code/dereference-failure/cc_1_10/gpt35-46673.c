//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 30
#define MAX_JSON_LENGTH 500

typedef enum { JSON_STRING, JSON_NUMBER, JSON_OBJECT } json_type;

typedef struct json_object {
    char* key;
    json_type type;
    union {
        char* string_val;
        double num_val;
        struct json_object* object_val;
    } value;
    struct json_object* next;
} json_object;

json_object* parse_json_value(char* json, int* index);
json_object* parse_json_object(char* json, int* index);
char* parse_json_string(char* json, int* index);
double parse_json_number(char* json, int* index);
char* extract_json_key(char* json, int* index);
void free_json_object(json_object* obj);

int main() {
    char json_string[MAX_JSON_LENGTH] = "{\"name\":\"John Smith\",\"age\":25,\"address\":{\"city\":\"New York\",\"state\":\"NY\"}}";
    int index = 0;
    json_object* root_obj = parse_json_object(json_string, &index);
    if(!root_obj) {
        printf("JSON parsing failed.\n");
        return 1;
    }
    
    printf("JSON parsed successfully:\n");
    printf("Name: %s\n", root_obj->value.object_val->value.string_val);
    printf("Age: %g\n", root_obj->value.object_val->next->value.num_val);
    printf("City: %s\n", root_obj->value.object_val->value.object_val->value.string_val);
    printf("State: %s\n", root_obj->value.object_val->value.object_val->next->value.string_val);
    
    free_json_object(root_obj);
    
    return 0;
}

json_object* parse_json_value(char* json, int* index) {
    json_object* obj = malloc(sizeof(json_object));
    obj->type = JSON_OBJECT;
    obj->key = NULL;
    obj->next = NULL;
    
    if(json[*index] == '{') {
        obj->type = JSON_OBJECT;
        obj->value.object_val = parse_json_object(json, index);
        return obj;
    }
    else if(json[*index] == '\"') {
        obj->type = JSON_STRING;
        obj->value.string_val = parse_json_string(json, index);
        return obj;
    }
    else {
        obj->type = JSON_NUMBER;
        obj->value.num_val = parse_json_number(json, index);
        return obj;
    }
}

json_object* parse_json_object(char* json, int* index) {
    json_object *head = NULL, *tail = NULL;
    *index += 1;
    while(json[*index] != '}') {
        if(json[*index] == ',') {
            *index += 1;
        }
        json_object* obj = malloc(sizeof(json_object));
        obj->key = extract_json_key(json, index);
        obj->next = NULL;
        
        if(json[*index] == ':' && json[*index + 1] != '{') {
            obj->value.object_val = parse_json_value(json, index);
        }
        else {
            obj->value.num_val = parse_json_number(json, index);
        }
        
        if(!head) {
            head = obj;
            tail = obj;
        }
        else {
            tail->next = obj;
            tail = obj;
        }
    }
    *index += 1;
    return head;
}

char* parse_json_string(char* json, int* index) {
    *index += 1;
    char* str = malloc(sizeof(char) * MAX_KEY_LENGTH);
    int i = 0;
    while(json[*index] != '\"') {
        str[i++] = json[*index];
        *index += 1;
    }
    str[i] = '\0';
    *index += 1;
    return str;
}

double parse_json_number(char* json, int* index) {
    double num = 0;
    int sign = 1;
    if(json[*index] == '-') {
        sign = -1;
        *index += 1;
    }
    while(json[*index] >= '0' && json[*index] <= '9') {
        num = num * 10 + (double)(json[*index] - '0');
        *index += 1;
    }
    if(json[*index] == '.') {
        *index += 1;
        double decimal = 0;
        double divisor = 10;
        while(json[*index] >= '0' && json[*index] <= '9') {
            decimal += (double)(json[*index] - '0') / divisor;
            divisor *= 10;
            *index += 1;
        }
        num += decimal;
    }
    return num * sign;
}

char* extract_json_key(char* json, int* index) {
    char* key = malloc(sizeof(char) * MAX_KEY_LENGTH);
    int i = 0;
    while(json[*index] != ':') {
        key[i++] = json[*index];
        *index += 1;
    }
    key[i] = '\0';
    *index += 1;
    return key;
}

void free_json_object(json_object* obj) {
    if(obj) {
        if(obj->key) {
            free(obj->key);
        }
        if(obj->type == JSON_STRING) {
            free(obj->value.string_val);
        }
        else if(obj->type == JSON_OBJECT) {
            while(obj->value.object_val) {
                json_object* next = obj->value.object_val->next;
                free_json_object(obj->value.object_val);
                obj->value.object_val = next;
            }
        }
        free(obj);
    }
}