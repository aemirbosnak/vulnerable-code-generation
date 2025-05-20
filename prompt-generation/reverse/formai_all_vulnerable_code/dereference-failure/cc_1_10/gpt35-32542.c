//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room struct
struct Room {
    char *name;
    char *description;
    struct Room **connections;
    int numConnections;
};

// Function prototypes
void playGame();
struct Room *createRoom(char *name, char *description);
void connectRooms(struct Room *room1, struct Room *room2);
int getPuzzleAnswer();
void printInstructions();

int main() {
    printInstructions();
    playGame();
    return 0;
}

// Play the game
void playGame() {
    // Create rooms
    struct Room *room1 = createRoom("Living Room", "You are in a cozy living room with a sofa and TV.");
    struct Room *room2 = createRoom("Kitchen", "The aroma of fresh baked bread fills the air.");
    struct Room *room3 = createRoom("Bedroom", "You see a large king-size bed and a wardrobe.");
    struct Room *room4 = createRoom("Bathroom", "The bathroom is pristine and sparkling clean.");
    struct Room *room5 = createRoom("Study", "The room is filled with books and papers.");
    struct Room *room6 = createRoom("Secret Room", "You've discovered a secret room!");

    // Connect rooms
    connectRooms(room1, room2);
    connectRooms(room1, room3);
    connectRooms(room2, room3);
    connectRooms(room2, room4);
    connectRooms(room3, room4);
    connectRooms(room3, room5);
    connectRooms(room4, room6);
    connectRooms(room5, room6);

    // Set starting room
    struct Room *currentRoom = room1;

    // Game loop
    int gameOver = 0;
    while (!gameOver) {
        printf("You are in the %s.\n", currentRoom->name);
        printf("%s\n", currentRoom->description);

        // Check for secret room
        if (currentRoom == room5 && room5->numConnections == 1) {
            printf("There seems to be something odd about this room. Perhaps you should investigate further...\n");
        }

        // Get user input
        char userInput[100];
        printf("Where would you like to go next? Enter a direction (north, south, east, west): ");
        fgets(userInput, 100, stdin);

        // Remove newline character
        userInput[strcspn(userInput, "\n")] = 0;

        // Determine next room
        int nextRoomIndex = -1;
        if (strcmp(userInput, "north") == 0) {
            nextRoomIndex = 0;
        } else if (strcmp(userInput, "south") == 0) {
            nextRoomIndex = 1;
        } else if (strcmp(userInput, "east") == 0) {
            nextRoomIndex = 2;
        } else if (strcmp(userInput, "west") == 0) {
            nextRoomIndex = 3;
        } else {
            printf("I'm sorry, I don't understand \"%s\".\n", userInput);
            continue;
        }

        // Check if next room exists
        if (currentRoom->connections[nextRoomIndex] == NULL) {
            printf("You can't go that way.\n");
        } else {
            currentRoom = currentRoom->connections[nextRoomIndex];

            // Check for secret room
            if (currentRoom == room5 && room5->numConnections == 1) {
                printf("Congratulations! You've found the secret room!\n");
                int answer = getPuzzleAnswer();
                if (answer == 42) {
                    printf("You've solved the puzzle and found a treasure chest! You win!\n");
                    gameOver = 1;
                } else {
                    printf("That wasn't the correct answer. However, you can keep exploring the secret room if you'd like.\n");
                }
            }
        }
    }
}

// Creates a new room with the given name and description
struct Room *createRoom(char *name, char *description) {
    struct Room *room = malloc(sizeof(struct Room));
    room->name = name;
    room->description = description;
    room->connections = calloc(4, sizeof(struct Room *));
    room->numConnections = 0;
    return room;
}

// Connects two rooms together
void connectRooms(struct Room *room1, struct Room *room2) {
    int index1 = room1->numConnections;
    int index2 = room2->numConnections;
    room1->connections[index1] = room2;
    room2->connections[index2] = room1;
    room1->numConnections++;
    room2->numConnections++;
}

// Gets the answer to the puzzle
int getPuzzleAnswer() {
    printf("You've found a strange machine with a screen displaying the number \"6\".\n");
    printf("The machine speaks: \"What is the answer to life, the universe, and everything?\"\n");
    printf("Enter a number: ");
    int answer;
    scanf("%d", &answer);
    getchar(); // remove newline character
    return answer;
}

// Prints instructions for the game
void printInstructions() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("Instructions:\n");
    printf("You will start in the Living Room. Your goal is to find the Secret Room and solve the puzzle inside.\n");
    printf("- Move between rooms by entering a direction (north, south, east, west)\n");
    printf("- Explore each room to find clues and items that may help you later\n");
    printf("- Good luck!\n\n");
}