//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void pop3_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("Error receiving response");
    }
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = getpass("Enter your password: ");

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Fetch the server address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Prepare the server structure
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(110);  // Standard POP3 port

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Receive server greeting
    receive_response(sockfd);

    // Send USER command
    char cmd[BUFFER_SIZE];
    snprintf(cmd, BUFFER_SIZE, "USER %s\r\n", username);
    pop3_command(sockfd, cmd);
    receive_response(sockfd);

    // Send PASS command
    snprintf(cmd, BUFFER_SIZE, "PASS %s\r\n", password);
    pop3_command(sockfd, cmd);
    receive_response(sockfd);

    // Send STAT command to get the number of messages
    pop3_command(sockfd, "STAT\r\n");
    receive_response(sockfd);

    // Send LIST command to list the messages
    pop3_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Interact with user to select email
    printf("Enter the number of the message you want to read: ");
    int msg_number;
    scanf("%d", &msg_number);

    // Send RETR command to retrieve the selected message
    snprintf(cmd, BUFFER_SIZE, "RETR %d\r\n", msg_number);
    pop3_command(sockfd, cmd);
    receive_response(sockfd);

    // Send QUIT command to disconnect from the server
    pop3_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}