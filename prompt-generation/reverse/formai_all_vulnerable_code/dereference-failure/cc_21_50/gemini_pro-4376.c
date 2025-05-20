//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21

int main(int argc, char *argv[])
{
    // Check if we have enough arguments
    if (argc != 3)
    {
        printf("Usage: %s <hostname> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and filename from the command line
    char *hostname = argv[1];
    char *filename = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the host
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL)
    {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(FTP_PORT);
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command
    char *user = "USER anonymous\r\n";
    if (send(sockfd, user, strlen(user), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK
    if (strncmp(response, "230", 3) != 0)
    {
        printf("Error: %s", response);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    char *pass = "PASS anonymous@\r\n";
    if (send(sockfd, pass, strlen(pass), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    if (recv(sockfd, response, sizeof(response), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK
    if (strncmp(response, "230", 3) != 0)
    {
        printf("Error: %s", response);
        return EXIT_FAILURE;
    }

    // Send the TYPE command
    char *type = "TYPE I\r\n";
    if (send(sockfd, type, strlen(type), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    if (recv(sockfd, response, sizeof(response), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK
    if (strncmp(response, "200", 3) != 0)
    {
        printf("Error: %s", response);
        return EXIT_FAILURE;
    }

    // Send the PASV command
    char *pasv = "PASV\r\n";
    if (send(sockfd, pasv, strlen(pasv), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    if (recv(sockfd, response, sizeof(response), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK
    if (strncmp(response, "227", 3) != 0)
    {
        printf("Error: %s", response);
        return EXIT_FAILURE;
    }

    // Parse the IP address and port number from the response
    char *ip_address = strtok(response, ",");
    char *port_number = strtok(NULL, ",");

    // Create a new socket for the data connection
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure for the data connection
    struct sockaddr_in data_servaddr;
    memset(&data_servaddr, 0, sizeof(data_servaddr));
    data_servaddr.sin_family = AF_INET;
    data_servaddr.sin_port = htons(atoi(port_number));
    data_servaddr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server
    if (connect(data_sockfd, (struct sockaddr *)&data_servaddr, sizeof(data_servaddr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the RETR command
    char *retr = "RETR ";
    strcat(retr, filename);
    strcat(retr, "\r\n");
    if (send(sockfd, retr, strlen(retr), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    if (recv(sockfd, response, sizeof(response), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK
    if (strncmp(response, "150", 3) != 0)
    {
        printf("Error: %s", response);
        return EXIT_FAILURE;
    }

    // Open a file for writing
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Receive the file data from the server
    char buffer[1024];
    while (1)
    {
        int n = recv(data_sockfd, buffer, sizeof(buffer), 0);
        if (n == -1)
        {
            perror("recv");
            return EXIT_FAILURE;
        }
        else if (n == 0)
        {
            break;
        }
        else
        {
            fwrite(buffer, 1, n, fp);
        }
    }

    // Close the file
    fclose(fp);

    // Send the QUIT command
    char *quit = "QUIT\r\n";
    if (send(sockfd, quit, strlen(quit), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the sockets
    close(sockfd);
    close(data_sockfd);

    return EXIT_SUCCESS;
}