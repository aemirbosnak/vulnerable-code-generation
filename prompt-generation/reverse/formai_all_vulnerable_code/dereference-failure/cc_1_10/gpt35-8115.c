//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc , char *argv[])
{
    // Check command line arguments
    if (argc != 4) {
        printf("Usage: ./httpclient <method> <hostname> <port>\n");
        printf("Example: ./httpclient GET example.com 80\n");
        return 1;
    }

    char *method = argv[1];
    char *hostname = argv[2];
    int port = atoi(argv[3]);

    // Create socket
    int sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    printf("Socket created\n");

    // Resolve hostname
    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(hostname)) == NULL) {
        printf("Could not resolve hostname");
        return 1;
    }
    addr_list = (struct in_addr **) he->h_addr_list;
    char ip[16];
    strcpy(ip, inet_ntoa(*addr_list[0]));
    printf("Resolved IP address: %s\n", ip);

    // Connect to server
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("Connect failed");
        return 1;
    }
    printf("Connected\n");

    // Send HTTP request
    char *request = malloc(1024);
    sprintf(request, "%s / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, hostname);
    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("HTTP request sent:\n%s\n", request);

    // Receive HTTP response
    char *response = malloc(1024);
    memset(response, 0, 1024);
    int bytes_received;
    while ((bytes_received = recv(sock, response, 1024, 0)) > 0) {
        printf("Received %d bytes:\n%s\n", bytes_received, response);
        memset(response, 0, 1024);
    }
    if (bytes_received == -1) {
        printf("Receive failed");
        return 1;
    }

    printf("HTTP response received\n");

    free(request);
    free(response);
    close(sock);

    return 0;
}