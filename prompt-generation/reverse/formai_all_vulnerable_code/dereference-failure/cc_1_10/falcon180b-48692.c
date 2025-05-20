//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if(argc!= 3)
    {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    struct hostent *server = gethostbyname(host);
    if(server == NULL)
    {
        printf("Error resolving hostname\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        printf("Error connecting to host\n");
        exit(1);
    }

    printf("Connected to host\n");

    for(int i = 1; i <= MAX_PORTS; i++)
    {
        if(i!= port)
        {
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, BUFFER_SIZE);

            struct sockaddr_in client_addr;
            memset(&client_addr, 0, sizeof(client_addr));
            client_addr.sin_family = AF_INET;
            client_addr.sin_port = htons(i);
            client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

            int client_sock = socket(AF_INET, SOCK_STREAM, 0);
            if(client_sock == -1)
            {
                printf("Error creating socket\n");
                exit(1);
            }

            if(connect(client_sock, (struct sockaddr *)&client_addr, sizeof(client_addr)) == 0)
            {
                printf("Port %d is open\n", i);
            }
            else
            {
                printf("Port %d is closed\n", i);
            }

            close(client_sock);
        }
    }

    close(sock);
    exit(0);
}