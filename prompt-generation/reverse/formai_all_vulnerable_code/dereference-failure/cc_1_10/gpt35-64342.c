//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct item{
    char name[20];
    int quantity;
    float price;
};

void add_item(struct item *ptr, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        printf("Enter details of item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", (ptr+i)->name);
        printf("Quantity: ");
        scanf("%d", &(ptr+i)->quantity);
        printf("Price: ");
        scanf("%f", &(ptr+i)->price);
        count++;
        printf("\n");
    }
    printf("%d item(s) added successfully!\n", count);
}

void display_items(struct item *ptr, int size){
    printf("Name\tQuantity\tPrice\n");
    for(int i = 0; i < size; i++){
        printf("%s\t%d\tRs. %.2f\n", (ptr+i)->name, (ptr+i)->quantity, (ptr+i)->price);
    }
}

void search_item(struct item *ptr, int size, char name[20]){
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(strcmp((ptr+i)->name, name) == 0){
            printf("Name: %s\n", (ptr+i)->name);
            printf("Quantity: %d\n", (ptr+i)->quantity);
            printf("Price: Rs. %.2f\n", (ptr+i)->price);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Item not found!\n");
    }
}

void update_item(struct item *ptr, int size, char name[20]){
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(strcmp((ptr+i)->name, name) == 0){
            printf("Enter new details of item:\n");
            printf("Quantity: ");
            scanf("%d", &(ptr+i)->quantity);
            printf("Price: ");
            scanf("%f", &(ptr+i)->price);
            flag = 1;
            printf("Item updated successfully!\n");
            break;
        }
    }
    if(flag == 0){
        printf("Item not found!\n");
    }
}

void delete_item(struct item *ptr, int *size, char name[20]){
    int flag = 0;
    for(int i = 0; i < *size; i++){
        if(strcmp((ptr+i)->name, name) == 0){
            for(int j = i; j < *size-1; j++){
                strcpy((ptr+j)->name, (ptr+j+1)->name);
                (ptr+j)->quantity = (ptr+j+1)->quantity;
                (ptr+j)->price = (ptr+j+1)->price;
            }
            (*size)--;
            flag = 1;
            printf("Item deleted successfully!\n");
            break;
        }
    }
    if(flag == 0){
        printf("Item not found!\n");
    }
}

int main(){
    printf("Welcome to Warehouse Management System!\n\n");
    int choice;
    struct item *items;
    int size = 0;
    char name[20];

    while(1){
        printf("\nMenu:\n");
        printf("1. Add item(s)\n");
        printf("2. Display all items\n");
        printf("3. Search for an item\n");
        printf("4. Update an item\n");
        printf("5. Delete an item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                items = (struct item*)realloc(items, (size+1)*sizeof(struct item));
                add_item(items, 1);
                size++;
                break;
            case 2:
                if(size == 0){
                    printf("No items found!\n");
                }
                else{
                    display_items(items, size);
                }
                break;
            case 3:
                if(size == 0){
                    printf("No items found!\n");
                }
                else{
                    printf("Enter name of item to be searched: ");
                    scanf("%s", name);
                    search_item(items, size, name);
                }
                break;
            case 4:
                if(size == 0){
                    printf("No items found!\n");
                }
                else{
                    printf("Enter name of item to be updated: ");
                    scanf("%s", name);
                    update_item(items, size, name);
                }
                break;
            case 5:
                if(size == 0){
                    printf("No items found!\n");
                }
                else{
                    printf("Enter name of item to be deleted: ");
                    scanf("%s", name);
                    delete_item(items, &size, name);
                }
                break;
            case 6:
                printf("Thank you for using our system!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}