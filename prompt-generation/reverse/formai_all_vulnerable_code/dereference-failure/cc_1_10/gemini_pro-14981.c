//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
} Person;

typedef struct {
    int id;
    int person_id;
    char *address;
} Address;

typedef struct {
    int id;
    char *name;
    int person_id;
} PhoneNumber;

typedef struct {
    Person *person;
    Address *address;
    PhoneNumber *phone_number;
} PersonDetails;

Person *create_person(int id, char *name, int age) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->id = id;
    person->name = strdup(name);
    person->age = age;
    return person;
}

Address *create_address(int id, int person_id, char *address) {
    Address *address_obj = (Address *)malloc(sizeof(Address));
    address_obj->id = id;
    address_obj->person_id = person_id;
    address_obj->address = strdup(address);
    return address_obj;
}

PhoneNumber *create_phone_number(int id, int person_id, char *phone_number) {
    PhoneNumber *phone_number_obj = (PhoneNumber *)malloc(sizeof(PhoneNumber));
    phone_number_obj->id = id;
    phone_number_obj->person_id = person_id;
    phone_number_obj->name = strdup(phone_number);
    return phone_number_obj;
}

PersonDetails *create_person_details(Person *person, Address *address, PhoneNumber *phone_number) {
    PersonDetails *person_details = (PersonDetails *)malloc(sizeof(PersonDetails));
    person_details->person = person;
    person_details->address = address;
    person_details->phone_number = phone_number;
    return person_details;
}

void print_person_details(PersonDetails *person_details) {
    printf("Person ID: %d\n", person_details->person->id);
    printf("Name: %s\n", person_details->person->name);
    printf("Age: %d\n", person_details->person->age);
    printf("Address: %s\n", person_details->address->address);
    printf("Phone Number: %s\n", person_details->phone_number->name);
}

int main() {
    Person *person1 = create_person(1, "John Doe", 25);
    Address *address1 = create_address(1, 1, "123 Main Street");
    PhoneNumber *phone_number1 = create_phone_number(1, 1, "123-456-7890");
    PersonDetails *person_details1 = create_person_details(person1, address1, phone_number1);

    Person *person2 = create_person(2, "Jane Smith", 30);
    Address *address2 = create_address(2, 2, "456 Elm Street");
    PhoneNumber *phone_number2 = create_phone_number(2, 2, "098-765-4321");
    PersonDetails *person_details2 = create_person_details(person2, address2, phone_number2);

    print_person_details(person_details1);
    print_person_details(person_details2);

    return 0;
}