//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int server_socket, client_socket, bytes_recv;
    struct sockaddr_in server_address, client_address;
    struct hostent *server_host;
    int port_number;
    char buffer[1024];

    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[1]);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    server_host = gethostbyname("localhost");
    if (server_host == NULL)
    {
        fprintf(stderr, "Error resolving host name\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    bcopy((char *)server_host->h_addr, (char *)&server_address.sin_addr.s_addr, server_host->h_length);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    listen(server_socket, 5);
    printf("Listening on port %d...\n", port_number);

    while (1)
    {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&bytes_recv);
        if (client_socket == -1)
        {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        printf("Connected by %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        while ((bytes_recv = recv(client_socket, buffer, sizeof(buffer), 0)) > 0)
        {
            printf("Received %d bytes from %s:%d: %s\n", bytes_recv, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}