//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h> 

#define MAX_BUFF 1024

int main(int argc, char *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFF] = {0};
    
    // Check user input
    if (argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return -1;
    }
    
    // Initiate socket connection
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <=0 ) {
        printf("Invalid address or address not supported.\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }
    
    // Send a request to the server
    char *request = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Failed to send request.\n");
        return -1;
    }

    // Receive response from the server & print to stdout
    while ((valread = read(sock, buffer, MAX_BUFF)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUFF);
    }

    if (valread < 0) {
        printf("Failed to receive response.\n");
        return -1;
    }

    return 0;
}