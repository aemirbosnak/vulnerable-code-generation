//FormAI DATASET v1.0 Category: Socket programming ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PLAYERS 5
#define PORT 8080

int player_count = 0;
int player_sockets[MAX_PLAYERS];

// function to handle the game logic after all players have joined
void start_game(int* sockets, int size) {
    int num_guesses = 0;
    char buffer[1024];
    bool game_over = false;
    bool correct_guess = false;

    srand(time(NULL));
    int secret_number = rand() % 101;

    while (!game_over) {
        for (int i = 0; i < size; i++) {
            bzero(buffer, 1024);
            sprintf(buffer, "Enter a guess (between 0-100): ");
            write(sockets[i], buffer, strlen(buffer));

            bzero(buffer, 1024);
            read(sockets[i], buffer, 1024);

            int guess = atoi(buffer);

            if (guess == secret_number) {
                bzero(buffer, 1024);
                sprintf(buffer, "Congratulations! You guessed the secret number in %d attempts.", num_guesses+1);
                write(sockets[i], buffer, strlen(buffer));

                game_over = true;
                break;
            } else if (guess < secret_number) {
                bzero(buffer, 1024);
                sprintf(buffer, "Your guess is lower than the secret number. Try again.\n");
                write(sockets[i], buffer, strlen(buffer));
            } else if (guess > secret_number) {
                bzero(buffer, 1024);
                sprintf(buffer, "Your guess is higher than the secret number. Try again.\n");
                write(sockets[i], buffer, strlen(buffer));
            }

            num_guesses++;
        }
    }
}

// function to handle individual player connections
void* handle_player(void* arg) {
    int client_socket = *((int*) arg);

    bzero(&arg, sizeof(arg));
    read(client_socket, arg, sizeof(arg));
    printf("Player %d has joined the game.\n", player_count+1);

    player_sockets[player_count] = client_socket;
    player_count++;

    if (player_count == MAX_PLAYERS) {
        printf("All players have joined the game. Starting game...\n");
        start_game(player_sockets, player_count);
    }

    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_PLAYERS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for players to join...\n");

    pthread_t player_threads[MAX_PLAYERS];

    while (player_count < MAX_PLAYERS) {
        if ((new_socket = accept(server_fd, (struct sockaddr*) &address, 
                (socklen_t*) &addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (pthread_create(&player_threads[player_count], NULL, 
                handle_player, (void*) &new_socket)) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(player_threads[i], NULL);
    }

    return 0;
}