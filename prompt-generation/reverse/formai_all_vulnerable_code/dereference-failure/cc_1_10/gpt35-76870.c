//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* A struct to hold each entry in the diary */
typedef struct diary_entry {
  int day;
  int month;
  int year;
  char *entry;
  struct diary_entry *next;
} diary_entry;

/* A function to add a new entry to the diary */
void add_entry(diary_entry **head_ref, int day, int month, int year, char *entry) {
  diary_entry *new_entry = malloc(sizeof(diary_entry));
  new_entry->day = day;
  new_entry->month = month;
  new_entry->year = year;
  new_entry->entry = malloc(strlen(entry) + 1);
  strcpy(new_entry->entry, entry);
  new_entry->next = *head_ref;
  *head_ref = new_entry;
}

/* A function to print out all the entries in the diary */
void print_entries(diary_entry *head) {
  diary_entry *current = head;

  while (current != NULL) {
    printf("On this day in the year %d, %d/%d, I wrote:\n%s\n\n", current->year, current->day, current->month, current->entry);
    current = current->next;
  }
}

int main() {
  diary_entry *diary_head = NULL;
  int option;
  int day, month, year;
  char entry[500];

  printf("Welcome to your digital diary!\n");

  do {
    printf("1. Add an entry to the diary\n");
    printf("2. View all diary entries\n");
    printf("3. Quit\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        /* Get the date of the entry */
        printf("\nEnter the date of the entry.\n");
        printf("Day: ");
        scanf("%d", &day);
        printf("Month: ");
        scanf("%d", &month);
        printf("Year: ");
        scanf("%d", &year);

        /* Get the entry itself */
        printf("Enter your diary entry for %d/%d/%d: ", day, month, year);
        fflush(stdin);
        fgets(entry, 500, stdin);

        /* Add the entry to the diary */
        add_entry(&diary_head, day, month, year, entry);
        printf("\nEntry added successfully!\n");
        break;
      case 2:
        /* Print out all the entries in the diary */
        printf("\n");
        print_entries(diary_head);
        break;
      case 3:
        /* Quit the program */
        printf("\nThank you for using your digital diary!\n");
        break;
      default:
        printf("\nInvalid option. Please try again.\n");
        break;
    }

  } while (option != 3);

  /* Free the memory used by the diary entries */
  diary_entry *current = diary_head;
  while (current != NULL) {
    diary_entry *next = current->next;
    free(current->entry);
    free(current);
    current = next;
  }

  return 0;
}