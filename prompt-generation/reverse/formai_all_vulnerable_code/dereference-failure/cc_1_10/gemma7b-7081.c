//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define LL long long
#define UL unsigned long long

typedef struct Node {
    LL data;
    struct Node* next;
} Node;

Node* parse_syntax(char* str) {
    Node* head = NULL;
    LL num = 0;
    char* ptr = str;

    while (*ptr) {
        if (*ptr >= 'a' && *ptr <= 'z') {
            num = num * 10 + *ptr - 'a' + 1;
        } else if (*ptr >= 'A' && *ptr <= 'Z') {
            num = num * 10 + *ptr - 'A' + 1;
        } else if (*ptr >= '0' && *ptr <= '9') {
            num = num * 10 + *ptr - '0';
        } else if (*ptr == '+') {
            Node* newNode = malloc(sizeof(Node));
            newNode->data = num;
            newNode->next = head;
            head = newNode;
            num = 0;
        } else if (*ptr == '-') {
            num = -num;
        } else if (*ptr == '(') {
            Node* newNode = malloc(sizeof(Node));
            newNode->data = num;
            newNode->next = head;
            head = newNode;
            num = 0;
            ptr++;
            parse_syntax(ptr);
            ptr--;
        } else if (*ptr == ')') {
            num = 0;
        } else if (*ptr == ')') {
            num = 0;
        }
        ptr++;
    }

    return head;
}

int main() {
    char* str = "12+3(4)-5)";
    Node* head = parse_syntax(str);

    while (head) {
        printf("%lld ", head->data);
        head = head->next;
    }

    return 0;
}