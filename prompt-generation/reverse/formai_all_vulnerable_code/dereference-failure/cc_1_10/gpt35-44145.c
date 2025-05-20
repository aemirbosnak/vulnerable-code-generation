//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct JsonNode {
    char* key;
    char* value;
    struct JsonNode* next;
};

struct JsonNode* parse(char* json_data){
    
    struct JsonNode* head = NULL;
    struct JsonNode* tail = NULL;

    char* key = strtok(json_data, ":,");
    while(key != NULL) {
        char* value = strtok(NULL, ":,");
        while(value != NULL && (*value == ' ' || *value == '\"')){
            value++;
        }

        struct JsonNode* node = malloc(sizeof(struct JsonNode));
        node->key = malloc(strlen(key) + 1);
        node->value = malloc(strlen(value) + 1);

        strcpy(node->key, key);
        strcpy(node->value, value);

        if(head == NULL){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        key = strtok(NULL, ":,");
    }

    return head;
}

int main(){
    char* json_data = "{\"name\":\"John Doe\",\"age\":26,\"occupation\":\"Programmer\"}";

    struct JsonNode* json = parse(json_data);

    printf("The parsed JSON is: \n");
    while(json != NULL){
        printf("%s : %s\n", json->key, json->value);
        json = json->next;
    }

    return 0;
}