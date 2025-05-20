//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define MAX_PACKET_SIZE 1024

// Structure to store client information
struct client_info {
    int sock;
    char username[50];
};

// Function to handle client connections
void handle_client_connection(int sock) {
    struct client_info *client_info;
    char buffer[MAX_PACKET_SIZE];

    // Receive username from client
    recv(sock, buffer, MAX_PACKET_SIZE, 0);
    client_info = malloc(sizeof(struct client_info));
    strcpy(client_info->username, buffer);

    // Spell check the received username
    int spell_check_result = spell_check(client_info->username);

    // Send spell check result to client
    char *result_message = (spell_check_result == 1) ? "Your username is correct!" : "Your username contains a spelling error!";
    send(sock, result_message, strlen(result_message), 0);

    // Free memory
    free(client_info);
}

// Function to spell check a given string
int spell_check(char *username) {
    int i, j;
    int spell_check_result = 0;
    char *word;

    // Split the username into words
    word = strtok(username, " ");
    while (word != NULL) {
        // Check each word for spelling errors
        for (i = 0; i < strlen(word); i++) {
            if (isdigit(word[i])) {
                // Ignore digits
                continue;
            }

            // Check if the character is a letter
            if (!isalpha(word[i])) {
                // If not, it's a spelling error
                spell_check_result = 0;
                break;
            }
        }

        // Move to the next word
        word = strtok(NULL, " ");
    }

    return spell_check_result;
}

// Function to listen for client connections
void listen_for_clients() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, MAX_CLIENT_CONNECTIONS);

    while (1) {
        // Accept a client connection
        int client_sock = accept(sock, NULL, NULL);
        handle_client_connection(client_sock);
    }
}

int main() {
    listen_for_clients();
    return 0;
}