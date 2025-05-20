//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
    int age;
} Person;

typedef struct {
    int id;
    char *title;
    int year;
} Book;

typedef struct {
    int id;
    char *name;
    int person_id;
    int book_id;
} Loan;

Person *people;
Book *books;
Loan *loans;
int num_people, num_books, num_loans;

void init_database() {
    people = malloc(sizeof(Person) * 10);
    books = malloc(sizeof(Book) * 10);
    loans = malloc(sizeof(Loan) * 10);

    num_people = 0;
    num_books = 0;
    num_loans = 0;
}

void add_person(char *name, int age) {
    people[num_people].id = num_people;
    people[num_people].name = strdup(name);
    people[num_people].age = age;

    num_people++;
}

void add_book(char *title, int year) {
    books[num_books].id = num_books;
    books[num_books].title = strdup(title);
    books[num_books].year = year;

    num_books++;
}

void add_loan(int person_id, int book_id) {
    loans[num_loans].id = num_loans;
    loans[num_loans].person_id = person_id;
    loans[num_loans].book_id = book_id;

    num_loans++;
}

void print_database() {
    int i;

    printf("People:\n");
    for (i = 0; i < num_people; i++) {
        printf("%d: %s, %d\n", people[i].id, people[i].name, people[i].age);
    }

    printf("Books:\n");
    for (i = 0; i < num_books; i++) {
        printf("%d: %s, %d\n", books[i].id, books[i].title, books[i].year);
    }

    printf("Loans:\n");
    for (i = 0; i < num_loans; i++) {
        printf("%d: %d, %d\n", loans[i].id, loans[i].person_id, loans[i].book_id);
    }
}

int main() {
    init_database();

    add_person("John Doe", 30);
    add_person("Jane Doe", 25);

    add_book("The Catcher in the Rye", 1951);
    add_book("To Kill a Mockingbird", 1960);

    add_loan(0, 0);
    add_loan(1, 1);

    print_database();

    return 0;
}