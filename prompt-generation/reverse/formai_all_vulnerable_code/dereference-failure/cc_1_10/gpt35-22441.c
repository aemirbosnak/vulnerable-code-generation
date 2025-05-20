//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_DATA_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
    int index;
    long offset;
} Index;

int compare_names(const void* a, const void* b) {
    return strcasecmp(((const Contact*)a)->name, ((const Contact*)b)->name);
}

int main() {
    FILE* data_file = fopen("contacts.dat", "rb");
    if (!data_file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    
    FILE* index_file = fopen("contacts.idx", "rb");
    if (!index_file) {
        printf("Error: Unable to open file.\n");
        fclose(data_file);
        return 1;
    }
    
    fseek(index_file, 0, SEEK_END);
    int num_indexes = ftell(index_file) / sizeof(Index);
    fseek(index_file, 0, SEEK_SET);
    
    Index* index = (Index*)malloc(num_indexes * sizeof(Index));
    fread(index, sizeof(Index), num_indexes, index_file);
    
    Contact* contacts = (Contact*)malloc(num_indexes * sizeof(Contact));
    for (int i = 0; i < num_indexes; i++) {
        fseek(data_file, index[i].offset, SEEK_SET);
        fread(&(contacts[i]), sizeof(Contact), 1, data_file);
    }
    
    fclose(data_file);
    fclose(index_file);
    
    qsort(contacts, num_indexes, sizeof(Contact), compare_names);
    
    printf("Enter a name to search: ");
    char search_name[MAX_NAME_LENGTH];
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strlen(search_name)-1] = '\0'; // Remove newline character
    
    Contact key;
    strncpy(key.name, search_name, MAX_NAME_LENGTH);
    Contact* result = bsearch(&key, contacts, num_indexes, sizeof(Contact), compare_names);
    
    if (result) {
        printf("Found contact:\nName: %s\nPhone: %s\n", result->name, result->phone);
    } else {
        printf("Contact not found.\n");
    }
    
    free(contacts);
    free(index);
    return 0;
}