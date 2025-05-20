//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char username[50];
char password[50];

void authenticate(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    printf("%s\n", buffer);

    bzero(buffer, BUFFER_SIZE);
    printf("Enter your username: ");
    fgets(username, 50, stdin);

    char *newline = strchr(username, '\n');
    if (newline) {
        *newline = '\0';
    }

    send(sockfd, username, strlen(username), 0);

    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    memset(password, 0, sizeof(password));
    printf("Enter your password: ");
    fgets(password, 50, stdin);

    newline = strchr(password, '\n');
    if (newline) {
        *newline = '\0';
    }

    send(sockfd, password, strlen(password), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (strcmp(buffer, "+OK Logged in.\r\n") != 0) {
        printf("Invalid credentials.\n");
        exit(1);
    }
}

void list(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}

void retrieve(int sockfd, int message_id) {
    char buffer[BUFFER_SIZE];
    char command[50];
    snprintf(command, 50, "RETR %d\r\n", message_id);
    send(sockfd, command, strlen(command), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <email>\n", argv[0]);
        return 1;
    }

    const char* hostname = argv[1];
    int port = atoi(argv[2]);
    const char* email = argv[3];

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: No such host.\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to server.\n");
        return 1;
    }

    // Authenticate
    authenticate(sockfd);

    // List emails
    send(sockfd, "LIST\r\n", 6, 0);
    list(sockfd);

    // Retrieve email
    int message_id;
    printf("Enter the ID of the message you want to retrieve: ");
    scanf("%d", &message_id);
    retrieve(sockfd, message_id);

    close(sockfd);

    return 0;
}