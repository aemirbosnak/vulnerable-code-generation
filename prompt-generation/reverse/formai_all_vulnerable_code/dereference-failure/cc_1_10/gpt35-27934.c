//FormAI DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record(int id, char name[], int age);
void update_record(int id, char name[], int age);
void delete_record(int id);
void print_database();
void write_database();
void read_database();

int main() {
    int choice, id, age;
    char name[20];
    
    read_database();
    
    do {
        printf("1. Add Record\n");
        printf("2. Update Record\n");
        printf("3. Delete Record\n");
        printf("4. Print Database\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                add_record(id, name, age);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                update_record(id, name, age);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 4:
                print_database();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
    
    write_database();
    
    return 0;
}

void add_record(int id, char name[], int age) {
    if(num_records >= MAX_RECORDS) {
        printf("Database is full\n");
        return;
    }
    
    database[num_records].id = id;
    strcpy(database[num_records].name, name);
    database[num_records].age = age;
    
    num_records++;
}

void update_record(int id, char name[], int age) {
    int i;
    for(i=0; i<num_records; i++) {
        if(database[i].id == id) {
            strcpy(database[i].name, name);
            database[i].age = age;
            printf("Record updated\n");
            return;
        }
    }
    printf("Record not found\n");
}

void delete_record(int id) {
    int i;
    for(i=0; i<num_records; i++) {
        if(database[i].id == id) {
            for(int j=i; j<num_records-1; j++) {
                database[j] = database[j+1];
            }
            num_records--;
            printf("Record deleted\n");
            return;
        }
    }
    printf("Record not found\n");
}

void print_database() {
    int i;
    printf("\n");
    printf("%-5s %-20s %-5s\n", "ID", "Name", "Age");
    for(i=0; i<num_records; i++) {
        printf("%-5d %-20s %-5d\n", database[i].id, database[i].name, database[i].age);
    }
    printf("\n");
}

void write_database() {
    FILE *fp = fopen("database.txt", "w");
    
    fprintf(fp, "%d\n", num_records);
    
    for(int i=0; i<num_records; i++) {
        fprintf(fp, "%d %s %d\n", database[i].id, database[i].name, database[i].age);
    }
    
    fclose(fp);
}

void read_database() {
    FILE *fp = fopen("database.txt", "r");
    
    if(fp == NULL) {
        printf("No existing database found\n");
        return;
    }
    
    fscanf(fp, "%d", &num_records);
    
    for(int i=0; i<num_records; i++) {
        fscanf(fp, "%d %s %d", &database[i].id, database[i].name, &database[i].age);
    }
    
    fclose(fp);
}