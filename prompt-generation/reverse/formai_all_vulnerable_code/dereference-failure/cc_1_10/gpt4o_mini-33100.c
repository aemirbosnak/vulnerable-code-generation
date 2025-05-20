//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void connect_to_pop3_server(const char *hostname, int port, int *sockfd) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Could not resolve hostname");
        exit(EXIT_FAILURE);
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to POP3 server failed");
        exit(EXIT_FAILURE);
    }
}

void send_command(int sockfd, const char *command, char *response) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0); // POP3 requires CRLF for the end of command
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Server Response: %s", response);
}

void retrieve_mail(int sockfd) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    int msg_count;

    send_command(sockfd, "USER your_username", response);
    send_command(sockfd, "PASS your_password", response);
    send_command(sockfd, "STAT", response); // Get number of messages

    // Parse the message count from response
    sscanf(response, "+OK %d", &msg_count);
    printf("Total Messages: %d\n", msg_count);

    for (int i = 1; i <= msg_count; ++i) {
        snprintf(command, sizeof(command), "RETR %d", i);
        send_command(sockfd, command, response);
        printf("Message %d:\n%s\n", i, response);
    }

    send_command(sockfd, "QUIT", response);
}

int main() {
    int sockfd;
    const char *pop3_server = "pop.example.com"; // Enter the POP3 server you want to connect to

    printf("Welcome to the Mind-Bending POP3 Client!\n");
    
    connect_to_pop3_server(pop3_server, POP3_PORT, &sockfd);
    printf("Connected to POP3 server: %s\n", pop3_server);
    
    retrieve_mail(sockfd);

    close(sockfd);
    printf("Disconnected from POP3 server. Goodbye!\n");

    return 0;
}