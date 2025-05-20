//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char address[MAX_NAME_LEN];
} Person;

int readCSV(char filename[], Person people[], int max_people) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        return 0;
    }

    int count = 0;
    char line[3 * MAX_NAME_LEN + sizeof(int)];
    while (!feof(file) && fgets(line, sizeof(line), file)) {
        if (count >= max_people) {
            printf("Maximum number of records (%d) exceeded\n", max_people);
            break;
        }

        char *name = strtok(line, ",");
        if (!name) continue;

        people[count].age = atoi(strtok(NULL, ","));
        if (!people[count].age) continue;

        char *address = strtok(NULL, ",");
        if (!address) continue;

        strcpy(people[count].name, name);
        strcpy(people[count].address, address);

        count++;
    }

    fclose(file);
    return count;
}

void printPeople(Person people[], int count) {
    printf("%-20s %-10s %-20s\n", "Name", "Age", "Address");
    printf("----------------------------------------------\n");
    for (int i = 0; i < count; i++)
        printf("%-20s %-10d %-20s\n", people[i].name, people[i].age,
                                       people[i].address);
}

int main() {
    Person people[MAX_RECORDS];
    int count = readCSV("people.csv", people, MAX_RECORDS);
    printPeople(people, count);
    return 0;
}