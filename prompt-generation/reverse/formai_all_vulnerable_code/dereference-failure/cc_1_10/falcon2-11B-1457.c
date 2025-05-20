//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/select.h>

void usage(const char *prog)
{
    printf("Usage: %s [-h] [-p port]\n", prog);
}

int main(int argc, char *argv[])
{
    int sockfd, new_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    struct hostent *server;
    int optval = 1;

    if (argc < 2)
    {
        usage(argv[0]);
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        usage(argv[0]);
        return 0;
    }
    else if (strcmp(argv[1], "-p") == 0)
    {
        int port;

        if (sscanf(argv[2], "%d", &port)!= 1)
        {
            usage(argv[0]);
            return 0;
        }

        optval = 1;
        new_socket = socket(AF_INET, SOCK_STREAM, 0);

        if (new_socket == -1)
        {
            fprintf(stderr, "Failed to create socket.\n");
            return 1;
        }

        bzero((char *) &server_addr, sizeof(server_addr));

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(new_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        {
            fprintf(stderr, "Failed to bind socket.\n");
            return 1;
        }

        if (listen(new_socket, 5) < 0)
        {
            fprintf(stderr, "Failed to listen on socket.\n");
            return 1;
        }

        printf("Server is ready to accept connections.\n");

        for (;;)
        {
            socklen_t len = sizeof(client_addr);
            new_socket = accept(new_socket, (struct sockaddr *) &client_addr, &len);

            if (new_socket < 0)
            {
                fprintf(stderr, "Failed to accept connection.\n");
                return 1;
            }

            printf("Accepted connection from client with IP address %s and port %d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            for (;;)
            {
                char buffer[256];
                int len;

                len = read(new_socket, buffer, sizeof(buffer));

                if (len <= 0)
                {
                    printf("Connection closed by client.\n");
                    break;
                }

                write(new_socket, buffer, len);
            }

            close(new_socket);
        }
    }
    else
    {
        usage(argv[0]);
        return 0;
    }
}