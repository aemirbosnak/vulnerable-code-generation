//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    void * data;
    size_t size;
    struct _node * next;
} node;

typedef struct _recovery_tool {
    node * head;
    node * tail;
} recovery_tool;

recovery_tool * new_recovery_tool() {
    recovery_tool * rt = malloc(sizeof(recovery_tool));
    rt->head = NULL;
    rt->tail = NULL;
    return rt;
}

void free_recovery_tool(recovery_tool * rt) {
    while (rt->head != NULL) {
        node * tmp = rt->head->next;
        free(rt->head->data);
        free(rt->head);
        rt->head = tmp;
    }
    free(rt);
}

void add_data(recovery_tool * rt, void * data, size_t size) {
    node * n = malloc(sizeof(node));
    n->data = data;
    n->size = size;
    n->next = NULL;
    if (rt->head == NULL) {
        rt->head = n;
        rt->tail = n;
    } else {
        rt->tail->next = n;
        rt->tail = n;
    }
}

void * get_data(recovery_tool * rt, size_t size) {
    node * n = rt->head;
    while (n != NULL) {
        if (n->size == size) {
            return n->data;
        }
        n = n->next;
    }
    return NULL;
}

void remove_data(recovery_tool * rt, size_t size) {
    node * n = rt->head;
    node * prev = NULL;
    while (n != NULL) {
        if (n->size == size) {
            if (prev == NULL) {
                rt->head = n->next;
            } else {
                prev->next = n->next;
            }
            free(n->data);
            free(n);
            return;
        }
        prev = n;
        n = n->next;
    }
}

int main() {
    recovery_tool * rt = new_recovery_tool();
    
    int i = 123;
    add_data(rt, &i, sizeof(int));

    float f = 3.14;
    add_data(rt, &f, sizeof(float));

    char * str = "Hello, world!";
    add_data(rt, str, strlen(str) + 1);

    printf("Int: %d\n", *(int *)get_data(rt, sizeof(int)));
    printf("Float: %f\n", *(float *)get_data(rt, sizeof(float)));
    printf("String: %s\n", (char *)get_data(rt, strlen(str) + 1));
    
    remove_data(rt, sizeof(int));

    printf("Int: %d\n", *(int *)get_data(rt, sizeof(int)));

    free_recovery_tool(rt);

    return 0;
}