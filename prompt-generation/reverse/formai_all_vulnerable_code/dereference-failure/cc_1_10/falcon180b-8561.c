//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    int score;
} Person;

int compare(const void *a, const void *b) {
    const Person *p1 = a;
    const Person *p2 = b;
    if (p1->score > p2->score) {
        return -1;
    } else if (p1->score < p2->score) {
        return 1;
    } else {
        return 0;
    }
}

void print_person(const Person *p) {
    printf("Name: %s, Age: %d, Score: %d\n", p->name, p->age, p->score);
}

int main() {
    int num_people = 1000000;
    Person *people = malloc(num_people * sizeof(Person));
    if (people == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }
    for (int i = 0; i < num_people; i++) {
        people[i].name = malloc(10 * sizeof(char));
        if (people[i].name == NULL) {
            printf("Failed to allocate memory.\n");
            return 1;
        }
        sprintf(people[i].name, "Person %d", i);
        people[i].age = rand() % 100;
        people[i].score = rand() % 100;
    }
    qsort(people, num_people, sizeof(Person), compare);
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }
    free(people);
    return 0;
}