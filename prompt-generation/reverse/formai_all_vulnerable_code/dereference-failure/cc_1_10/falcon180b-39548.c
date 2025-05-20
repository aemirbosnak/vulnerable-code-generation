//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_error(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main()
{
    struct addrinfo hints, *result, *rp;
    int sfd, s;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int rv;
    int yes = 1;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    if ((rv = getaddrinfo("localhost", "80", &hints, &result))!= 0)
    {
        print_error("getaddrinfo");
    }
    
    for (rp = result; rp!= NULL; rp = rp->ai_next)
    {
        if ((sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
        {
            continue;
        }
        
        if (setsockopt(sfd, IPPROTO_TCP, TCP_NODELAY, (void *)&yes, sizeof(int)) == -1)
        {
            close(sfd);
            continue;
        }
        
        if (connect(sfd, rp->ai_addr, rp->ai_addrlen) == -1)
        {
            close(sfd);
            continue;
        }
        
        break;
    }
    
    if (rp == NULL)
    {
        print_error("connect");
    }
    
    freeaddrinfo(result);
    
    char request[1024] = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
    send(sfd, request, strlen(request), 0);
    
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    
    while ((bytes_received = recv(sfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0)) > 0)
    {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    
    close(sfd);
    
    return 0;
}