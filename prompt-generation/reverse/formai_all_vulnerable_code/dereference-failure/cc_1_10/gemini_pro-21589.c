//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char gender;
    int age;
    char address[100];
    char phone[20];
} person;

typedef struct {
    person *romeo;
    person *juliet;
    char date[20];
    char time[20];
} meeting;

// Create a new person
person *create_person(char *name, char gender, int age, char *address, char *phone) {
    person *p = (person *)malloc(sizeof(person));
    strcpy(p->name, name);
    p->gender = gender;
    p->age = age;
    strcpy(p->address, address);
    strcpy(p->phone, phone);
    return p;
}

// Create a new meeting
meeting *create_meeting(person *romeo, person *juliet, char *date, char *time) {
    meeting *m = (meeting *)malloc(sizeof(meeting));
    m->romeo = romeo;
    m->juliet = juliet;
    strcpy(m->date, date);
    strcpy(m->time, time);
    return m;
}

// Print a person
void print_person(person *p) {
    printf("Name: %s\n", p->name);
    printf("Gender: %c\n", p->gender);
    printf("Age: %d\n", p->age);
    printf("Address: %s\n", p->address);
    printf("Phone: %s\n", p->phone);
}

// Print a meeting
void print_meeting(meeting *m) {
    printf("Romeo: ");
    print_person(m->romeo);
    printf("Juliet: ");
    print_person(m->juliet);
    printf("Date: %s\n", m->date);
    printf("Time: %s\n", m->time);
}

// Free a person
void free_person(person *p) {
    free(p);
}

// Free a meeting
void free_meeting(meeting *m) {
    free_person(m->romeo);
    free_person(m->juliet);
    free(m);
}

int main() {
    // Create Romeo and Juliet
    person *romeo = create_person("Romeo Montague", 'M', 16, "Verona, Italy", "+39 333 123 4567");
    person *juliet = create_person("Juliet Capulet", 'F', 14, "Verona, Italy", "+39 333 789 1011");

    // Create a meeting between Romeo and Juliet
    meeting *m = create_meeting(romeo, juliet, "February 14th", "10:00 PM");

    // Print the meeting
    print_meeting(m);

    // Free the meeting and the people
    free_meeting(m);
    free_person(romeo);
    free_person(juliet);

    return 0;
}