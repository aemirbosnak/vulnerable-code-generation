//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 1024
#define MAX_OBJS 10

typedef struct obj {
    char *name;
    size_t size;
    struct obj *next;
} obj_t;

void *malloc_with_name(size_t size, const char *name) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Failed to allocate memory for %s\n", name);
        return NULL;
    }
    return ptr;
}

void free_with_name(void *ptr, const char *name) {
    if (ptr == NULL) {
        printf("Trying to free NULL pointer for %s\n", name);
        return;
    }
    free(ptr);
}

int main() {
    obj_t *obj_list = NULL;
    for (int i = 0; i < MAX_OBJS; i++) {
        char name[20];
        sprintf(name, "Object %d", i);
        obj_t *obj = malloc_with_name(sizeof(obj_t), name);
        obj->name = name;
        obj->size = strlen(name) + 1;
        obj->next = obj_list;
        obj_list = obj;
    }

    for (int i = 0; i < MAX_OBJS; i++) {
        obj_t *obj = obj_list;
        obj_list = obj->next;
        free_with_name(obj, obj->name);
    }

    return 0;
}