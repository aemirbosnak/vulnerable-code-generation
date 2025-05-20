//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[256];
    char phone[256];
    char email[256];
};

struct PhoneBook {
    struct Person *people;
    int size;
};

struct PhoneBook *createPhoneBook() {
    struct PhoneBook *pb = malloc(sizeof(struct PhoneBook));
    pb->people = NULL;
    pb->size = 0;
    return pb;
}

void addPerson(struct PhoneBook *pb, struct Person *p) {
    pb->people = realloc(pb->people, (pb->size + 1) * sizeof(struct Person));
    pb->people[pb->size++] = *p;
}

void printPhoneBook(struct PhoneBook *pb) {
    for (int i = 0; i < pb->size; i++) {
        printf("%s: %s, %s\n", pb->people[i].name, pb->people[i].phone, pb->people[i].email);
    }
}

void freePhoneBook(struct PhoneBook *pb) {
    free(pb->people);
    free(pb);
}

int main() {
    struct PhoneBook *pb = createPhoneBook();

    struct Person p1 = {"John Doe", "555-1212", "john.doe@example.com"};
    addPerson(pb, &p1);

    struct Person p2 = {"Jane Doe", "555-1213", "jane.doe@example.com"};
    addPerson(pb, &p2);

    struct Person p3 = {"Bob Smith", "555-1214", "bob.smith@example.com"};
    addPerson(pb, &p3);

    printPhoneBook(pb);

    freePhoneBook(pb);

    return 0;
}