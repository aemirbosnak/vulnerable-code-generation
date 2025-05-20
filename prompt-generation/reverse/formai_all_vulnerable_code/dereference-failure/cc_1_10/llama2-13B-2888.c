//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_LEN 32

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} person_t;

void add_person(person_t *persons, int num_persons, char *name, char *phone);
void print_phone_book(person_t *persons, int num_persons);

int main() {
    srand(time(NULL));
    person_t *persons = (person_t *)calloc(10, sizeof(person_t));
    int i, j;

    for (i = 0; i < 10; i++) {
        char name[MAX_NAME_LEN];
        char phone[MAX_PHONE_LEN];
        sprintf(name, "Person %d", i + 1);
        sprintf(phone, "0123456789%d", i % 2 ? 1 : 2);
        add_person(persons, i + 1, name, phone);
    }

    print_phone_book(persons, 10);

    return 0;
}

void add_person(person_t *persons, int num_persons, char *name, char *phone) {
    int i;
    for (i = 0; i < num_persons; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            printf("Person already exists in the phone book. Please try again.\n");
            return;
        }
    }
    strcpy(persons[i].name, name);
    strcpy(persons[i].phone, phone);
    i++;
}

void print_phone_book(person_t *persons, int num_persons) {
    int i;
    for (i = 0; i < num_persons; i++) {
        printf("%d: %s %s\n", i + 1, persons[i].name, persons[i].phone);
    }
}