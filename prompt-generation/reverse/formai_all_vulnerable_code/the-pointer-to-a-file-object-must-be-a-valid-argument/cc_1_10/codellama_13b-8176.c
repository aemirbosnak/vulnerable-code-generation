//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

    // Structure to store the data
    typedef struct {
        int id;
        char name[100];
        char email[100];
    } Record;

    // Function to add a record to the database
    void addRecord(Record record) {
        FILE *fp;
        fp = fopen("database.txt", "a+");
        fprintf(fp, "%d %s %s\n", record.id, record.name, record.email);
        fclose(fp);
    }

    // Function to search a record in the database
    Record searchRecord(int id) {
        Record record;
        char buffer[100];
        FILE *fp;
        fp = fopen("database.txt", "r");
        while (fgets(buffer, 100, fp)) {
            if (atoi(buffer) == id) {
                sscanf(buffer, "%d %s %s", &record.id, record.name, record.email);
                break;
            }
        }
        fclose(fp);
        return record;
    }

    // Function to update a record in the database
    void updateRecord(int id, Record record) {
        char buffer[100];
        FILE *fp;
        fp = fopen("database.txt", "r+");
        while (fgets(buffer, 100, fp)) {
            if (atoi(buffer) == id) {
                fseek(fp, -strlen(buffer), SEEK_CUR);
                fprintf(fp, "%d %s %s\n", record.id, record.name, record.email);
                break;
            }
        }
        fclose(fp);
    }

    // Function to delete a record from the database
    void deleteRecord(int id) {
        char buffer[100];
        FILE *fp;
        fp = fopen("database.txt", "r+");
        while (fgets(buffer, 100, fp)) {
            if (atoi(buffer) == id) {
                fseek(fp, -strlen(buffer), SEEK_CUR);
                fprintf(fp, "");
                break;
            }
        }
        fclose(fp);
    }

    int main() {
        Record record;
        int id;
        char choice;
        do {
            printf("1. Add Record\n");
            printf("2. Search Record\n");
            printf("3. Update Record\n");
            printf("4. Delete Record\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%c", &choice);

            switch (choice) {
                case '1':
                    printf("Enter id: ");
                    scanf("%d", &id);
                    printf("Enter name: ");
                    scanf("%s", record.name);
                    printf("Enter email: ");
                    scanf("%s", record.email);
                    addRecord(record);
                    break;
                case '2':
                    printf("Enter id: ");
                    scanf("%d", &id);
                    record = searchRecord(id);
                    printf("Name: %s\n", record.name);
                    printf("Email: %s\n", record.email);
                    break;
                case '3':
                    printf("Enter id: ");
                    scanf("%d", &id);
                    printf("Enter new name: ");
                    scanf("%s", record.name);
                    printf("Enter new email: ");
                    scanf("%s", record.email);
                    updateRecord(id, record);
                    break;
                case '4':
                    printf("Enter id: ");
                    scanf("%d", &id);
                    deleteRecord(id);
                    break;
                case '5':
                    exit(0);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
        } while (choice != '5');

        return 0;
    }