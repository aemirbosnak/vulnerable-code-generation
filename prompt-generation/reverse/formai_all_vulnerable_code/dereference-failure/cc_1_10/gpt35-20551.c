//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char address[100];
} Person;

int main() {
    Person *people = malloc(sizeof(Person) * 5);
    strcpy(people[0].name, "John Doe");
    people[0].age = 25;
    strcpy(people[0].gender, "Male");
    strcpy(people[0].address, "1234 Main St, Anytown USA");

    strcpy(people[1].name, "Jane Smith");
    people[1].age = 32;
    strcpy(people[1].gender, "Female");
    strcpy(people[1].address, "5678 Elm St, Anycity USA");

    strcpy(people[2].name, "Bob Johnson");
    people[2].age = 45;
    strcpy(people[2].gender, "Male");
    strcpy(people[2].address, "9999 Oak St, Anyville USA");

    strcpy(people[3].name, "Mary Brown");
    people[3].age = 31;
    strcpy(people[3].gender, "Female");
    strcpy(people[3].address, "5555 Maple St, Anystate USA");

    strcpy(people[4].name, "Tom Wilson");
    people[4].age = 55;
    strcpy(people[4].gender, "Male");
    strcpy(people[4].address, "7777 Pine St, Anycity USA");

    int i;
    for(i=0; i<5; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Gender: %s\n", people[i].gender);
        printf("Address: %s\n\n", people[i].address);
    }

    free(people);

    return 0;
}