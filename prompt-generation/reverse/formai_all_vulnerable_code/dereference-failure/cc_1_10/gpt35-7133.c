//FormAI DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} Employee;

typedef struct {
    int key;
    int position;
} Index;

int addRecord(FILE* file, Employee emp, Index* index, int* currentIndex) {
    int filePosition, indexPosition;
    fseek(file, 0, SEEK_END);
    filePosition = ftell(file);
    fwrite(&emp, sizeof(Employee), 1, file);
    indexPosition = *currentIndex;
    index[*currentIndex].key = emp.id;
    index[*currentIndex].position = filePosition;
    (*currentIndex)++;
    return indexPosition;
}

void searchRecord(FILE* file, Index* index, int currentIndex, int key) {
    int i;
    for (i = 0; i < currentIndex; i++) {
        if (index[i].key == key) {
            Employee emp;
            fseek(file, index[i].position, SEEK_SET);
            fread(&emp, sizeof(Employee), 1, file);
            printf("ID: %d\tName: %s\n", emp.id, emp.name);
            return;
        }
    }
    printf("No employee with id %d found.\n", key);
}

int main() {
    FILE* file;
    Index* index;
    Employee emp;
    int currentIndex = 0, choice, key, position;
    char name[20];
    index = (Index*)malloc(100 * sizeof(Index));
    file = fopen("employee.dat", "wb");
    if (file == NULL) {
        printf("Failed to open file.");
        exit(1);
    }
    while (1) {
        printf("1. Add Employee\n2. Search Employee\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter id: ");
                scanf("%d", &emp.id);
                printf("Enter name: ");
                scanf("%s", emp.name);
                position = addRecord(file, emp, index, &currentIndex);
                printf("Record added at index: %d\n", position);
                break;
            case 2:
                printf("Enter id: ");
                scanf("%d", &key);
                searchRecord(file, index, currentIndex, key);
                break;
            case 3:
                fclose(file);
                free(index);
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}