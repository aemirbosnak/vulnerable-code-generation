//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct node{
    char data[MAX_SIZE];
    int freq;
    struct node* next;
};

struct node* create_node(char ch){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, ch);
    new_node->freq = 1;
    new_node->next = NULL;
    return new_node;
}

void add_word(struct node** head, char* word){
    int len = strlen(word);
    struct node* temp = *head;
    while(temp!= NULL){
        if(temp->data[0] == word[0]){
            if(strcmp(temp->data, word) == 0){
                temp->freq++;
                return;
            }
        }
        temp = temp->next;
    }
    temp = create_node(word[0]);
    temp->next = *head;
    *head = temp;
}

void display_tree(struct node* node){
    if(node == NULL){
        return;
    }
    printf("%c %d\n", node->data[0], node->freq);
    struct node* temp = node->next;
    while(temp!= NULL){
        display_tree(temp);
        temp = temp->next;
    }
}

int main(){
    struct node* root = NULL;
    char word[MAX_SIZE];
    int choice;
    do{
        printf("Enter the word to be added: ");
        scanf("%s", word);
        add_word(&root, word);
        printf("Enter 1 to display the tree\n");
        scanf("%d", &choice);
        if(choice == 1){
            printf("The tree is:\n");
            display_tree(root);
        }
    }while(choice!= 0);
    return 0;
}