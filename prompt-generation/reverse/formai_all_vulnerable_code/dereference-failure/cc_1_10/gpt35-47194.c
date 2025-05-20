//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to display error messages
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to retrieve the IP address
bool get_ip_address(char *hostname, char *ip_address) {
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
    
    if ((he = gethostbyname(hostname)) == NULL) {
        return false;
    }
    
    addr_list = (struct in_addr **)he->h_addr_list;
    
    for (i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip_address, inet_ntoa(*addr_list[i]));
        return true;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        error("Missing arguments. Use format: ./httpclient hostname portnumber");
    }
    
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char ip_address[INET_ADDRSTRLEN];
    char buffer[BUFFER_SIZE];
    int socket_desc, bytes_recv;
    struct sockaddr_in server_addr;
    
    if (!get_ip_address(hostname, ip_address)) {
        error("Error retrieving IP address.");
    }
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_desc == -1) {
        error("Error: Could not create socket.");
    }
    
    // Set server address information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port);
    
    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        error("Error: Could not connect to server.");
    }
    
    // Send HTTP request
    char *message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) == -1) {
        error("Error: Could not send message.");
    }
    
    // Receive response from server
    while ((bytes_recv = recv(socket_desc, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s", buffer);
    }
    
    // Close socket
    close(socket_desc);
    
    return 0;
}