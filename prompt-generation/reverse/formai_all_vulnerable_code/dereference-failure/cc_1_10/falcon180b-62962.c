//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 100
#define MAX_ARRAY_SIZE 1000

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    float height;
} Person;

void read_file(FILE* file, Person* people, int* num_people) {
    char line[MAX_STRING_LENGTH];
    char* token;
    while (fgets(line, MAX_STRING_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        strcpy(people[*num_people].name, token);
        token = strtok(NULL, ",");
        people[*num_people].age = atoi(token);
        token = strtok(NULL, ",");
        people[*num_people].height = atof(token);
        (*num_people)++;
    }
}

void sort_people(Person* people, int num_people, int (*compare)(const void*, const void*)) {
    qsort(people, num_people, sizeof(Person), compare);
}

int compare_age(const void* a, const void* b) {
    const Person* person_a = (const Person*)a;
    const Person* person_b = (const Person*)b;
    return person_a->age - person_b->age;
}

int compare_height(const void* a, const void* b) {
    const Person* person_a = (const Person*)a;
    const Person* person_b = (const Person*)b;
    return person_a->height - person_b->height;
}

void print_people(const Person* people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("%s %d %.2f\n", people[i].name, people[i].age, people[i].height);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(1);
    }

    Person people[MAX_ARRAY_SIZE];
    int num_people = 0;

    read_file(input_file, people, &num_people);

    if (num_people > MAX_ARRAY_SIZE) {
        fprintf(stderr, "Too many people in input file.\n");
        exit(1);
    }

    sort_people(people, num_people, compare_age);
    print_people(people, num_people);

    sort_people(people, num_people, compare_height);
    print_people(people, num_people);

    fclose(input_file);
    return 0;
}