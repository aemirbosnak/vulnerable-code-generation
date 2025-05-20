//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int* data;
    int size;
} List;

List* create_list(int size) {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("Failed to allocate memory for list\n");
        exit(1);
    }
    list->data = (int*)malloc(size * sizeof(int));
    if (list->data == NULL) {
        free(list);
        printf("Failed to allocate memory for list data\n");
        exit(1);
    }
    list->size = size;
    return list;
}

void print_list(List* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void append_to_list(List* list, int value) {
    if (list == NULL || list->size == MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    if (list->size == 0) {
        list->data[0] = value;
    } else {
        for (int i = list->size - 1; i >= 0; i--) {
            list->data[i + 1] = list->data[i];
        }
        list->data[0] = value;
        list->size++;
    }
}

int main() {
    List* list = create_list(5);
    append_to_list(list, 1);
    append_to_list(list, 2);
    append_to_list(list, 3);
    append_to_list(list, 4);
    print_list(list);
    append_to_list(list, 5);
    append_to_list(list, 6);
    print_list(list);
    append_to_list(list, 7);
    append_to_list(list, 8);
    print_list(list);

    return 0;
}