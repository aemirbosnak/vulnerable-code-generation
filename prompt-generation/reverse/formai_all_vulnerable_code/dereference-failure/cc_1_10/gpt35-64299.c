//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

struct node {
    int value;
    struct node* next;
};

typedef struct node* list;

void push(list* head, int value) {
    list new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void print_list(list head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void draw_line(int length) {
    for (int i = 0; i < length; i++)
        printf("─");
    printf("\n");
}

void draw_box(int row, int col) {
    printf("╭");
    draw_line(col);
    for (int i = 0; i < row; i++) {
        printf("│");
        for (int j = 0; j < col; j++)
            printf(" ");
        printf("│");
        printf("\n");
    }
    printf("╰");
    draw_line(col);
}

void print_header() {
    printf("╭");
    draw_line(32);
    printf("│");
    printf("   CYBERPUNK DATA STRUCTURES   ");
    printf("│");
    printf("\n╰");
    draw_line(32);
    printf("\n");
}

int main() {
    list head = NULL;
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++)
        push(&head, rand() % 10);
    print_header();
    printf("╭──────╮\n");
    printf("│ LIST │\n");
    printf("╰──────╯\n");
    print_list(head);
    printf("\n");
    int row = 6, col = 10;
    int array[MAX_SIZE][col];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < col; j++)
            array[i][j] = rand() % 10;
    }
    printf("╭──────╮\n");
    printf("│ ARRAY │\n");
    printf("╰──────╯\n");
    draw_box(row, col);
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("│");
        for (int j = 0; j < col; j++) {
            printf("%d", array[i][j]);
            printf(" ");
        }
        printf("│");
        printf("\n");
    }
    printf("╰");
    draw_line(col);
    return 0;
}