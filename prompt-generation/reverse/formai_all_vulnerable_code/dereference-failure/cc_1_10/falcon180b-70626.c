//Falcon-180B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

void create_person(Person **person, int id, char *name, int age) {
    Person *p = (Person *)malloc(sizeof(Person));
    p->id = id;
    strcpy(p->name, name);
    p->age = age;
    *person = p;
}

void delete_person(Person **person) {
    free(*person);
    *person = NULL;
}

void display_person(Person *person) {
    printf("ID: %d\nName: %s\nAge: %d\n", person->id, person->name, person->age);
}

int main() {
    Person *person = NULL;
    int choice, id, age;
    char name[20];

    do {
        printf("\n\n*** Memory Management Example Program ***\n");
        printf("1. Create Person\n2. Display Person\n3. Delete Person\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                create_person(&person, id, name, age);
                break;

            case 2:
                if(person!= NULL)
                    display_person(person);
                else
                    printf("No person created yet!\n");
                break;

            case 3:
                if(person!= NULL)
                    delete_person(&person);
                else
                    printf("No person created yet!\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

    } while(1);

    return 0;
}