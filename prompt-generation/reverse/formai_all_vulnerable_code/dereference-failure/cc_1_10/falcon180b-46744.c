//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

struct json_node{
    char *name;
    char *value;
    struct json_node *next;
};

struct json{
    struct json_node *head;
};

struct json_node* create_node(char *name, char *value){
    struct json_node *node = (struct json_node*)malloc(sizeof(struct json_node));
    node->name = name;
    node->value = value;
    node->next = NULL;
    return node;
}

void append_node(struct json_node **head, char *name, char *value){
    struct json_node *node = create_node(name, value);
    if(*head == NULL){
        *head = node;
        return;
    }
    struct json_node *temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = node;
}

struct json* create_json(){
    struct json *json = (struct json*)malloc(sizeof(struct json));
    json->head = NULL;
    return json;
}

void print_json(struct json *json){
    struct json_node *temp = json->head;
    while(temp!= NULL){
        printf("Name: %s Value: %s\n", temp->name, temp->value);
        temp = temp->next;
    }
}

int main(){
    char input[MAX_SIZE];
    struct json *json = create_json();

    printf("Enter JSON input:\n");
    fgets(input, MAX_SIZE, stdin);

    char *token = strtok(input, " \t\r\n");
    while(token!= NULL){
        if(strlen(token) == 0){
            continue;
        }
        if(token[0] == '{'){
            append_node(&json->head, "", "");
        }
        else if(token[0] == '}'){
            continue;
        }
        else if(token[0] == '\"'){
            char *name = token;
            char *value = strtok(NULL, " \t\r\n");
            while(value!= NULL && value[0]!= ':'){
                value = strtok(NULL, " \t\r\n");
            }
            if(value!= NULL){
                value++;
                append_node(&json->head, name, value);
            }
        }
        token = strtok(NULL, " \t\r\n");
    }

    print_json(json);

    return 0;
}