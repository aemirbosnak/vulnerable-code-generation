//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[20];
    int roll_no;
    int marks;
};

void add_student(struct student *s, int n){
    printf("Enter the name of the student: ");
    scanf("%s", s[n].name);
    printf("Enter the roll number of the student: ");
    scanf("%d", &s[n].roll_no);
    printf("Enter the marks of the student: ");
    scanf("%d", &s[n].marks);
}

void display_students(struct student *s, int n){
    printf("Name\tRoll No.\tMarks\n");
    for(int i=0; i<n; i++){
        printf("%s\t%d\t%d\n", s[i].name, s[i].roll_no, s[i].marks);
    }
}

void search_student(struct student *s, int n){
    char name[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<n; i++){
        if(strcmp(s[i].name, name) == 0){
            printf("Name: %s\nRoll No.: %d\nMarks: %d\n", s[i].name, s[i].roll_no, s[i].marks);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Student not found.\n");
    }
}

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student s[n];
    for(int i=0; i<n; i++){
        add_student(s, i);
    }
    printf("Students added successfully.\n");
    display_students(s, n);
    printf("\n");
    search_student(s, n);
    return 0;
}