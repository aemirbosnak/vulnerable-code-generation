//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    // Create a socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up the socket address structure
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    
    // Send a message to the server
    char msg[100];
    sprintf(msg, "Message from the client");
    send(sockfd, msg, strlen(msg), 0);
    
    // Receive a message from the server
    char buf[100];
    int nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Received: %s\n", buf);
    }
    
    // Close the socket
    close(sockfd);
    return 0;
}