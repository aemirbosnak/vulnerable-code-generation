//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char address[100];
    int age;
} Person;

int main() {
    FILE *csv_file;
    csv_file = fopen("data.csv", "r");

    if (csv_file == NULL) {
        printf("Error: Unable to open CSV file!\n");
        exit(1);
    }

    char line[1000];
    Person *people = (Person *)malloc(sizeof(Person));
    int num_people = 0;

    while (fgets(line, sizeof(line), csv_file)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            switch (i) {
                case 0:
                    people[num_people].id = atoi(token);
                    break;
                case 1:
                    strcpy(people[num_people].name, token);
                    break;
                case 2:
                    strcpy(people[num_people].address, token);
                    break;
                case 3:
                    people[num_people].age = atoi(token);
                    break;
                default:
                    break;
            }
            i++;
            token = strtok(NULL, ",");
            num_people++;
        }
    }

    for (int i = 0; i < num_people; i++) {
        printf("ID: %d\nName: %s\nAddress: %s\nAge: %d\n\n", people[i].id, people[i].name, people[i].address, people[i].age);
    }

    free(people);
    fclose(csv_file);

    return 0;
}