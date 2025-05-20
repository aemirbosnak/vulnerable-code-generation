//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Structure for the database record
struct Record {
    int id;
    char name[20];
    float salary;
};

// Function to create index file
void create_index(char* filename, char* index_filename) {
    FILE* fp = fopen(filename, "rb");
    FILE* index_fp = fopen(index_filename, "wb");
    if(fp == NULL || index_fp == NULL) {
        printf("Error opening file(s).\n");
        return;
    }
    struct Record record;
    int offset = 0;
    while(fread(&record, sizeof(struct Record), 1, fp)) {
        fwrite(&offset, sizeof(int), 1, index_fp);
        offset = ftell(fp);
    }
    fclose(fp);
    fclose(index_fp);
}

// Function to search the index
int search_index(int id, char* index_filename) {
    FILE* index_fp = fopen(index_filename, "rb");
    if(index_fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }
    int offset;
    while(fread(&offset, sizeof(int), 1, index_fp)) {
        struct Record record;
        FILE* fp = fopen("data.bin", "rb");
        if(fp == NULL) {
            printf("Error opening file.\n");
            return -1;
        }
        fseek(fp, offset, SEEK_SET);
        fread(&record, sizeof(struct Record), 1, fp);
        if(record.id == id) {
            fclose(fp);
            fclose(index_fp);
            return offset;
        }
        fclose(fp);
    }
    fclose(index_fp);
    return -1;
}

int main() {
    // Create data file
    FILE* fp = fopen("data.bin", "wb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct Record records[5] = {
        {1, "John", 5000},
        {2, "Jane", 6000},
        {3, "Bob", 5500},
        {4, "Alice", 6500},
        {5, "Dave", 7000}
    };
    fwrite(records, sizeof(struct Record), 5, fp);
    fclose(fp);

    // Create index file
    create_index("data.bin", "index.bin");

    // Search index
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    int offset = search_index(id, "index.bin");
    if(offset == -1) {
        printf("Record not found.\n");
        return 1;
    }

    // Retrieve record using offset
    fp = fopen("data.bin", "rb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct Record record;
    fseek(fp, offset, SEEK_SET);
    fread(&record, sizeof(struct Record), 1, fp);
    printf("Record found:\n");
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Salary: %.2f\n", record.salary);

    return 0;
}