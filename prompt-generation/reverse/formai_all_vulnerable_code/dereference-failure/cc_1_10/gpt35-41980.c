//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int open_socket(char *server_name, char *port) {
    struct addrinfo hints, *results, *rp;
    int sockfd, errorcode;

    // Initialize hints structure
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info
    errorcode = getaddrinfo(server_name, port, &hints, &results);
    if (errorcode != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errorcode));
        exit(EXIT_FAILURE);
    }

    // Try each address until we successfully connect
    for (rp = results; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }

        close(sockfd);
    }

    if (rp == NULL) {
        fprintf(stderr, "Could not connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(results);
    return sockfd;
}

int receive_response(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = 0, response_code = 0;

    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "Error receiving response\n");
        exit(EXIT_FAILURE);
    }

    sscanf(buffer, "%d", &response_code);
    return response_code;
}

void send_command(int sockfd, char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error sending command\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    int sockfd, response_code;
    char user_agent[MAX_BUFFER_SIZE], buffer[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE];
    char command[MAX_BUFFER_SIZE];

    // Set user agent
    sprintf(user_agent, "User-Agent: POP3-Client/1.0");

    // Connect to server
    sockfd = open_socket("pop.gmail.com", "995");

    // Receive banner message
    receive_response(sockfd);

    // Login
    sprintf(username, "USER %s\r\n", "example@gmail.com");
    sprintf(password, "PASS %s\r\n", "password");
    send_command(sockfd, username);
    receive_response(sockfd);
    send_command(sockfd, password);
    response_code = receive_response(sockfd);

    if (response_code != 0) {
        fprintf(stderr, "Login failed\n");
        exit(EXIT_FAILURE);
    }

    // List messages
    send_command(sockfd, "LIST\r\n");
    response_code = receive_response(sockfd);

    if (response_code != 0) {
        fprintf(stderr, "Error listing messages\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        if (strstr(buffer, "quit") != NULL) {
            break;
        }

        // Get message number
        int message_number;
        sscanf(buffer, "%d", &message_number);

        // Retrieve message
        sprintf(command, "RETR %d\r\n", message_number);
        send_command(sockfd, command);
        response_code = receive_response(sockfd);

        if (response_code != 0) {
            fprintf(stderr, "Error retrieving message\n");
            exit(EXIT_FAILURE);
        }

        // Receive message data
        while (1) {
            int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }
            fwrite(buffer, 1, bytes_received, stdout);
        }
    }

    // Logout
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    close(sockfd);
    return 0;
}