//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 256

typedef struct {
    char name[MAX_LEN];
    char occupation[MAX_LEN];
    int age;
} Person;

void extractName(const char *str, Person *person) {
    int i = 0, j = 0;

    while (str[i] != ',' && str[i] != '\0') {
        person->name[i] = tolower(str[i]);
        i++;
    }
    person->name[i] = '\0';

    i++;

    while (str[i] != ' ' && str[i] != '\0') {
        person->occupation[j++] = tolower(str[i]);
        person->occupation[j] = '\0';
        i++;
    }

    person->age = atoi(str + i + 1);
}

int main(int argc, char *argv[]) {
    char input[MAX_LEN];
    Person person;

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    extractName(input, &person);

    printf("Name: %s\n", person.name);
    printf("Occupation: %s\n", person.occupation);
    printf("Age: %d\n", person.age);

    char *scandal = malloc(strlen(person.name) + strlen("'s scandal") + 2);
    strcpy(scandal, person.name);
    strcat(scandal, "'s scandal");

    printf("\nSherlock: %s is in a scandal? Impossible!\n", scandal);

    free(scandal);

    return 0;
}