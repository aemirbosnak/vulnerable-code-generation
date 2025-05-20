//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Structure to hold customer information and order information
typedef struct {
  char name[20];
  int order_number;
  float price;
} Order;

// Structure to hold list of orders
typedef struct {
  Order *orders;
  int num_orders;
} OrderList;

int main() {
  OrderList *list = malloc(sizeof(OrderList));
  list->orders = malloc(sizeof(Order));
  list->num_orders = 0;
  
  float total_price = 0;
  int choice, i;
  
  // Display menu
  printf("Welcome to our cafe billing system!\n\n");
  printf("Menu:\n");
  printf("1. Coffee - $2.50\n");
  printf("2. Tea - $1.50\n");
  printf("3. Sandwich - $5.00\n");
  printf("4. Salad - $3.50\n\n");
  
  while(1) {
    printf("Enter choice (0 to exit): ");
    scanf("%d", &choice);
    
    if(choice == 0) {
      break;
    }
    
    Order *new_order = malloc(sizeof(Order));
    
    // Get customer name and order number
    printf("Enter customer name: ");
    scanf("%s", new_order->name);
    printf("Enter order number: ");
    scanf("%d", &new_order->order_number);
    
    // Set price and add to total price
    switch(choice) {
      case 1:
        new_order->price = 2.50;
        break;
      case 2:
        new_order->price = 1.50;
        break;
      case 3:
        new_order->price = 5.00;
        break;
      case 4:
        new_order->price = 3.50;
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
    
    // Add order to list and increment number of orders
    list->orders = realloc(list->orders, (list->num_orders + 1) * sizeof(Order));
    list->orders[list->num_orders++] = *new_order;
    total_price += new_order->price;
  }
  
  // Print out all orders and calculate total price
  printf("\nOrder Summary:\n");
  for(i = 0; i < list->num_orders; i++) {
    printf("Customer name: %s\n", list->orders[i].name);
    printf("Order number: %d\n", list->orders[i].order_number);
    printf("Price: $%.2f\n\n", list->orders[i].price);
  }
  
  printf("Total Price: $%.2f\n", total_price);
  
  // Clean up memory
  free(list->orders);
  free(list);
  
  return 0;
}