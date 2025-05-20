//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char *name;
    float price;
    int quantity;
} product;

typedef struct node {
    product *data;
    struct node *next;
} node;

typedef struct linked_list {
    node *head;
    node *tail;
} linked_list;

linked_list *create_linked_list() {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_product(linked_list *list, product *p) {
    node *new_node = malloc(sizeof(node));
    new_node->data = p;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

product *find_product_by_id(linked_list *list, int id) {
    node *current = list->head;
    while (current != NULL) {
        if (current->data->id == id) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void remove_product_by_id(linked_list *list, int id) {
    node *current = list->head;
    node *previous = NULL;
    while (current != NULL) {
        if (current->data->id == id) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_linked_list(linked_list *list) {
    node *current = list->head;
    while (current != NULL) {
        printf("Product ID: %d, Name: %s, Price: %f, Quantity: %d\n", current->data->id, current->data->name, current->data->price, current->data->quantity);
        current = current->next;
    }
}

void free_linked_list(linked_list *list) {
    node *current = list->head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    linked_list *list = create_linked_list();

    product *p1 = malloc(sizeof(product));
    p1->id = 1;
    p1->name = strdup("Product 1");
    p1->price = 10.0;
    p1->quantity = 10;
    add_product(list, p1);

    product *p2 = malloc(sizeof(product));
    p2->id = 2;
    p2->name = strdup("Product 2");
    p2->price = 20.0;
    p2->quantity = 20;
    add_product(list, p2);

    product *p3 = malloc(sizeof(product));
    p3->id = 3;
    p3->name = strdup("Product 3");
    p3->price = 30.0;
    p3->quantity = 30;
    add_product(list, p3);

    print_linked_list(list);

    product *found_product = find_product_by_id(list, 2);
    if (found_product != NULL) {
        printf("Found product: %s\n", found_product->name);
    } else {
        printf("Product not found\n");
    }

    remove_product_by_id(list, 2);

    print_linked_list(list);

    free_linked_list(list);

    return 0;
}