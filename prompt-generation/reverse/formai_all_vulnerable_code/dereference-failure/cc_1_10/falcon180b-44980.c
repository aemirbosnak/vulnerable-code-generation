//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *) a;
    Person *p2 = (Person *) b;

    if (p1->age < p2->age) {
        return -1;
    } else if (p1->age > p2->age) {
        return 1;
    } else {
        return 0;
    }
}

void print_person(Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    Person *people = NULL;
    int num_people = 0;

    FILE *fp;
    fp = fopen("people.txt", "r");

    if (fp!= NULL) {
        char line[MAX_SIZE];
        while (fgets(line, MAX_SIZE, fp)!= NULL) {
            Person *person = (Person *) malloc(sizeof(Person));
            person->name = strtok(line, ",");
            person->age = atoi(strtok(NULL, ","));

            if (num_people >= MAX_SIZE) {
                printf("Error: Maximum number of people reached.\n");
                exit(1);
            }

            people[num_people++] = *person;
        }

        fclose(fp);
    }

    qsort(people, num_people, sizeof(Person), compare);

    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people + i);
    }

    return 0;
}