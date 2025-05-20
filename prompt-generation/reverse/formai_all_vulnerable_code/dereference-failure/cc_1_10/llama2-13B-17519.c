//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 50
#define MAX_OBJS 10

typedef struct obj {
    char *name;
    int age;
    struct obj *next;
} obj_t;

typedef struct {
    obj_t *head;
    obj_t *tail;
} obj_list_t;

void init_list(obj_list_t *list) {
    list->head = NULL;
    list->tail = NULL;
}

void add_obj(obj_list_t *list, char *name, int age) {
    obj_t *new_obj = malloc(sizeof(obj_t));
    new_obj->name = name;
    new_obj->age = age;
    new_obj->next = NULL;

    if (list->head == NULL) {
        list->head = new_obj;
    } else {
        list->tail->next = new_obj;
    }
    list->tail = new_obj;
}

void print_list(obj_list_t *list) {
    obj_t *curr = list->head;
    while (curr != NULL) {
        printf("%s %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main() {
    srand(time(NULL));

    obj_list_t *list = malloc(sizeof(obj_list_t));
    init_list(list);

    for (int i = 0; i < MAX_OBJS; i++) {
        char *name = malloc(sizeof(char) * MAX_STRLEN);
        int age = rand() % 100;

        add_obj(list, name, age);
    }

    print_list(list);

    return 0;
}