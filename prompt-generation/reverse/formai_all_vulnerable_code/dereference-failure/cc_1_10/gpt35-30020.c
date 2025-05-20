//FormAI DATASET v1.0 Category: Database querying ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100
#define MAX_PHONE_NUM_LEN 20

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
} Person;

typedef struct {
    Person *data;
    int size;
} PersonList;

void print_person(Person person) {
    printf("ID: %d\nName: %s\nAddress: %s\nPhone Number: %s\n\n", person.id, person.name, person.address, person.phone_num);
}

void print_all_people(PersonList *person_list) {
    for (int i = 0; i < person_list->size; i++) {
        Person person = person_list->data[i];
        print_person(person);
    }
}

bool person_contains_name(Person person, char *name) {
    return strcmp(person.name, name) == 0;
}

PersonList *get_people_by_name(PersonList *person_list, char *name) {
    PersonList *result = (PersonList *) malloc(sizeof(PersonList));
    result->data = NULL;
    result->size = 0;

    for (int i = 0; i < person_list->size; i++) {
        Person person = person_list->data[i];
        if (person_contains_name(person, name)) {
            result->size++;
            result->data = realloc(result->data, result->size * sizeof(Person));
            result->data[result->size - 1] = person;
        }
    }

    return result;
}

PersonList *read_people_data_from_db() {
    // read data from database and populate person_list
    PersonList *person_list = (PersonList *) malloc(sizeof(PersonList));
    person_list->data = NULL;
    person_list->size = 0;

    // simulate reading data from database
    person_list->size = 3;
    person_list->data = (Person *) malloc(person_list->size * sizeof(Person));
    person_list->data[0].id = 1;
    strcpy(person_list->data[0].name, "John");
    strcpy(person_list->data[0].address, "123 Main St");
    strcpy(person_list->data[0].phone_num, "(123) 456-7890");
    person_list->data[1].id = 2;
    strcpy(person_list->data[1].name, "Jim");
    strcpy(person_list->data[1].address, "456 Elm St");
    strcpy(person_list->data[1].phone_num, "(345) 678-9012");
    person_list->data[2].id = 3;
    strcpy(person_list->data[2].name, "John");
    strcpy(person_list->data[2].address, "789 Oak St");
    strcpy(person_list->data[2].phone_num, "(234) 567-8901");

    return person_list;
}

void free_person_list(PersonList *person_list) {
    free(person_list->data);
    free(person_list);
}

int main() {
    char search_name[MAX_NAME_LEN];
    printf("Enter a name to search for: ");
    fgets(search_name, MAX_NAME_LEN, stdin);
    // remove newline character from fgets
    search_name[strcspn(search_name, "\n")] = '\0';

    PersonList *person_list = read_people_data_from_db();

    printf("\nPeople found:\n");
    PersonList *people_found = get_people_by_name(person_list, search_name);
    print_all_people(people_found);
    free_person_list(people_found);

    free_person_list(person_list);

    return 0;
}