//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    struct Node *next;
    char *key;
    char *val;
} node;

node* create_node(char *key, char *val) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->key = strdup(key);
    new_node->val = strdup(val);
    return new_node;
}

void print_node(node *curr) {
    printf("\"%s\": \"%s\"\n", curr->key, curr->val);
}

void print_list(node *head) {
    node *curr = head;
    while(curr!=NULL) {
        print_node(curr);
        curr = curr->next;
    }
}

node* parse_json(char *json_str) {
    node *head = NULL, *tail = NULL;
    char *key = NULL, *val = NULL;
    char *token = strtok(json_str, "{}\":,");
    int i = 0;
    while(token!=NULL) {
        if(i%4==1) {
            key = token;
        }
        if(i%4==3) {
            val = token;
            node *new_node = create_node(key, val);
            if(head==NULL) {
                head = new_node;
            }
            else {
                tail->next = new_node;
            }
            tail = new_node;
        }
        token = strtok(NULL, "{}\":,");
        i++;
    }
    return head;
}

int main() {
    char *json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    node *head = parse_json(json_str);
    print_list(head);
    return 0;
}