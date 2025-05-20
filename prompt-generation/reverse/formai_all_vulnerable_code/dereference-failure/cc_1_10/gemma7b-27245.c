//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PORTS 65536

typedef struct Port {
  int number;
  char name[256];
  struct Port* next;
} Port;

Port* head = NULL;

void scanPorts(void) {
  printf("Scanning for ports...\n");

  // Allocate memory for the new port
  Port* newPort = malloc(sizeof(Port));

  // Get the port number and name
  printf("Enter port number: ");
  scanf("%d", &newPort->number);

  printf("Enter port name: ");
  scanf("%s", newPort->name);

  // Link the new port to the head
  if (head) {
    head->next = newPort;
  } else {
    head = newPort;
  }

  // Print the newly scanned port
  printf("Port %d (%s) added.\n", newPort->number, newPort->name);
}

int main() {
  // Scan ports until the user enters a quit command
  while (1) {
    char command;

    printf("Enter command (scan/quit): ");
    scanf(" %c", &command);

    switch (command) {
      case 's':
        scanPorts();
        break;
      case 'q':
        exit(0);
      default:
        printf("Invalid command.\n");
    }
  }

  return 0;
}