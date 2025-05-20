//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    char age[20];
    char gender[10];
    char* address;
    char* phone;
} person;

int main() {
    srand(time(NULL));

    person* people[100];
    int numPeople = 0;

    while (numPeople < 100) {
        person newPerson;
        char* address = malloc(100);
        char* phone = malloc(20);

        if (address == NULL || phone == NULL) {
            perror("Error allocating memory");
            return 1;
        }

        strcpy(newPerson.name, "Haunted House Simulator");
        strcpy(newPerson.age, "18");
        strcpy(newPerson.gender, "N/A");

        sprintf(address, "%d Haunted Drive", rand() % 100);
        sprintf(phone, "(555) 555-5555");

        newPerson.address = address;
        newPerson.phone = phone;

        people[numPeople++] = &newPerson;
    }

    for (int i = 0; i < numPeople; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", people[i]->name);
        printf("Age: %s\n", people[i]->age);
        printf("Gender: %s\n", people[i]->gender);
        printf("Address: %s\n", people[i]->address);
        printf("Phone: %s\n", people[i]->phone);
        printf("\n");
    }

    return 0;
}