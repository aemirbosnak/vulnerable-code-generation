//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

// POP3 command codes
#define USER    "USER"
#define PASS    "PASS"
#define STAT    "STAT"
#define LIST    "LIST"
#define RETR    "RETR"
#define DELE    "DELE"
#define QUIT    "QUIT"

// POP3 response codes
#define OK      "+OK"
#define ERR     "-ERR"

// Maximum length of a POP3 command or response
#define MAX_LINE_LENGTH 512

// Function to send a POP3 command to the server
int send_command(int sockfd, char *command) {
    // Send the command to the server
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return -1;
    }

    // Receive the server's response
    char response[MAX_LINE_LENGTH];
    if (recv(sockfd, response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return -1;
    }

    // Check the server's response
    if (strncmp(response, OK, strlen(OK)) != 0) {
        printf("Error: %s\n", response);
        return -1;
    }

    return 0;
}

// Function to receive a POP3 response from the server
int recv_response(int sockfd, char *response) {
    // Receive the server's response
    if (recv(sockfd, response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return -1;
    }

    // Check for an error response
    if (strncmp(response, ERR, strlen(ERR)) == 0) {
        printf("Error: %s\n", response);
        return -1;
    }

    return 0;
}

// Function to get the number of messages on the server
int get_message_count(int sockfd) {
    // Send the STAT command to the server
    if (send_command(sockfd, STAT) == -1) {
        return -1;
    }

    // Receive the server's response
    char response[MAX_LINE_LENGTH];
    if (recv_response(sockfd, response) == -1) {
        return -1;
    }

    // Parse the server's response
    int message_count;
    sscanf(response, "+OK %d messages", &message_count);

    return message_count;
}

// Function to list the messages on the server
int list_messages(int sockfd) {
    // Send the LIST command to the server
    if (send_command(sockfd, LIST) == -1) {
        return -1;
    }

    // Receive the server's response
    char response[MAX_LINE_LENGTH];
    while (recv_response(sockfd, response) == 0) {
        // Print the message number and size
        int message_number, message_size;
        sscanf(response, "%d %d", &message_number, &message_size);
        printf("Message %d: %d bytes\n", message_number, message_size);
    }

    return 0;
}

// Function to retrieve a message from the server
int retrieve_message(int sockfd, int message_number) {
    // Send the RETR command to the server
    char command[MAX_LINE_LENGTH];
    sprintf(command, "RETR %d", message_number);
    if (send_command(sockfd, command) == -1) {
        return -1;
    }

    // Receive the server's response
    char response[MAX_LINE_LENGTH];
    while (recv_response(sockfd, response) == 0) {
        // Print the message
        printf("%s\n", response);
    }

    return 0;
}

// Function to delete a message from the server
int delete_message(int sockfd, int message_number) {
    // Send the DELE command to the server
    char command[MAX_LINE_LENGTH];
    sprintf(command, "DELE %d", message_number);
    if (send_command(sockfd, command) == -1) {
        return -1;
    }

    return 0;
}

// Function to quit the POP3 session
int quit_session(int sockfd) {
    // Send the QUIT command to the server
    if (send_command(sockfd, QUIT) == -1) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and port number from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the POP3 server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the server's welcome message
    char response[MAX_LINE_LENGTH];
    if (recv_response(sockfd, response) == -1) {
        exit(1);
    }

    // Authenticate with the server
    if (send_command(sockfd, USER " username") == -1) {
        exit(1);
    }
    if (send_command(sockfd, PASS " password") == -1) {
        exit(1);
    }

    // Get the number of messages on the server
    int message_count = get_message_count(sockfd);
    if (message_count == -1) {
        exit(1);
    }

    // List the messages on the server
    if (list_messages(sockfd) == -1) {
        exit(1);
    }

    // Retrieve the first message from the server
    if (retrieve_message(sockfd, 1) == -1) {
        exit(1);
    }

    // Delete the first message from the server
    if (delete_message(sockfd, 1) == -1) {
        exit(1);
    }

    // Quit the POP3 session
    if (quit_session(sockfd) == -1) {
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}