//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_OBJS 10

typedef struct {
    char *name;
    int age;
} person;

void *malloc_fn(size_t size) {
    // simulate a slow memory allocator
    int i = 0;
    while (i < size) {
        if (i % 2 == 0) {
            // allocate even-sized blocks twice as slow
            sleep(1);
        } else {
            // allocate odd-sized blocks three times as slow
            sleep(3);
        }
        i++;
    }
    return malloc(size);
}

void free_fn(void *ptr) {
    // simulate a slow free function
    int i = 0;
    while (i < 10) {
        printf("Freeing memory... %d\n", i++);
        sleep(1);
    }
    free(ptr);
}

int main() {
    // create some objects
    person *p1 = malloc_fn(sizeof(person));
    person *p2 = malloc_fn(sizeof(person));
    person *p3 = malloc_fn(sizeof(person));

    // set some data
    p1->name = "Alice";
    p1->age = 25;
    p2->name = "Bob";
    p2->age = 30;
    p3->name = "Charlie";
    p3->age = 35;

    // print the objects
    printf("Objects:\n");
    printf("p1: %s, age: %d\n", p1->name, p1->age);
    printf("p2: %s, age: %d\n", p2->name, p2->age);
    printf("p3: %s, age: %d\n", p3->name, p3->age);

    // free the objects
    free_fn(p1);
    free_fn(p2);
    free_fn(p3);

    return 0;
}