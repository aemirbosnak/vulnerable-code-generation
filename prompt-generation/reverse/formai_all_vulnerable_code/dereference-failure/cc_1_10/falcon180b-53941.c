//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sock, val = 1;
    struct sockaddr_in serv_addr;
    char send_data[1024];
    char recv_data[1024];
    int n, len;
    struct hostent *server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set socket options
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));

    // Connect to server
    server = gethostbyname("localhost");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Send data
    n = send(sock, "Hello, World!", strlen("Hello, World!"), 0);
    if (n < 0)
    {
        printf("Error sending data\n");
        exit(1);
    }

    // Receive data
    memset(recv_data, 0, sizeof(recv_data));
    n = recv(sock, recv_data, sizeof(recv_data), 0);
    if (n < 0)
    {
        printf("Error receiving data\n");
        exit(1);
    }
    printf("Received data: %s\n", recv_data);

    // Close socket
    close(sock);
    return 0;
}