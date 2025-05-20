//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    char key[100];
    char value[1000];
    struct node* next;
} Node;

Node* createNode(char* key, char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->key, key);
    strcpy(node->value, value);
    node->next = NULL;
    return node;
}

void insert(Node** arr, char* key, char* value) {
    int index = 0;
    while(key[index]!='\0') {
        index++;
    }
    int sum = 0;
    for(int i=0;i<index;i++) {
        sum+=(int)key[i];
    }
    int hash = sum%10;
    Node* newNode = createNode(key, value);
    if(arr[hash]==NULL) {
        arr[hash] = newNode;
    } else {
        Node* curr = arr[hash];
        while(curr->next!=NULL) {
            curr= curr->next;
        }
        curr->next = newNode;
    }
}

char* getValue(Node** arr, char* key) {
    int index = 0;
    while(key[index]!='\0') {
        index++;
    }
    int sum = 0;
    for(int i=0;i<index;i++) {
        sum+=(int)key[i];
    }
    int hash = sum%10;
    if(arr[hash] == NULL) {
        return "null";
    }
    Node* curr = arr[hash];
    while(curr!=NULL) {
        if(strcmp(curr->key, key)==0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return "null";
}

int main() {
    Node* arr[10] = {NULL};
    insert(arr, "name", "Jon Snow");
    insert(arr, "age", "26");
    insert(arr, "weapon", "Longclaw");
    insert(arr, "title", "King in the North");
    insert(arr, "alive", "true");
    printf("Name: %s\n", getValue(arr, "name"));
    printf("Age: %s\n", getValue(arr, "age"));
    printf("Weapon: %s\n", getValue(arr, "weapon"));
    printf("Title: %s\n", getValue(arr, "title"));
    printf("Alive: %s\n", getValue(arr, "alive"));
    printf("Location: %s\n", getValue(arr, "location"));

    return 0;
}