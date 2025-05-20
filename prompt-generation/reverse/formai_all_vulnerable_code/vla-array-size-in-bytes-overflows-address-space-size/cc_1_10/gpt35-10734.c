//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Struct to hold customer information
typedef struct {
    char name[100];
    int billAmount;
    int tableNumber;
} Customer;

// Function to calculate bill for a customer
int calculateBill(int menuSelections[], int numSelections) {
    int totalBill = 0;
    for(int i=0; i<numSelections; i++) {
        if(menuSelections[i] == 1) totalBill += 50;
        else if(menuSelections[i] == 2) totalBill += 75;
        else if(menuSelections[i] == 3) totalBill += 100;
        else printf("Invalid menu selection!\n");
    }
    return totalBill;
}

// Function to display menu options
void displayMenu() {
    printf("MENU\n");
    printf("1. Coffee - Rs. 50\n");
    printf("2. Tea - Rs. 75\n");
    printf("3. Sandwich - Rs. 100\n");
}

int main() {
    int numTables = 5;
    int tableStatus[numTables]; // Holds status of each table - 0 for available, 1 for occupied
    for(int i=0; i<numTables; i++) {
        tableStatus[i] = 0; // Setting all tables to available initially
    }
    
    int numCustomers = 0;
    printf("Welcome to C Cafe Billing System!\n");
    printf("Enter number of customers: ");
    scanf("%d", &numCustomers);
    
    Customer customers[numCustomers];
    int menuSelections[10];
    int numSelections = 0;
    int selectedTable = 0;
    
    for(int i=0; i<numCustomers; i++) {
        printf("\n***** CUSTOMER %d *****\n", i+1);
        
        // Displaying available tables
        printf("Available Tables: ");
        for(int j=0; j<numTables; j++) {
            if(tableStatus[j] == 0) printf("%d ", j+1);
        }
        printf("\n");
        
        // Selecting table
        while(1) {
            printf("Select Table (1-%d): ", numTables);
            scanf("%d", &selectedTable);
            if(selectedTable<1 || selectedTable>numTables) {
                printf("Invalid Table Number!\n");
                continue;
            }
            else if(tableStatus[selectedTable-1] == 1) {
                printf("Table %d is occupied. Select another table.\n", selectedTable);
                continue;
            }
            else break;
        }
        customers[i].tableNumber = selectedTable;
        tableStatus[selectedTable-1] = 1; // Marking table as occupied
        
        // Getting customer name
        printf("Enter Customer Name: ");
        scanf("%s", customers[i].name);
        
        // Displaying menu options
        displayMenu();
        
        // Getting menu selections
        numSelections = 0;
        while(1) {
            printf("Select Menu Option (-1 to End): ");
            scanf("%d", &menuSelections[numSelections]);
            if(menuSelections[numSelections] == -1) break;
            else if(menuSelections[numSelections] < 1 || menuSelections[numSelections] > 3) {
                printf("Invalid Menu Option. Try again.\n");
                continue;
            }
            numSelections++;
        }
        customers[i].billAmount = calculateBill(menuSelections, numSelections);
        
        printf("\n%s's Bill Details:\nTable Number: %d\nBill Amount: Rs. %d\n", customers[i].name, customers[i].tableNumber, customers[i].billAmount);
    }
    return 0;
}