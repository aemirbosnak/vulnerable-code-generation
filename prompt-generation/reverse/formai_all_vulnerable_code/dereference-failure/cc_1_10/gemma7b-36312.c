//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 256

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertNode(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int convertHex(char* str) {
    int i = 0;
    int num = 0;
    int digit = 0;
    Node* head = NULL;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'f') {
            digit = str[i] - 'a' + 10;
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            digit = str[i] - 'A' + 10;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digit = str[i] - '0';
        }

        insertNode(&head, digit);
    }

    while (head) {
        num = num * 16 + head->data;
        head = head->next;
    }

    return num;
}

int main() {
    char* str = "A1B";
    int num = convertHex(str);
    printf("%d", num);

    return 0;
}