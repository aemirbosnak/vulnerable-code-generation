//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 20
#define MAX_OBJS 10

typedef struct {
    char *name;
    size_t size;
} obj_t;

typedef struct {
    obj_t objs[MAX_OBJS];
    size_t num_objs;
} mem_t;

void init_mem(mem_t *mem) {
    mem->num_objs = 0;
    return;
}

void add_obj(mem_t *mem, char *name, size_t size) {
    obj_t *obj = (obj_t *) malloc(sizeof(obj_t));
    obj->name = name;
    obj->size = size;
    mem->objs[mem->num_objs++] = *obj;
}

void del_obj(mem_t *mem, char *name) {
    int i = 0;
    for (; i < mem->num_objs; i++) {
        if (strcmp(mem->objs[i].name, name) == 0) {
            free(mem->objs[i].name);
            mem->objs[i].name = NULL;
            break;
        }
    }
}

void print_mem(mem_t *mem) {
    int i = 0;
    for (; i < mem->num_objs; i++) {
        printf("%s: %zu\n", mem->objs[i].name, mem->objs[i].size);
    }
}

int main() {
    mem_t mem;
    init_mem(&mem);

    add_obj(&mem, "obj1", 10);
    add_obj(&mem, "obj2", 20);
    add_obj(&mem, "obj3", 30);

    del_obj(&mem, "obj2");

    print_mem(&mem);

    return 0;
}