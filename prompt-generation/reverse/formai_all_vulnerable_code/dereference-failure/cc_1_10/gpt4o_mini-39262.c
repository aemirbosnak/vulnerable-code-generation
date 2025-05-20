//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_PLAYERS 5
#define ROLLED_NUMBERS_LENGTH 20

int roll_dice() {
    return (rand() % 6) + 1;
}

void setup_server(int *server_fd, struct sockaddr_in *address) {
    if ((*server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(PORT);

    if (bind(*server_fd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        perror("Binding error");
        exit(EXIT_FAILURE);
    }

    if (listen(*server_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for players to join...\n");
}

int main() {
    srand(time(NULL));

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int player_count = 0;
    int rolled_numbers[MAX_PLAYERS] = {0};

    setup_server(&server_fd, &address);
    
    while (player_count < MAX_PLAYERS) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }
        
        // Simulate rolling the dice
        rolled_numbers[player_count] = roll_dice();
        
        char message[50];
        sprintf(message, "Player %d rolled a %d\n", player_count + 1, rolled_numbers[player_count]);
        send(new_socket, message, strlen(message), 0);
        
        close(new_socket);
        player_count++;
    }
    
    int max_roll = rolled_numbers[0];
    int winner_index = 0;

    for (int i = 1; i < MAX_PLAYERS; i++) {
        if (rolled_numbers[i] > max_roll) {
            max_roll = rolled_numbers[i];
            winner_index = i;
        }
    }
    
    printf("\nPlayer %d wins with a roll of %d!\n", winner_index + 1, max_roll);
    
    close(server_fd);
    return 0;
}