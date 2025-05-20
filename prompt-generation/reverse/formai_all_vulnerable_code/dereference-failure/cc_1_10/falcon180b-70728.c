//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100000

struct node{
    char word[MAX_SIZE];
    int count;
    struct node *next;
};

struct node *create_node(char *word){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->word,word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node **head, char *word){
    struct node *new_node = create_node(word);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list(struct node *head){
    while(head!= NULL){
        printf("%s : %d\n",head->word,head->count);
        head = head->next;
    }
}

void merge_lists(struct node **head1, struct node **head2){
    struct node *temp1 = *head1;
    struct node *temp2 = *head2;
    struct node *new_head = NULL;
    if(temp1 == NULL){
        *head1 = temp2;
        return;
    }
    if(temp2 == NULL){
        return;
    }
    if(strcmp(temp1->word,temp2->word) < 0){
        new_head = temp1;
        temp1 = temp1->next;
    }else{
        new_head = temp2;
        temp2 = temp2->next;
    }
    while(temp1!= NULL && temp2!= NULL){
        if(strcmp(temp1->word,temp2->word) < 0){
            insert_node(new_head,temp1->word);
            temp1 = temp1->next;
        }else{
            insert_node(new_head,temp2->word);
            temp2 = temp2->next;
        }
    }
    while(temp1!= NULL){
        insert_node(new_head,temp1->word);
        temp1 = temp1->next;
    }
    while(temp2!= NULL){
        insert_node(new_head,temp2->word);
        temp2 = temp2->next;
    }
    *head1 = new_head;
}

void merge_sort(struct node **head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }
    struct node *mid = *head;
    while(mid->next!= NULL && mid->next->next!= NULL){
        mid = mid->next;
    }
    struct node *temp = mid->next;
    mid->next = NULL;
    merge_sort(&(*head));
    merge_sort(&temp);
    merge_lists(head,&temp);
}

int main(){
    FILE *fp;
    char line[MAX_SIZE];
    char word[MAX_SIZE];
    struct node *head = NULL;
    fp = fopen("logfile.txt","r");
    if(fp == NULL){
        printf("Error opening file\n");
        return 0;
    }
    while(fgets(line,MAX_SIZE,fp)!= NULL){
        strtok(line," ");
        while(strcmp(word,"")!= 0){
            insert_node(&head,word);
            strtok(NULL," ");
        }
    }
    fclose(fp);
    merge_sort(&head);
    print_list(head);
    return 0;
}