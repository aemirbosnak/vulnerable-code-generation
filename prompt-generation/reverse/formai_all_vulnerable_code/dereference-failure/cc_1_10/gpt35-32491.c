//FormAI DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_SIZE 100

struct student {
    int id;
    char name[50];
    float score;
};

struct student_db {
    struct student students[MAX_DB_SIZE];
    int count;
};

void add_student(struct student_db *db) {
    if (db->count == MAX_DB_SIZE) {
        printf("Error: Database is full.\n");
        return;
    }

    struct student new_student;
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter student score: ");
    scanf("%f", &new_student.score);

    db->students[db->count] = new_student;
    db->count++;
    printf("Student added to database.\n");
}

void print_database(struct student_db *db) {
    printf("ID\tName\tScore\n");
    for (int i = 0; i < db->count; i++) {
        struct student s = db->students[i];
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.score);
    }
}

void save_database(struct student_db *db) {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < db->count; i++) {
        struct student s = db->students[i];
        fprintf(fp, "%d,%s,%.2f\n", s.id, s.name, s.score);
    }
    fclose(fp);
    printf("Database saved to file.\n");
}

void load_database(struct student_db *db) {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        struct student s;
        char *token = strtok(line, ",");
        s.id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(s.name, token);
        token = strtok(NULL, ",");
        s.score = atof(token);
        db->students[db->count] = s;
        db->count++;
    }

    fclose(fp);
    printf("Database loaded from file.\n");
}

int main() {
    struct student_db db = {0};

    int choice = 0;
    while (choice != 5) {
        printf("\n1. Add student\n");
        printf("2. Print database\n");
        printf("3. Save database\n");
        printf("4. Load database\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(&db); break;
            case 2: print_database(&db); break;
            case 3: save_database(&db); break;
            case 4: load_database(&db); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    }

    return 0;
}