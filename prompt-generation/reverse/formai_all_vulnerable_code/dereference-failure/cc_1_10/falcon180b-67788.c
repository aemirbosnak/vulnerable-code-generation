//Falcon-180B DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

// Define a structure for a person's name and phone number
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Person;

// Define a structure for a phone book entry
typedef struct {
    Person* people;
    int num_people;
} PhoneBook;

// Function to add a person to the phone book
void add_person(PhoneBook* pb, char* name, char* phone) {
    Person* new_person = (Person*) malloc(sizeof(Person));
    strcpy(new_person->name, name);
    strcpy(new_person->phone, phone);
    pb->people = realloc(pb->people, sizeof(Person) * (pb->num_people + 1));
    pb->people[pb->num_people] = *new_person;
    pb->num_people++;
}

// Function to search the phone book for a person's phone number
int search_phone_book(PhoneBook* pb, char* phone) {
    for (int i = 0; i < pb->num_people; i++) {
        if (strcmp(pb->people[i].phone, phone) == 0) {
            printf("Found %s at %s\n", pb->people[i].name, phone);
            return 1;
        }
    }
    return 0;
}

// Function to print the entire phone book
void print_phone_book(PhoneBook* pb) {
    for (int i = 0; i < pb->num_people; i++) {
        printf("%s: %s\n", pb->people[i].name, pb->people[i].phone);
    }
}

int main() {
    // Initialize an empty phone book
    PhoneBook pb = { NULL, 0 };

    // Add some people to the phone book
    add_person(&pb, "John Doe", "555-1234");
    add_person(&pb, "Jane Doe", "555-5678");

    // Search for a person's phone number
    char* phone_to_search = "555-1234";
    int found = search_phone_book(&pb, phone_to_search);
    if (found) {
        printf("Found %s at %s\n", pb.people[0].name, phone_to_search);
    } else {
        printf("Could not find %s\n", phone_to_search);
    }

    // Print the entire phone book
    print_phone_book(&pb);

    return 0;
}