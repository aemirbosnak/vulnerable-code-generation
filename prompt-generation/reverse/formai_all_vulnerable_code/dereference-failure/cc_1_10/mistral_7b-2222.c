//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct{
    int id;
    char name[50];
    float salary;
}Employee;

int main(int argc, char *argv[])
{
    int i, j;
    Employee *employees, *new_employee;
    int fd;
    size_t size;
    void *shared_memory;

    // Allocating memory for employee structure array
    employees = (Employee *) malloc(MAX_SIZE * sizeof(Employee));
    if(employees == NULL){
        perror("Memory allocation failed");
        return 1;
    }

    // Initializing some employees
    for(i=0; i<5; i++){
        employees[i].id = i+1;
        strcpy(employees[i].name, "Employee");
        employees[i].salary = 5000.0;
    }

    // Opening shared memory file for map_mmap()
    fd = open("/shm_employees", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(fd == -1){
        perror("Failed to open shared memory file");
        free(employees);
        return 1;
    }

    // Setting shared memory size
    ftruncate(fd, MAX_SIZE * sizeof(Employee));

    // Map the shared memory file to the process address space
    shared_memory = mmap(NULL, MAX_SIZE * sizeof(Employee), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(shared_memory == MAP_FAILED){
        perror("Failed to map shared memory file");
        close(fd);
        free(employees);
        return 1;
    }

    // Copying the employees array to the shared memory
    memcpy(shared_memory, employees, MAX_SIZE * sizeof(Employee));

    // Freeing the local memory
    free(employees);

    // Printing the employees in the shared memory
    printf("Employees in the shared memory:\n");
    for(i=0; i<MAX_SIZE; i++){
        new_employee = (Employee *) ((char *)shared_memory + i * sizeof(Employee));
        printf("ID: %d, Name: %s, Salary: %.2f\n", new_employee->id, new_employee->name, new_employee->salary);
    }

    // Updating an employee's salary in the shared memory
    for(i=0; i<MAX_SIZE; i++){
        new_employee = (Employee *) ((char *)shared_memory + i * sizeof(Employee));
        if(new_employee->id == 3){
            new_employee->salary = 6000.0;
            break;
        }
    }

    // Syncing the shared memory to make the changes persistent
    msync(shared_memory, MAX_SIZE * sizeof(Employee), MS_SYNC);

    // Unmapping the shared memory from the process address space
    munmap(shared_memory, MAX_SIZE * sizeof(Employee));

    // Closing the shared memory file
    close(fd);

    return 0;
}