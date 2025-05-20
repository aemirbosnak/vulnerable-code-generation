//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int capacity;
    int count;
} Restaurant;

typedef struct {
    char *name;
    int age;
} Person;

void init_restaurant(Restaurant *r, char *name, int capacity) {
    r->name = strdup(name);
    r->capacity = capacity;
    r->count = 0;
}

void add_person(Restaurant *r, Person *p) {
    if (r->count >= r->capacity) {
        printf("Sorry, the restaurant is full.\n");
        return;
    }
    r->count++;
    printf("Welcome, %s! Enjoy your meal.\n", p->name);
}

void remove_person(Restaurant *r) {
    if (r->count == 0) {
        printf("There's no one in the restaurant.\n");
        return;
    }
    r->count--;
    printf("Goodbye! Hope to see you again soon.\n");
}

int main() {
    Restaurant r1, r2;
    Person p1, p2, p3;

    init_restaurant(&r1, "Happy Restaurant 1", 10);
    init_restaurant(&r2, "Happy Restaurant 2", 20);

    add_person(&r1, &p1);
    add_person(&r1, &p2);
    add_person(&r1, &p3);

    remove_person(&r1);
    remove_person(&r1);

    add_person(&r2, &p1);
    add_person(&r2, &p2);
    add_person(&r2, &p3);

    remove_person(&r2);
    remove_person(&r2);

    return 0;
}