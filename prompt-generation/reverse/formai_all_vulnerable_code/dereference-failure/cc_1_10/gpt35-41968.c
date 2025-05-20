//FormAI DATASET v1.0 Category: Client Server Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 4444
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int game[MAX_CLIENTS] = {0}; // Array to keep track of each client's game state
int turn = 1; // Variable to keep track of the current turn

void start_game(int* game_state) { // Function to initialize the game state
    for (int i = 0; i < MAX_CLIENTS; i++) {
        game_state[i] = rand() % 10 + 1;
    }
}

void play_game(int* game_state, int index) { // Function to simulate playing the game
    int guess;

    printf("Player %d's turn:\n", index+1);
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &guess);

    if (guess == game_state[index]) {
        printf("Congratulations! You win!\n");
        game_state[index] = 0;
    } else {
        printf("Wrong! Try again.\n");
    }
}

void* handle_client(void* arg) { // Thread function to handle each client connection
    int client_socket = *((int*) arg);
    int index;

    for (int i = 0; i < MAX_CLIENTS; i++) { // Find an empty slot in the game state array
        if (game[i] == 0) {
            game[i] = -1; // Mark as taken by this client
            index = i;
            break;
        }
    }

    printf("Player %d connected\n", index+1);

    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];

    sprintf(message, "You are Player %d\n", index+1);
    send(client_socket, message, strlen(message), 0);

    while (1) {
        if (turn == index+1) { // It's this client's turn
            play_game(game, index);
            turn = (turn % MAX_CLIENTS) + 1; // Increment turn, loop back to 1 if past max
        }

        // Send game state to all clients
        sprintf(buffer, "%d %d %d %d %d\n", game[0], game[1], game[2], game[3], game[4]);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (game[i] == -1) { // Skip empty slots
                continue;
            }
            send(i+3, buffer, strlen(buffer), 0);
        }

        sleep(1); // Wait a second before checking again
    }

    close(client_socket);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int server_fd, client_socket, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t thread_id[MAX_CLIENTS];

    start_game(game); // Initialize game state

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started listening on port %d\n", PORT);

    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_create(&thread_id[MAX_CLIENTS], NULL, handle_client, (void*) &client_socket);
    }

    return 0;
}