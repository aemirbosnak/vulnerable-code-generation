//FormAI DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL 1024

typedef struct node {
    int id;
    char url[MAX_URL];
    struct node* next;
} Node;

Node* head = NULL;

bool id_exists(int id) {
    Node* current = head;
    while(current != NULL) {
        if(current->id == id) {
            return true;
        }
        current = current->next;
    }
    return false;
}

Node* get_node_by_id(int id) {
    Node* current = head;
    while(current != NULL) {
        if(current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_node(int id, char* url) {
    if(id_exists(id)) {
        printf("Error: ID already exists!\n");
        return;
    }
    if(strlen(url) >= MAX_URL) {
        printf("Error: URL too long!\n");
        return;
    }
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->id = id;
    strcpy(new_node->url, url);
    new_node->next = NULL;
    if(head == NULL) {
        head = new_node;
        return;
    }
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void remove_node(int id) {
    if(head == NULL) {
        printf("Error: Empty list!\n");
        return;
    }
    Node* current = head;
    Node* prev = current;
    while(current != NULL) {
        if(current->id == id) {
            if(current == head) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Node %d removed successfully.\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Error: ID not found!\n");
}

void print_list() {
    if(head == NULL) {
        printf("Empty list.\n");
        return;
    }
    Node* current = head;
    while(current != NULL) {
        printf("ID: %d, URL: %s\n", current->id, current->url);
        current = current->next;
    }
}

int main() {
    add_node(1, "https://www.google.com");
    add_node(2, "https://www.youtube.com");
    add_node(3, "https://www.amazon.com");
    print_list();
    remove_node(2);
    print_list();
    return 0;
}