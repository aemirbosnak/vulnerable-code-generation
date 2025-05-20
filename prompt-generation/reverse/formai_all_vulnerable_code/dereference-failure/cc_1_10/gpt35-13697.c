//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Usage: ./smtp_client <server address> <port number>\n");
        return -1;
    }

    // Creating a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Socket creation failed!");
        return -1;
    }

    // Resolving server host name to its IP address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host exists\n");
        return -1;
    }

    // Building server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connecting to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed!");
        return -1;
    }

    char buffer[BUFFER_SIZE];

    // Reading greeting message from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Sending HELO command
    char helo_cmd[BUFFER_SIZE];
    sprintf(helo_cmd, "HELO %s\r\n", argv[1]);
    send(client_socket, helo_cmd, strlen(helo_cmd), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Sending MAIL FROM command
    char mail_from[BUFFER_SIZE];
    printf("Enter sender email address: ");
    fgets(mail_from, BUFFER_SIZE, stdin);
    strtok(mail_from, "\n");
    sprintf(buffer, "MAIL FROM: <%s>\r\n", mail_from);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Sending RCPT TO command
    char mail_to[BUFFER_SIZE];
    printf("Enter recipient email address: ");
    fgets(mail_to, BUFFER_SIZE, stdin);
    strtok(mail_to, "\n");
    sprintf(buffer, "RCPT TO: <%s>\r\n", mail_to);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Sending DATA command
    send(client_socket, "DATA\r\n", strlen("DATA\r\n"), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Sending email message
    char message[BUFFER_SIZE];
    printf("Enter email message: ");
    fgets(message, BUFFER_SIZE, stdin);
    strtok(message, "\n");
    sprintf(buffer, "%s\r\n.\r\n", message);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Sending QUIT command
    send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    // Closing connection
    close(client_socket);

    return 0;
}