//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *name;
    char *email;
    struct ListNode *next;
} ListNode;
ListNode *head, *tail;
void add(char *name, char *email) {
    ListNode *node = malloc(sizeof(*node));
    node->name = strdup(name);
    node->email = strdup(email);
    node->next = NULL;
    if (tail)
        tail->next = node;
    else
        head = node;
    tail = node;
}
void del(char *name) {
    ListNode *node = head, *prev = NULL;
    while (node) {
        if (!strcmp(node->name, name)) {
            if (prev)
                prev->next = node->next;
            else
                head = node->next;
            if (node == tail)
                tail = prev;
            free(node->name);
            free(node->email);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}
void print() {
    ListNode *node = head;
    while (node) {
        printf("%s: %s\n", node->name, node->email);
        node = node->next;
    }
}
int main() {
    char *command[3];
    while (scanf("%s", command[0]) != EOF) {
        scanf("%s", command[1]);
        switch (command[0][0]) {
            case 'a':
                scanf("%s", command[2]);
                add(command[1], command[2]);
                break;
            case 'd':
                del(command[1]);
                break;
            case 'p':
                print();
                break;
        }
    }
    return 0;
}