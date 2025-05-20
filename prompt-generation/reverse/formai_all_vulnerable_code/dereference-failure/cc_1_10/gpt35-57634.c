//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000 //maximum length of a line in the csv file
#define MAX_FIELDS 20 //maximum number of fields in a line

//the function to read a line from csv and return the number of fields
int read_line(FILE* fp, char** fields)
{
    char buffer[MAX_LEN];
    fgets(buffer, MAX_LEN, fp);

    //check if end of file has been reached
    if (feof(fp)) {
        return -1;
    }

    //tokenize the line into fields
    int i = 0;
    char* token = strtok(buffer, ",");
    while (token != NULL && i < MAX_FIELDS) {
        fields[i++] = strdup(token);
        token = strtok(NULL, ",");
    }

    return i;
}

//the main function to read the csv file
int main()
{
    FILE* fp = fopen("sample.csv", "r"); //open the csv file
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char* fields[MAX_FIELDS];
    int num_fields;
    while ((num_fields = read_line(fp, fields)) != -1) {
        //print the fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }

    fclose(fp); //close the file

    return 0;
}