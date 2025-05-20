//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    float height;
} Person;

void create(Person *person, char *name) {
    person->name = (char *)malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = 0;
    person->height = 0.0;
}

void setAge(Person *person, int age) {
    person->age = age;
}

void setHeight(Person *person, float height) {
    person->height = height;
}

int compare(Person *person1, Person *person2) {
    if (person1->age > person2->age)
        return 1;
    else if (person1->age < person2->age)
        return -1;
    else
        return 0;
}

void swap(Person *person1, Person *person2) {
    Person temp;
    temp = *person1;
    *person1 = *person2;
    *person2 = temp;
}

void print(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %f\n", person->height);
}

int main() {
    Person *people = (Person *)malloc(MAX_SIZE * sizeof(Person));
    int count = 0;

    create(&people[count], "John");
    setAge(&people[count], 25);
    setHeight(&people[count], 1.8);
    count++;

    create(&people[count], "Jane");
    setAge(&people[count], 30);
    setHeight(&people[count], 1.7);
    count++;

    create(&people[count], "Bob");
    setAge(&people[count], 20);
    setHeight(&people[count], 1.9);
    count++;

    printf("Before sorting:\n");
    for (int i = 0; i < count; i++) {
        print(&people[i]);
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (compare(&people[i], &people[j]) > 0) {
                swap(&people[i], &people[j]);
            }
        }
    }

    printf("\nAfter sorting by age:\n");
    for (int i = 0; i < count; i++) {
        print(&people[i]);
    }

    free(people);
    return 0;
}