//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

struct node {
    int data;
    struct node *next;
};

struct node *create_list(int n) {
    struct node *head = NULL;
    int i;
    for (i = 1; i <= n; i++) {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

void print_list(struct node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void time_travel(struct node *head, int pos, int year) {
    if (head == NULL)
        return;
    if (pos == 1) {
        printf("Current year: %d\n", year);
        printf("List: ");
        print_list(head);
    } else {
        time_travel(head->next, pos - 1, year + 1);
    }
}

int main() {
    int n, pos;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    struct node *head = create_list(n);
    printf("Original list: ");
    print_list(head);
    printf("Enter the position to time travel from: ");
    scanf("%d", &pos);
    printf("Enter the year to time travel to: ");
    scanf("%d", &pos);
    time_travel(head, pos, 0);
    return 0;
}