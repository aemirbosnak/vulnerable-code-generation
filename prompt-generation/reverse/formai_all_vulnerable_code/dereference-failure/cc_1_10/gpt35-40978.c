//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining struct for JSON object
typedef struct json_object {
    char* key;
    char* value;
    struct json_object* next;
} JSON_Object;

// method to print error message and exit the program
void error(char* message) {
    printf("%s", message);
    exit(1);
}

// method to create a new JSON object
JSON_Object* new_JSON_object(char* key, char* value) {
    JSON_Object* json = (JSON_Object*) malloc(sizeof(JSON_Object));
    json->key = (char*) malloc(strlen(key) + 1);
    json->value = (char*) malloc(strlen(value) + 1);
    strcpy(json->key, key);
    strcpy(json->value, value);
    json->next = NULL;
    return json;
}

// method to add JSON object to the list
void add_JSON_object(JSON_Object* head, char* key, char* value) {
    JSON_Object* json = new_JSON_object(key, value);
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = json;
}

// method to parse input JSON string
JSON_Object* parse_JSON(char* str) {
    JSON_Object* head = new_JSON_object("", "");
    int len = strlen(str);
    int i = 0;
    char key[100];
    char value[100];
    int in_key = 0, in_value = 0; // boolean variables to track if we are parsing key or value
    while(i < len) {
        if(in_key) {
            if(str[i] == '\"') {
                in_key = 0;
            } else {
                key[strlen(key)] = str[i];
            }
        } else if(in_value) {
            if(str[i] == '\"') {
                in_value = 0;
                add_JSON_object(head, key, value);
                memset(key, 0, 100*sizeof(char));
                memset(value, 0, 100*sizeof(char));
            } else {
                value[strlen(value)] = str[i];
            }
        } else {
            if(str[i] == '\"') {
                in_key = 1;
            }
        }
        i++;
    }
    return head;
}

int main() {
    char* input = "{ \"name\": \"John\", \"age\": \"25\", \"city\": \"New York\" }";
    JSON_Object* json = parse_JSON(input);
    while(json->next != NULL) {
        json = json->next;
        printf("%s: %s\n", json->key, json->value);
    }
    return 0;
}