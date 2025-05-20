//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define TIMEOUT 5000 // 5 seconds

int main(int argc, char *argv[])
{
    int sock, port;
    struct sockaddr_in server;
    char *ip;
    int opt = 1;

    if(argc!= 3)
    {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(0);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Error creating socket\n");
        exit(0);
    }

    // Set socket options
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) == -1)
    {
        printf("Error setting socket option\n");
        exit(0);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    close(sock);

    return 0;
}