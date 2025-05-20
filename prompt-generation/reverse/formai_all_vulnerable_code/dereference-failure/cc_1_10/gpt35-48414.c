//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
  int id;
  char name[50];
  char email[50];
  struct mailing_list *next;
};

struct mailing_list *head;

void add_to_list() {
  struct mailing_list *new_list = malloc(sizeof(struct mailing_list));
  printf("Enter ID: ");
  scanf("%d", &new_list->id);
  printf("Enter name: ");
  scanf("%s", new_list->name);
  printf("Enter email: ");
  scanf("%s", new_list->email);
  new_list->next = NULL;
  if (head == NULL) {
    head = new_list;
  } else {
    struct mailing_list *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_list;
  }
  printf("Successfully added to mailing list!\n\n");
}

void delete_from_list() {
  if (head == NULL) {
    printf("Mailing list is empty!\n\n");
    return;
  }
  int id;
  printf("Enter ID to delete: ");
  scanf("%d", &id);
  struct mailing_list *current = head;
  struct mailing_list *prev = NULL;
  while (current != NULL) {
    if (current->id == id) {
      if (prev == NULL) {
        head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      printf("Successfully deleted from mailing list!\n\n");
      return;
    }
    prev = current;
    current = current->next;
  }
  printf("ID was not found in the mailing list!\n\n");
}

void print_list() {
  if (head == NULL) {
    printf("Mailing list is empty!\n\n");
  } else {
    printf("ID\tName\t\tEmail\n");
    printf("--\t----\t\t-----\n");
    struct mailing_list *current = head;
    while (current != NULL) {
      printf("%d\t%s\t\t%s\n", current->id, current->name, current->email);
      current = current->next;
    }
  }
}

void save_list() {
  char filename[100];
  printf("Enter filename to save: ");
  scanf("%s", filename);
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error creating file!\n\n");
    return;
  }
  struct mailing_list *current = head;
  while (current != NULL) {
    fprintf(fp, "%d,%s,%s\n", current->id, current->name, current->email);
    current = current->next;
  }
  fclose(fp);
  printf("Successfully saved mailing list to file!\n\n");
}

void load_list() {
  char filename[100];
  printf("Enter filename to load: ");
  scanf("%s", filename);
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file!\n\n");
    return;
  }
  char line[200];
  while (fgets(line, sizeof(line), fp)) {
    line[strcspn(line, "\n")] = 0; // remove trailing newline character
    char *token = strtok(line, ",");
    int id = atoi(token);
    token = strtok(NULL, ",");
    char name[50];
    strcpy(name, token);
    token = strtok(NULL, ",");
    char email[50];
    strcpy(email, token);
    struct mailing_list *new_list = malloc(sizeof(struct mailing_list));
    new_list->id = id;
    strcpy(new_list->name, name);
    strcpy(new_list->email, email);
    new_list->next = NULL;
    if (head == NULL) {
      head = new_list;
    } else {
      struct mailing_list *current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = new_list;
    }
  }
  fclose(fp);
  printf("Successfully loaded mailing list from file!\n\n");
}

int main() {
  head = NULL;
  int choice;
  do {
    printf("Mailing List Manager\n");
    printf("--------------------\n");
    printf("1. Add to list\n");
    printf("2. Delete from list\n");
    printf("3. Print list\n");
    printf("4. Save list to file\n");
    printf("5. Load list from file\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_to_list();
        break;
      case 2:
        delete_from_list();
        break;
      case 3:
        print_list();
        break;
      case 4:
        save_list();
        break;
      case 5:
        load_list();
        break;
      case 6:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice!\n\n");
        break;
    }
  } while (choice != 6);
  return 0;
}