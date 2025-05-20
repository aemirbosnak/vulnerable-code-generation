//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct node {
    char* message;
    struct node* next;
} Node;

const char* keywords[] = {"hack", "crack", "attack", "exploit", "malware"};

void add_message(Node** head, char* message) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->message = message;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void search_message(Node* head) {
    Node* current = head;
    while (current != NULL) {
        char* message = current->message;
        int i;
        for (i = 0; i < 5; i++) {
            if (strstr(message, keywords[i]) != NULL) {
                printf("Alert! Detected a possible intrusion attempt: %s\n", message);
                return;
            }
        }
        current = current->next;
    }
}

int main() {
    Node* messages = NULL;
    FILE* file_ptr = fopen("messages.txt", "r");
    if (file_ptr == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file_ptr) != NULL) {
        char* message = (char*)malloc(strlen(line) + 1);
        strcpy(message, line);
        add_message(&messages, message);
    }
    fclose(file_ptr);
    search_message(messages);
    return 0;
}