//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024
#define POP3_PORT 110

// Function to get the hostname from the user
char *get_hostname() {
    char *hostname = malloc(MAX_LINE_SIZE);
    if (!hostname) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("Enter the hostname of the POP3 server: ");
    fgets(hostname, MAX_LINE_SIZE, stdin);

    // Remove the newline character from the hostname
    hostname[strcspn(hostname, "\n")] = '\0';

    return hostname;
}

// Function to get the username from the user
char *get_username() {
    char *username = malloc(MAX_LINE_SIZE);
    if (!username) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("Enter your POP3 username: ");
    fgets(username, MAX_LINE_SIZE, stdin);

    // Remove the newline character from the username
    username[strcspn(username, "\n")] = '\0';

    return username;
}

// Function to get the password from the user
char *get_password() {
    char *password = malloc(MAX_LINE_SIZE);
    if (!password) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("Enter your POP3 password: ");
    fgets(password, MAX_LINE_SIZE, stdin);

    // Remove the newline character from the password
    password[strcspn(password, "\n")] = '\0';

    return password;
}

// Function to send a command to the POP3 server
int send_command(int sockfd, char *command) {
    int n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        perror("send");
        return -1;
    }

    return n;
}

// Function to receive a line of text from the POP3 server
int receive_line(int sockfd, char *buffer) {
    int n = recv(sockfd, buffer, MAX_LINE_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        return -1;
    }

    buffer[n] = '\0';

    return n;
}

// Function to retrieve the email messages from the POP3 server
int retrieve_messages(int sockfd, char *username, char *password) {
    // Send the USER command
    if (send_command(sockfd, "USER ") < 0) {
        return -1;
    }

    // Send the username
    if (send_command(sockfd, username) < 0) {
        return -1;
    }

    // Receive the response from the server
    char buffer[MAX_LINE_SIZE];
    if (receive_line(sockfd, buffer) < 0) {
        return -1;
    }

    // Check if the response is positive
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buffer);
        return -1;
    }

    // Send the PASS command
    if (send_command(sockfd, "PASS ") < 0) {
        return -1;
    }

    // Send the password
    if (send_command(sockfd, password) < 0) {
        return -1;
    }

    // Receive the response from the server
    if (receive_line(sockfd, buffer) < 0) {
        return -1;
    }

    // Check if the response is positive
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buffer);
        return -1;
    }

    // Send the LIST command
    if (send_command(sockfd, "LIST\n") < 0) {
        return -1;
    }

    // Receive the response from the server
    int message_count = 0;
    while (receive_line(sockfd, buffer) > 0) {
        // Check if the response is positive
        if (strncmp(buffer, "+OK", 3) != 0) {
            fprintf(stderr, "Error: %s\n", buffer);
            return -1;
        }

        // Get the message size
        int message_size = atoi(buffer + 4);

        // Receive the message
        char *message = malloc(message_size + 1);
        if (!message) {
            perror("malloc");
            return -1;
        }

        int n = recv(sockfd, message, message_size, 0);
        if (n < 0) {
            perror("recv");
            free(message);
            return -1;
        }

        message[n] = '\0';

        // Print the message
        printf("Message %d: %s\n", message_count + 1, message);

        free(message);
        message_count++;
    }

    // Send the QUIT command
    if (send_command(sockfd, "QUIT\n") < 0) {
        return -1;
    }

    return message_count;
}

int main(int argc, char *argv[]) {
    // Get the hostname from the user
    char *hostname = get_hostname();

    // Get the username from the user
    char *username = get_username();

    // Get the password from the user
    char *password = get_password();

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the POP3 server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Retrieve the email messages from the POP3 server
    int message_count = retrieve_messages(sockfd, username, password);
    if (message_count < 0) {
        exit(EXIT_FAILURE);
    }

    printf("Retrieved %d message(s).\n", message_count);

    // Close the socket
    close(sockfd);

    // Free the hostname, username, and password
    free(hostname);
    free(username);
    free(password);

    return EXIT_SUCCESS;
}