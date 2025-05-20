//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 80

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    char *message;
    char server_reply[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }
    puts("Socket created");

    // Resolve hostname
    host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Could not resolve hostname\n");
        return 1;
    }

    // Prepare server address
    server.sin_addr.s_addr = *(unsigned long *) host->h_addr;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        printf("Connection failed\n");
        return 1;
    }
    puts("Connected");

    // Send HTTP request
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed\n");
        return 1;
    }
    puts("Request sent");

    // Receive server reply
    if (recv(sock, server_reply, 2000, 0) < 0)
    {
        printf("Receive failed\n");
        return 1;
    }
    puts("Reply received");

    // Print server reply
    printf("%s\n", server_reply);

    close(sock);
    return 0;
}