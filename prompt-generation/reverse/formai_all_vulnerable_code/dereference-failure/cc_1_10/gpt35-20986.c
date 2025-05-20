//FormAI DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

/* Structure for the records */
struct database_record {
    int id;
    char name[30];
    char address[100];
    char phone[15];
};

/* Structure for the index */
struct index_entry {
    int id;
    long offset;
};

/* Declare the functions */
void create_index(char *filename);
void search_database(char *filename, int id);

/* The main function */
int main(int argc, char *argv[])
{
    /* Check for the correct number of arguments */
    if (argc != 3) {
        printf("Usage: %s <filename> <id>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Create the index */
    create_index(argv[1]);

    /* Search the database */
    search_database(argv[1], atoi(argv[2]));

    return 0;
}

/* Create the index */
void create_index(char *filename)
{
    /* Open the database file */
    FILE *database = fopen(filename, "rb");
    if (database == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Open the index file */
    FILE *index_file = fopen("index.bin", "wb");
    if (index_file == NULL) {
        printf("Unable to create file: index.bin\n");
        exit(EXIT_FAILURE);
    }

    /* Seek to the beginning of the database */
    fseek(database, 0, SEEK_SET);

    /* Initialize the index entry */
    struct index_entry entry;
    entry.id = -1;
    entry.offset = -1;

    /* Loop through the database */
    while (fread(&entry.id, sizeof(int), 1, database) == 1) {
        /* Save the current offset */
        entry.offset = ftell(database) - sizeof(int);

        /* Write the index entry */
        fwrite(&entry, sizeof(struct index_entry), 1, index_file);

        /* Seek to the next record */
        fseek(database, sizeof(struct database_record) - sizeof(int), SEEK_CUR);

        /* Reset the index entry */
        entry.id = -1;
        entry.offset = -1;
    }

    /* Close the files */
    fclose(database);
    fclose(index_file);
}

/* Search the database */
void search_database(char *filename, int id)
{
    /* Open the index file */
    FILE *index_file = fopen("index.bin", "rb");
    if (index_file == NULL) {
        printf("Unable to open file: index.bin\n");
        exit(EXIT_FAILURE);
    }

    /* Search for the index entry */
    struct index_entry entry;
    fseek(index_file, 0, SEEK_SET);
    while (fread(&entry, sizeof(struct index_entry), 1, index_file) == 1) {
        if (entry.id == id) {
            break;
        }
    }

    /* Check if the index entry was found */
    if (entry.id != id) {
        printf("Record not found in database: %d\n", id);
        exit(EXIT_FAILURE);
    }

    /* Open the database file */
    FILE *database = fopen(filename, "rb");
    if (database == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Seek to the record */
    fseek(database, entry.offset, SEEK_SET);

    /* Read the record */
    struct database_record record;
    fread(&record, sizeof(struct database_record), 1, database);

    /* Print the record */
    printf("Record found in database:\n");
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Address: %s\n", record.address);
    printf("Phone: %s\n", record.phone);

    /* Close the files */
    fclose(database);
    fclose(index_file);
}