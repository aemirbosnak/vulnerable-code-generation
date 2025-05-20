//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_JSON_LENGTH 1024

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct json_t {
    json_type type;
    union {
        struct json_object_t *object;
        struct json_array_t *array;
        char *string;
        double number;
        int boolean;
    } data;
} json;

typedef struct json_node_t {
    char *name;
    json *value;
    struct json_node_t *next;
} json_node;

typedef struct json_object_t {
    json_node *head;
} json_object;

typedef struct json_node_array_t {
    json *value;
    struct json_node_array_t *next;
} json_node_array;

typedef struct json_array_t {
    json_node_array *head;
} json_array;

static char *json_pos;

json *parse(char *input);
static json *parse_object();
static json *parse_array();
static json *parse_string();
static json *parse_number();
static json *parse_boolean();
static json *parse_null();
static json_node *parse_object_node();
static json_node_array *parse_array_node();

json *parse(char *input){
    json_pos = input;
    return parse_object(); //The first element should always be an object
}

static char *next_token(){
    char *token_start = json_pos;
    switch(*json_pos++){
        case '{':
        case '}':
        case '[':
        case ']':
        case ',':
        case ':':
        case '\0':
            return token_start;
    }
    while(*json_pos != '\0' && *json_pos != ' ' && *json_pos != '\n' && *json_pos != '\r' && *json_pos != '\t' && *json_pos != ',' && *json_pos != ':' && *json_pos != '[' && *json_pos != ']' && *json_pos != '{' && *json_pos != '}'){
        json_pos++;
    }
    return token_start;
}

static json *parse_object(){
    json_object *object = malloc(sizeof(json_object));
    object->head = NULL;
    json *new_json = malloc(sizeof(json));
    new_json->type = JSON_OBJECT;
    new_json->data.object = object;
    json_pos++; //skip opening brace
    while(*json_pos != '}'){
        json_node *node = parse_object_node();
        if(node != NULL){
            node->next = object->head;
            object->head = node;
        }
        if(*json_pos == ','){
            json_pos++; //skip comma and continue
        } else if(*json_pos == '}'){
            break;
        }
    }
    json_pos++; //skip closing brace
    return new_json;
}

static json_node *parse_object_node(){
    json_node *node = malloc(sizeof(json_node));
    char *name = next_token();
    if(*json_pos != ':'){
        return NULL;
    }
    json_pos++; //skip colon
    node->name = malloc(strlen(name)+1);
    strcpy(node->name, name);
    node->value = parse_string(); //Assuming all values are strings
    return node;
}

static json *parse_array(){
    json_array *array = malloc(sizeof(json_array));
    array->head = NULL;
    json *new_json = malloc(sizeof(json));
    new_json->type = JSON_ARRAY;
    new_json->data.array = array;
    json_pos++; //skip opening bracket
    while(*json_pos != ']'){
        json_node_array *node = parse_array_node();
        if(node != NULL){
            node->next = array->head;
            array->head = node;
        }
        if(*json_pos == ','){
            json_pos++; //skip comma and continue
        } else if(*json_pos == ']'){
            break;
        }
    }
    json_pos++; //skip closing bracket
    return new_json;
}

static json_node_array *parse_array_node(){
    json_node_array *node = malloc(sizeof(json_node_array));
    node->value = parse_string(); //Assuming all values are strings
    return node;
}

static json *parse_string(){
    char *value_start = strstr(json_pos, "\"");
    if(value_start == NULL){
        return NULL;
    }
    json_pos += 1; //skip opening quote
    char *value_end = strstr(json_pos, "\"");
    char *value = malloc((value_end - value_start) + 1);
    strncpy(value, value_start, value_end - value_start);
    value[value_end - value_start] = '\0';
    json *new_json = malloc(sizeof(json));
    new_json->type = JSON_STRING;
    new_json->data.string = value;
    json_pos = value_end + 1; //skip closing quote
    return new_json;
}

static json *parse_number(){
    char *value_start = next_token();
    double value = atof(value_start);
    json *new_json = malloc(sizeof(json));
    new_json->type = JSON_NUMBER;
    new_json->data.number = value;
    return new_json;
}

static json *parse_boolean(){
    char *value_start = next_token();
    int value = strcmp(value_start, "true") == 0 ? 1 : 0;
    json *new_json = malloc(sizeof(json));
    new_json->type = JSON_BOOLEAN;
    new_json->data.boolean = value;
    return new_json;
}

static json *parse_null(){
    char *value_start = next_token();
    json *new_json = malloc(sizeof(json));
    new_json->type = JSON_NULL;
    new_json->data.string = NULL;
    return new_json;
}

int main(){
    char json_str[MAX_JSON_LENGTH] = "{\"foo\":\"bar\",\"baz\":[1,2,3],\"qux\":{\"quux\":\"corge\"}}";
    json *root = parse(json_str);
    //Traverse and print the JSON object
    json_node *node = root->data.object->head;
    while(node != NULL){
        printf("\"%s\": ", node->name);
        switch(node->value->type){
            case JSON_OBJECT:
                printf("{object}\n");
                break;
            case JSON_ARRAY:
                printf("[array]\n");
                break;
            case JSON_STRING:
                printf("\"%s\"\n", node->value->data.string);
                break;
            case JSON_NUMBER:
                printf("%f\n", node->value->data.number);
                break;
            case JSON_BOOLEAN:
                printf("%s\n", node->value->data.boolean ? "true" : "false");
                break;
            case JSON_NULL:
                printf("null\n");
                break;
        }
        node = node->next;
    }
    return 0;
}