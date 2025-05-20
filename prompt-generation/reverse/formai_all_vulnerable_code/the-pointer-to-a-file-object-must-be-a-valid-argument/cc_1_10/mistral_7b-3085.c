//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 1024

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void print_employee(Employee emp) {
    printf("\nID : %d", emp.id);
    printf("\nName : %s", emp.name);
    printf("\nSalary : %.2f", emp.salary);
}

int main() {
    int fd;
    char filename[] = "employees.txt";
    Employee employees[10];
    char line[MAX_SIZE];
    int i = 0;

    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fd) != NULL) {
        sscanf(line, "%d %s %f", &employees[i].id, employees[i].name, &employees[i].salary);
        i++;
    }

    close(fd);

    printf("\nEmployee Records:\n");

    for (int j = 0; j < i; j++) {
        print_employee(employees[j]);
    }

    return 0;
}