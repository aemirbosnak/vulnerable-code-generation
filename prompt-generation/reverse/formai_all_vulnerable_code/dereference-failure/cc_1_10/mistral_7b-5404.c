//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct Node {
    void *data;
    size_t size;
    struct Node *next;
} Node;

Node *head = NULL;

void *kmalloc(size_t size) {
    Node *newNode, *current, *prev;

    if ((newNode = mmap(NULL, size + sizeof(Node), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    newNode->size = size;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return (char *) newNode + sizeof(Node);
    }

    current = head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
    return (char *) newNode + sizeof(Node);
}

void kfree(void *ptr) {
    Node *node;

    if (head == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    node = (Node *) ((char *) head - sizeof(Node));
    while (node->next != NULL && node->next < (Node *) ptr) {
        node = node->next;
    }

    if (node->next == NULL) {
        fprintf(stderr, "Invalid pointer\n");
        exit(EXIT_FAILURE);
    }

    node->size += ((Node *) ptr)->size;
    node->next = node->next->next;

    munmap((void *) ((char *) node + sizeof(Node)), node->size + sizeof(Node));
}

int main() {
    char *str1, *str2, *str3;
    int i;

    str1 = (char *) kmalloc(100);
    strcpy(str1, "Hello, World!");

    str2 = (char *) kmalloc(50);
    strcpy(str2, "Ken");

    str3 = (char *) kmalloc(strlen(str1) + strlen(str2) + 1);

    strcat(str3, str1);
    strcat(str3, str2);

    printf("%s\n", str3);

    for (i = 0; i < 100; i++) {
        char c = str3[i];
        str3[i] = str3[i + strlen(str2)];
        str3[i + strlen(str2)] = c;
    }

    kfree(str3);
    kfree(str2);
    kfree(str1);

    return EXIT_SUCCESS;
}