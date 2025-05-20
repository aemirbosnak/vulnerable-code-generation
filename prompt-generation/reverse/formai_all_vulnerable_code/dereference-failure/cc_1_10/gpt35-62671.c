//FormAI DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct database {
    char name[50];
    int id;
    struct database *next;
} Database;

Database *create_database(Database *head, char name[], int id) {
    if(head == NULL) {
        head = malloc(sizeof(Database));
        strcpy(head->name, name);
        head->id = id;
        head->next = NULL;
        return head;
    }
    head->next = create_database(head->next, name, id);
    return head;
}

Database *delete_database(Database *head, int id) {
    if(head == NULL) {
        printf("Database not found!\n");
        return head;
    } else if(head->id == id) {
        Database *temp = head;
        head = head->next;
        free(temp);
        printf("Database with ID %d has been deleted successfully!\n", id);
        return head;
    }
    head->next = delete_database(head->next, id);
    return head;
}

void display_all(Database *head) {
    if(head == NULL) {
        return;
    }
    printf("ID: %d | Name: %s\n", head->id, head->name);
    display_all(head->next);
}

int main() {
    Database *head = NULL;

    printf("Creating database...\n");
    head = create_database(head, "John", 101);
    head = create_database(head, "Amanda", 102);
    head = create_database(head, "Mike", 103);

    printf("Displaying all databases:\n");
    display_all(head);

    printf("Deleting database with ID 102...\n");
    head = delete_database(head, 102);

    printf("Displaying all databases:\n");
    display_all(head);

    return 0;
}