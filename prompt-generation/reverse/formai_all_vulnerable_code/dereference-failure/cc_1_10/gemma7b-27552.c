//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

int main() {
    Node* head = NULL;
    char str[100];
    int i = 0;

    printf("Enter a C syntax expression: ");
    scanf("%s", str);

    while (str[i] != '\0') {
        if (str[i] == '(') {
            Node* newNode = malloc(sizeof(Node));
            newNode->data = str[i + 1] - 'a' + 1;
            newNode->next = head;
            head = newNode;
        } else if (str[i] == ')') {
            Node* current = head;
            int parenCount = 0;
            while (current) {
                if (current->data == str[i] - 'a' + 1) {
                    parenCount++;
                    current = current->next;
                }
            }
            if (parenCount == 1) {
                head = head->next;
            }
        } else {
            i++;
        }
    }

    if (head) {
        printf("Expression parsed: ");
        while (head) {
            printf("%c ", head->data);
            head = head->next;
        }
        printf("\n");
    } else {
        printf("Error parsing expression.\n");
    }

    return 0;
}