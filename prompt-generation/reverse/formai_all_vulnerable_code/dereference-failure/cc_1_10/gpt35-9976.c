//FormAI DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    struct sockaddr_in server;
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sockfd, rc, len;
    char buffer[4096];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = AI_PASSIVE; 

    rc = getaddrinfo(NULL, "8080", &hints, &result);
    if (rc != 0) 
    {
        printf("Error: getaddrinfo() failed\n");
        return -1;
    }
    
    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1)
        {
            continue;
        }

        if (bind(sockfd, rp->ai_addr, rp->ai_addrlen) == 0)
        {
            printf("Bind successful\n");
            break;
        }

        close(sockfd);
    }

    if (rp == NULL)
    {
        printf("Error: bind() failed\n");
        return -1;
    }
    
    freeaddrinfo(result);

    if (listen(sockfd, 10) == -1)
    {
        printf("Error: listen() failed\n");
    }

    while (1)
    {
        int clientfd;
        clientfd = accept(sockfd, (struct sockaddr *)&server, (socklen_t *)&len);
        printf("Accepted connection from %s:%d\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port));
        
        memset(buffer, 0, sizeof(buffer));
        if (recv(clientfd, buffer, sizeof(buffer), 0) == -1)
        {
            printf("Error: recv() failed\n");
        }
        else
        {
            printf("Received message: %s\n", buffer);
        }
        
        close(clientfd);
    }

    close(sockfd);

    return 0;
}