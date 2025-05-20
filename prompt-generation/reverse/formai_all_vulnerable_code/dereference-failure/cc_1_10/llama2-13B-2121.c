//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to store person information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person_t;

// Function to create a new person
person_t* create_person(char* name, int age) {
    person_t* p = malloc(sizeof(person_t));
    strcpy(p->name, name);
    p->age = age;
    return p;
}

// Function to print a person's information
void print_person(person_t* p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

// Function to calculate and print the person's birthday
void print_birthday(person_t* p) {
    time_t now = time(NULL);
    struct tm current_time;
    localtime_r(&now, &current_time);
    char birthday[20];
    strftime(birthday, sizeof(birthday), "%m/%d/%Y", &current_time);
    printf("Birthday: %s\n", birthday);
}

int main() {
    person_t* p1 = create_person("Alice", 25);
    person_t* p2 = create_person("Bob", 30);
    person_t* p3 = create_person("Charlie", 35);

    print_person(p1);
    print_person(p2);
    print_person(p3);

    print_birthday(p1);
    print_birthday(p2);
    print_birthday(p3);

    return 0;
}