//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100

typedef struct {
    char name[50];
    int id;
    char command[100];
    char result[100];
} command_t;

command_t commands[MAX_COMMANDS];
int command_count = 0;

void add_command(const char* name, const char* command) {
    command_t* new_command = malloc(sizeof(command_t));
    strcpy(new_command->name, name);
    new_command->id = command_count++;
    strcpy(new_command->command, command);
    strcpy(new_command->result, "");
    commands[command_count - 1] = *new_command;
}

int execute_command(int command_id) {
    command_t* command = &commands[command_id];
    printf("%s: %s\n", command->name, command->command);
    system(command->command);
    printf("%s\n", command->result);
    free(command);
    return 0;
}

int main() {
    add_command("Turn on lights", "sudo /home/pi/lights/on");
    add_command("Turn off lights", "sudo /home/pi/lights/off");
    add_command("Adjust temperature", "sudo /home/pi/thermostat/set 30");
    add_command("Play music", "sudo /home/pi/music/play");
    add_command("Pause music", "sudo /home/pi/music/pause");
    add_command("Close curtains", "sudo /home/pi/curtains/close");
    add_command("Open curtains", "sudo /home/pi/curtains/open");

    printf("Available commands:\n");
    for (int i = 0; i < command_count; i++) {
        printf("%d. %s\n", i + 1, commands[i].name);
    }

    int choice;
    printf("Enter the number of the command you want to execute: ");
    scanf("%d", &choice);
    execute_command(choice);

    return 0;
}