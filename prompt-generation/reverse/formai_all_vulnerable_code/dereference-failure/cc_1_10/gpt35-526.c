//FormAI DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

int is_empty(struct Node* head) {
  return head == NULL;
}

void insert_first(struct Node** head_ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void insert_after(struct Node* prev_node, int data) {
  if (prev_node == NULL) {
    printf("Cannot insert after null node\n");
    return;
  }
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void append(struct Node** head_ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  struct Node* last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
}

void delete_node(struct Node** head_ref, int key) {
  struct Node* temp = *head_ref, *prev;
  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Key not found in list\n");
    return;
  }
  prev->next = temp->next;
  free(temp);
}

void print_list(struct Node* head) {
  struct Node* temp = head;
  printf("List: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void clear_list(struct Node** head_ref) {
  struct Node* temp = *head_ref;
  struct Node* next;
  while (temp != NULL) {
    next = temp->next;
    free(temp);
    temp = next;
  }
  *head_ref = NULL;
}

int main() {
  struct Node* head = NULL;
  int choice, value, pos;
  while (1) {
    printf("1. Insert at the beginning\n");
    printf("2. Insert after node\n");
    printf("3. Append to end\n");
    printf("4. Delete node containing value\n");
    printf("5. Clear list\n");
    printf("6. Print list\n");
    printf("7. Exit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter value to insert: ");
        scanf("%d", &value);
        insert_first(&head, value);
        printf("Value inserted!\n");
        break;
      case 2:
        printf("Enter value to insert: ");
        scanf("%d", &value);
        printf("Enter node value to insert after: ");
        scanf("%d", &pos);
        struct Node* temp = head;
        while (temp != NULL) {
          if (temp->data == pos) {
            insert_after(temp, value);
            printf("Value inserted!\n");
            break;
          }
          temp = temp->next;
        }
        if (temp == NULL) {
          printf("Node not found\n");
        }
        break;
      case 3:
        printf("Enter value to append: ");
        scanf("%d", &value);
        append(&head, value);
        printf("Value appended!\n");
        break;
      case 4:
        printf("Enter value to delete: ");
        scanf("%d", &value);
        delete_node(&head, value);
        printf("Value deleted!\n");
        break;
      case 5:
        clear_list(&head);
        printf("List cleared!\n");
        break;
      case 6:
        print_list(head);
        break;
      case 7:
        clear_list(&head);
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }
  return 0;
}