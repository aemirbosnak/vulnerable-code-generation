//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data[MAX_SIZE];
    int freq;
    struct node* next;
};

struct node* createNode(char data[], int freq) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->freq = freq;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, char data[], int freq) {
    struct node* newNode = createNode(data, freq);
    struct node* temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node* searchNode(struct node* head, char data[]) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteNode(struct node* head, char data[]) {
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s %d\n", temp->data, temp->freq);
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;
    char word[MAX_SIZE];
    int freq;
    while (1) {
        printf("Enter word: ");
        scanf("%s", word);
        if (strcmp(word, "exit") == 0) {
            break;
        }
        head = searchNode(head, word);
        if (head == NULL) {
            head = insertNode(head, word, 1);
        } else {
            head->freq++;
        }
    }
    printList(head);
    return 0;
}