//Gemma-7B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct MemoryManager {
    Node* head;
    int size;
} MemoryManager;

MemoryManager* mm_init() {
    MemoryManager* mm = malloc(sizeof(MemoryManager));
    mm->head = NULL;
    mm->size = 0;
    return mm;
}

void mm_insert(MemoryManager* mm, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (mm->head == NULL) {
        mm->head = newNode;
    } else {
        mm->head->next = newNode;
    }

    mm->size++;
}

void mm_free(MemoryManager* mm, int data) {
    Node* prev = NULL;
    Node* current = mm->head;

    while (current) {
        if (current->data == data) {
            if (prev) {
                prev->next = current->next;
            } else {
                mm->head = current->next;
            }

            free(current);
            mm->size--;
            return;
        }

        prev = current;
        current = current->next;
    }

    return;
}

int main() {
    MemoryManager* mm = mm_init();

    mm_insert(mm, 10);
    mm_insert(mm, 20);
    mm_insert(mm, 30);
    mm_insert(mm, 40);

    mm_free(mm, 20);

    for (Node* current = mm->head; current; current = current->next) {
        printf("%d ", current->data);
    }

    printf("\n");
    printf("Size: %d\n", mm->size);

    return 0;
}