//FormAI DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    int age;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int numRecords;
};

void printRecord(struct Record r) {
    printf("%d.\tName: %s\n\tAge: %d\n", r.id, r.name, r.age);
}

void printDatabase(struct Database db) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < db.numRecords; i++) {
        printRecord(db.records[i]);
    }
    printf("\nTotal Number of Records: %d\n", db.numRecords);
}

void saveDatabase(struct Database db) {
    FILE *fp;
    fp = fopen("database.txt", "w");
    for (int i = 0; i < db.numRecords; i++) {
        fprintf(fp, "%d,%s,%d\n", db.records[i].id, db.records[i].name, db.records[i].age);
    }
    fclose(fp);
}

struct Database loadDatabase() {
    struct Database db;
    db.numRecords = 0;

    FILE *fp;
    fp = fopen("database.txt", "r");
    if (fp != NULL) {
        char buffer[1024];
        while (fgets(buffer, sizeof buffer, fp) != NULL) {
            char *idStr = strtok(buffer, ",");
            char *nameStr = strtok(NULL, ",");
            char *ageStr = strtok(NULL, ",");
            struct Record r;
            r.id = atoi(idStr);
            strcpy(r.name, nameStr);
            r.age = atoi(ageStr);
            db.records[db.numRecords] = r;
            db.numRecords++;
        }
        fclose(fp);
    }

    return db;
}

void addRecord(struct Database *db, char name[], int age) {
    struct Record r;
    r.id = db->numRecords + 1;
    strcpy(r.name, name);
    r.age = age;
    db->records[db->numRecords] = r;
    db->numRecords++;
}

void deleteRecord(struct Database *db, int id) {
    int index = -1;
    for (int i = 0; i < db->numRecords; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        for (int i = index; i < db->numRecords - 1; i++) {
            db->records[i] = db->records[i + 1];
        }
        db->numRecords--;
    }
}

void updateRecord(struct Database *db, int id, char name[], int age) {
    int index = -1;
    for (int i = 0; i < db->numRecords; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        strcpy(db->records[index].name, name);
        db->records[index].age = age;
    }
}

int main() {
    struct Database db = loadDatabase();
    char input[1024];
    while (1) {
        printf("\nEnter Command (ADD, DELETE, UPDATE, PRINT, SAVE, EXIT): ");
        fgets(input, sizeof input, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "ADD") == 0) {
            char name[50];
            int age;
            printf("Name: ");
            fgets(name, sizeof name, stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Age: ");
            scanf("%d", &age);
            getchar();
            addRecord(&db, name, age);
        } else if (strcmp(input, "DELETE") == 0) {
            int id;
            printf("ID: ");
            scanf("%d", &id);
            getchar();
            deleteRecord(&db, id);
        } else if (strcmp(input, "UPDATE") == 0) {
            int id, age;
            char name[50];
            printf("ID: ");
            scanf("%d", &id);
            getchar();
            printf("Name: ");
            fgets(name, sizeof name, stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Age: ");
            scanf("%d", &age);
            getchar();
            updateRecord(&db, id, name, age);
        } else if (strcmp(input, "PRINT") == 0) {
            printDatabase(db);
        } else if (strcmp(input, "SAVE") == 0) {
            saveDatabase(db);
            printf("Database saved to file.\n");
        } else if (strcmp(input, "EXIT") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}