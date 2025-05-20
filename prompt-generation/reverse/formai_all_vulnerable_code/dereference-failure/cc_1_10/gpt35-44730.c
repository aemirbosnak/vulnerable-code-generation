//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: random
#include<stdio.h>
#include<stdlib.h>

typedef struct Item {
  int item_id;
  char item_name[20];
  float item_price;
  int item_quantity;
} Item;

struct Node {
  Item item;
  struct Node* next;
};

struct Node* head = NULL;

void print_menu() {
  printf("============ Warehouse Management System Menu ===========\n");
  printf("1. Add item\n");
  printf("2. Remove item\n");
  printf("3. Update item quantity\n");
  printf("4. Display all items\n");
  printf("5. Exit\n");
}

void add_item() {
  int id, quantity;
  float price;
  char name[20];
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

  printf("Enter item id: ");
  scanf("%d", &id);
  new_node->item.item_id = id;
  
  printf("Enter item name: ");
  scanf("%s", &name);
  strcpy(new_node->item.item_name, name);

  printf("Enter item price: ");
  scanf("%f", &price);
  new_node->item.item_price = price;
  
  printf("Enter item quantity: ");
  scanf("%d", &quantity);
  new_node->item.item_quantity = quantity;

  new_node->next = head;
  head = new_node;
  printf("\nItem added successfully.\n");
}

void remove_item() {
  int id;
  struct Node* temp_node = head;
  struct Node* prev_node = NULL;

  printf("Enter item id: ");
  scanf("%d", &id);

  while (temp_node != NULL && temp_node->item.item_id != id) {
    prev_node = temp_node;
    temp_node = temp_node->next;
  }

  if (temp_node == NULL) {
    printf("Item not found.\n");
    return;
  }

  if (prev_node == NULL){
    head = temp_node->next;
  } else {
    prev_node->next = temp_node->next;
  }

  free(temp_node);
  printf("\nItem deleted successfully.\n");
}

void update_item_quantity() {
  int id, quantity;
  struct Node* temp_node = head;

  printf("Enter item id: ");
  scanf("%d", &id);

  while (temp_node != NULL && temp_node->item.item_id != id) {
    temp_node = temp_node->next;
  }

  if (temp_node == NULL) {
    printf("Item not found.\n");
    return;
  }

  printf("Enter new quantity: ");
  scanf("%d", &quantity);

  temp_node->item.item_quantity = quantity;
  printf("\nItem quantity updated successfully.\n");
}

void display_all_items() {
  struct Node* temp_node = head;

  if (temp_node == NULL) {
    printf("No items found.\n");
    return;
  }

  printf("Item ID\tItem Name\tItem Price\tItem Quantity\n");
  
  while (temp_node != NULL) {
    printf("%d\t%s\t\t%.2f\t\t%d\n", 
      temp_node->item.item_id, 
      temp_node->item.item_name, 
      temp_node->item.item_price, 
      temp_node->item.item_quantity);
    temp_node = temp_node->next;
  }
}

int main() {
  int choice;

  while(1) {
    print_menu();
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: add_item();
              break;
      case 2: remove_item();
              break;
      case 3: update_item_quantity();
              break;
      case 4: display_all_items();
              break;
      case 5: exit(0);
      default: printf("Invalid choice.\n");
    }
  }

  return 0;
}