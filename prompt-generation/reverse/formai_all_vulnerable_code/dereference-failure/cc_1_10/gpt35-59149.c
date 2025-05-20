//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s [SERVER_IP_ADDRESS] [SERVER_PORT] [USER_EMAIL]\n", argv[0]);
        return 1;
    }

    char *server_ip_address = argv[1];
    int server_port = atoi(argv[2]);
    char *user_email = argv[3];

    char buffer[BUFFER_SIZE];

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip_address, &server_address.sin_addr) <= 0)
    {
        perror("Invalid server address");
        return 1;
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server at %s:%d\n", server_ip_address, server_port);

    sprintf(buffer, "EHLO %s\r\n", user_email);
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    int quit = 0;
    while (!quit)
    {
        printf("Enter an email address to send to (or enter 'quit' to exit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        strtok(buffer, "\n");
        if (strcmp(buffer, "quit") == 0)
        {
            quit = 1;
            continue;
        }

        sprintf(buffer, "MAIL FROM:<%s>\r\n", user_email);
        send(client_socket, buffer, strlen(buffer), 0);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);

        sprintf(buffer, "RCPT TO:<%s>\r\n", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);

        sprintf(buffer, "DATA\r\n");
        send(client_socket, buffer, strlen(buffer), 0);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);

        printf("Enter the email message (end message with a single period on a line by itself):\n");
        do
        {
            fgets(buffer, BUFFER_SIZE, stdin);
            send(client_socket, buffer, strlen(buffer), 0);
        } while (buffer[0] != '.');

        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    sprintf(buffer, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(client_socket);

    return 0;
}