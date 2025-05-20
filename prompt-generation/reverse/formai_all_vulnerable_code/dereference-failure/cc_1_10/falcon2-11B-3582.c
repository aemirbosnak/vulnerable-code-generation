//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Person;

typedef struct {
    int id;
    int age;
} Student;

typedef struct {
    int id;
    int score;
} Exam;

int main() {
    // Create database connection
    FILE *db = fopen("database.txt", "w");
    fprintf(db, "Name\tID\tAge\tScore\n");
    fclose(db);

    // Create database objects
    Person p1;
    Person p2;
    Person p3;

    Student s1;
    Student s2;
    Student s3;

    Exam e1;
    Exam e2;
    Exam e3;

    // Populate database
    p1.id = 1;
    strcpy(p1.name, "John");
    p2.id = 2;
    strcpy(p2.name, "Jane");
    p3.id = 3;
    strcpy(p3.name, "Bob");

    s1.id = 1;
    s1.age = 20;
    s2.id = 2;
    s2.age = 18;
    s3.id = 3;
    s3.age = 22;

    e1.id = 1;
    e1.score = 90;
    e2.id = 2;
    e2.score = 75;
    e3.id = 3;
    e3.score = 85;

    // Write to database
    fprintf(db, "%s\t%d\t%d\t%d\n", p1.name, p1.id, s1.age, e1.score);
    fprintf(db, "%s\t%d\t%d\t%d\n", p2.name, p2.id, s2.age, e2.score);
    fprintf(db, "%s\t%d\t%d\t%d\n", p3.name, p3.id, s3.age, e3.score);
    fclose(db);

    // Read from database
    FILE *db_read = fopen("database.txt", "r");
    fprintf(db_read, "Name\tID\tAge\tScore\n");
    while (!feof(db_read)) {
        char name[MAX_NAME_LEN];
        int id, age, score;
        fscanf(db_read, "%s\t%d\t%d\t%d\n", name, &id, &age, &score);
        printf("Name: %s\nID: %d\nAge: %d\nScore: %d\n\n", name, id, age, score);
    }
    fclose(db_read);

    return 0;
}