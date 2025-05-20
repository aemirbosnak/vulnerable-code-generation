//FormAI DATASET v1.0 Category: Online Examination System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure to hold details of a student
struct student{
    char name[20], regno[10];
    int marks;
};

// Define function to conduct exam
void conduct_exam(struct student* arr, int n){
    printf("*** Welcome to the Online Examination System ***\n");
    printf("*** This is a C Programming Test (100 marks) ***\n");
    for(int i=0;i<n;i++){
        printf("\nExam for Student %d - Name : %s, Registration Number : %s\n", i+1, arr[i].name, arr[i].regno);
        printf("Please answer the following questions.\n");
        int temp=0;
        for(int j=1;j<=10;j++){
            printf("Q%d. ", j);
            int ans;
            scanf("%d", &ans);
            if(ans==1){
                temp+=10;
            }
        }
        printf("Your total score is : %d/100\n", temp);
        arr[i].marks = temp;
    }
}

// Define function to display results
void display_results(struct student* arr, int n){
    printf("\n*** Results ***\n");
    printf("Name\t\t Registration Number\t\t Marks\n");
    for(int i=0;i<n;i++){
        printf("%s\t\t %s\t\t\t\t %d\n", arr[i].name, arr[i].regno, arr[i].marks);
    }
}

int main(){
    printf("*** Welcome to the Online Examination System ***\n");
    printf("Please enter the number of students taking the exam : ");
    int n;
    scanf("%d", &n);
    struct student arr[n];
    for(int i=0;i<n;i++){
        printf("\nStudent %d\n", i+1);
        printf("Name : ");
        scanf("%s", arr[i].name);
        printf("Registration Number : ");
        scanf("%s", arr[i].regno);
    }
    conduct_exam(arr, n);
    display_results(arr, n);
    return 0;
}