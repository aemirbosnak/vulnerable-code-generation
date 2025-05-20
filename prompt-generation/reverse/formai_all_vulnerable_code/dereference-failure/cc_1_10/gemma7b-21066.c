//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void sanitizeUrl(char* url) {
    Node* head = insertAtTail(NULL, url[0]);
    for (int i = 1; url[i] != '\0'; i++) {
        insertAtTail(head, url[i]);
    }

    char sanitizedUrl[MAX_BUFFER_SIZE] = "";
    Node* current = head;
    while (current) {
        if (current->data >= 'a' && current->data <= 'z') {
            sanitizedUrl[0] = 'a';
            sanitizedUrl[1] = current->data - 'a' + 'A';
            sanitizedUrl[2] = '\0';
        } else if (current->data >= 'A' && current->data <= 'Z') {
            sanitizedUrl[0] = 'A';
            sanitizedUrl[1] = current->data - 'A' + 'a';
            sanitizedUrl[2] = '\0';
        } else if (current->data >= '0' && current->data <= '9') {
            sanitizedUrl[0] = '0';
            sanitizedUrl[1] = current->data - '0' + 'a';
            sanitizedUrl[2] = '\0';
        } else if (current->data == '-') {
            sanitizedUrl[0] = '-';
            sanitizedUrl[1] = '\0';
        } else {
            sanitizedUrl[0] = current->data;
            sanitizedUrl[1] = '\0';
        }

        strcat(sanitizedUrl, "_");
        current = current->next;
    }

    printf("Sanitized URL: %s\n", sanitizedUrl);
}

int main() {
    char url[] = "abc-123!@#$%^&*";
    sanitizeUrl(url);

    return 0;
}