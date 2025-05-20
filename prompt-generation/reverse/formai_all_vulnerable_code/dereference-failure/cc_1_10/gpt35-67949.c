//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining Constants
#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_SUPPLIER_LENGTH 30
#define MAX_BATCH_NUMBER 15
#define MAX_EX_DATE_LENGTH 15
#define MAX_PRICE_LENGTH 15

//Defining Structures
struct Medicine {
    char name[MAX_NAME_LENGTH];
    char supplier[MAX_SUPPLIER_LENGTH];
    char batch_number[MAX_BATCH_NUMBER];
    char expiration_date[MAX_EX_DATE_LENGTH];
    char price[MAX_PRICE_LENGTH];
};

//Global Variable Declaration
struct Medicine inventory[MAX_MEDICINES];
int inventory_count = 0;

//Function Declaration
void add_medicine();
void remove_medicine();
void display_inventory();
void export_inventory();
void import_inventory();

//Main Method
int main(){
    int choice;

    while(1){
        printf("----Medical Store Management System----\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Inventory\n");
        printf("4. Export Inventory\n");
        printf("5. Import Inventory\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_medicine(); break;
            case 2: remove_medicine(); break;
            case 3: display_inventory(); break; 
            case 4: export_inventory(); break;
            case 5: import_inventory(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

//Function Definitions
void add_medicine(){
    if(inventory_count >= MAX_MEDICINES){
        printf("Inventory is Full. Cannot add more medicines\n");
        return;
    }
    printf("Enter Medicine Name: ");
    scanf("%s", inventory[inventory_count].name);

    printf("Enter Supplier Name: ");
    scanf("%s", inventory[inventory_count].supplier);

    printf("Enter Batch Number: ");
    scanf("%s", inventory[inventory_count].batch_number);

    printf("Enter Expiration Date: ");
    scanf("%s", inventory[inventory_count].expiration_date);

    printf("Enter Price: ");
    scanf("%s", inventory[inventory_count].price);

    printf("Medicine added successfully.\n");
    inventory_count++;
}

void remove_medicine(){
    if(inventory_count <= 0){
        printf("Inventory is Empty. Cannot remove medicines.\n");
        return;
    }

    char batch_number[MAX_BATCH_NUMBER];

    printf("Enter Batch Number to be Removed: ");
    scanf("%s", batch_number);

    int index = -1;

    for(int i=0; i<inventory_count; i++){
        if(strcmp(inventory[i].batch_number, batch_number) == 0){   //comparing batch numbers
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Medicine not found.\n");
        return;
    }
    else {
        for(int i=index; i<inventory_count-1; i++){
            strcpy(inventory[i].name, inventory[i+1].name);
            strcpy(inventory[i].supplier, inventory[i+1].supplier);
            strcpy(inventory[i].batch_number, inventory[i+1].batch_number);
            strcpy(inventory[i].expiration_date, inventory[i+1].expiration_date);
            strcpy(inventory[i].price, inventory[i+1].price);
        }
        printf("Medicine removed successfully.\n");
        inventory_count--;
    }
}

void display_inventory(){
    if(inventory_count <= 0){
        printf("Inventory is Empty. Cannot Display Medicines.\n");
        return;
    }
    printf("Medicine Name\tSupplier\tBatch No.\tExpiration Date\tPrice\n");
    printf("-----------------------------------------------------------------\n");
    for(int i=0; i<inventory_count; i++){
        printf("%s\t%s\t%s\t%s\t\t%s\t\n", 
                    inventory[i].name, 
                    inventory[i].supplier, 
                    inventory[i].batch_number, 
                    inventory[i].expiration_date,
                    inventory[i].price);
    }
}

void export_inventory(){
    if(inventory_count <= 0){
        printf("Inventory is Empty. Cannot Export Medicines.\n");
        return;
    }

    FILE *file;
    char filename[MAX_NAME_LENGTH];

    printf("Enter File Name: ");
    scanf("%s", filename);

    file = fopen(filename, "w");

    fprintf(file, "Medicine Name,Supplier,Batch No.,Expiration Date,Price\n");

    for(int i=0; i<inventory_count; i++){
        fprintf(file, "%s,%s,%s,%s,%s\n", 
                    inventory[i].name, 
                    inventory[i].supplier, 
                    inventory[i].batch_number, 
                    inventory[i].expiration_date,
                    inventory[i].price);
    }

    fclose(file);
    printf("Inventory Exported to %s successfully.\n", filename);
}

void import_inventory(){
    FILE *file;
    char filename[MAX_NAME_LENGTH];
    char buffer[1024];
    char *token;

    printf("Enter File Name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if(file == NULL){
        printf("File Not Found.\n");
        return;
    }

    fgets(buffer, 1024, file);   //reading csv header

    while(fgets(buffer, 1024, file)){
        struct Medicine new_medicine;

        token = strtok(buffer, ",");
        strcpy(new_medicine.name, token);

        token = strtok(NULL, ",");
        strcpy(new_medicine.supplier, token);

        token = strtok(NULL, ",");
        strcpy(new_medicine.batch_number, token);

        token = strtok(NULL, ",");
        strcpy(new_medicine.expiration_date, token);

        token = strtok(NULL, ",");
        strcpy(new_medicine.price, token);

        inventory[inventory_count] = new_medicine;
        inventory_count++;
    }
    fclose(file);
    printf("%d Medicines Imported from %s Successfully.\n", inventory_count, filename);
}