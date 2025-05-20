//FormAI DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int id;
    char name[50];
    float cgpa;
};

// Function for comparing students based on their CGPA
int compareCGPA(const void *a, const void *b){
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;

    if(s1->cgpa > s2->cgpa)
        return -1;
    else if(s1->cgpa < s2->cgpa)
        return 1;
    else
        return 0;
}

int main(){
    int num_students = 5;
    struct student *students;
    students = malloc(num_students * sizeof(struct student));

    // Initializing student data
    students[0].id = 101;
    strcpy(students[0].name, "Alice");
    students[0].cgpa = 8.7;

    students[1].id = 102;
    strcpy(students[1].name, "Bob");
    students[1].cgpa = 7.9;

    students[2].id = 103;
    strcpy(students[2].name, "Charlie");
    students[2].cgpa = 9.5;

    students[3].id = 104;
    strcpy(students[3].name, "Dave");
    students[3].cgpa = 8.3;

    students[4].id = 105;
    strcpy(students[4].name, "Emily");
    students[4].cgpa = 9.1;

    // Sorting students based on their CGPA
    qsort(students, num_students, sizeof(struct student), compareCGPA);

    // Displaying the sorted student data
    printf("Rank\tID\tName\tCGPA\n");
    for(int i=0; i<num_students; i++){
        printf("%d\t%d\t%s\t%.2f\n", i+1, students[i].id, students[i].name, students[i].cgpa);
    }

    return 0;
}