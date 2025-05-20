//FormAI DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ebook {
    char title[100];
    char author[100];
    char publisher[100];
    int year_published;
    char filepath[100];
} Ebook;

typedef struct node {
    Ebook ebook;
    struct node* next;
} Node;

typedef struct linkedlist {
    Node* head;
    Node* tail;
    int count;
} LinkedList;

void initialize_list(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

Node* create_node(Ebook ebook) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->ebook = ebook;
    new_node->next = NULL;
    return new_node;
}

void add_to_list(LinkedList* list, Ebook ebook) {
    Node* new_node = create_node(ebook);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->count++;
}

void remove_from_list(LinkedList* list, Ebook ebook) {
    Node* current_node = list->head;
    Node* previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->ebook.title, ebook.title) == 0) {
            if (current_node == list->head) {
                list->head = current_node->next;
            } else if (current_node == list->tail) {
                list->tail = previous_node;
                previous_node->next = NULL;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            list->count--;
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

void display_list(LinkedList* list) {
    Node* current_node = list->head;
    while (current_node != NULL) {
        printf("Title: %s\n", current_node->ebook.title);
        printf("Author: %s\n", current_node->ebook.author);
        printf("Publisher: %s\n", current_node->ebook.publisher);
        printf("Year published: %d\n", current_node->ebook.year_published);
        printf("File path: %s\n", current_node->ebook.filepath);
        printf("\n");
        current_node = current_node->next;
    }
}

int main() {
    LinkedList list;
    initialize_list(&list);
    Ebook ebook1 = {.title = "C Programming", .author = "John Doe", .publisher = "ABC Publishing", .year_published = 2020, .filepath = "c_programming.pdf"};
    Ebook ebook2 = {.title = "Data Structures and Algorithms", .author = "Jane Doe", .publisher = "XYZ Publishing", .year_published = 2019, .filepath = "dsa.pdf"};
    Ebook ebook3 = {.title = "Object Oriented Programming", .author = "Bob Smith", .publisher = "MNO Publishing", .year_published = 2021, .filepath = "oop.pdf"};

    add_to_list(&list, ebook1);
    add_to_list(&list, ebook2);
    add_to_list(&list, ebook3);

    printf("List before removing ebook:\n");
    display_list(&list);

    Ebook ebook_to_remove = {.title = "Data Structures and Algorithms", .author = "Jane Doe", .publisher = "XYZ Publishing", .year_published = 2019, .filepath = "dsa.pdf"};
    remove_from_list(&list, ebook_to_remove);

    printf("List after removing ebook:\n");
    display_list(&list);

    return 0;
}