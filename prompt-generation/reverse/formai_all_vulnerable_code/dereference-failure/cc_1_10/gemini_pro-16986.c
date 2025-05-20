//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <math.h>

#define PORT 8080
#define MAXLINE 1024

// Structure to store player information
typedef struct player {
    int socket;
    char name[32];
    double loan_amount;
    double interest_rate;
    int loan_term;
    double monthly_payment;
} player_t;

// Function to calculate monthly payment
double calculate_monthly_payment(double loan_amount, double interest_rate, int loan_term) {
    double monthly_rate = interest_rate / 1200;
    double num_payments = loan_term * 12;
    double monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));
    return monthly_payment;
}

// Function to send message to player
void send_message(int socket, char *message) {
    int len = strlen(message);
    send(socket, &len, sizeof(len), 0);
    send(socket, message, len, 0);
}

// Function to receive message from player
void receive_message(int socket, char *buffer) {
    int len;
    recv(socket, &len, sizeof(len), 0);
    recv(socket, buffer, len, 0);
}

// Function to handle player connection
void handle_player(int socket) {
    char buffer[MAXLINE];

    // Receive player information
    receive_message(socket, buffer);
    player_t player;
    sscanf(buffer, "%s %lf %lf %d", player.name, &player.loan_amount, &player.interest_rate, &player.loan_term);

    // Calculate monthly payment
    player.monthly_payment = calculate_monthly_payment(player.loan_amount, player.interest_rate, player.loan_term);

    // Send monthly payment to player
    sprintf(buffer, "%.2f", player.monthly_payment);
    send_message(socket, buffer);

    // Close player connection
    close(socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        // Create new thread to handle player connection
        int *new_socket = malloc(sizeof(int));
        *new_socket = client_socket;
        pthread_t tid;
        pthread_create(&tid, NULL, (void *)handle_player, (void *)new_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}