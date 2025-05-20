//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_LEN 100

// Structure for a linked list node
typedef struct node_t{
    char name[MAX_LEN];
    struct node_t *next;
}node_t;

// Structure for the database
typedef struct db_t{
    node_t *head;
}db_t;

// Function to add a new entry to the database
void add(db_t *db, char *name){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if(db->head == NULL){
        db->head = new_node;
        return;
    }

    node_t *curr = db->head;
    while(curr->next!= NULL){
        curr = curr->next;
    }

    curr->next = new_node;
}

// Function to search for an entry in the database
char *search(db_t *db, char *name){
    node_t *curr = db->head;
    while(curr!= NULL){
        if(strcmp(curr->name, name) == 0){
            return curr->name;
        }
        curr = curr->next;
    }
    return NULL;
}

// Function to delete an entry from the database
void delete(db_t *db, char *name){
    node_t *curr = db->head;
    node_t *prev = NULL;

    while(curr!= NULL){
        if(strcmp(curr->name, name) == 0){
            if(prev == NULL){
                db->head = curr->next;
                free(curr);
                return;
            }
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to print all entries in the database
void print(db_t *db){
    node_t *curr = db->head;
    while(curr!= NULL){
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

int main(void){
    db_t db;
    db.head = NULL;

    add(&db, "John");
    add(&db, "Jane");
    add(&db, "Bob");

    printf("Searching for John...\n");
    char *found = search(&db, "John");
    if(found == NULL){
        printf("Not found\n");
    }else{
        printf("Found: %s\n", found);
    }

    printf("Deleting Bob...\n");
    delete(&db, "Bob");

    printf("Printing all entries...\n");
    print(&db);

    return 0;
}