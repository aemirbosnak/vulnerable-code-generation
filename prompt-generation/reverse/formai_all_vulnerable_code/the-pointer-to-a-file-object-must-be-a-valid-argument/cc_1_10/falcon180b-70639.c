//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct node{
    char word[20];
    int count;
    struct node* next;
}node;

node* create_node(char* word){
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->word,word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void insert_word(node** head, char* word){
    node* new_node = *head;
    while(new_node!= NULL && strcmp(new_node->word,word)!= 0){
        new_node = new_node->next;
    }
    if(new_node == NULL){
        new_node = create_node(word);
        new_node->next = *head;
        *head = new_node;
    }
    else{
        new_node->count++;
    }
}

void print_word_counts(node* head){
    while(head!= NULL){
        printf("%s: %d\n",head->word,head->count);
        head = head->next;
    }
}

int main(){
    FILE* file = fopen("log.txt","r");
    char line[100];
    char word[20];
    node* head = NULL;
    while(fgets(line,100,file)!= NULL){
        char* token = strtok(line," ");
        while(token!= NULL){
            strcpy(word,token);
            for(int i=0;i<strlen(word);i++){
                word[i] = tolower(word[i]);
            }
            insert_word(&head,word);
            token = strtok(NULL," ");
        }
    }
    fclose(file);
    print_word_counts(head);
    return 0;
}