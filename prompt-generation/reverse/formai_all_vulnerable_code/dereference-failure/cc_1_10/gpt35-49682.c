//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[20];
    char email[50];
} Person;

typedef struct{
    Person *people;
    int size;
    int capacity;
} PersonList;

void init(PersonList *list){
    list->people = NULL;
    list->size = 0;
    list->capacity = 0;
}

void addPerson(PersonList *list, Person person){
    if(list->capacity == 0){
        list->people = (Person*)malloc(sizeof(Person));
        list->capacity = 1;
    }
    else if(list->size == list->capacity){
        list->people = (Person*)realloc(list->people, sizeof(Person)*list->capacity*2);
        list->capacity *= 2;
    }
    
    list->people[list->size++] = person;
}

void displayPeople(PersonList list){
    printf("ID\tName\t\tEmail\n");
    for(int i = 0; i < list.size; i++){
        printf("%d\t%s\t\t%s\n", list.people[i].id, list.people[i].name, list.people[i].email);
    }
}

int main(){
    char option;
    Person person;
    PersonList peopleList;
    init(&peopleList);
    do{ 
        printf("1. Add Person\n");
        printf("2. Display People\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf(" %c", &option);

        switch(option){
            case '1':
                printf("Enter ID: ");
                scanf("%d", &person.id);
                printf("Enter Name: ");
                scanf(" %[^\n]s", person.name);
                printf("Enter Email: ");
                scanf(" %[^\n]s", person.email);
                addPerson(&peopleList, person);
                break;
            case '2':
                displayPeople(peopleList);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Option\n");
        }
    }while(option != '3');

    free(peopleList.people);
    return 0;
}