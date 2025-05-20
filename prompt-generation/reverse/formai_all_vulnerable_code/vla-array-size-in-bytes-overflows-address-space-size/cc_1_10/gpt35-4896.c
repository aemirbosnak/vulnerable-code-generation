//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int roll;
    float marks;
};

int main(){
    int i, n, size=sizeof(struct student);
    char ch, sname[50];
    FILE *fp;

    //Creating file and writing data to it
    fp = fopen("student.dat", "wb");
    if(fp == NULL){
        printf("Error in creating file...");
        exit(0);
    }
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student s[n];
    printf("\nEnter details of students...\n");
    for(i=0; i<n; i++){
        printf("\nStudent %d:\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);      //Input name
        printf("Roll number: ");
        scanf("%d", &s[i].roll);    //Input Roll number
        printf("Marks: ");
        scanf("%f", &s[i].marks);   //Input Marks
        fwrite(&s[i], size, 1, fp); //Writing data to the file
    }

    fclose(fp);

    //Reading data from the file
    fp = fopen("student.dat", "rb");
    if(fp == NULL){
        printf("Error in opening file...");
        exit(0);
    }

    printf("\n\n**Data from the file**\n\n");
    printf("%-15s%-15s%-15s\n", "Name", "Roll number", "Marks");
    printf("------------------------------------------\n");
    while(fread(&s[0], size, 1, fp)){
        printf("%-15s%-15d%-15.2f\n", s[0].name, s[0].roll, s[0].marks);
    }

    fclose(fp);

    //Searching a student details based on name
    fp = fopen("student.dat", "rb");
    if(fp == NULL){
        printf("Error in opening file...");
        exit(0);
    }

    printf("\n\n**Searching a student details based on name**\n\n");
    printf("Enter the name of the student: ");
    scanf("%s", sname);

    while(fread(&s[0], size, 1, fp)){
        if(strcmp(s[0].name, sname) == 0){
            printf("\nStudent details:\n");
            printf("Name: %s\nRoll number: %d\nMarks: %.2f\n", s[0].name, s[0].roll, s[0].marks);
            break;
        }
    }

    fclose(fp);

    return 0;
}