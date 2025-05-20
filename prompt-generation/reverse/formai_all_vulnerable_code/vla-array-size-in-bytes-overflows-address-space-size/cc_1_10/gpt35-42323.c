//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

typedef struct {
    int id;
    long position;
} Index;

int main() {
    int n = 0; //number of records to input
    printf("Enter the number of records you want to input: ");
    scanf("%d", &n);

    Person database[n]; //array of Persons to store the records
    Index index[n]; //array of Indexes to store the positions of persons in the file

    for (int i = 0; i < n; i++) {
        Person person;
        person.id = i+1;
        printf("\nEnter name for person %d: ", i+1);
        scanf("%s", person.name);
        printf("Enter age for person %d: ", i+1);
        scanf("%d", &person.age);
        database[i] = person;
    }

    FILE *fptr;
    fptr = fopen("person_db.txt", "w"); //opening file in write mode

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        exit(1);
    }

    Index current_index;
    int index_count = 0;

    for (int i = 0; i < n; i++) { //writing records to file and creating index
        Person person = database[i];
        fprintf(fptr, "%d %s %d\n", person.id, person.name, person.age);
        current_index.id = person.id;
        current_index.position = ftell(fptr);
        index[index_count++] = current_index;
    }

    fclose(fptr); //closing file

    int choice = 0;
    printf("\nEnter the ID of the person you want to search for: ");
    scanf("%d", &choice);

    fptr = fopen("person_db.txt", "r"); //opening the file in read mode

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        exit(1);
    }

    Index result;
    int found = 0;

    for (int i = 0; i < n; i++) { //iterating through the index to find the person's position in file
        Index current = index[i];
        if (choice == current.id) {
            result = current;
            found = 1;
            break;
        }
    }

    if (found) { //if person is found in the index
        fseek(fptr, result.position, SEEK_SET); //set file pointer to the position of the person in file
        char person_data[100];
        fgets(person_data, 100, fptr);
        printf("\nPerson found: %s", person_data);
    } else { //if person is not found in the index
        printf("\nPerson not found!\n");
    }

    fclose(fptr); //closing file
    return 0;
}