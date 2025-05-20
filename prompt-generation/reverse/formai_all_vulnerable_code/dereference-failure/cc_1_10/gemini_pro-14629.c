//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 100
#define MAX_PASSWORD_LENGTH 100

struct client {
    int sockfd;
    char password[MAX_PASSWORD_LENGTH + 1];
    int strength;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_sockfd) {
    char buffer[MAX_PASSWORD_LENGTH + 1];
    int n;

    // Receive the password from the client
    n = recv(client_sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        close(client_sockfd);
        return;
    }

    // Check the strength of the password
    int strength = check_password_strength(buffer);

    // Send the strength of the password back to the client
    n = send(client_sockfd, &strength, sizeof(strength), 0);
    if (n < 0) {
        perror("send");
        close(client_sockfd);
        return;
    }

    // Close the client socket
    close(client_sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int i;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket to a port
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    listen(sockfd, MAX_CLIENTS);

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Add the new client to the list of clients
        clients[num_clients].sockfd = newsockfd;
        strcpy(clients[num_clients].password, "");
        clients[num_clients].strength = 0;
        num_clients++;

        // Handle the client in a separate thread
        int *client_sockfd = malloc(sizeof(int));
        *client_sockfd = newsockfd;
        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handle_client, client_sockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}

int check_password_strength(char *password) {
    int strength = 0;
    int length = strlen(password);

    // Check the length of the password
    if (length >= 8) {
        strength++;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            strength++;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            strength++;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            strength++;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (ispunct(password[i])) {
            strength++;
            break;
        }
    }

    return strength;
}