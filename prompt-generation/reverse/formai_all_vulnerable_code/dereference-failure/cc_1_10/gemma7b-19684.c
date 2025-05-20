//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char name[256];
    int pid;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} linked_list;

void insert_node(linked_list *list, char *name, int pid) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->pid = pid;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void scan_system(linked_list *list) {
    pid_t pid;
    char name[256];

    for (pid = 0; pid < getpid() + 1; pid++) {
        snprintf(name, 256, "/proc/%d/name", pid);
        FILE *file = fopen(name, "r");
        fscanf(file, "%s", name);
        fclose(file);

        insert_node(list, name, pid);
    }
}

int main() {
    linked_list list;
    list.head = NULL;
    list.tail = NULL;

    scan_system(&list);

    node *current_node = list.head;
    while (current_node) {
        printf("Name: %s, PID: %d\n", current_node->name, current_node->pid);
        current_node = current_node->next;
    }

    return 0;
}