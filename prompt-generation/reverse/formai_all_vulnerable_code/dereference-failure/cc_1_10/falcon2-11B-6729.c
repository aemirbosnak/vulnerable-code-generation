//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <string.h>

struct list_entry {
    char name[50];
    struct list_entry *next;
};

struct list {
    struct list_entry *head;
    struct list_entry *tail;
};

void add_entry(struct list *list, char *name) {
    struct list_entry *new_entry = malloc(sizeof(struct list_entry));
    if (new_entry == NULL) {
        printf("Error: Failed to allocate memory\n");
        return;
    }
    strcpy(new_entry->name, name);
    new_entry->next = NULL;
    if (list->head == NULL) {
        list->head = new_entry;
        list->tail = new_entry;
    } else {
        list->tail->next = new_entry;
        list->tail = new_entry;
    }
}

void print_list(struct list *list) {
    struct list_entry *current = list->head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    struct list *list = malloc(sizeof(struct list));
    if (list == NULL) {
        printf("Error: Failed to allocate memory\n");
        return 1;
    }
    list->head = NULL;
    list->tail = NULL;
    
    add_entry(list, "Alice");
    add_entry(list, "Bob");
    add_entry(list, "Charlie");
    print_list(list);
    
    return 0;
}