//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 20

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insert(Node* head, int value) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    current->next = new_node;
}

void display_list(Node* head) {
    Node* current = head->next;
    printf("HEAD -> ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void destroy_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

void draw_node() {
    int random_num = rand() % 10 + 1;
    if (random_num == 1) {
        printf("\033[31m");
    }
    else if (random_num == 2) {
        printf("\033[32m");
    }
    else if (random_num == 3) {
        printf("\033[33m");
    }
    else if (random_num == 4) {
        printf("\033[34m");
    }
    else if (random_num == 5) {
        printf("\033[35m");
    }
    else if (random_num == 6) {
        printf("\033[36m");
    }
    else if (random_num == 7) {
        printf("\033[37m");
    }
    else if (random_num == 8) {
        printf("\033[1;31m");
    }
    else if (random_num == 9) {
        printf("\033[1;32m");
    }
    else {
        printf("\033[1;33m");
    }
    printf("O");
    printf("\033[0m");
}

void visualize_list(Node* head) {
    system("clear");
    Node* current = head->next;
    printf("LIST\n");
    printf("HEAD -> ");
    while (current != NULL) {
        draw_node();
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    srand(time(NULL));
    Node* head = malloc(sizeof(Node));
    head->value = -1;
    head->next = NULL;
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        insert(head, i);
    }
    while (1) {
        display_list(head);
        visualize_list(head);
        delay(1);
    }
    destroy_list(head);
    return 0;
}