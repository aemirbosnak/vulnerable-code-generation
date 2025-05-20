//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    float price;
    int quantity;
    struct medicine *next;
} Medicine;

Medicine *head = NULL;

void insert_medicine() {
    Medicine *new_med = (Medicine *)malloc(sizeof(Medicine));
    printf("Enter name of medicine: ");
    scanf("%s", new_med->name);
    printf("Enter price of medicine: ");
    scanf("%f", &new_med->price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &new_med->quantity);

    new_med->next = head;
    head = new_med;

    printf("Medicine added successfully!\n");
}

void delete_medicine() {
    if(head == NULL) {
        printf("No medicines found!\n");
        return;
    }

    char name[50];
    printf("Enter name of medicine to delete: ");
    scanf("%s", name);

    Medicine *temp = head, *prev;
    if(strcmp(temp->name, name) == 0) {
        head = head->next;
        free(temp);
        printf("Medicine deleted successfully!\n");
        return;
    }

    while(temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Medicine not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Medicine deleted successfully!\n");
}

void list_medicines() {
    if(head == NULL) {
        printf("No medicines found!\n");
        return;
    }

    printf("Name\tPrice\tQuantity\n");
    Medicine *temp = head;
    while(temp != NULL) {
        printf("%s\t%.2f\t%d\n", temp->name, temp->price, temp->quantity);
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("1. Insert medicine\n2. Delete medicine\n3. List medicines\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert_medicine();
                break;
            case 2:
                delete_medicine();
                break;
            case 3:
                list_medicines();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}