//FormAI DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100 // maximum number of records that can be stored

// data structure to store each record
typedef struct record {
    int id;
    char name[50];
    int age;
} Record;

// data structure to store multiple nodes of type Record
typedef struct node {
    Record data;
    struct node* next;
} Node;

// global variables
Node* head[MAX_RECORDS]; // array of head pointers for each record
int num_records = 0; // current number of records stored

// function to initialize the head pointers of each record
void init_database() {
    int i;
    for(i = 0; i < MAX_RECORDS; i++) {
        head[i] = NULL;
    }
}

// function to insert a new record into the database
void insert_record(Record new_record) {
    if(num_records < MAX_RECORDS) { // check if database is full
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = new_record;
        new_node->next = head[new_record.id];
        head[new_record.id] = new_node;
        num_records++;
        printf("Record with ID %d inserted successfully.\n", new_record.id);
    }
    else {
        printf("Database is full. Cannot insert new record.\n");
    }
}

// function to print all records with a certain ID
void print_records_with_id(int id) {
    Node* curr_node = head[id];
    printf("Records with ID %d:\n", id);
    while(curr_node != NULL) {
        printf("Name: %s, Age: %d\n", curr_node->data.name, curr_node->data.age);
        curr_node = curr_node->next;
    }
}

// main function to test the database simulation
int main() {
    init_database();
    Record r1 = {1, "John", 20};
    Record r2 = {2, "Emily", 25};
    Record r3 = {2, "Alex", 30};
    insert_record(r1);
    insert_record(r2);
    insert_record(r3);
    print_records_with_id(2);
    return 0;
}