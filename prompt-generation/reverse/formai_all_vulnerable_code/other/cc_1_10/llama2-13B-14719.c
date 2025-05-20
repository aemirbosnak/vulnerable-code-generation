//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJS 10
#define MAX_NAME_LEN 20

typedef struct obj_t {
    void* data;   // data stored in the object
    size_t size;  // size of the object
    struct obj_t* next; // next object in the list
} obj_t;

typedef struct {
    obj_t* head; // head of the object list
    obj_t* tail; // tail of the object list
} mem_t;

void init_mem(mem_t* mem) {
    mem->head = NULL;
    mem->tail = NULL;
}

void* alloc_obj(mem_t* mem, size_t size) {
    void* data = malloc(size);
    if (data == NULL) {
        printf("Error: unable to allocate memory\n");
        return NULL;
    }
    obj_t* obj = (obj_t*)data;
    obj->size = size;
    obj->next = NULL;
    if (mem->head == NULL) {
        mem->head = obj;
        mem->tail = obj;
    } else {
        mem->tail->next = obj;
        mem->tail = obj;
    }
    return data;
}

void free_obj(mem_t* mem, void* data) {
    obj_t* obj = (obj_t*)data;
    if (obj == NULL) {
        printf("Error: null pointer passed to free_obj\n");
        return;
    }
    if (obj == mem->head) {
        mem->head = obj->next;
    } else if (obj == mem->tail) {
        mem->tail = obj->next;
    }
    free(obj);
}

int main() {
    mem_t mem;
    init_mem(&mem);

    void* p1 = alloc_obj(&mem, 10);
    void* p2 = alloc_obj(&mem, 20);
    void* p3 = alloc_obj(&mem, 30);

    // check for memory leaks
    assert(mem.head == mem.tail);

    free_obj(&mem, p3);
    free_obj(&mem, p2);
    free_obj(&mem, p1);

    // check for correctness of free_obj
    assert(mem.head == NULL);
    assert(mem.tail == NULL);

    return 0;
}