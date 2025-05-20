//FormAI DATASET v1.0 Category: File handling ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This is a program to demonstrate file handling in C for scientific research purposes */

int main(){
    FILE *fp; // file pointer to hold file address
    char filename[20], data[100]; //to store file name and data to be written
    int choice;

    printf("*****File Handling Demo*****\n");
    printf("Enter the file name to create or open:");
    scanf("%s",filename);

    fp = fopen(filename,"a+"); // open file in append mode or create a new one if it doesn't exist

    if(fp == NULL){ //check if file could be opened
        printf("Failed to open file!");
        exit(1);
    }
    else{
        printf("File opened successfully\n");
    }

    printf("What do you want to do?\n1. Write to file\n2. Read from file\n3. Exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            getchar(); // consume newline character left by scanf
            printf("Enter the data to be written to file:\n");
            fgets(data,100,stdin); //read data from user
            fputs(data,fp); //write data to file
            printf("Data written successfuly\n");
            fclose(fp);
            break;
        case 2:
            printf("Reading data from file...\n");
            rewind(fp); //move the file pointer to the beginning of the file
            while(fgets(data,100,fp)!=NULL){ //read data from file and print it line by line
                printf("%s",data);
            }
            fclose(fp);
            break;
        case 3:
            fclose(fp);
            exit(0);
        default:
            printf("Invalid choice!");
            break;
    }
    return 0;
}