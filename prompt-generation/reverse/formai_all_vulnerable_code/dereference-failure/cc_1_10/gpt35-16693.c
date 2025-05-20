//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to handle errors
void error(char *msg)
{
    perror(msg);
    exit(0);
}

// Main function
int main(int argc, char *argv[])
{
    int sockfd, portno, n, bytesReceived = 0;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256]; // to store messages
    char fileBuffer[1024]; // to store file data

    // Check if enough arguments have been provided
    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // Get port number and create socket
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Get server details
    server = gethostbyname(argv[1]);
    if (server == NULL)
        error("ERROR, no such host");

    // Set up server address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Display welcome message from server
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Loop to handle commands
    while (1)
    {
        printf("Enter command: ");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        // Check for quit command
        if (strncmp(buffer, "quit", 4) == 0)
        {
            printf("Exiting...\n");
            break;
        }

        // Send command to server
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");

        // Handle list command
        if (strncmp(buffer, "list", 4) == 0)
        {
            bzero(buffer, 256);
            n = read(sockfd, buffer, 255);
            if (n < 0)
                error("ERROR reading from socket");
            printf("%s\n", buffer);
        }

        // Handle get command
        if (strncmp(buffer, "get", 3) == 0)
        {
            char *filename = strtok(buffer + 4, "\n");
            FILE *fp = fopen(filename, "wb");

            // Receive file data
            while ((n = read(sockfd, fileBuffer, 1024)) > 0)
            {
                fwrite(fileBuffer, sizeof(char), n, fp);
                bytesReceived += n;
            }

            // Check for errors during file transfer
            if (n < 0)
            {
                error("ERROR reading from socket");
            }

            printf("File received successfully. Bytes received = %d\n", bytesReceived);
            fclose(fp);
        }
    }

    // Close socket and exit
    close(sockfd);
    return 0;
}