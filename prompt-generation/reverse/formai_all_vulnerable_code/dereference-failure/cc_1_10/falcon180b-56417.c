//Falcon-180B DATASET v1.0 Category: Text processing ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct node{
    char word[MAX];
    int count;
    struct node *next;
};

struct node *create_node(char *word){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->word,word);
    newnode->count = 1;
    newnode->next = NULL;
    return newnode;
}

void add_word(struct node **head,char *word){
    struct node *newnode = create_node(word);
    struct node *temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void delete_word(struct node **head,char *word){
    struct node *temp = *head;
    if(strcmp(temp->word,word)==0){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        if(strcmp(temp->next->word,word)==0){
            struct node *ptr = temp->next;
            temp->next = temp->next->next;
            free(ptr);
            return;
        }
        temp = temp->next;
    }
}

void display_list(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%s : %d\n",temp->word,temp->count);
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;
    char ch;
    while((ch=getchar())!=EOF){
        if(isalpha(ch)){
            ungetc(ch,stdin);
            char word[MAX];
            int i=0;
            while(isalpha(ch=getchar())){
                word[i++] = ch;
            }
            word[i] = '\0';
            add_word(&head,word);
        }
    }
    display_list(head);
    return 0;
}