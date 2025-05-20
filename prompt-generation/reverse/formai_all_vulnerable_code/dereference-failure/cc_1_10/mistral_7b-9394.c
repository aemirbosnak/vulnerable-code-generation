//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#define WIDTH 60
#define HEIGHT 20
#define SIZE 4096
typedef struct Node {
    int data;
    struct Node* next;
} Node;
void draw_box(int x, int y, int len, int w) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%c", (i < y || i > y + HEIGHT || i == x || i == x + WIDTH) ? '#' : ' ');
        if (i == x + WIDTH - 1) putchar('\n');
    }
}
void draw_line(int x, int y, int len) {
    int i;
    for (i = 0; i < len; i++) putchar((i < y || i > y + HEIGHT) ? '#' : '*');
    putchar('\n');
}
void print_list(Node* head) {
    Node* current = head;
    int i;
    while (current != NULL) {
        draw_line(WIDTH / 2 + i * 5, HEIGHT / 2, 10);
        printf("%d\n", current->data);
        current = current->next;
        i++;
    }
}
void create_list(Node** head, int size) {
    Node* current, * new_node;
    int i;
    *head = NULL;
    for (i = 0; i < size; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        new_node->data = rand() % 100;
        new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
        } else {
            current = *head;
            while (current->next != NULL) current = current->next;
            current->next = new_node;
        }
    }
}
int main() {
    srand(time(NULL));
    Node* list_head;
    create_list(&list_head, SIZE);
    draw_box(0, 0, WIDTH, HEIGHT);
    print_list(list_head);
    usleep(500000);
    munmap((void*)list_head, SIZE * sizeof(Node));
    return 0;
}