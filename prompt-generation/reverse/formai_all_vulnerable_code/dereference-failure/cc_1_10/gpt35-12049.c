//FormAI DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

typedef struct {
    int age;
    char gender;
    float height;
    float weight;
    char occupation[20];
    char education[20];
} Person;

void read_csv(Person *people) {
    FILE *fp;
    char buff[MAX_LEN];

    fp = fopen("people.csv", "r");
    if (!fp) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fgets(buff, MAX_LEN, fp) != NULL) {
        sscanf(buff, "%d,%c,%f,%f,%[^,],%s", 
            &people[i].age, &people[i].gender, 
            &people[i].height, &people[i].weight, 
            people[i].occupation, people[i].education);
        i++;
    }

    fclose(fp);
}

void print_people(Person *people, int n) {
    for (int i = 0; i < n; i++) {
        printf("Person %d:\n", i+1);
        printf("\tAge: %d\n", people[i].age);
        printf("\tGender: %c\n", people[i].gender);
        printf("\tHeight: %.2f\n", people[i].height);
        printf("\tWeight: %.2f\n", people[i].weight);
        printf("\tOccupation: %s\n", people[i].occupation);
        printf("\tEducation: %s\n", people[i].education);
    }
}

int main() {
    int n = 10; // number of people to be read from csv
    Person *people = (Person*) malloc(n * sizeof(Person));

    read_csv(people);
    print_people(people, n);

    free(people);

    return 0;
}