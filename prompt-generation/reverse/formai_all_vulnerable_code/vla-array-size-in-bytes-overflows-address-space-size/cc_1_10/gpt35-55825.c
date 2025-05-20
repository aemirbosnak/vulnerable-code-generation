//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Customer structure
struct customer {
    char name[50];
    int table_no;
    float bill_amt;
};

// Menu Item structure
struct menu_item{
    int item_no;
    char item_name[50];
    float item_price;
};

// Array of menu items
struct menu_item menu_items[] = {{1, "Coffee", 2.50},
                                 {2, "Tea", 1.50},
                                 {3, "Brownie", 3.50},
                                 {4, "Muffin", 2.50},
                                 {5, "Sandwich", 4.50},
                                 {6, "Burger", 5.50},
                                 {7, "Fries", 3.00},
                                 {8, "Salad", 4.00}};

// Function to calculate bill amount for a customer
float calc_bill(int* selected_items, int num_items){
    float bill = 0.0;
    for(int i=0; i<num_items; i++){
        bill += menu_items[selected_items[i]].item_price;
    }
    return bill;
}

// Function to print the menu
void print_menu(){
    printf("\t\tMenu\n");
    printf("--------------------------------\n");
    for(int i=0; i<8; i++){
        printf("%d. %-20s $%.2f\n", menu_items[i].item_no, menu_items[i].item_name, menu_items[i].item_price);
    }
    printf("--------------------------------\n");
}

int main(){
    int num_customers;
    printf("Welcome to Cafe Bill Calculator\n");
    printf("How many customers are at your table? ");
    scanf("%d", &num_customers);
    
    struct customer customers[num_customers];
    for(int i=0; i<num_customers; i++){
        printf("\nCustomer %d\n", i+1);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Table No: ");
        scanf("%d", &customers[i].table_no);
        int selected_items[8];
        int num_items = 0;
        int choice;
        do{
            print_menu();
            printf("Enter choice (0 to stop): ");
            scanf("%d", &choice);
            if(choice != 0){
                selected_items[num_items] = choice-1;
                num_items++;
            }
        }while(choice != 0);
        customers[i].bill_amt = calc_bill(selected_items, num_items);
    }
    
    printf("\n\n\n");
    printf("+------------------------+-------+------------+\n");
    printf("| Name                   | Table | Bill Amount|\n");
    printf("+------------------------+-------+------------+\n");
    for(int i=0; i<num_customers; i++){
        printf("| %-22s| %-6d| $%-9.2f|\n", customers[i].name, customers[i].table_no, customers[i].bill_amt);
    }
    printf("+------------------------+-------+------------+\n");
    return 0;
}