//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_SIZE 10
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char data[50];
} Record;

typedef struct {
    Record records[MAX_DB_SIZE];
    int num_records;
    int locked;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->num_records = 0;
    db->locked = 0;
    return db;
}

void insert_record(Database *db, Record record) {
    if (db->num_records >= MAX_DB_SIZE) {
        printf("Database is full!\n");
        return;
    }
    db->records[db->num_records++] = record;
}

void delete_record(Database *db, int id) {
    int i, index = -1;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record with id %d not found!\n", id);
        return;
    }
    for (i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->num_records--;
}

void print_database(Database *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("ID: %d\nName: %s\nData: %s\n\n", db->records[i].id, db->records[i].name, db->records[i].data);
    }
}

void lock_database(Database *db) {
    db->locked = 1;
}

void unlock_database(Database *db) {
    db->locked = 0;
}

int main() {
    int choice;
    int id;
    Record record;
    char name[MAX_NAME_LENGTH];
    char data[50];

    Database *db = create_database();

    while (1) {
        printf("1. Insert record\n");
        printf("2. Delete record\n");
        printf("3. Print database\n");
        printf("4. Lock database\n");
        printf("5. Unlock database\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (db->locked) {
                    printf("Database is locked!\n");
                    break;
                }
                printf("Enter ID: ");
                scanf("%d", &record.id);
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter data: ");
                scanf("%s", record.data);
                insert_record(db, record);
                break;
            case 2:
                if (db->locked) {
                    printf("Database is locked!\n");
                    break;
                }
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_record(db, id);
                break;
            case 3:
                print_database(db);
                break;
            case 4:
                printf("Are you sure you want to lock the database? (y/n): ");
                char answer[10];
                scanf("%s", answer);
                if (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0) {
                    lock_database(db);
                    printf("Database locked!\n");
                }
                break;
            case 5:
                if (!db->locked) {
                    printf("Database is not locked!\n");
                    break;
                }
                printf("Enter password to unlock database: ");
                scanf("%s", name);
                if (strcmp(name, "password") == 0) {
                    unlock_database(db);
                    printf("Database unlocked!\n");
                } else {
                    printf("Wrong password!\n");
                }
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}