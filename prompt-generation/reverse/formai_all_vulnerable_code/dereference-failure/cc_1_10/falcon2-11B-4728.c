//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char* text;
    struct node* next;
};

void add_to_list(struct node** head, char* text){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->text = strdup(text);
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    struct node* current = *head;
    while(current->next!= NULL){
        current = current->next;
    }
    current->next = new_node;
}

char* get_summarized_text(struct node* head, int count){
    char* result = (char*)malloc(count + 1);
    result[count] = '\0';
    int i = 0;
    struct node* current = head;
    while(i < count){
        if(current == NULL){
            break;
        }
        add_to_list(&result, current->text);
        current = current->next;
        i++;
    }
    return result;
}

int main(){
    struct node* head = NULL;
    add_to_list(&head, "This is a text summarizer program.");
    add_to_list(&head, "It takes a long piece of text and generates a shorter version of it.");
    add_to_list(&head, "The summarization is based on the frequency of words in the text.");
    add_to_list(&head, "The program uses a hash table to store the frequency of each word.");
    add_to_list(&head, "The most frequent words are then used to generate the summary.");
    char* summarized_text = get_summarized_text(head, 100);
    printf("The summarized text is:\n%s\n", summarized_text);
    return 0;
}