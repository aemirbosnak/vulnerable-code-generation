//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct node{
    char data[MAX];
    int count;
    struct node *next;
}node;

typedef struct hash{
    node **table;
    int size;
}hash;

int hashFunction(char *key, int size){
    int sum = 0;
    int i = 0;
    while(key[i]!= '\0'){
        sum += key[i];
        i++;
    }
    return sum % size;
}

void insert(hash *ht, char *key){
    int index = hashFunction(key, ht->size);
    node *newnode = (node*)malloc(sizeof(node));
    newnode->count = 1;
    strcpy(newnode->data, key);
    newnode->next = ht->table[index];
    ht->table[index] = newnode;
}

void delete(hash *ht, char *key){
    int index = hashFunction(key, ht->size);
    node *temp = ht->table[index];
    node *prev = NULL;
    while(temp!= NULL && strcmp(temp->data, key)!= 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Key not found\n");
        return;
    }
    if(temp->count == 1){
        free(temp);
        ht->table[index] = temp->next;
    }
    else{
        temp->count--;
    }
}

void search(hash *ht, char *key){
    int index = hashFunction(key, ht->size);
    node *temp = ht->table[index];
    while(temp!= NULL){
        if(strcmp(temp->data, key) == 0){
            printf("Key found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Key not found\n");
}

int main(){
    hash ht;
    ht.size = 7;
    ht.table = (node**)malloc(sizeof(node*) * ht.size);
    for(int i=0; i<ht.size; i++){
        ht.table[i] = NULL;
    }
    insert(&ht, "hello");
    insert(&ht, "world");
    search(&ht, "hello");
    search(&ht, "world");
    delete(&ht, "hello");
    search(&ht, "hello");
    return 0;
}