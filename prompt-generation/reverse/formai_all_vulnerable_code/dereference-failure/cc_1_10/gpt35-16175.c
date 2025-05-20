//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 4096
#define MAX_EMAILS 100

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_address> <port> <user_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int port = atoi(argv[2]);
    char *user_name = argv[3];

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error("Could not create socket");
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(port);

    if (connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    int count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (count < 0) {
        error("Error receiving data");
    }
    printf("%s", buffer);

    // send user name
    char command[MAX_BUFFER_SIZE];
    memset(command, 0, MAX_BUFFER_SIZE);
    sprintf(command, "USER %s\r\n", user_name);
    if (send(sock_fd, command, strlen(command), 0) < 0) {
        error("Error sending data");
    }
    memset(buffer, 0, MAX_BUFFER_SIZE);
    count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (count < 0) {
        error("Error receiving data");
    }
    printf("%s", buffer);

    // send password
    char password[MAX_BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, MAX_BUFFER_SIZE-1, stdin);
    password[strlen(password)-1] = '\0'; // remove newline character
    memset(command, 0, MAX_BUFFER_SIZE);
    sprintf(command, "PASS %s\r\n", password);
    if (send(sock_fd, command, strlen(command), 0) < 0) {
        error("Error sending data");
    }
    memset(buffer, 0, MAX_BUFFER_SIZE);
    count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (count < 0) {
        error("Error receiving data");
    }
    printf("%s", buffer);

    // retrieve email list
    if (send(sock_fd, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
        error("Error sending data");
    }
    memset(buffer, 0, MAX_BUFFER_SIZE);
    count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (count < 0) {
        error("Error receiving data");
    }
    printf("%s", buffer);

    int email_count = 0;
    memset(buffer, 0, MAX_BUFFER_SIZE);
    count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    while (strncmp(buffer, ".\r\n", 3) != 0) {
        email_count++;
        int email_size = atoi(strtok(buffer, " "));
        printf("Email %d size: %d\n", email_count, email_size);
        memset(buffer, 0, MAX_BUFFER_SIZE);
        count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    }

    if (email_count == 0) {
        printf("No emails\n");
        return 0;
    }

    // select email by number
    int email_number;
    printf("Enter email number (1-%d): ", email_count);
    scanf("%d", &email_number);
    if (email_number < 1 || email_number > email_count) {
        printf("Invalid input\n");
        return 0;
    }

    // retrieve selected email
    memset(command, 0, MAX_BUFFER_SIZE);
    sprintf(command, "RETR %d\r\n", email_number);
    if (send(sock_fd, command, strlen(command), 0) < 0) {
        error("Error sending data");
    }
    memset(buffer, 0, MAX_BUFFER_SIZE);
    count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s", buffer);

    memset(buffer, 0, MAX_BUFFER_SIZE);
    count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    while (strncmp(buffer, ".\r\n", 3) != 0) {
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
        count = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    }

    close(sock_fd);
    return 0;
}