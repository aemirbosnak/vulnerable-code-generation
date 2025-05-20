//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUF_SIZE 1024

char* getIP(char* url) {
    char* ip = NULL;
    struct hostent* hent;
    if ((hent = gethostbyname(url)) == NULL) {
        printf("Couldn't find IP address for %s\n", url);
        return NULL;
    }
    ip = inet_ntoa(*(struct in_addr*)hent->h_addr_list[0]);
    printf("Resolved %s to IP address %s\n", url, ip);
    return ip;
}

void handleRequest(int clientSocket) {
    char buffer[MAX_BUF_SIZE];
    memset(buffer, 0, MAX_BUF_SIZE);
    int bytes = recv(clientSocket, buffer, MAX_BUF_SIZE - 1, 0);
    if (bytes < 0) {
        printf("Error receiving data from client\n");
        exit(1);
    }
    printf("Received request: \n%s\n", buffer);

    char* res = strtok(buffer, " ");
    char* url = strtok(NULL, " ");
    char* protocol = strtok(NULL, "\r\n");
    char* ip = getIP(url);

    if (ip != NULL) {
        int proxySocket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in proxyAddr;
        proxyAddr.sin_family = AF_INET;
        proxyAddr.sin_port = htons(PORT);
        proxyAddr.sin_addr.s_addr = inet_addr(ip);

        if (connect(proxySocket, (struct sockaddr*)&proxyAddr, sizeof(proxyAddr)) < 0) {
            printf("Couldn't connect to proxy server\n");
            exit(1);
        }
        printf("Connected to proxy server at %s:%d\n", ip, PORT);
        if (send(proxySocket, buffer, bytes, 0) < 0) {
            printf("Error sending request to proxy server\n");
            exit(1);
        }

        memset(buffer, 0, MAX_BUF_SIZE);
        if (recv(proxySocket, buffer, MAX_BUF_SIZE - 1, 0) < 0) {
            printf("Error receiving data from proxy server\n");
            exit(1);
        }
        printf("Received response: \n%s\n", buffer);
        if (send(clientSocket, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending response to client\n");
            exit(1);
        }
        close(proxySocket);
    } else {
        printf("Could not proxy request as IP could not be resolved\n");
    }
}

int main() {
    int serverSocket, clientSocket, opt = 1;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }
    printf("Created socket successfully\n");

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        printf("Failed to set socket options\n");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Failed to bind socket\n");
        exit(1);
    }
    printf("Bound socket to %s:%d successfully\n", inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));

    if (listen(serverSocket, 5) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started and waiting for requests...\n");

    while (1) {
        if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }
        printf("Accepted new connection from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        handleRequest(clientSocket);
        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}