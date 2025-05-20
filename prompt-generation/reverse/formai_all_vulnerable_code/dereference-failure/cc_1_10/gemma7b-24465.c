//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct DroneCommand {
  char name[20];
  int parameter;
  struct DroneCommand* next;
} DroneCommand;

DroneCommand* drone_command_list = NULL;

void add_command(char* name, int parameter) {
  DroneCommand* new_command = malloc(sizeof(DroneCommand));
  strcpy(new_command->name, name);
  new_command->parameter = parameter;
  new_command->next = drone_command_list;
  drone_command_list = new_command;
}

void send_command(char* command) {
  DroneCommand* current_command = drone_command_list;
  while (current_command) {
    if (strcmp(current_command->name, command) == 0) {
      switch (current_command->parameter) {
        case 0:
          printf("Motor forward\n");
          break;
        case 1:
          printf("Motor right\n");
          break;
        case 2:
          printf("Motor back\n");
          break;
        case 3:
          printf("Motor left\n");
          break;
        default:
          printf("Invalid parameter\n");
          break;
      }
      return;
    }
    current_command = current_command->next;
  }
  printf("Command not found\n");
}

int main() {
  add_command("forward", 0);
  add_command("right", 1);
  add_command("back", 2);
  add_command("left", 3);

  send_command("forward");
  send_command("right");
  send_command("back");
  send_command("left");
  send_command("invalid_command");

  return 0;
}