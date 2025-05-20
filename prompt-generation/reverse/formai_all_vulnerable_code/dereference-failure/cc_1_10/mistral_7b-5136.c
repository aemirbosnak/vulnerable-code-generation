//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CASES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
} Person;

typedef struct Case {
    Person suspect;
    struct Case *next;
} Case;

void print_case(Case *case_ptr) {
    printf("\nCase File:\n");
    printf("Name: %s\n", case_ptr->suspect.name);
    printf("Age: %d\n", case_ptr->suspect.age);
    printf("Occupation: %s\n", case_ptr->suspect.occupation);
    if (case_ptr->next != NULL)
        printf("Next Suspect:\n");
    else
        printf("No Next Suspect\n");
}

void add_suspect(Case **head_ptr, Person new_suspect) {
    Case *new_case_ptr = (Case *)malloc(sizeof(Case));

    strcpy(new_case_ptr->suspect.name, new_suspect.name);
    new_case_ptr->suspect.age = new_suspect.age;
    strcpy(new_case_ptr->suspect.occupation, new_suspect.occupation);
    new_case_ptr->next = *head_ptr;
    *head_ptr = new_case_ptr;
}

int main() {
    Case *case_list = NULL;
    Person suspect1 = {"Watson, Dr. John H.", 35, "Doctor"};
    Person suspect2 = {"Moriarty, Professor James", 45, "Professor"};
    Person suspect3 = {"Doyle, Sir Arthur Conan", 50, "Writer"};

    add_suspect(&case_list, suspect1);
    add_suspect(&case_list, suspect2);
    add_suspect(&case_list, suspect3);

    printf("\nSherlock Holmes's Thoughts:\n");
    print_case(case_list);

    return 0;
}