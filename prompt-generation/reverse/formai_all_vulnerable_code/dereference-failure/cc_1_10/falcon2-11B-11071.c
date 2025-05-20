//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <string.h>

typedef struct person {
    char name[50];
    char phone[15];
    struct person *next;
} person;

person *start = NULL;

int main() {
    char name[50];
    char phone[15];
    char operation;
    
    printf("Welcome to the Phone Book!\n");
    printf("Enter your name:\n");
    scanf("%s", name);
    printf("Enter your phone number:\n");
    scanf("%s", phone);
    printf("Do you want to add another entry? (y/n)\n");
    scanf(" %c", &operation);
    
    if (strcmp(operation, "y") == 0) {
        person *new_person = malloc(sizeof(person));
        strcpy(new_person->name, name);
        strcpy(new_person->phone, phone);
        new_person->next = NULL;
        
        if (start == NULL) {
            start = new_person;
        } else {
            person *current = start;
            while (current->next!= NULL) {
                current = current->next;
            }
            current->next = new_person;
        }
    } else if (strcmp(operation, "n") == 0) {
        printf("Thank you for using the Phone Book!\n");
    } else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
    
    printf("Phone Book:\n");
    person *current = start;
    while (current!= NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
    
    return 0;
}