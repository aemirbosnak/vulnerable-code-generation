//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

// Function to connect to the FTP server using a socket
int connect_to_ftp_server(char *hostname, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed!\n");
        return -1;
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Invalid hostname!\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed!\n");
        return -1;
    }

    printf("Connected to FTP server!\n");
    return sock;
}

// Function to receive data from the FTP server
int receive_data(int sock, char* buffer)
{
    int bytes_received = recv(sock, buffer, 1024, 0);
    if (bytes_received < 0) {
        printf("Error occurred while receiving data!\n");
        return -1;
    }

    buffer[bytes_received] = '\0';
    return bytes_received;
}

int main()
{
    char hostname[] = "localhost";
    int port = 21;

    // Connect to the FTP server
    int sock = connect_to_ftp_server(hostname, port);
    
    // Receive the welcome message from the FTP server
    char buffer[1024];
    receive_data(sock, buffer);
    printf("%s", buffer);

    // Send the login details to the FTP server
    char username[] = "username";
    char password[] = "password";
    char login_message[1024];
    sprintf(login_message, "USER %s\r\nPASS %s\r\n", username, password);
    send(sock, login_message, strlen(login_message), 0);

    // Receive the response to the login message
    receive_data(sock, buffer);
    printf("%s", buffer);

    // Send a command to the FTP server
    char command_message[] = "PWD\r\n";
    send(sock, command_message, strlen(command_message), 0);

    // Receive the response to the command
    receive_data(sock, buffer);
    printf("Current directory: %s", buffer);

    // Close the socket connection
    close(sock);
    return 0;
}