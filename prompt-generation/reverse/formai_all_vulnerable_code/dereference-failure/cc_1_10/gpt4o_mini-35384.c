//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 110 // POP3 port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

char *read_response(int sockfd) {
    static char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    return buffer;
}

void pop3_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    // User login
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    printf("%s", read_response(sockfd));

    // Pass login
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    printf("%s", read_response(sockfd));
}

void fetch_email_list(int sockfd) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "LIST");
    send_command(sockfd, command);
    printf("%s", read_response(sockfd));
}

void fetch_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d", email_number);
    send_command(sockfd, command);
    printf("%s", read_response(sockfd));
}

void disconnect_pop3(int sockfd) {
    send_command(sockfd, "QUIT");
    printf("%s", read_response(sockfd));
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Create socket
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting");
    }

    // Read server welcome message
    printf("%s", read_response(sockfd));

    // Login to POP3
    pop3_login(sockfd, username, password);

    // Fetch email list
    fetch_email_list(sockfd);

    // Fetch first email (if available)
    fetch_email(sockfd, 1);

    // Disconnect from POP3
    disconnect_pop3(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}