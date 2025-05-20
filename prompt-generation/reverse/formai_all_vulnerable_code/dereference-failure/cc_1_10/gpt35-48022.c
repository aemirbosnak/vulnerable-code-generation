//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs for data and index
typedef struct Employee {
    int emp_id;
    char name[50];
    char department[30];
    float salary;
} Employee;

typedef struct Index {
    int emp_id;
    int offset;
} Index;

// Function to create index
void create_index(char* filename, char* indexname) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    // Get number of records
    fseek(fp, 0, SEEK_END);
    int num_records = ftell(fp) / sizeof(Employee);
    rewind(fp);
    // Create index array
    Index* index = (Index*)malloc(num_records * sizeof(Index));
    // Read records into data array and create index
    Employee e;
    int i = 0;
    while(fread(&e, sizeof(Employee), 1, fp)) {
        index[i].emp_id = e.emp_id;
        index[i].offset = i * sizeof(Employee);
        i++;
    }
    fclose(fp);
    // Write index to file
    FILE* index_file = fopen(indexname, "wb");
    if (index_file == NULL) {
        printf("Error creating index file!\n");
        exit(1);
    }
    fwrite(index, sizeof(Index), num_records, index_file);
    fclose(index_file);
    printf("Index created successfully!\n");
}

// Function to search using index
void search_index(char* filename, char* indexname, int id) {
    FILE* fp = fopen(indexname, "rb");
    if (fp == NULL) {
        printf("Error opening index file!\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int num_records = ftell(fp) / sizeof(Index);
    rewind(fp);
    Index* index = (Index*)malloc(num_records * sizeof(Index));
    fread(index, sizeof(Index), num_records, fp);
    fclose(fp);
    // Binary Search on index
    int low = 0, high = num_records - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (id == index[mid].emp_id) {
            printf("Record found at offset %d\n", index[mid].offset);
            FILE* data = fopen(filename, "rb");
            if (data == NULL) {
                printf("Error opening data file!\n");
                exit(1);
            }
            Employee e;
            fseek(data, index[mid].offset, SEEK_SET);
            fread(&e, sizeof(Employee), 1, data);
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", 
                e.emp_id, e.name, e.department, e.salary);
            fclose(data);
            return;
        } else if (id < index[mid].emp_id) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("Record not found!\n");
}

int main() {
    create_index("data.bin", "index.bin");
    search_index("data.bin", "index.bin", 1234);
    return 0;
}