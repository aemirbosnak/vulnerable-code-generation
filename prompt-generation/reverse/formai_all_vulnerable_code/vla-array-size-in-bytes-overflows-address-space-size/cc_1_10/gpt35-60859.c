//FormAI DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int roll_no;
    float cgpa;
};

void display(struct student s[],int n){
    int i;
    printf("\nStudent details are:\n");
    printf("---------------------\n");
    for(i=0;i<n;i++){
        printf("Name: %s\n",s[i].name);
        printf("Roll number: %d\n",s[i].roll_no);
        printf("CGPA: %.2f\n",s[i].cgpa);
        printf("\n");
    }
}

void get_data(struct student s[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nEnter student %d details:\n",i+1);
        printf("Enter the name of student: ");
        scanf("%s",s[i].name);
        printf("Enter the roll number of student: ");
        scanf("%d",&s[i].roll_no);
        printf("Enter the CGPA of student: ");
        scanf("%f",&s[i].cgpa);
    }
    display(s,n);
    printf("\n");
}

void search(struct student s[],int n){
    int i,flag=0,roll_no;
    printf("Enter roll number of the student to be searched: ");
    scanf("%d",&roll_no);
    for(i=0;i<n;i++){
        if(s[i].roll_no==roll_no){
            printf("\nStudent found. Details are: \n");
            printf("Name: %s\n",s[i].name);
            printf("CGPA: %.2f\n",s[i].cgpa);
            flag=1;
        }
    }
    if(flag==0){
        printf("\nError: Student not found!\n");
    }
}

void sort(struct student s[],int n){
    int i,j;
    struct student temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(s[i].cgpa>s[j].cgpa){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    display(s,n);
}

void update(struct student s[],int n){
    int i,flag=0,roll_no;
    printf("Enter the roll number of the student to be updated: ");
    scanf("%d",&roll_no);
    for(i=0;i<n;i++){
        if(s[i].roll_no==roll_no){
            printf("\nEnter updated details for Student %d:\n",i+1);
            printf("Enter the name of student: ");
            scanf("%s",s[i].name);
            printf("Enter the CGPA of student: ");
            scanf("%f",&s[i].cgpa);
            flag=1;
        }
    }
    if(flag==0){
        printf("\nError: Student not found!");
    }
    else{
        printf("\nDetails updated successfully!\n");
        display(s,n);
    }
}

int main(){
    int i,n,choice;
    printf("\nEnter the number of students: ");
    scanf("%d",&n);
    struct student s[n];
    get_data(s,n);
    printf("\nMENU:\n1.Search\n2.Sort\n3.Update\n4.Exit\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                search(s,n);
                break;
            case 2:
                sort(s,n);
                break;
            case 3:
                update(s,n);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid input! Try again...\n");
        }
    }
    return 0;
}