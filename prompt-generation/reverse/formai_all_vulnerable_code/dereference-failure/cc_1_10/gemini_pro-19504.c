//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Be a little bit of a nerd here...
#define THE_ANSWER 42
#define PORT_NUMBER 143

// Define the IMAP command constants
#define LOGIN "LOGIN"
#define LOGOUT "LOGOUT"
#define LIST "LIST"
#define SELECT "SELECT"
#define FETCH "FETCH"
#define CLOSE "CLOSE"

// Declare the functions we'll use.
int connect_to_server(char *hostname, int port);
void send_command(int socket, char *command);
char *receive_response(int socket);
int main(int argc, char **argv) {
    // Define the variables we'll need.
    int sockfd;
    char *hostname;
    char *username;
    char *password;
    char *mailbox;
    char *message_number;
    char *command;

    // Check the command line arguments.
    if (argc < 5) {
        fprintf(stderr, "Usage: %s hostname username password mailbox [message_number]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the command line arguments.
    hostname = argv[1];
    username = argv[2];
    password = argv[3];
    mailbox = argv[4];
    if (argc > 5) {
        message_number = argv[5];
    }

    // Connect to the server.
    sockfd = connect_to_server(hostname, PORT_NUMBER);

    // Send the LOGIN command.
    command = malloc(strlen(LOGIN) + strlen(username) + strlen(password) + 3);
    sprintf(command, "%s %s %s", LOGIN, username, password);
    send_command(sockfd, command);
    free(command);

    // Receive the response.
    printf("%s", receive_response(sockfd));

    // Send the LIST command.
    command = malloc(strlen(LIST) + strlen(mailbox) + 2);
    sprintf(command, "%s \"%s\"", LIST, mailbox);
    send_command(sockfd, command);
    free(command);

    // Receive the response.
    printf("%s", receive_response(sockfd));

    // Send the SELECT command.
    command = malloc(strlen(SELECT) + strlen(mailbox) + 2);
    sprintf(command, "%s \"%s\"", SELECT, mailbox);
    send_command(sockfd, command);
    free(command);

    // Receive the response.
    printf("%s", receive_response(sockfd));

    // Send the FETCH command.
    if (message_number) {
        command = malloc(strlen(FETCH) + strlen(message_number) + 2);
        sprintf(command, "%s %s", FETCH, message_number);
        send_command(sockfd, command);
        free(command);

        // Receive the response.
        printf("%s", receive_response(sockfd));
    }

    // Send the CLOSE command.
    send_command(sockfd, CLOSE);

    // Receive the response.
    printf("%s", receive_response(sockfd));

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}

int connect_to_server(char *hostname, int port) {
    // Get the server's address.
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server.
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&server_address.sin_addr.s_addr,
          server->h_length);
    server_address.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_command(int socket, char *command) {
    // Send the command to the server.
    if (send(socket, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: could not send command\n");
        exit(EXIT_FAILURE);
    }

    // Send a newline character.
    if (send(socket, "\r\n", 2, 0) < 0) {
        fprintf(stderr, "Error: could not send newline character\n");
        exit(EXIT_FAILURE);
    }
}

char *receive_response(int socket) {
    // Receive the response from the server.
    char *response = malloc(THE_ANSWER); //HINT: Let's start with a small buffer to make the puzzle easier.
    int response_length = 0;
    while (1) {
        char buffer[THE_ANSWER];
        int bytes_received = recv(socket, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            fprintf(stderr, "Error: could not receive response\n");
            exit(EXIT_FAILURE);
        }

        // Be ready to expand the buffer if needed to accommodate the whole response.
        if (response_length + bytes_received >= THE_ANSWER) {
            response = realloc(response, response_length + bytes_received + THE_ANSWER);
        }

        // Append the received data to the response.
        memcpy(response + response_length, buffer, bytes_received);
        response_length += bytes_received;

        // Check if the response is complete.
        if (strstr(response, "\r\n.\r\n") != NULL) {
            break;
        }
    }

    // Return the response.
    return response;
}