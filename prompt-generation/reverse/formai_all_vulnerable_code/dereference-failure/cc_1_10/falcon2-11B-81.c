//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char* word;
    struct node* next;
};

struct node* create_node(char* word) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->word = word;
    new_node->next = NULL;
    return new_node;
}

struct node* insert_node(struct node* head, char* word) {
    if (head == NULL) {
        head = create_node(word);
    } else {
        struct node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = create_node(word);
    }
    return head;
}

void delete_node(struct node** head, char* word) {
    if (*head == NULL) {
        printf("No such word in the dictionary.\n");
        return;
    }
    struct node* temp = *head;
    while (temp->next!= NULL) {
        if (strcmp(temp->next->word, word) == 0) {
            break;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("No such word in the dictionary.\n");
        return;
    }
    if (temp == *head) {
        *head = temp->next;
    } else {
        struct node* prev = *head;
        while (prev->next!= temp) {
            prev = prev->next;
        }
        prev->next = temp->next;
    }
    free(temp);
}

void print_words(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void print_summary(struct node* head, int n) {
    int i = 0;
    while (head!= NULL) {
        if (i++ == n) {
            break;
        }
        head = head->next;
    }
    while (head!= NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insert_node(head, "The");
    insert_node(head, "quick");
    insert_node(head, "brown");
    insert_node(head, "fox");
    insert_node(head, "jumped");
    insert_node(head, "over");
    insert_node(head, "the");
    insert_node(head, "lazy");
    insert_node(head, "dog");
    print_words(head);
    print_summary(head, 4);
    delete_node(&head, "fox");
    print_summary(head, 3);
    return 0;
}