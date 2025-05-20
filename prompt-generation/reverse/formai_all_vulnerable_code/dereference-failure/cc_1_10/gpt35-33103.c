//FormAI DATASET v1.0 Category: Database Indexing System ; Style: irregular
/* Welcome to our unique Database Indexing System! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define our structs */
typedef struct {
    int id;
    char name[25];
    char email[50];
    char phone[15];
} Record;

typedef struct {
    int id;
    long pos;
} Index;

/* Define our function prototypes */
void add_record(char *, char *, char *);
void display_record(int);
void search_record(char *);
void update_record(int, char *);
void delete_record(int);

/* Define our global variables */
FILE *data_file, *index_file;
int num_records, index_size = 0;

int main() {
    printf("\nWelcome to our Database Indexing System!\n\n");

    /* Open our data and index files */
    data_file = fopen("records.dat", "ab+");
    index_file = fopen("records.idx", "ab+");

    /* If files don't exist, create them */
    if (data_file == NULL || index_file == NULL) {
        printf("Error: Unable to create files.\n");
        exit(1);
    }

    /* Read in the number of records in our data file */
    fseek(data_file, 0, SEEK_END);
    num_records = ftell(data_file) / sizeof(Record);

    /* If index file is empty, create index */
    fseek(index_file, 0, SEEK_END);
    if (ftell(index_file) == 0) {
        for (int i = 0; i < num_records; i++) {
            Index index_entry;
            index_entry.id = i + 1;
            index_entry.pos = i * sizeof(Record);
            fwrite(&index_entry, sizeof(Index), 1, index_file);
            index_size++;
        }
    }

    /* User menu */
    int selection = 0;
    while (selection != 5) {
        printf("Please select an option:\n");
        printf("1. Add a record\n");
        printf("2. Display a record\n");
        printf("3. Search for a record\n");
        printf("4. Update a record\n");
        printf("5. Delete a record\n");
        printf("6. Exit\n\n");

        /* Get user selection */
        printf("Selection: ");
        scanf("%d", &selection);

        /* Handle user selection */
        switch (selection) {
            case 1:
                /* Add a record */
                printf("\nAdding a new record...\n");
                char name[25], email[50], phone[15];
                printf("Name: ");
                scanf("%s", name);
                printf("Email: ");
                scanf("%s", email);
                printf("Phone: ");
                scanf("%s", phone);
                add_record(name, email, phone);
                printf("\nRecord added successfully!\n\n");
                break;

            case 2:
                /* Display a record */
                printf("\nDisplaying a record...\n");
                int id;
                printf("Record ID: ");
                scanf("%d", &id);
                display_record(id);
                printf("\n");
                break;

            case 3:
                /* Search for a record */
                printf("\nSearching for a record...\n");
                char query[25];
                printf("Search query: ");
                scanf("%s", query);
                search_record(query);
                printf("\n");
                break;

            case 4:
                /* Update a record */
                printf("\nUpdating a record...\n");
                int update_id;
                printf("Record ID: ");
                scanf("%d", &update_id);
                char update_data[50];
                printf("New data: ");
                scanf("%s", update_data);
                update_record(update_id, update_data);
                printf("\nRecord updated successfully!\n\n");
                break;

            case 5:
                /* Delete a record */
                printf("\nDeleting a record...\n");
                int delete_id;
                printf("Record ID: ");
                scanf("%d", &delete_id);
                delete_record(delete_id);
                printf("\nRecord deleted successfully!\n\n");
                break;

            case 6:
                /* Exit program */
                printf("\nExiting program...\n");
                break;

            default:
                /* Invalid selection */
                printf("\nInvalid selection! Please enter a number between 1 and 6.\n\n");
                break;
        }
    }

    /* Close our files */
    fclose(data_file);
    fclose(index_file);

    return 0;
}

/* Definition for our add_record function */
void add_record(char *name, char *email, char *phone) {
    /* Create a new record */
    Record new_record;
    new_record.id = num_records + 1;
    strcpy(new_record.name, name);
    strcpy(new_record.email, email);
    strcpy(new_record.phone, phone);

    /* Write record to data file */
    fseek(data_file, 0, SEEK_END);
    fwrite(&new_record, sizeof(Record), 1, data_file);

    /* Update number of records */
    num_records++;

    /* Create a new index entry */
    Index new_index_entry;
    new_index_entry.id = new_record.id;
    new_index_entry.pos = (num_records - 1) * sizeof(Record);

    /* Write index entry to index file */
    fseek(index_file, 0, SEEK_END);
    fwrite(&new_index_entry, sizeof(Index), 1, index_file);

    /* Update index size */
    index_size++;
}

/* Definition for our display_record function */
void display_record(int id) {
    /* Check if record exists */
    if (id > num_records || id < 1) {
        printf("Record not found!\n");
        return;
    }

    /* Find record position using index */
    Index index_entry;
    fseek(index_file, (id - 1) * sizeof(Index), SEEK_SET);
    fread(&index_entry, sizeof(Index), 1, index_file);

    /* Read in record from data file */
    Record record;
    fseek(data_file, index_entry.pos, SEEK_SET);
    fread(&record, sizeof(Record), 1, data_file);

    /* Display record */
    printf("Record ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Email: %s\n", record.email);
    printf("Phone: %s\n", record.phone);
}

/* Definition for our search_record function */
void search_record(char *query) {
    /* Iterate through each index entry and check if record matches query */
    for (int i = 1; i <= index_size; i++) {
        Index index_entry;
        fseek(index_file, (i - 1) * sizeof(Index), SEEK_SET);
        fread(&index_entry, sizeof(Index), 1, index_file);

        Record record;
        fseek(data_file, index_entry.pos, SEEK_SET);
        fread(&record, sizeof(Record), 1, data_file);

        if (strstr(record.name, query) != NULL || strstr(record.email, query) != NULL || strstr(record.phone, query) != NULL) {
            printf("Record ID: %d\n", record.id);
            printf("Name: %s\n", record.name);
            printf("Email: %s\n", record.email);
            printf("Phone: %s\n\n", record.phone);
        }
    }
}

/* Definition for our update_record function */
void update_record(int id, char *update_data) {
    /* Check if record exists */
    if (id > num_records || id < 1) {
        printf("Record not found!\n");
        return;
    }

    /* Find record position using index */
    Index index_entry;
    fseek(index_file, (id - 1) * sizeof(Index), SEEK_SET);
    fread(&index_entry, sizeof(Index), 1, index_file);

    /* Update record */
    Record record;
    fseek(data_file, index_entry.pos, SEEK_SET);
    fread(&record, sizeof(Record), 1, data_file);

    if (strlen(update_data) <= 15) {
        strcpy(record.phone, update_data);
    } else if (strlen(update_data) <= 25) {
        strcpy(record.name, update_data);
    } else {
        strcpy(record.email, update_data);
    }

    /* Write updated record to data file */
    fseek(data_file, index_entry.pos, SEEK_SET);
    fwrite(&record, sizeof(Record), 1, data_file);
}

/* Definition for our delete_record function */
void delete_record(int id) {
    /* Check if record exists */
    if (id > num_records || id < 1) {
        printf("Record not found!\n");
        return;
    }

    /* Find record position using index */
    Index index_entry;
    fseek(index_file, (id - 1) * sizeof(Index), SEEK_SET);
    fread(&index_entry, sizeof(Index), 1, index_file);

    /* Delete record from data file */
    Record record;
    fseek(data_file, index_entry.pos, SEEK_SET);
    fread(&record, sizeof(Record), 1, data_file);

    /* Shift all records after deleted record to the left */
    for (int i = id; i <= num_records; i++) {
        Index next_index_entry;
        fseek(index_file, i * sizeof(Index), SEEK_SET);
        fread(&next_index_entry, sizeof(Index), 1, index_file);

        fseek(data_file, next_index_entry.pos, SEEK_SET);
        fread(&record, sizeof(Record), 1, data_file);

        fseek(data_file, (i - 1) * sizeof(Record), SEEK_SET);
        fwrite(&record, sizeof(Record), 1, data_file);

        next_index_entry.pos = (i - 1) * sizeof(Record);
        fseek(index_file, i * sizeof(Index), SEEK_SET);
        fwrite(&next_index_entry, sizeof(Index), 1, index_file);
    }

    /* Update number of records and index size */
    num_records--;
    index_size--;
    ftruncate(fileno(index_file), index_size * sizeof(Index));
}