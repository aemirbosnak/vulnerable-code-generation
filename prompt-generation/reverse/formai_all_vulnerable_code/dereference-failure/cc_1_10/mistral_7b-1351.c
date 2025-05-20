//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <ctype.h>

#define BITMAP_SIZE 64
#define BMP_SIZE (BITMAP_SIZE + sizeof(unsigned int) * 2)
#define NODE_SIZE sizeof(struct Node)
#define LIST_SIZE 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Bitmap {
    unsigned int *bits;
    unsigned int width;
    unsigned int height;
} Bitmap;

void init_bitmap(Bitmap *bitmap) {
    bitmap->bits = mmap(NULL, BITMAP_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    bitmap->width = BITMAP_SIZE;
    bitmap->height = 1;
    memset(bitmap->bits, 0, BITMAP_SIZE);
}

void set_pixel(Bitmap *bitmap, int x) {
    bitmap->bits[x / 32] |= (1 << (x % 32));
}

void print_bitmap(Bitmap *bitmap) {
    int i, j;
    for (i = 0; i < bitmap->height; i++) {
        for (j = 0; j < bitmap->width; j++) {
            if (bitmap->bits[i] & (1 << j))
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

void add_to_list(Node **head, int data) {
    Node *new_node = (Node *) malloc(NODE_SIZE);
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void visualize_list(Node *head, Bitmap *bitmap) {
    int i;
    Node *current = head;
    int size = 0;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    if (size > LIST_SIZE) {
        printf("List too long to visualize\n");
        return;
    }

    for (i = 0; i < size; i++) {
        set_pixel(bitmap, i);
        add_to_list(&head, i);
    }

    print_list(head);
    print_bitmap(bitmap);
}

int main() {
    Node *head = NULL;
    Bitmap bitmap;
    init_bitmap(&bitmap);

    add_to_list(&head, 5);
    add_to_list(&head, 10);
    add_to_list(&head, 15);

    visualize_list(head, &bitmap);

    munmap(bitmap.bits, bitmap.width);

    return 0;
}