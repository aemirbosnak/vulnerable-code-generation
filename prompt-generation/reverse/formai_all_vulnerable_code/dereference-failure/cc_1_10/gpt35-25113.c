//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 100 //maximum length of a field in the csv file

//struct to hold the csv data
typedef struct {
    int id;
    char name[MAX_FIELD_LENGTH];
    double salary;
} Employee;

//function to split a line of csv data into fields
int split_csv_line(char *line, char *fields[]) {
    char *field;
    int i = 0;

    //get the first field
    field = strtok(line, ",");

    //loop through the rest of the fields
    while(field != NULL) {
        fields[i++] = field;
        field = strtok(NULL, ",");
    }

    //return the number of fields
    return i;
}

//function to read the csv file and return an array of employees
Employee *read_csv(char *filename, int *num_employees) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *fields[3];
    int id;
    char name[MAX_FIELD_LENGTH];
    double salary;
    Employee *employees;
    int i = 0;

    //open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    //get the number of lines in the file (i.e. the number of employees)
    *num_employees = 0;
    while ((read = getline(&line, &len, file)) != -1) {
        (*num_employees)++;
    }
    rewind(file); //reset file pointer to the beginning of the file

    //allocate memory for the array of employees
    employees = (Employee *)malloc(sizeof(Employee) * (*num_employees));
    if (employees == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    //read each line of the file and store the data in the employees array
    while ((read = getline(&line, &len, file)) != -1) {
        //split the line into fields
        split_csv_line(line, fields);

        //convert the fields to the appropriate data types
        id = atoi(fields[0]);
        strcpy(name, fields[1]);
        salary = atof(fields[2]);

        //store the data in the employees array
        employees[i].id = id;
        strcpy(employees[i].name, name);
        employees[i].salary = salary;

        i++;
    }

    //cleanup
    fclose(file);
    if (line)
        free(line);

    return employees;
}

int main(int argc, char *argv[]) {
    int num_employees;
    Employee *employees;
    int i;

    //read the csv file into an array of employees
    employees = read_csv("employees.csv", &num_employees);

    //print out the employee data
    printf("ID\tName\t\t\tSalary\n");
    printf("--------------------------------\n");
    for (i = 0; i < num_employees; i++) {
        printf("%d\t%-20s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    //cleanup
    free(employees);

    return 0;
}