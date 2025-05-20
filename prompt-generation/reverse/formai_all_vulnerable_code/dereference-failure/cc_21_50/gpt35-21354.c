//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    char manufacturer[50];
    int qty;
    float price;
} med_item;

int main(){
    // declare variables
    int choice, menu_choice, found, index;
    int num_items = 0, i = 0;
    char search_name[50];
    char del_name[50];
    char edit_name[50];
    
    // create dynamic memory allocation for item array
    med_item *items = (med_item*)malloc(sizeof(med_item));
    if(items == NULL){
        printf("Memory allocation failed!");
        exit(1);
    }
    
    do{
        printf("\n\nWelcome to the Medical Store Management System!");
        printf("\n==============================================");
        // display menu
        printf("\n1. Add a new item");
        printf("\n2. Search for an item");
        printf("\n3. Edit an item");
        printf("\n4. Delete an item");
        printf("\n5. Display all items");
        printf("\n6. Exit");
        printf("\n\nPlease enter your choice: ");
        scanf("%d", &menu_choice);
        
        switch(menu_choice){
            case 1: // add a new item
                num_items++;
                items = (med_item*)realloc(items, num_items * sizeof(med_item));
                if(items == NULL){
                    printf("Memory reallocation failed!");
                    exit(1);
                }
                printf("\nPlease enter the item details:");
                printf("\nName: ");
                scanf("%s", items[num_items-1].name);
                printf("Manufacturer: ");
                scanf("%s", items[num_items-1].manufacturer);
                printf("Stock Quantity: ");
                scanf("%d", &items[num_items-1].qty);
                printf("Price: ");
                scanf("%f", &items[num_items-1].price);
                break;
            case 2: // search for an item
                found = 0;
                printf("\nPlease enter the name of the item to search for: ");
                scanf("%s", search_name);
                for(i=0;i<num_items;i++){
                    if(strcmp(items[i].name, search_name)==0){
                        found = 1;
                        printf("\nItem Found:");
                        printf("\nName: %s", items[i].name);
                        printf("\nManufacturer: %s", items[i].manufacturer);
                        printf("\nStock Quantity: %d", items[i].qty);
                        printf("\nPrice: $%.2f", items[i].price);
                        break;
                    }
                }
                if(!found){
                    printf("\nItem not Found!");
                }
                break;
            case 3: // edit an item
                found = 0;
                printf("\nPlease enter the name of the item to edit: ");
                scanf("%s", edit_name);
                for(i=0;i<num_items;i++){
                    if(strcmp(items[i].name, edit_name)==0){
                        found = 1;
                        printf("\nPlease enter the updated details for the item:");
                        printf("\nName: ");
                        scanf("%s", items[i].name);
                        printf("Manufacturer: ");
                        scanf("%s", items[i].manufacturer);
                        printf("Stock Quantity: ");
                        scanf("%d", &items[i].qty);
                        printf("Price: ");
                        scanf("%f", &items[i].price);
                        break;
                    }
                }
                if(!found){
                    printf("\nItem not Found!");
                }
                break;
            case 4: // delete an item
                found = 0;
                printf("\nPlease enter the name of the item to delete: ");
                scanf("%s", del_name);
                for(i=0;i<num_items;i++){
                    if(strcmp(items[i].name, del_name)==0){
                        found = 1;
                        index = i;
                        break;
                    }
                }
                if(found){
                    printf("\nItem Deleted:");
                    printf("\nName: %s", items[index].name);
                    printf("\nManufacturer: %s", items[index].manufacturer);
                    printf("\nStock Quantity: %d", items[index].qty);
                    printf("\nPrice: $%.2f", items[index].price);
                    for(i=index;i<num_items-1;i++){
                        memset(&items[i], 0, sizeof(med_item)); // set item to empty
                        items[i] = items[i+1]; // move all items down the array
                    }
                    num_items--;
                    items = (med_item*)realloc(items, num_items * sizeof(med_item)); // reallocate memory
                }
                else{
                    printf("\nItem not Found!");
                }
                break;
            case 5: // display all items
                printf("\nItems in Inventory:");
                for(i=0;i<num_items;i++){
                    printf("\n\nItem %d:", i+1);
                    printf("\nName: %s", items[i].name);
                    printf("\nManufacturer: %s", items[i].manufacturer);
                    printf("\nStock Quantity: %d", items[i].qty);
                    printf("\nPrice: $%.2f", items[i].price);
                }
                if(num_items == 0){
                    printf("\nNo items in Inventory!");
                }
                break;
            case 6: // exit
                printf("\nThank you for using the Medical Store Management System!");
                free(items); // free memory
                exit(0);
                break;
            default:
                printf("\nInvalid Choice!");
                break;
        }
    }while(choice!=6);
    
    return 0;
}