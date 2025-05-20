//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STRLEN 1024
#define MAX_OBJS 10

typedef struct obj_t {
    char *name;
    int age;
    struct obj_t *next;
} obj_t;

void *malloc_custom(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

void free_custom(void *ptr) {
    free(ptr);
}

int main() {
    obj_t *obj_list = NULL;
    char *str = NULL;

    // Create a list of objects
    for (int i = 0; i < MAX_OBJS; i++) {
        obj_t *new_obj = (obj_t *)malloc_custom(sizeof(obj_t));
        new_obj->name = (char *)malloc_custom(MAX_STRLEN);
        new_obj->age = i % 2 == 0 ? 25 : 35;
        strcpy(new_obj->name, "Object ");
        strcat(new_obj->name, (i + 1) % 2 == 0 ? "A" : "B");
        new_obj->next = obj_list;
        obj_list = new_obj;
    }

    // Use the objects
    for (int i = 0; i < MAX_OBJS; i++) {
        obj_t *curr_obj = obj_list;
        printf("Object %d: %s, age %d\n", i + 1, curr_obj->name, curr_obj->age);
        curr_obj = curr_obj->next;
    }

    // Free the memory
    for (obj_t *curr_obj = obj_list; curr_obj != NULL; ) {
        obj_t *next_obj = curr_obj->next;
        free_custom(curr_obj->name);
        free_custom(curr_obj);
        curr_obj = next_obj;
    }

    return 0;
}