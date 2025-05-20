//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product{
    char name[30];
    int id;
    float price;
    int quantity;
} product;

product products[10];
int count = 0;

void clear_screen(){
    system("clear||cls");
}

void add_product(){
    clear_screen();
    if(count < 10){
        printf("***ADD PRODUCT***\n");
        printf("Enter Product Name: ");
        scanf(" %[^\n]s", &products[count].name);
        printf("Enter Product ID: ");
        scanf("%d", &products[count].id);
        printf("Enter Product Price: ");
        scanf("%f", &products[count].price);
        printf("Enter Product Quantity: ");
        scanf("%d", &products[count].quantity);
        count++;
    }
    else{
        printf("Inventory is full!\n");
    }
    printf("\nPress any key to continue...");
    getchar();
    clear_screen();
}

void remove_product(){
    clear_screen();
    int index, id, i;
    printf("***REMOVE PRODUCT***\n");
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for(i=0; i<count; i++){
        if(products[i].id == id){
            index = i;
        }
    }
    for(i = index; i<(count-1); i++){
        products[i] = products[i+1];
    }
    count--;
    printf("Product removed successfully!\n");
    printf("\nPress any key to continue...");
    getchar();
    clear_screen();
}

void display_products(){
    clear_screen();
    int i;
    printf("***PRODUCT INVENTORY***\n");
    printf("NAME\tID\tPRICE\tQUANTITY\n");
    for(i=0; i<count; i++){
        printf("%s\t%d\t%.1f\t%d\n", products[i].name, products[i].id, products[i].price, products[i].quantity);
    }
    printf("\nPress any key to continue...");
    getchar();
    clear_screen();
}

void save_inventory(){
    clear_screen();
    FILE *file = fopen("inventory.txt", "w");
    int i;
    fprintf(file, "***PRODUCT INVENTORY***\n");
    fprintf(file, "NAME,ID,PRICE,QUANTITY\n");
    for(i=0; i<count; i++){
        fprintf(file, "%s,%d,%.1f,%d\n", products[i].name, products[i].id, products[i].price, products[i].quantity);
    }
    fclose(file);
    printf("Inventory saved successfully!\n");
    printf("\nPress any key to continue...");
    getchar();
    clear_screen();
}

void load_inventory(){
    clear_screen();
    FILE *file = fopen("inventory.txt", "r");
    int i = 0;
    char line[100], *token;
    while(fgets(line, 100, file)){
        if(i == 1){
            token = strtok(line, ",");
            strcpy(products[count].name, token);
            token = strtok(NULL, ",");
            products[count].id = atoi(token);
            token = strtok(NULL, ",");
            products[count].price = atof(token);
            token = strtok(NULL, ",");
            products[count].quantity = atoi(token);
            count++;
        }
        i++;
    }
    fclose(file);
    printf("Inventory loaded successfully!\n");
    printf("\nPress any key to continue...");
    getchar();
    clear_screen();
}

void menu(){
    int option;
    do{
        printf("***PRODUCT INVENTORY SYSTEM***\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Save Inventory\n");
        printf("5. Load Inventory\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                save_inventory();
                break;
            case 5:
                load_inventory();
                break;
            case 6:
                clear_screen();
                printf("Goodbye!\n");
                break;
            default:
                clear_screen();
                printf("Invalid option, please try again.\n");
                break;
        }
    }while(option != 6);
}

int main(){
    menu();
    return 0;
}