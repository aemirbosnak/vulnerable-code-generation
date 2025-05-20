//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Declare variables and structures
    struct sockaddr_in server_addr;
    struct hostent *he;
    int sock;

    // Ensure correct number of arguments are passed
    if (argc != 2) {
        printf("Usage: ./httpclient <hostname>\n");
        return 1;
    }

    // Resolve hostname to IP address
    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("Error: Cannot resolve hostname\n");
        return 1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("Error: Cannot create socket\n");
        return 1;
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    server_addr.sin_port = htons(80);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Cannot connect to server\n");
        return 1;
    }

    // Send HTTP GET request to server
    char *request = "GET / HTTP/1.1\r\n"
                    "Host: %s\r\n"
                    "Connection: close\r\n\r\n";
    char buffer[1024];
    sprintf(buffer, request, argv[1]);
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Cannot send request to server\n");
        return 1;
    }

    // Receive response from server
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, stdout);
    }

    // Close socket
    if (close(sock) == -1) {
        printf("Error: Cannot close socket\n");
        return 1;
    }

    return 0;
}