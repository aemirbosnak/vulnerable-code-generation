//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Vector;

Vector *create_vector() {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (Person *)malloc(MAX_SIZE * sizeof(Person));
    v->size = 0;
    v->capacity = MAX_SIZE;
    return v;
}

void destroy_vector(Vector *v) {
    free(v->data);
    free(v);
}

void push_back(Vector *v, Person p) {
    if (v->size == v->capacity) {
        printf("Vector is full. Cannot push back.\n");
        return;
    }
    v->data[v->size] = p;
    v->size++;
}

Person pop_back(Vector *v) {
    if (v->size == 0) {
        printf("Vector is empty. Cannot pop back.\n");
        return (Person){NULL, 0};
    }
    Person p = v->data[v->size - 1];
    v->size--;
    return p;
}

void print_vector(Vector *v) {
    printf("Vector: [");
    for (int i = 0; i < v->size; i++) {
        Person p = v->data[i];
        printf("(%s, %d)", p.name, p.age);
        if (i < v->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Vector *v = create_vector();

    Person p1 = {.name = "Sir Lancelot",.age = 35};
    Person p2 = {.name = "King Arthur",.age = 50};
    Person p3 = {.name = "Merlin",.age = 150};

    push_back(v, p1);
    push_back(v, p2);
    push_back(v, p3);

    print_vector(v);

    Person p4 = pop_back(v);
    printf("Popped back: (%s, %d)\n", p4.name, p4.age);

    destroy_vector(v);

    return 0;
}