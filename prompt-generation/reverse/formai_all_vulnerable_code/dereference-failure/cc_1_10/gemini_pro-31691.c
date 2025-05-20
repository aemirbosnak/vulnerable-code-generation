//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int age;
    char *gender;
    char *occupation;
    double salary;
} person;

person *generate_random_person() {
    person *p = malloc(sizeof(person));
    p->age = rand() % 100;
    p->gender = malloc(sizeof(char) * 10);
    strcpy(p->gender, rand() % 2 == 0 ? "male" : "female");
    p->occupation = malloc(sizeof(char) * 20);
    strcpy(p->occupation, rand() % 3 == 0 ? "student" : (rand() % 2 == 0 ? "doctor" : "lawyer"));
    p->salary = rand() % 1000000;
    return p;
}

void print_person(person *p) {
    printf("Age: %d\n", p->age);
    printf("Gender: %s\n", p->gender);
    printf("Occupation: %s\n", p->occupation);
    printf("Salary: %.2f\n", p->salary);
}

int compare_persons(const void *a, const void *b) {
    const person *p1 = (const person *)a;
    const person *p2 = (const person *)b;
    return p1->age - p2->age;
}

int main() {
    srand(time(NULL));
    int n = rand() % 1000;
    person *people = malloc(sizeof(person) * n);
    for (int i = 0; i < n; i++) {
        people[i] = *generate_random_person();
    }
    qsort(people, n, sizeof(person), compare_persons);
    for (int i = 0; i < n; i++) {
        print_person(&people[i]);
        printf("\n");
    }
    return 0;
}