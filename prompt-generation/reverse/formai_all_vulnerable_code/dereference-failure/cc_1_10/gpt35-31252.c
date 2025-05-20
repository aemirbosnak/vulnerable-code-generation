//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    int id;
    char name[50];
    int age;
    int marks;
};

int main(){

    int n,i;
    printf("Enter the number of students: ");
    scanf("%d",&n);

    struct Student *s = (struct Student*) malloc(n*sizeof(struct Student));
    for(i=0;i<n;i++){
        printf("\nEnter details of student %d\n",i+1);
        s[i].id = i+1;
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter age: ");
        scanf("%d",&s[i].age);
        printf("Enter marks: ");
        scanf("%d",&s[i].marks);
    }

    printf("\nAll Students record:\n");
    printf("ID\tName\tAge\tMarks\n");

    for(i=0;i<n;i++){
        printf("%d\t%s\t%d\t%d\n",s[i].id,s[i].name,s[i].age,s[i].marks);
    }

    int max_marks = s[0].marks;
    char max_marks_name[50];

    for(i=1;i<n;i++){
        if(s[i].marks>max_marks){
            max_marks = s[i].marks;
            strcpy(max_marks_name, s[i].name);
        }
    }

    printf("\n%s scored highest marks of %d\n",max_marks_name,max_marks);

    free(s);

    return 0;
}