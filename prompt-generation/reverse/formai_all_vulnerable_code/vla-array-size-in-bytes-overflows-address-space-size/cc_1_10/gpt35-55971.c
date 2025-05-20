//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
 char name[30];
 int id;
 float gpa;
};

int main(){
    int n,i;// n is the number of students
    printf("Enter the number of students: ");
    scanf("%d",&n);
    FILE *fptr; //creating a file pointer
    fptr=fopen("students.txt","w");// opening file in write mode
    
    if (fptr==NULL){
        printf("Error! File cannot be opened.");
        exit(1);
    }
    
    struct student stud[n];//creating an array of struct objects
    
    for(i=0;i<n;i++){
        printf("Enter details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", stud[i].name);
        printf("ID: ");
        scanf("%d", &stud[i].id);
        printf("GPA: ");
        scanf("%f", &stud[i].gpa);
        printf("\n");
    }
    
    fwrite(stud,sizeof(struct student),n,fptr);//writing the struct array to the file
    fclose(fptr);//closing the file
    
    printf("\nData written to file successfully.\n\n");
    
    fptr=fopen("students.txt","r"); //opening file in read mode
    
    struct student read_stud;
    
    printf("Name\tID\tGPA\n");
    for(i=0;i<n;i++){
        fread(&read_stud,sizeof(struct student),1,fptr);//reading each struct object from the file
        printf("%s\t%d\t%.2f\n",read_stud.name,read_stud.id,read_stud.gpa);
    }
    
    fclose(fptr);//closing the file
    
    return 0;
}