//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Alan Touring
// Medical Store Management System in C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure to store medicine info
struct Medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

// function to add medicine to stock
void add_medicine(struct Medicine *medicines, int size) {
    printf("\nAdd Medicine to Stock\n");
    printf("---------------------\n");
    for(int i=0; i<size; i++) {
        printf("Enter details of medicine %d: \n", i+1);
        printf("Name: ");
        scanf("%s", medicines[i].name);
        printf("Manufacturer: ");
        scanf("%s", medicines[i].manufacturer);
        printf("Quantity: ");
        scanf("%d", &medicines[i].quantity);
        printf("Price: ");
        scanf("%f", &medicines[i].price);
        printf("---------------------\n");
    }
}

// function to display stock
void display_stock(struct Medicine *medicines, int size) {
    printf("\nStock Details\n");
    printf("---------------------\n");
    for(int i=0; i<size; i++) {
        printf("Medicine %d: \n", i+1);
        printf("Name: %s \n", medicines[i].name);
        printf("Manufacturer: %s \n", medicines[i].manufacturer);
        printf("Quantity: %d \n", medicines[i].quantity);
        printf("Price: Rs %.2f \n", medicines[i].price);
        printf("---------------------\n");
    }
}

// function to search stock by medicine name
void search_stock(struct Medicine *medicines, int size) {
    char search_name[50];
    printf("\nEnter the medicine name to search: ");
    scanf("%s", search_name);
    printf("---------------------\n");
    for(int i=0; i<size; i++) {
        if(strcmp(search_name, medicines[i].name) == 0) {
            printf("Medicine %d: \n", i+1);
            printf("Name: %s \n", medicines[i].name);
            printf("Manufacturer: %s \n", medicines[i].manufacturer);
            printf("Quantity: %d \n", medicines[i].quantity);
            printf("Price: Rs %.2f \n", medicines[i].price);
            printf("---------------------\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    int choice, size;
    struct Medicine *medicines = NULL;

    printf("\nWelcome to Medical Store Management System\n\n");

    printf("Enter the number of medicines to add to stock: ");
    scanf("%d", &size);

    medicines = (struct Medicine*) malloc(size * sizeof(struct Medicine));

    do {
        printf("\nMenu\n");
        printf("---------------------\n");
        printf("1. Add Medicine to Stock\n");
        printf("2. Display Stock\n");
        printf("3. Search Stock\n");
        printf("4. Exit\n");
        printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine(medicines, size);
                break;

            case 2:
                display_stock(medicines, size);
                break;

            case 3:
                search_stock(medicines, size);
                break;

            case 4:
                printf("\nThank you for using Medical Store Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while(choice != 4);

    free(medicines);

    return 0;
}