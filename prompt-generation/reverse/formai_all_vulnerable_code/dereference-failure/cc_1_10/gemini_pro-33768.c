//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    char *name;
    int age;
} Person;

typedef struct {
    int id;
    char *title;
    int salary;
} Job;

typedef struct {
    int id;
    char *name;
    int *person_ids;
    int num_people;
} Team;

int main() {
    // Create a database of people
    Person people[] = {
        {1, "John Doe", 30},
        {2, "Jane Smith", 25},
        {3, "Bill Jones", 40}
    };

    // Create a database of jobs
    Job jobs[] = {
        {1, "Software Engineer", 100000},
        {2, "Manager", 150000},
        {3, "CEO", 200000}
    };

    // Create a database of teams
    Team teams[] = {
        {1, "Engineering", {1, 2}, 2},
        {2, "Sales", {3}, 1}
    };

    // Print the database
    printf("People:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %s %d\n", people[i].id, people[i].name, people[i].age);
    }

    printf("\nJobs:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %s %d\n", jobs[i].id, jobs[i].title, jobs[i].salary);
    }

    printf("\nTeams:\n");
    for (int i = 0; i < 2; i++) {
        printf("%d %s ", teams[i].id, teams[i].name);
        for (int j = 0; j < teams[i].num_people; j++) {
            printf("%d ", teams[i].person_ids[j]);
        }
        printf("\n");
    }

    return 0;
}