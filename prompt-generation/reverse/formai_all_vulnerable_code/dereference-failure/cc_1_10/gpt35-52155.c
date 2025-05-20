//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Item{
    char name[20];
    int price;
    int quantity;
} Item;

typedef struct Order{
    Item *items;
    int size;
} Order;

Order createOrder();
int displayMenu();
void displayOrder(Order);
int calculateTotal(Order);

int main(){
    printf("Welcome to Immersive Cafe!\n");
    Order order = createOrder();
    int choice;
    do{
        choice = displayMenu();
        switch(choice){
            case 1:{
                printf("You ordered a cappuccino.\n");
                order.items[order.size].price = 50;
                strcpy(order.items[order.size].name, "Cappuccino");
                order.items[order.size].quantity++;
                order.size++;
                break;
            }
            case 2:{
                printf("You ordered a latte.\n");
                order.items[order.size].price = 60;
                strcpy(order.items[order.size].name, "Latte");
                order.items[order.size].quantity++;
                order.size++;
                break;
            }
            case 3:{
                printf("You ordered a croissant.\n");
                order.items[order.size].price = 30;
                strcpy(order.items[order.size].name, "Croissant");
                order.items[order.size].quantity++;
                order.size++;
                break;
            }
            case 4:{
                printf("You ordered a sandwich.\n");
                order.items[order.size].price = 50;
                strcpy(order.items[order.size].name, "Sandwich");
                order.items[order.size].quantity++;
                order.size++;
                break;
            }
            case 5:{
                printf("You ordered a slice of cake.\n");
                order.items[order.size].price = 40;
                strcpy(order.items[order.size].name, "Cake");
                order.items[order.size].quantity++;
                order.size++;
                break;
            }
            case 6:{
                printf("You ordered a fruit bowl.\n");
                order.items[order.size].price = 35;
                strcpy(order.items[order.size].name, "Fruit Bowl");
                order.items[order.size].quantity++;
                order.size++;
                break;
            }
            case 7:{
                printf("Thank you for visiting Immersive Cafe! Here's your bill:\n");
                displayOrder(order);
                printf("The total amount payable is: %d\n", calculateTotal(order));
                break;
            }
            default:{
                printf("Invalid input! Please enter a number from the menu.\n");
            }
        }
    }while(choice!=7);

    return 0;
}

Order createOrder(){
    Order order;
    order.items = (Item*)malloc(sizeof(Item)*10);
    order.size = 0;
    return order;
}

int displayMenu(){
    printf("\n-------------------\nMenu:\n");
    printf("1. Cappuccino - $50\n");
    printf("2. Latte - $60\n");
    printf("3. Croissant - $30\n");
    printf("4. Sandwich - $50\n");
    printf("5. Cake Slice - $40\n");
    printf("6. Fruit Bowl - $35\n");
    printf("7. Proceed to Payment\n");
    int choice;
    printf("\nEnter the number of your choice: ");
    scanf("%d", &choice);
    return choice;
}

void displayOrder(Order order){
    printf("\n-------------------\nOrder:\n");
    int i, total = 0;
    for(i=0; i<order.size; i++){
        int subTotal = order.items[i].price * order.items[i].quantity;
        printf("%s x %d = %d\n", order.items[i].name, order.items[i].quantity, subTotal);
        total+=subTotal;
    }
}

int calculateTotal(Order order){
    int i, total = 0;
    for(i=0; i<order.size; i++){
        int subTotal = order.items[i].price * order.items[i].quantity;
        total+=subTotal;
    }
    return total;
}