//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>

#define BUFFER_SIZE 1024   // Size of the buffer for sending and receiving data

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    fd_set readfds;          // Set of file descriptors for select()
    int max_fd;              // Maximum file descriptor for select()
    int activity;            // Return value of select()
    char buffer[BUFFER_SIZE]; // Buffer for sending and receiving data

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        perror("Error finding host");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    {
        perror("Error connecting");
        exit(1);
    }

    while (1)
    {
        // Clear the set of file descriptors
        FD_ZERO(&readfds);

        // Add the socket file descriptor to the set
        FD_SET(sockfd, &readfds);
        max_fd = sockfd;
        
        // Wait for activity on any of the file descriptors in the set
        activity = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0)
        {
            perror("Error in select");
            exit(1);
        }

        // Check if there is activity on the socket file descriptor
        if (FD_ISSET(sockfd, &readfds))
        {
            // Receive data from the server
            bzero(buffer, BUFFER_SIZE);
            n = read(sockfd, buffer, BUFFER_SIZE);
            if (n < 0)
            {
                perror("Error reading from socket");
                exit(1);
            }
            printf("Received data from server: %s\n", buffer);

            // Send data to the server
            bzero(buffer, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE, stdin);
            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0)
            {
                perror("Error writing to socket");
                exit(1);
            }
        }
    }

    close(sockfd);
    return 0;
}