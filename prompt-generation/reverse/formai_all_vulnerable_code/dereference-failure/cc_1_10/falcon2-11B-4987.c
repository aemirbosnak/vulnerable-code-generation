//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Function to send data to client
void sendData(int sockfd, char *data) {
    send(sockfd, data, strlen(data), 0);
}

// Function to receive data from client
char* receiveData(int sockfd) {
    char buffer[1024];
    int n;
    
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        return NULL;
    }
    
    return buffer;
}

// Function to handle client requests
void handleRequest(int sockfd, char *request) {
    if (strstr(request, "GET /index.html")) {
        char indexHtml[1024];
        sprintf(indexHtml, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>");
        sendData(sockfd, indexHtml);
    } else if (strstr(request, "GET /about.html")) {
        char aboutHtml[1024];
        sprintf(aboutHtml, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>About Page</h1></body></html>");
        sendData(sockfd, aboutHtml);
    } else {
        char errorHtml[1024];
        sprintf(errorHtml, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>");
        sendData(sockfd, errorHtml);
    }
}

// Function to create a new socket and bind it to a port
int createSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);
    
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    return sockfd;
}

// Function to accept connections from clients
int acceptConnections(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    
    char request[1024];
    char *requestData = receiveData(client_sockfd);
    if (requestData == NULL) {
        return 0;
    }
    
    handleRequest(client_sockfd, requestData);
    
    return 1;
}

// Function to start the server and listen for connections
void startServer() {
    int sockfd = createSocket();
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    listen(sockfd, 5);
    
    while (1) {
        acceptConnections(sockfd);
    }
}

int main() {
    startServer();
    return 0;
}