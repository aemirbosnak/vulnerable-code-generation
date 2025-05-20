//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
  char name[20];
  int quantity;
  float price;
  struct Medicine *next;
};

void insert_medicine(struct Medicine **head) {
  struct Medicine *new_node = (struct Medicine *)malloc(sizeof(struct Medicine));
  printf("Enter medicine name: ");
  scanf("%s", new_node->name);
  printf("Enter quantity: ");
  scanf("%d", &new_node->quantity);
  printf("Enter price: ");
  scanf("%f", &new_node->price);
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

void search_medicine(struct Medicine *head) {
  char search_name[20];
  printf("Enter medicine name: ");
  scanf("%s", search_name);

  struct Medicine *current = head;
  while (current) {
    if (strcmp(current->name, search_name) == 0) {
      printf("Name: %s\n", current->name);
      printf("Quantity: %d\n", current->quantity);
      printf("Price: %.2f\n", current->price);
      break;
    }
    current = current->next;
  }

  if (current == NULL) {
    printf("Medicine not found.\n");
  }
}

void update_medicine(struct Medicine *head) {
  char update_name[20];
  printf("Enter medicine name: ");
  scanf("%s", update_name);

  struct Medicine *current = head;
  while (current) {
    if (strcmp(current->name, update_name) == 0) {
      printf("Enter new quantity: ");
      scanf("%d", &current->quantity);
      printf("Enter new price: ");
      scanf("%f", &current->price);
      break;
    }
    current = current->next;
  }

  if (current == NULL) {
    printf("Medicine not found.\n");
  }
}

void delete_medicine(struct Medicine *head) {
  char delete_name[20];
  printf("Enter medicine name: ");
  scanf("%s", delete_name);

  struct Medicine *current = head;
  struct Medicine *previous = NULL;

  while (current) {
    if (strcmp(current->name, delete_name) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      break;
    }
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Medicine not found.\n");
  }
}

int main() {
  struct Medicine *head = NULL;

  while (1) {
    int choice;
    printf("1. Insert Medicine\n");
    printf("2. Search Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insert_medicine(&head);
        break;
      case 2:
        search_medicine(head);
        break;
      case 3:
        update_medicine(head);
        break;
      case 4:
        delete_medicine(head);
        break;
      default:
        printf("Invalid choice.\n");
    }

    if (choice == 4) {
      break;
    }
  }

  return 0;
}