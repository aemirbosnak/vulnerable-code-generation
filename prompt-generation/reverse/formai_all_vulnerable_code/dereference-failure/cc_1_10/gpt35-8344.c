//FormAI DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define struct for stock information
typedef struct stock{
    int stock_id;
    char* name;
    float price;
} Stock;

// Function to allocate memory for Stock and initialize it with given values
Stock* create_stock(int id, char* name, float price){
    Stock* s = (Stock*)malloc(sizeof(Stock));
    s->stock_id = id;
    s->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(s->name, name);
    s->price = price;
    return s;
}

// Function to print stock information
void print_stock(Stock* s){
    printf("Stock ID: %d\n", s->stock_id);
    printf("Name: %s\n", s->name);
    printf("Price: %.2f\n", s->price);
}

// Function to update stock price
void update_price(Stock* s, float new_price){
    s->price = new_price;
}

int main(){
    int n;
    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    // Allocate memory for array of stocks
    Stock** stocks = (Stock**)malloc(sizeof(Stock*)*n);

    // Read stock information from user input and create Stock objects
    for(int i=0; i<n; i++){
        int id;
        char name[50];
        float price;
        printf("Enter stock ID: ");
        scanf("%d", &id);
        printf("Enter stock name: ");
        scanf("%s", name);
        printf("Enter stock price: ");
        scanf("%f", &price);
        stocks[i] = create_stock(id, name, price);
    }

    // Print initial stock information
    printf("Initial stock information:\n");
    for(int i=0; i<n; i++){
        print_stock(stocks[i]);
    }

    // Perform stock updates based on user input
    char choice;
    do{
        printf("Do you want to update the price of any stock? (y/n): ");
        scanf(" %c", &choice);
        if(choice=='y'){
            int id;
            float new_price;
            printf("Enter stock ID: ");
            scanf("%d", &id);
            printf("Enter new price: ");
            scanf("%f", &new_price);

            // Find the stock object with given ID and update its price
            int found = 0;
            for(int i=0; i<n; i++){
                if(stocks[i]->stock_id == id){
                    update_price(stocks[i], new_price);
                    found = 1;
                    break;
                }
            }
            if(found){
                printf("Stock price updated.\n");
            }
            else{
                printf("Stock not found!\n");
            }
        }
    } while(choice=='y');

    // Print final stock information
    printf("Final stock information:\n");
    for(int i=0; i<n; i++){
        print_stock(stocks[i]);
    }

    // Free memory allocated for Stock objects and array of stocks
    for(int i=0; i<n; i++){
        free(stocks[i]->name);
        free(stocks[i]);
    }
    free(stocks);

    return 0;
}