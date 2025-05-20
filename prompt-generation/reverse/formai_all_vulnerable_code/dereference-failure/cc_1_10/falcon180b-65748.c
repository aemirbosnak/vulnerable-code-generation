//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define PORT_NUMBER 80

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char *ip;
    int port = PORT_NUMBER;
    int status;
    char buffer[1024];

    if(argc!= 3)
    {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("Error connecting to server\n");
        return 1;
    }

    status = TRUE;
    while(status)
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);

        if(buffer[0] == 'q')
        {
            status = FALSE;
        }
        else
        {
            send(sock, buffer, strlen(buffer), 0);
        }
    }

    close(sock);

    return 0;
}