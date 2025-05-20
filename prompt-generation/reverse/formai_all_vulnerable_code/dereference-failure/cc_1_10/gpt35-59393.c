//FormAI DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    char address[50];
    int age;
} Record;

Record records[MAX_RECORDS];
int current_record_count = 0;

void add_record() {
    Record new_record;
    printf("Enter ID: ");
    scanf("%d", &new_record.id);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter address: ");
    scanf("%s", new_record.address);
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    records[current_record_count] = new_record;
    current_record_count++;
    printf("\nRecord added successfully.\n");
}

void display_records() {
    if (current_record_count == 0) {
        printf("\nNo records to display.\n");
        return;
    }
    printf("\nID\tName\tAddress\t\tAge\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < current_record_count; i++) {
        printf("%d\t%s\t%s\t%d\n", records[i].id, records[i].name, records[i].address, records[i].age);
    }
}

void save_records() {
    FILE *file;
    file = fopen("records.txt", "w");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    for (int i = 0; i < current_record_count; i++) {
        fprintf(file, "%d;%s;%s;%d\n", records[i].id, records[i].name, records[i].address, records[i].age);
    }
    fclose(file);
    printf("\nRecords saved to file successfully.\n");
}

void load_records() {
    FILE *file;
    file = fopen("records.txt", "r");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    current_record_count = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        Record new_record;
        char *token;
        token = strtok(line, ";");
        new_record.id = atoi(token);
        token = strtok(NULL, ";");
        strcpy(new_record.name, token);
        token = strtok(NULL, ";");
        strcpy(new_record.address, token);
        token = strtok(NULL, ";");
        new_record.age = atoi(token);
        records[current_record_count] = new_record;
        current_record_count++;
    }
    fclose(file);
    printf("\nRecords loaded from file successfully.\n");
}

int main() {
    int choice = 0;
    while (1) {
        printf("\n---- futuristic database management system ----\n");
        printf("1. Add record\n");
        printf("2. Display records\n");
        printf("3. Save records to file\n");
        printf("4. Load records from file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                save_records();
                break;
            case 4:
                load_records();
                break;
            case 5:
                return 0;
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}