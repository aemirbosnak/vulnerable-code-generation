//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct list_item {
    char name[100];
    struct list_item *next;
} list_item;

typedef struct mailing_list {
    list_item *head;
    int size;
} mailing_list;

mailing_list* create_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_item(mailing_list* list, char* name) {
    list_item* new_item = malloc(sizeof(list_item));
    strcpy(new_item->name, name);
    new_item->next = NULL;
    
    if (list->head == NULL) {
        list->head = new_item;
        list->size++;
    } else {
        list_item* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_item;
        list->size++;
    }
}

void print_list(mailing_list* list) {
    list_item* current = list->head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void free_list(mailing_list* list) {
    list_item* current = list->head;
    while (current!= NULL) {
        list_item* temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}

int main() {
    mailing_list* list = create_list();
    
    add_item(list, "Alice");
    add_item(list, "Bob");
    add_item(list, "Charlie");
    
    print_list(list);
    
    free_list(list);
    
    return 0;
}