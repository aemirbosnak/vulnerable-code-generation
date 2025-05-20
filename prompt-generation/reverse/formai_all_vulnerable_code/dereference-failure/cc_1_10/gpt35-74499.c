//FormAI DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct inventory {
    char product_name[50];
    int product_id;
    float product_price;
    int product_quantity;
    char product_description[100];
    struct inventory *next;
} Inventory;

Inventory *head = NULL;
int last_id = 0;

void display_menu() {
    printf("\n*** Product Inventory System Menu ***\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. View all products\n");
    printf("4. Search for a product\n");
    printf("5. Exit\n");
}

void add_product() {
    char name[50], description[100];
    float price;
    int quantity, id;

    printf("\nEnter product name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter product price: ");
    scanf("%f", &price);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product description: ");
    getchar();
    fgets(description, 100, stdin);
    description[strcspn(description, "\n")] = 0;

    id = last_id + 1;
    last_id++;

    Inventory *new_product = (Inventory *) malloc(sizeof(Inventory));
    strcpy(new_product->product_name, name);
    new_product->product_price = price;
    new_product->product_quantity = quantity;
    strcpy(new_product->product_description, description);
    new_product->product_id = id;
    new_product->next = NULL;

    if(head == NULL) {
        head = new_product;
    }
    else {
        Inventory *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_product;
    }

    printf("Product added successfully!\n");
}

void remove_product() {
    int id;
    printf("\nEnter the ID of the product you want to remove: ");
    scanf("%d", &id);

    Inventory *temp = head;
    Inventory *prev = NULL;

    while(temp != NULL && temp->product_id != id) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("\nNo product found with ID %d\n", id);
    }
    else {
        if(prev == NULL) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Product removed successfully!\n");
    }
}

void view_products() {
    Inventory *temp = head;
    printf("\n ID\tProduct Name\tPrice\tQuantity\tDescription\n");
    while(temp != NULL) {
        printf(" %d\t%-20s %5.2f\t%d\t\t%s\n", temp->product_id, temp->product_name, temp->product_price, temp->product_quantity, temp->product_description);
        temp = temp->next;
    }
}

void search_product() {
    char name[50];
    printf("\nEnter the name of the product you want to search: ");
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    Inventory *temp = head;
    while(temp != NULL) {
        if(strcasecmp(temp->product_name, name) == 0) {
            printf("\nProduct found!\n");
            printf("Product Name: %s\n", temp->product_name);
            printf("Product Price: %5.2f\n", temp->product_price);
            printf("Product Quantity: %d\n", temp->product_quantity);
            printf("Product Description: %s\n", temp->product_description);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 0) {
        printf("\nNo product found with name %s\n", name);
    }
}

int main() {
    int choice;
    while(1) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                    add_product();
                    break;
            case 2:
                    remove_product();
                    break;
            case 3:
                    view_products();
                    break;
            case 4:
                    search_product();
                    break;
            case 5:
                    printf("\nExiting Program...\n");
                    exit(0);
            default:
                    printf("\nInvalid Choice. Please try again.\n");
        }
    }
    return 0;
}