//Gemma-7B DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_CMD_LEN 256
#define MAX_HISTORY_ENTRIES 10

typedef struct CommandEntry {
  char command[MAX_CMD_LEN];
  struct CommandEntry* next;
} CommandEntry;

CommandEntry* head = NULL;

void addCommand(char* command) {
  CommandEntry* newEntry = malloc(sizeof(CommandEntry));
  strcpy(newEntry->command, command);
  newEntry->next = head;
  head = newEntry;
}

int executeCommand(char* command) {
  if (head == NULL) {
    return -1;
  }

  for (CommandEntry* entry = head; entry; entry = entry->next) {
    if (strcmp(command, entry->command) == 0) {
      return 0;
    }
  }

  return -1;
}

int main() {
  char command[MAX_CMD_LEN];

  printf("Enter a command: ");
  scanf("%s", command);

  addCommand(command);

  if (executeCommand(command) == 0) {
    printf("Command executed successfully.\n");
  } else {
    printf("Command not found.\n");
  }

  return 0;
}