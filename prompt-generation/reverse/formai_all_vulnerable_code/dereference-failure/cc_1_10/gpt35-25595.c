//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_KEYS 10
#define MAX_KEY_LEN 20
#define MAX_VAL_LEN 50

typedef enum {
    NONE,
    STRING,
    NUMBER,
    OBJECT,
    ARRAY,
    BOOLEAN,
    NULLVAL
} value_type_t;

typedef struct {
    char key[MAX_KEY_LEN];
    value_type_t type;
    union {
        int num;
        char str[MAX_VAL_LEN];
        bool boolean;
        struct Json* subjson;
    } value;
} key_value_t;

typedef struct Json {
    int size;
    key_value_t* kvs[MAX_KEYS];
} Json;

void parse_value(Json* json, char* str, int start, int end, key_value_t* kv);
void parse_key_value(Json* json, char* str, int start, int end, key_value_t* kv);
void parse_object(Json* json, char* str, int start, int end);
void parse_json(Json* json, char* str);
void print_json(Json* json);

void parse_value(Json* json, char* str, int start, int end, key_value_t* kv) {
    char* sub = str + start;
    if (*sub == '\"') {
        kv->type = STRING;
        sub++;
        int len = 0;
        while (*sub != '\"') {
            kv->value.str[len++] = *sub++;
        }
        kv->value.str[len] = '\0';
    } else if (*sub == '[') {
        kv->type = ARRAY;
        parse_object(json, str, start+1, end-1);
    } else if (*sub == 't' || *sub == 'f') {
        kv->type = BOOLEAN;
        kv->value.boolean = *sub == 't';
    } else if (*sub == 'n') {
        kv->type = NULLVAL;
    } else {
        kv->type = NUMBER;
        kv->value.num = atoi(sub);
    }
}

void parse_key_value(Json* json, char* str, int start, int end, key_value_t* kv) {
    char* sub = str + start;
    int len = 0;
    while (*sub != ':') {
        kv->key[len++] = *sub++;
    }
    kv->key[len] = '\0';
    parse_value(json, str, start+len+1, end, kv);
    json->kvs[json->size++] = kv;
}

void parse_object(Json* json, char* str, int start, int end) {
    char* sub = str + start;
    while (sub < str+end) {
        key_value_t* kv = malloc(sizeof(key_value_t));
        parse_key_value(json, str, sub-str+1, end, kv);

        sub = str + end - 1;
        while (*sub != ',' && sub > str+start) sub--;
        if (*sub == ',') end = sub - str;
    }
}

void parse_json(Json* json, char* str) {
    int start = 0, end = strlen(str)-1;
    if (str[start] == '{') {
        parse_object(json, str, 1, end-1);
    }
}

void print_json(Json* json) {
    printf("{\n");
    for (int i = 0; i < json->size; i++) {
        printf("  \"%s\": ", json->kvs[i]->key);
        switch (json->kvs[i]->type) {
            case STRING:
                printf("\"%s\"", json->kvs[i]->value.str);
                break;
            case NUMBER:
                printf("%d", json->kvs[i]->value.num);
                break;
            case BOOLEAN:
                printf("%s", json->kvs[i]->value.boolean ? "true" : "false");
                break;
            case NULLVAL:
                printf("null");
                break;
            case ARRAY:
                print_json(json->kvs[i]->value.subjson);
                break;
            default:
                break;
        }
        if (i < json->size - 1) printf(",\n");
    }
    printf("\n}\n");
}

int main() {
    Json* json = malloc(sizeof(Json));
    json->size = 0;
    char* str = "{\"firstName\": \"John\",\"lastName\": \"Doe\",\"age\": 25,\"address\":{\"streetAddress\": \"21 2nd Street\",\"city\": \"New York\",\"state\": \"NY\",\"postalCode\": 10021}, \"phoneNumbers\": [\"212 555-1234\", \"646 555-4567\"]}";
    parse_json(json, str);
    print_json(json);
    return 0;
}