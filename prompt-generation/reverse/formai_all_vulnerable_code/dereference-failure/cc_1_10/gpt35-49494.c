//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct {
    char name[MAX_SIZE];
    int age;
    int income;
    int expenses;
    int savings;
} Person;

int main() {
    int n;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    Person* persons = (Person*) malloc(n * sizeof(Person));

    for (int i = 0; i < n; i++) {
        printf("\nEnter the name of Person %d: ", i + 1);
        scanf("%s", persons[i].name);

        printf("Enter the age of Person %d: ", i + 1);
        scanf("%d", &persons[i].age);

        printf("Enter the monthly income of Person %d: ", i + 1);
        scanf("%d", &persons[i].income);

        printf("Enter the monthly expenses of Person %d: ", i + 1);
        scanf("%d", &persons[i].expenses);

        persons[i].savings = persons[i].income - persons[i].expenses;
    }

    printf("\n\n\t\tPERSONAL FINANCE PLANNER\n\n");
    printf("------------------------------------------------------------------------\n");
    printf("|   Name\t| Age\t| Income\t| Expenses\t| Savings\t|\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("|   %s\t| %d\t| $%d\t\t| $%d\t\t| $%d\t\t|\n", persons[i].name, persons[i].age, persons[i].income, persons[i].expenses, persons[i].savings);
    }

    printf("------------------------------------------------------------------------\n");

    free(persons);

    return 0;
}