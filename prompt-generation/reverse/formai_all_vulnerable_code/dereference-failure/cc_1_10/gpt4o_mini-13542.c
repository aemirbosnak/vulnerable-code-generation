//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    while (read(sockfd, buffer, BUFFER_SIZE - 1) > 0) {
        printf("%s", buffer);
        if (buffer[strlen(buffer) - 1] == '\n') {
            break;
        }
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    read_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void list_messages(int sockfd) {
    send_command(sockfd, "LIST");
    read_response(sockfd);
}

void retrieve_message(int sockfd, const char *message_id) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %s", message_id);
    send_command(sockfd, command);
    read_response(sockfd);
}

void quit(int sockfd) {
    send_command(sockfd, "QUIT");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_server(hostname);
    if (sockfd == -1) {
        return 1;
    }

    read_response(sockfd);
    
    login(sockfd, username, password);
    
    list_messages(sockfd);
    
    char message_id[8];
    printf("Enter the message ID to retrieve: ");
    fgets(message_id, sizeof(message_id), stdin);
    message_id[strcspn(message_id, "\n")] = 0;  // Remove newline character
    retrieve_message(sockfd, message_id);
    
    quit(sockfd);

    return 0;
}