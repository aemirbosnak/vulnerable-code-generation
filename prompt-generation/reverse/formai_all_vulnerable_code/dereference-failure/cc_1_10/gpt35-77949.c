//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80

int main()
{
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sock, i, n;
    char buffer[256];
    
    printf("Enter website URL: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Error opening socket");
        exit(1);
    }
    
    server = gethostbyname(buffer);
    if (server == NULL)
    {
        fprintf(stderr, "Error, no such host");
        exit(1);
    }
    
    bzero((char*) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in connecting");
        exit(1);
    }

    printf("\nConnected to website: %s\n\n", buffer);

    bzero(buffer, 256);
    n = recv(sock, buffer, 255, 0);
    if (n < 0)
    {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    close(sock);
    return 0;
}