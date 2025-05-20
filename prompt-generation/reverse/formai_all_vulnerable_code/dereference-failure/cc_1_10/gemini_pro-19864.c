//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product;

product *create_product(int id, char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    p->id = id;
    p->name = strdup(name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

void destroy_product(product *p) {
    free(p->name);
    free(p);
}

typedef struct node {
    product *data;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

list *create_list() {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void destroy_list(list *l) {
    node *current = l->head;
    while (current != NULL) {
        node *next = current->next;
        destroy_product(current->data);
        free(current);
        current = next;
    }
    free(l);
}

void add_product(list *l, product *p) {
    node *n = malloc(sizeof(node));
    n->data = p;
    n->next = NULL;
    if (l->head == NULL) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}

product *get_product(list *l, int id) {
    node *current = l->head;
    while (current != NULL) {
        if (current->data->id == id) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void remove_product(list *l, int id) {
    node *current = l->head;
    node *previous = NULL;
    while (current != NULL) {
        if (current->data->id == id) {
            if (previous == NULL) {
                l->head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == l->tail) {
                l->tail = previous;
            }
            destroy_product(current->data);
            free(current);
            l->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_list(list *l) {
    node *current = l->head;
    while (current != NULL) {
        printf("%d %s %d %.2f\n", current->data->id, current->data->name, current->data->quantity, current->data->price);
        current = current->next;
    }
}

int main() {
    list *l = create_list();
    add_product(l, create_product(1, "Apple", 10, 1.00));
    add_product(l, create_product(2, "Orange", 5, 1.50));
    add_product(l, create_product(3, "Banana", 15, 2.00));

    print_list(l);

    product *p = get_product(l, 2);
    if (p != NULL) {
        printf("Found product: %d %s %d %.2f\n", p->id, p->name, p->quantity, p->price);
    } else {
        printf("Product not found.\n");
    }

    remove_product(l, 3);

    print_list(l);

    destroy_list(l);

    return 0;
}