//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int data;
    int next;
} Node;

Node* create_list(int n) {
    Node* list = malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        list[i].data = i;
        list[i].next = i + 1;
    }
    list[n - 1].next = 0;
    return list;
}

void free_list(Node* list) {
    free(list);
}

Node* shuffle_list(Node* list) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int j = rand() % 10;
        Node tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
    }
    return list;
}

void print_list(Node* list) {
    Node* curr = list;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node* list = create_list(10);
    printf("Original list:\n");
    print_list(list);

    Node* shuffled_list = shuffle_list(list);
    printf("Shuffled list:\n");
    print_list(shuffled_list);

    free_list(list);
    free_list(shuffled_list);
    return 0;
}