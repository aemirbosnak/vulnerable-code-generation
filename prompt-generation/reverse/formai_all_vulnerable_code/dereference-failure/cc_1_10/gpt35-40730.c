//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCT_NAME_SIZE 50

// Function to display the menu options
void display_menu();

// Function to update stock
void update_stock(int *stock, int quantity);

// Function to get the product name
char* get_product_name();

// Main Function
int main() {
    
    // Defining the products and their initial stock
    int stock[5] = {10, 15, 20, 5, 12};     // The initial stock


    // List of product names
    char *product_names[5] = {
        "Paracetamol",
        "Amoxicillin",
        "Omeprazole",
        "Atorvastatin",
        "Metformin"
    };
    
    // Welcome Message
    printf("Welcome to Medical Store Management System\n");
    printf("------------------------------------------\n\n");
    
    // Display the menu options
    display_menu();
    
    // Ask the user for input
    int user_choice;
    printf("Select an option: ");
    scanf("%d", &user_choice);
    
    // Handle user choice
    switch(user_choice) {
        case 1: {
            char *product_name = get_product_name();
            printf("\nYou have chosen to search for %s\n", product_name);
            printf("The available stock of %s is %d\n", product_name, stock[user_choice-1]);
            break;
        }
        case 2: {
            printf("\nYou have chosen to update stock\n");
            char *product_name = get_product_name();
            printf("Enter the quantity to add: ");
            int quantity;
            scanf("%d", &quantity);
            update_stock(&stock[user_choice-1], quantity);
            printf("\nThe stock of %s has been updated to %d\n", product_name, stock[user_choice-1]);
            break;
        }
        case 3: {
            printf("\nYou have chosen to view stock\n");
            for(int i=0;i<5;i++) {
                printf("%s - %d\n", product_names[i], stock[i]);
            }
            break;
        }
        case 4: {
            printf("\nThank you for using Medical Store Management System\n");
            return 0;
        }
        default: {
            printf("\nInvalid choice. Please try again\n");
            break;
        }
    }
    
    return 0;
}

// Function to display the menu options
void display_menu() {
    printf("1. Search for a product\n");
    printf("2. Update stock of a product\n");
    printf("3. View stock of all products\n");
    printf("4. Exit\n");
}

// Function to update stock
void update_stock(int *stock, int quantity) {
    *stock += quantity;
}

// Function to get the product name
char* get_product_name() {
    char *product_name = (char*)malloc(MAX_PRODUCT_NAME_SIZE * sizeof(char));
    printf("Enter the product name: ");
    getchar();
    fgets(product_name, MAX_PRODUCT_NAME_SIZE, stdin);
    product_name[strcspn(product_name, "\n")] = 0;
    return product_name;
}