//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#define PORT 8080
#define MAX_MSG_SIZE 1024

// Global variables
int sockfd;
struct sockaddr_in serv_addr;
char recv_msg[MAX_MSG_SIZE];
char send_msg[MAX_MSG_SIZE];

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR opening socket");

    // Set up address struct
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind to the socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0)
        error("ERROR on listen");

    printf("Waiting for connection...\n");

    int newsockfd;
    while ((newsockfd = accept(sockfd, (struct sockaddr *)NULL, NULL)) > 0)
    {
        printf("Connected with %s\n", inet_ntoa(serv_addr.sin_addr));

        // Receive message from client
        recv(newsockfd, recv_msg, MAX_MSG_SIZE, 0);

        // Parse message
        char *token;
        token = strtok(recv_msg, ",");
        int dir = atoi(token);
        token = strtok(NULL, ",");
        int speed = atoi(token);

        // Send message to client
        sprintf(send_msg, "Direction: %d, Speed: %d", dir, speed);
        send(newsockfd, send_msg, strlen(send_msg), 0);

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}