//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} node;

typedef struct List {
    node *item;
    struct List *next;
} list;

list *createList(char character, int frequency) {
    list *newList = (list *)malloc(sizeof(list));
    newList->item = (node *)malloc(sizeof(node));
    newList->item->character = character;
    newList->item->frequency = frequency;
    newList->item->left = NULL;
    newList->item->right = NULL;
    newList->next = NULL;
    return newList;
}

list *insertList(list *head, list *newNode) {
    if (!head) {
        head = newNode;
    } else {
        list *current = head;
        list *previous = NULL;
        while (current && current->item->frequency < newNode->item->frequency) {
            previous = current;
            current = current->next;
        }
        if (!previous) {
            newNode->next = current;
            head = newNode;
        } else {
            newNode->next = previous->next;
            previous->next = newNode;
        }
    }
    return head;
}

node *buildTree(list *head) {
    while (head->next) {
        list *first = head;
        list *second = head->next;
        node *newNode = (node *)malloc(sizeof(node));
        newNode->character = '*';
        newNode->frequency = first->item->frequency + second->item->frequency;
        newNode->left = first->item;
        newNode->right = second->item;
        list *newList = createList(newNode->character, newNode->frequency);
        newList->item = newNode;
        head = head->next->next;
        head = insertList(head, newList);
    }
    return head->item;
}

void traverseTree(node *root, int *code, int depth) {
    if (!root->left && !root->right) {
        printf("%c\t%d\t", root->character, root->frequency);
        for (int i = 0; i < depth; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    } else {
        code[depth] = 0;
        traverseTree(root->left, code, depth + 1);
        code[depth] = 1;
        traverseTree(root->right, code, depth + 1);
    }
}

int main() {
    char input[] = "The quick brown fox jumps over the lazy dog";
    int freq[256] = {0};
    int code[256] = {0};
    for (int i = 0; i < strlen(input); i++) {
        freq[input[i]]++;
    }

    list *head = NULL;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            list *newList = createList(i, freq[i]);
            head = insertList(head, newList);
        }
    }

    node *root = buildTree(head);
    printf("Encoding Table:\n");
    traverseTree(root, code, 0);

    return 0;
}