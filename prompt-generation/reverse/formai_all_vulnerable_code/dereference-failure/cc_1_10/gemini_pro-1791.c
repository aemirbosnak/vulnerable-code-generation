//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Medicine Structure
typedef struct medicine {
    char name[50];
    char manufacturer[50];
    char expiry_date[11];
    int quantity;
    float price;
} medicine;

// Node Structure
typedef struct node {
    medicine med;
    struct node *next;
} node;

// Global Variables
node *head = NULL;

// Function to Add a Medicine
void add_medicine() {
    medicine new_med;
    
    printf("\nEnter Medicine Name: ");
    scanf(" %[^\n]", new_med.name);
    
    printf("Enter Manufacturer: ");
    scanf(" %[^\n]", new_med.manufacturer);
    
    printf("Enter Expiry Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", new_med.expiry_date);
    
    printf("Enter Quantity: ");
    scanf(" %d", &new_med.quantity);
    
    printf("Enter Price: ");
    scanf(" %f", &new_med.price);
    
    // Create a new node and store the medicine
    node *new_node = (node *)malloc(sizeof(node));
    new_node->med = new_med;
    new_node->next = NULL;
    
    // Add the new node to the linked list
    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    
    printf("\nMedicine added successfully!\n");
}

// Function to Display the Medicines
void display_medicines() {
    if (head == NULL) {
        printf("\nNo medicines found!\n");
        return;
    }
    
    node *temp = head;
    printf("\n----------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-20s | %-10s | %-10s |\n", "Medicine Name", "Manufacturer", "Expiry Date", "Quantity", "Price");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("| %-20s | %-20s | %-20s | %-10d | %-10.2f |\n", temp->med.name, temp->med.manufacturer, temp->med.expiry_date, temp->med.quantity, temp->med.price);
        temp = temp->next;
    }
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
}

// Function to Search a Medicine by Name
void search_medicine() {
    char med_name[50];
    
    printf("\nEnter the name of the medicine you want to search for: ");
    scanf(" %[^\n]", med_name);
    
    node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->med.name, med_name) == 0) {
            printf("\nMedicine Found!\n");
            printf("----------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-20s | %-20s | %-20s | %-10s | %-10s |\n", "Medicine Name", "Manufacturer", "Expiry Date", "Quantity", "Price");
            printf("----------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-20s | %-20s | %-20s | %-10d | %-10.2f |\n", temp->med.name, temp->med.manufacturer, temp->med.expiry_date, temp->med.quantity, temp->med.price);
            printf("----------------------------------------------------------------------------------------------------------------------------\n");
            return;
        }
        temp = temp->next;
    }
    
    printf("\nNo medicine found with that name!\n");
}

// Function to Update a Medicine
void update_medicine() {
    char med_name[50];
    
    printf("\nEnter the name of the medicine you want to update: ");
    scanf(" %[^\n]", med_name);
    
    node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->med.name, med_name) == 0) {
            int choice;
            
            printf("\nWhat do you want to update?\n");
            printf("1. Manufacturer\n");
            printf("2. Expiry Date\n");
            printf("3. Quantity\n");
            printf("4. Price\n");
            printf("Enter your choice: ");
            scanf(" %d", &choice);
            
            switch (choice) {
                case 1:
                    printf("Enter the new manufacturer: ");
                    scanf(" %[^\n]", temp->med.manufacturer);
                    break;
                case 2:
                    printf("Enter the new expiry date (DD/MM/YYYY): ");
                    scanf(" %[^\n]", temp->med.expiry_date);
                    break;
                case 3:
                    printf("Enter the new quantity: ");
                    scanf(" %d", &temp->med.quantity);
                    break;
                case 4:
                    printf("Enter the new price: ");
                    scanf(" %f", &temp->med.price);
                    break;
                default:
                    printf("Invalid choice!\n");
            }
            
            printf("\nMedicine updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    
    printf("\nNo medicine found with that name!\n");
}

// Function to Delete a Medicine
void delete_medicine() {
    char med_name[50];
    
    printf("\nEnter the name of the medicine you want to delete: ");
    scanf(" %[^\n]", med_name);
    
    node *temp = head;
    node *prev = NULL;
    
    while (temp != NULL) {
        if (strcmp(temp->med.name, med_name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            
            free(temp);
            printf("\nMedicine deleted successfully!\n");
            return;
        }
        
        prev = temp;
        temp = temp->next;
    }
    
    printf("\nNo medicine found with that name!\n");
}

// Main Function
int main() {
    int choice;
    
    do {
        printf("\n----------------------------------------------------------------------------------------------------------------------------\n");
        printf("                      MEDICAL STORE MANAGEMENT SYSTEM                                \n");
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
        printf("1. Add a Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search a Medicine by Name\n");
        printf("4. Update a Medicine\n");
        printf("5. Delete a Medicine\n");
        printf("6. Quit\n");
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                printf("\nThank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 6);
    
    return 0;
}