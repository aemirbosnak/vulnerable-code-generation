//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include<stdio.h>
#include<string.h>

struct student {
	char name[30];
	int roll;
	float marks;
};

int main() {

    int no_of_students,i,j;
    printf("Enter the number of students: ");
    scanf("%d",&no_of_students);

    struct student students[no_of_students];
	for(i=0; i<no_of_students; i++) {
		printf("\nEnter the details of student %d:\n",i+1);
		printf("Name: ");
		scanf("%s",students[i].name);
		printf("Roll: ");
		scanf("%d",&students[i].roll);
		printf("Marks: ");
		scanf("%f",&students[i].marks);
	}

	//Sorting based on marks
	for(i=0;i<no_of_students;i++) {
	    for(j=i+1;j<no_of_students;j++) {
	        if(students[i].marks < students[j].marks) {
	            struct student temp;
	            temp = students[i];
	            students[i] = students[j];
	            students[j] = temp;
            }
        }
    }

    printf("\nSorted list of students based on marks:\n");
    printf("----------------------------------------------\n");
    printf("| %-10s| %-10s| %-10s|\n","Name","Roll","Marks");
    printf("----------------------------------------------\n");
    for(i=0;i<no_of_students;i++) {
        printf("| %-10s| %-10d| %-10.2f|\n",students[i].name,students[i].roll,students[i].marks);
    }
    printf("----------------------------------------------\n");

    //Sorting based on roll number
	for(i=0; i<no_of_students; i++) {
	    for(j=i+1; j<no_of_students; j++) {
	        if(students[i].roll > students[j].roll) {
	            struct student temp;
	            temp = students[i];
	            students[i] = students[j];
	            students[j] = temp;
            }
        }
    }

    printf("\nSorted list of students based on roll number:\n");
    printf("----------------------------------------------\n");
    printf("| %-10s| %-10s| %-10s|\n","Name","Roll","Marks");
    printf("----------------------------------------------\n");
    for(i=0;i<no_of_students;i++) {
        printf("| %-10s| %-10d| %-10.2f|\n",students[i].name,students[i].roll,students[i].marks);
    }
    printf("----------------------------------------------\n");

	return 0;
}