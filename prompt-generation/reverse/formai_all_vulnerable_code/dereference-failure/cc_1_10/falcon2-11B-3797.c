//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global variables
char* game_text;
char* verb;
char* noun;
int current_room;

// Function declarations
void print_menu();
void print_room();
void print_game_over();
void move_to_room();
void move_to_room_verb_noun();
void move_to_room_noun();
void move_to_room_verb();
void read_input();
void start_game();

int main() {
    start_game();
    return 0;
}

// Game logic
void start_game() {
    game_text = (char*) malloc(1000 * sizeof(char));
    memset(game_text, '\0', 1000);
    strcpy(game_text, "You are in a dark room.");
    current_room = 0;

    printf("%s\n", game_text);
    read_input();
}

// Print game menu
void print_menu() {
    printf("Choose an action:\n");
    printf("1. Look around\n");
    printf("2. Go north\n");
    printf("3. Go south\n");
    printf("4. Go east\n");
    printf("5. Go west\n");
    printf("6. Use <verb> on <noun>\n");
    printf("7. Use <verb>\n");
    printf("8. Use <noun>\n");
    printf("9. Quit\n");
}

// Print current room
void print_room() {
    printf("%s\n", game_text);
}

// Print game over message
void print_game_over() {
    printf("Game over.\n");
}

// Move to a new room
void move_to_room() {
    int choice = get_user_input("Enter your choice: ");

    switch(choice) {
        case 1:
            print_room();
            break;
        case 2:
            current_room = 1;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 3:
            current_room = 2;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 4:
            current_room = 3;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 5:
            current_room = 4;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 6:
            move_to_room_verb_noun();
            break;
        case 7:
            move_to_room_verb();
            break;
        case 8:
            move_to_room_noun();
            break;
        case 9:
            exit(0);
    }
}

// Move to a new room using verb and noun
void move_to_room_verb_noun() {
    int choice = get_user_input("Enter your choice: ");

    switch(choice) {
        case 1:
            current_room = 1;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 2:
            current_room = 2;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 3:
            current_room = 3;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 4:
            current_room = 4;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 5:
            current_room = 5;
            strcpy(game_text, "You are in a dark room.");
            break;
    }
}

// Move to a new room using verb
void move_to_room_verb() {
    int choice = get_user_input("Enter your choice: ");

    switch(choice) {
        case 1:
            current_room = 1;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 2:
            current_room = 2;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 3:
            current_room = 3;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 4:
            current_room = 4;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 5:
            current_room = 5;
            strcpy(game_text, "You are in a dark room.");
            break;
    }
}

// Move to a new room using noun
void move_to_room_noun() {
    int choice = get_user_input("Enter your choice: ");

    switch(choice) {
        case 1:
            current_room = 1;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 2:
            current_room = 2;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 3:
            current_room = 3;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 4:
            current_room = 4;
            strcpy(game_text, "You are in a dark room.");
            break;
        case 5:
            current_room = 5;
            strcpy(game_text, "You are in a dark room.");
            break;
    }
}

// Read user input
void read_input() {
    char input[100];
    printf("> ");
    fgets(input, 100, stdin);

    // Process input
    switch(input[0]) {
        case '1':
            print_room();
            break;
        case '2':
            move_to_room();
            break;
        case '3':
            print_room();
            break;
        case '4':
            print_room();
            break;
        case '5':
            print_room();
            break;
        case '6':
            move_to_room_verb_noun();
            break;
        case '7':
            move_to_room_verb();
            break;
        case '8':
            move_to_room_noun();
            break;
        case '9':
            exit(0);
        default:
            printf("Invalid input.\n");
            break;
    }
}

// Get user input
int get_user_input(const char* prompt) {
    int choice;
    printf("%s", prompt);
    scanf("%d", &choice);
    return choice;
}