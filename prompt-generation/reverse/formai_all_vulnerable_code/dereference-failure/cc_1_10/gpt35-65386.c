//FormAI DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll_number;
    int marks;
};

void add_student() {
    struct student s;
    FILE *fp;
    fp = fopen("students.dat", "a");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll_number);
    printf("Enter marks: ");
    scanf("%d", &s.marks);
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
    printf("Student added successfully.\n");
}

void display() {
    struct student s;
    FILE *fp;
    fp = fopen("students.dat", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("\n%-15s%-15s%-15s\n", "Name", "Roll Number", "Marks");
    printf("-----------------------------------\n");
    while(fread(&s, sizeof(struct student), 1, fp)) {
        printf("%-15s%-15d%-15d\n", s.name, s.roll_number, s.marks);
    }
    fclose(fp);
}

void search() {
    struct student s;
    FILE *fp;
    int roll_no, found = 0;
    fp = fopen("students.dat", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Enter roll number: ");
    scanf("%d", &roll_no);
    while(fread(&s, sizeof(struct student), 1, fp)) {
        if(s.roll_number == roll_no) {
            found = 1;
            printf("\n%-15s%-15s%-15s\n", "Name", "Roll Number", "Marks");
            printf("-----------------------------------\n");
            printf("%-15s%-15d%-15d\n", s.name, s.roll_number, s.marks);
            break;
        }
    }
    if(!found) {
        printf("Student not found.\n");
    }
    fclose(fp);
}

void delete() {
    struct student s;
    FILE *fp1, *fp2;
    int roll_no, found = 0;
    fp1 = fopen("students.dat", "r");
    if(fp1 == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fp2 = fopen("temp.dat", "w");
    if(fp2 == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Enter roll number: ");
    scanf("%d", &roll_no);
    while(fread(&s, sizeof(struct student), 1, fp1)) {
        if(s.roll_number != roll_no) {
            fwrite(&s, sizeof(struct student), 1, fp2);
        } else {
            found = 1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found) {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        printf("Student deleted successfully.\n");
    } else {
        printf("Student not found.\n");
        remove("temp.dat");
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add student\n2. Display all students\n3. Search for a student\n4. Delete a student\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}