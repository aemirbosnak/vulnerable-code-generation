//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>

int main()
{
    printf("Welcome to the FTP Client!\n");
    printf("Please enter the IP address of the FTP server: ");
    char ip_address[100];
    scanf("%s", ip_address);

    printf("Please enter the port number of the FTP server: ");
    int port_number;
    scanf("%d", &port_number);

    printf("Please enter the username for the FTP server: ");
    char username[100];
    scanf("%s", username);

    printf("Please enter the password for the FTP server: ");
    char password[100];
    scanf("%s", password);

    printf("Please enter the command you want to execute on the FTP server: ");
    char command[100];
    scanf("%s", command);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error creating socket!\n");
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(ip_address);
    if (host == NULL)
    {
        printf("Error resolving hostname!\n");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Error connecting to server!\n");
        return -1;
    }

    // Send the username and password to the server
    char login_buffer[100];
    sprintf(login_buffer, "USER %s\r\n", username);
    if (send(sockfd, login_buffer, strlen(login_buffer), 0) < 0)
    {
        printf("Error sending username!\n");
        return -1;
    }

    char password_buffer[100];
    sprintf(password_buffer, "PASS %s\r\n", password);
    if (send(sockfd, password_buffer, strlen(password_buffer), 0) < 0)
    {
        printf("Error sending password!\n");
        return -1;
    }

    // Send the command to the server
    if (send(sockfd, command, strlen(command), 0) < 0)
    {
        printf("Error sending command!\n");
        return -1;
    }

    // Receive the response from the server
    char response_buffer[1000];
    int response_length = recv(sockfd, response_buffer, sizeof(response_buffer), 0);
    if (response_length < 0)
    {
        printf("Error receiving response!\n");
        return -1;
    }

    // Print the response to the console
    printf("%s", response_buffer);

    // Close the socket
    close(sockfd);

    return 0;
}