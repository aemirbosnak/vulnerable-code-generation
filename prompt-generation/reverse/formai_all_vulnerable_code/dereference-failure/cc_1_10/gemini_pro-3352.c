//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *email;
} Person;

typedef struct {
    Person *to;
    Person *from;
    char *subject;
    char *body;
} Email;

Person *create_person(char *name, char *email) {
    Person *person = malloc(sizeof(Person));
    person->name = name;
    person->email = email;
    return person;
}

Email *create_email(Person *to, Person *from, char *subject, char *body) {
    Email *email = malloc(sizeof(Email));
    email->to = to;
    email->from = from;
    email->subject = subject;
    email->body = body;
    return email;
}

void send_email(Email *email) {
    printf("Sending email from %s (%s) to %s (%s)\n", email->from->name, email->from->email, email->to->name, email->to->email);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    Person *alice = create_person("Alice", "alice@example.com");
    Person *bob = create_person("Bob", "bob@example.com");

    Email *email = create_email(alice, bob, "Hello", "How are you?");

    send_email(email);

    free(email);
    free(bob);
    free(alice);

    return 0;
}