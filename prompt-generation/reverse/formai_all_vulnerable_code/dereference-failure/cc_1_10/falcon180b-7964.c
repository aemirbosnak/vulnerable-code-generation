//Falcon-180B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

typedef struct {
    char name[MAX_LINE_SIZE];
    int age;
    char address[MAX_LINE_SIZE];
} Person;

void read_file(char *filename, Person *people, int *num_people) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    int num_lines = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (num_lines == *num_people) {
            printf("Error: too many lines in file.\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        strcpy(people[num_lines].name, token);

        token = strtok(NULL, ",");
        people[num_lines].age = atoi(token);

        token = strtok(NULL, ",");
        strcpy(people[num_lines].address, token);

        num_lines++;
    }

    fclose(file);
}

void write_file(char *filename, Person *people, int num_people) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%s\n", people[i].name, people[i].age, people[i].address);
    }

    fclose(file);
}

void sort_people(Person *people, int num_people, int (*compare)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    const Person *person_a = a;
    const Person *person_b = b;

    if (person_a->age < person_b->age) {
        return -1;
    } else if (person_a->age > person_b->age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Person people[100];
    int num_people = 0;

    read_file("input.txt", people, &num_people);

    printf("Unsorted data:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s, %d years old, lives at %s\n", people[i].name, people[i].age, people[i].address);
    }

    sort_people(people, num_people, compare_age);

    printf("\nSorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s, %d years old, lives at %s\n", people[i].name, people[i].age, people[i].address);
    }

    write_file("output.txt", people, num_people);

    return 0;
}