//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

typedef struct {
    char name[20];
    int age;
    char gender;
} Person;

void writeFile(FILE *fp, Person *persons, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%d,%c\n", persons[i].name, persons[i].age, persons[i].gender);
    }
}

void readFile(FILE *fp, Person *persons, int *count) {
    Person tempPerson;
    int i = 0;
    char line[MAX_LEN];

    while (fgets(line, MAX_LEN, fp) != NULL) {
        sscanf(line, "%s,%d,%c", tempPerson.name, &tempPerson.age, &tempPerson.gender);
        if (i < *count) {
            persons[i] = tempPerson;
        } else {
            *count += 1;
            persons = (Person *)realloc(persons, sizeof(Person) * (*count + 1));
            persons[*count - 1] = tempPerson;
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Person *persons;
    int count = 0;

    if ((file = fopen("romeo_juliet.txt", "w+")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Writing data to file
    Person romeo = {"Romeo Montague", 16, 'M'};
    Person juliet = {"Juliet Capulet", 13, 'F'};
    Person mercutio = {"Mercutio Montague", 25, 'M'};
    Person tybalt = {"Tybalt Capulet", 30, 'M'};

    persons = (Person *)calloc(1, sizeof(Person));
    persons[0] = romeo;
    persons[1] = juliet;

    writeFile(file, persons, 2);

    // Reading data from file
    fseek(file, 0, SEEK_SET);
    Person tempPersons[10];

    readFile(file, tempPersons, &count);

    for (int i = 0; i < count; i++) {
        printf("%s,%d,%c\n", tempPersons[i].name, tempPersons[i].age, tempPersons[i].gender);
    }

    free(persons);
    fclose(file);

    return 0;
}