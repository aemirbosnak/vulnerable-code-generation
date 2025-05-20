//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a database record
typedef struct Record {
    int id;
    char name[50];
    struct Record *next;
} Record;

// Structure for an index node
typedef struct IndexNode {
    int index;
    Record *record;
    struct IndexNode *next;
} IndexNode;

// Function prototypes
Record* create_record(int id, const char* name);
IndexNode* create_index_node(int index, Record *record);
void add_record(Record **head, IndexNode **index_head, int id, const char* name);
void display_records(Record *head);
Record* search_record(IndexNode *index_head, int index);
void free_memory(Record *head, IndexNode *index_head);

// Main function
int main() {
    Record *record_list = NULL;
    IndexNode *index_list = NULL;
    char choice;
    int id;
    char name[50];

    printf("Welcome to the Simple C Database Indexing System!\n");

    do {
        printf("\n1. Add Record\n2. Display all Records\n3. Search Record by Index\n4. Exit\n");
        printf("Enter your choice: ");
        choice = getchar();
        getchar(); // To consume the newline character after character input

        switch (choice) {
            case '1':
                printf("Enter Record ID: ");
                scanf("%d", &id);
                getchar(); // Consume newline character
                printf("Enter Record Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character from input

                add_record(&record_list, &index_list, id, name);
                break;

            case '2':
                printf("Displaying all Records:\n");
                display_records(record_list);
                break;

            case '3':
                printf("Enter Index to Search: ");
                scanf("%d", &id);
                Record *found = search_record(index_list, id);
                if (found) {
                    printf("Record found! ID: %d, Name: %s\n", found->id, found->name);
                } else {
                    printf("No record found at index %d.\n", id);
                }
                break;

            case '4':
                printf("Exiting the system. Thank you!\n");
                free_memory(record_list, index_list);
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (1);

    return 0;
}

// Function to create a new record
Record* create_record(int id, const char* name) {
    Record *new_record = (Record *)malloc(sizeof(Record));
    new_record->id = id;
    strcpy(new_record->name, name);
    new_record->next = NULL;
    return new_record;
}

// Function to create a new index node
IndexNode* create_index_node(int index, Record *record) {
    IndexNode *new_index = (IndexNode *)malloc(sizeof(IndexNode));
    new_index->index = index;
    new_index->record = record;
    new_index->next = NULL;
    return new_index;
}

// Function to add a record and build index
void add_record(Record **head, IndexNode **index_head, int id, const char* name) {
    Record *new_record = create_record(id, name);
    new_record->next = *head;
    *head = new_record;

    // Adding to index
    IndexNode *new_index = create_index_node(id, new_record);
    new_index->next = *index_head;
    *index_head = new_index;

    printf("Record added successfully!\n");
}

// Function to display all records
void display_records(Record *head) {
    if (head == NULL) {
        printf("No records available.\n");
        return;
    }
    
    Record *temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Function to search for a record by index
Record* search_record(IndexNode *index_head, int index) {
    IndexNode *temp = index_head;
    while (temp != NULL) {
        if (temp->index == index) {
            return temp->record;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to free memory
void free_memory(Record *head, IndexNode *index_head) {
    while (head != NULL) {
        Record *temp = head;
        head = head->next;
        free(temp);
    }
    
    while (index_head != NULL) {
        IndexNode *temp = index_head;
        index_head = index_head->next;
        free(temp);
    }
}