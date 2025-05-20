//FormAI DATASET v1.0 Category: Email Client ; Style: asynchronous
// Include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_BUF_SIZE 2048
#define SERVER_PORT "25"
#define SERVER_NAME "mail.example.com"
#define CLIENT_DOMAIN "example.com"
#define FROM_ADDRESS "sender@example.com"
#define TO_ADDRESS "receiver@example.com"

// Declare global variables
volatile bool is_connected = false;
int sockfd;

// Declare functions
void sig_handler(int sig);
void send_message(const char *message);
void receive_data();

// Signal handling function
void sig_handler(int sig) {
    printf("Closing client...\n");
    close(sockfd);
    is_connected = false;
    exit(0);
}

// Function to send message to the server
void send_message(const char *message) {
    int len = strlen(message);
    if (send(sockfd, message, len, 0) == -1) {
        perror("send");
        exit(1);
    }
}

// Function to receive data from the server
void receive_data() {
    char buffer[MAX_BUF_SIZE];
    int num_bytes_received;
    do {
        num_bytes_received = recv(sockfd, buffer, MAX_BUF_SIZE-1, 0);
        buffer[num_bytes_received] = '\0';
        printf("%s", buffer);
    } while (num_bytes_received == MAX_BUF_SIZE-1);
}

// Main function
int main(int argc, char *argv[]) {
    // Ignore SIGPIPE signals
    signal(SIGPIPE, SIG_IGN);

    // Get server information
    struct addrinfo hints, *serverinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &serverinfo) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    // Connect to the server
    for (p = serverinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        return 2;
    }
    freeaddrinfo(serverinfo);
    is_connected = true;

    // Set up input/output file descriptors
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    FD_SET(sockfd, &readfds);

    // Send initial message to server
    send_message("EHLO ");
    send_message(CLIENT_DOMAIN);
    send_message("\r\n");

    // Receive welcome message from server
    receive_data();

    // Send MAIL FROM command
    send_message("MAIL FROM:<");
    send_message(FROM_ADDRESS);
    send_message(">\r\n");

    // Receive response from server
    receive_data();

    // Send RCPT TO command
    send_message("RCPT TO:<");
    send_message(TO_ADDRESS);
    send_message(">\r\n");

    // Receive response from server
    receive_data();

    // Send DATA command
    send_message("DATA\r\n");

    // Receive response from server
    receive_data();

    // Read message from user
    char message[MAX_BUF_SIZE];
    printf("Enter your message:\n");
    fgets(message, MAX_BUF_SIZE, stdin);

    // Send message to server
    send_message(message);

    // Send QUIT command
    send_message("QUIT\r\n");

    // Receive response from server
    receive_data();

    // Close connection and exit
    close(sockfd);
    return 0;
}