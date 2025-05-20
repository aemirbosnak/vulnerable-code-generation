//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to print the room description
void print_room_desc(char *room_desc) {
    printf("%s\n", room_desc);
}

// Function to print the available actions in a room
void print_actions(char *room_desc) {
    printf("Actions available:\n");
}

// Function to print the user's input
void print_input(char *room_desc) {
    printf("You: ");
}

// Function to read user's input
char *read_input(char *room_desc) {
    char *input = malloc(sizeof(char) * 100);
    printf("> ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';
    return input;
}

// Function to execute the user's action
void execute_action(char *room_desc) {
    char *action = read_input(room_desc);
    printf("%s\n", action);
}

// Function to handle room transitions
void change_room(char *current_room, char *new_room) {
    printf("You enter the %s.\n", new_room);
}

int main() {
    // Initialize the current room
    char *current_room = "You are in the first room.\n";
    char *new_room = "The second room.\n";

    // Main loop
    while (1) {
        // Print the room description
        print_room_desc(current_room);

        // Print the available actions
        print_actions(current_room);

        // Read user's input
        char *input = read_input(current_room);

        // Execute the user's action
        execute_action(current_room);

        // Handle room transitions
        change_room(current_room, new_room);
    }

    return 0;
}