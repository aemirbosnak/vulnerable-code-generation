//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define BUFF_SIZE 1024

void receive_data(int socket_fd, char *buff, char *message)
{
    memset(buff, 0, BUFF_SIZE);
    if (recv(socket_fd, buff, BUFF_SIZE, 0) < 0)
    {
        printf("Failed to receive %s\n", message);
        exit(EXIT_FAILURE);
    }
}

void send_data(int socket_fd, char *data, char *message)
{
    if (send(socket_fd, data, strlen(data), 0) < 0)
    {
        printf("Failed to send %s\n", message);
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Specify server address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110);
    if (inet_pton(AF_INET, "pop.server.com", &server_address.sin_addr) < 0)
    {
        printf("Failed to convert server address\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }
    receive_data(socket_fd, NULL, "connection message");

    // Log in
    char username[100], password[100];
    printf("Enter username: ");
    fgets(username, 100, stdin);
    printf("Enter password: ");
    fgets(password, 100, stdin);
    send_data(socket_fd, "USER ", "username");
    send_data(socket_fd, username, "username");
    send_data(socket_fd, "\r\n", "username");
    receive_data(socket_fd, NULL, "username response");
    send_data(socket_fd, "PASS ", "password");
    send_data(socket_fd, password, "password");
    send_data(socket_fd, "\r\n", "password");
    receive_data(socket_fd, NULL, "password response");

    // List emails
    send_data(socket_fd, "LIST\r\n", "list command");
    char buff[BUFF_SIZE];
    receive_data(socket_fd, buff, "list response");
    printf("Emails:\n%s\n", buff);

    // Retrieve email
    int email_id;
    printf("Enter email ID to retrieve: ");
    scanf("%d", &email_id);
    char command[50];
    sprintf(command, "RETR %d\r\n", email_id);
    send_data(socket_fd, command, "retrieve command");
    receive_data(socket_fd, buff, "retrieve response");
    printf("Email:\n%s\n", buff);

    // Close socket
    if (close(socket_fd) < 0)
    {
        printf("Failed to close socket\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}