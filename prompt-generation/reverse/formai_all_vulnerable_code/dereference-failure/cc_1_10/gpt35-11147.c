//FormAI DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 20

struct Entry {
  char *title;
  char *entry_text;
  char *date;
} entries[MAX_ENTRY];

int entry_count = 0;

void add_entry() {
  char *title = malloc(256);
  char *entry_text = malloc(1024);
  char *date = malloc(16);

  printf("Enter title: ");
  scanf("%s", title);

  printf("Enter date (DD/MM/YYYY): ");
  scanf("%s", date);

  printf("Enter entry:\n");
  getchar();
  fgets(entry_text, 1024, stdin);

  entries[entry_count].title = title;
  entries[entry_count].entry_text = entry_text;
  entries[entry_count].date = date;

  entry_count++;

  printf("New entry added!\n");
}

void view_entry() {
  int i;
  char *title = malloc(256);

  printf("Enter title of entry to view: ");
  scanf("%s", title);

  for (i = 0; i < entry_count; i++) {
    if (strcmp(entries[i].title, title) == 0) {
      printf("%s\n%s\n%s\n", entries[i].title, entries[i].date, entries[i].entry_text);
      return;
    }
  }

  printf("Entry not found.\n");
}

int main() {
  char choice;

  printf("Dearest Diary,\n\n");
  printf("Shall I compare thee to a summer's day?\n");
  printf("Thou art more lovely and more temperate.\n");
  printf("Rough winds do shake the darling buds of May,\n");
  printf("And summer's lease hath all too short a date.\n\n");

  while (1) {
    printf("What wouldst thou like to do? (A)dd an entry, (V)iew an entry, or (Q)uit? ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'A':
        add_entry();
        break;
      case 'V':
        view_entry();
        break;
      case 'Q':
        printf("Farewell, dear diary!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
        break;
    }

    printf("\n");
  }
}