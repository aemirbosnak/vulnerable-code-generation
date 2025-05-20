//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scalable
// C program for building a simple FTP client
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>

#define BUFFER_SIZE 1024

// Function to handle error
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char** argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char filename[BUFFER_SIZE];

    if(argc < 3)
    {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        error("ERROR opening socket");
    }

    // Get the host
    server = gethostbyname(argv[1]);

    if(server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Set the server address to zero
    bzero((char *)&serv_addr, sizeof(serv_addr));

    // Set the server address properties
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR connecting");
    }

    // Read file name from the user
    printf("Enter the file name: ");
    bzero(filename, BUFFER_SIZE);
    fgets(filename, BUFFER_SIZE, stdin);
    strtok(filename, "\n");     // Remove the newline character

    // Send the file name to the server
    n = write(sockfd, filename, strlen(filename));

    if(n < 0)
    {
        error("ERROR writing to socket");
    }

    // Receive the file from the server
    bzero(buffer, BUFFER_SIZE);
    while((n = read(sockfd, buffer, BUFFER_SIZE)) > 0)
    {
        if(buffer[n-1] == EOF)
            break;

        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }
    printf("\n");

    close(sockfd);
    return 0;
}