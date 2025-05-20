//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    double income;
} Person;

typedef struct {
    int count;
    Person *people;
} PersonList;

int main() {
    PersonList myList;

    // create list of people
    myList.count = 4;
    myList.people = malloc(sizeof(Person) * myList.count);

    // add people to list
    strcpy(myList.people[0].name, "John");
    myList.people[0].age = 25;
    myList.people[0].income = 30000.0;

    strcpy(myList.people[1].name, "Mary");
    myList.people[1].age = 35;
    myList.people[1].income = 50000.0;

    strcpy(myList.people[2].name, "Bob");
    myList.people[2].age = 28;
    myList.people[2].income = 35000.0;

    strcpy(myList.people[3].name, "Jane");
    myList.people[3].age = 42;
    myList.people[3].income = 70000.0;

    // sort people by age
    for (int i = 0; i < myList.count - 1; i++) {
        for (int j = i + 1; j < myList.count; j++) {
            if (myList.people[i].age > myList.people[j].age) {
                Person temp = myList.people[i];
                myList.people[i] = myList.people[j];
                myList.people[j] = temp;
            }
        }
    }

    // print people sorted by age
    printf("People sorted by age:\n");
    for (int i = 0; i < myList.count; i++) {
        printf("%s, %d years old, $%.2lf income\n", myList.people[i].name, myList.people[i].age, myList.people[i].income);
    }

    // calculate average income
    double totalIncome = 0.0;
    for (int i = 0; i < myList.count; i++) {
        totalIncome += myList.people[i].income;
    }
    double averageIncome = totalIncome / myList.count;

    // print people with above average income
    printf("\nPeople with above average income:\n");
    for (int i = 0; i < myList.count; i++) {
        if (myList.people[i].income > averageIncome) {
            printf("%s, %d years old, $%.2lf income\n", myList.people[i].name, myList.people[i].age, myList.people[i].income);
        }
    }

    return 0;
}