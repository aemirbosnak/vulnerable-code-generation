//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// function to create the proxy connection
void createProxyConnection(int connectedSocket, char *destinationHost, int destinationPort) {
    int proxySocket;
    struct sockaddr_in proxyAddr;

    // create socket for the proxy server
    proxySocket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxySocket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // initialize the proxy server address
    memset(&proxyAddr, 0, sizeof(proxyAddr));
    proxyAddr.sin_family = AF_INET;
    proxyAddr.sin_port = htons(destinationPort);
    proxyAddr.sin_addr.s_addr = inet_addr(destinationHost);

    // connect to the proxy server
    if (connect(proxySocket, (struct sockaddr*)&proxyAddr, sizeof(proxyAddr)) == -1) {
        perror("Error connecting to proxy server");
        exit(1);
    }

    // echo the received request to the console
    char buffer[BUFFER_SIZE];
    int bytesRead = recv(connectedSocket, buffer, BUFFER_SIZE, 0);
    if (bytesRead == -1) {
        perror("Error receiving data from client");
        exit(1);
    }
    buffer[bytesRead] = '\0';
    printf("Received request from client:\n%s\n", buffer);

    // forward the request to the proxy server
    if (send(proxySocket, buffer, bytesRead, 0) == -1) {
        perror("Error sending data to proxy server");
        exit(1);
    }

    // read the response from the proxy server and send it back to the client
    while (1) {
        bytesRead = recv(proxySocket, buffer, BUFFER_SIZE, 0);
        if (bytesRead == -1) {
            perror("Error receiving data from proxy server");
            exit(1);
        }
        if (bytesRead == 0) break; // end of file

        // send the data back to the client
        if (send(connectedSocket, buffer, bytesRead, 0) == -1) {
            perror("Error sending data to client");
            exit(1);
        }
    }

    // close the sockets
    close(proxySocket);
    close(connectedSocket);
}

int main(int argc, char *argv[]) {
    int listenSocket, connectedSocket, destinationPort;
    struct sockaddr_in listenAddr;
    char *destinationHost;

    // check command-line arguments
    if (argc != 3) {
        printf("Usage: %s <listenPort> <destinationHost>:<destinationPort>\n", argv[0]);
        exit(1);
    }

    // parse the destination host and port
    char *destination = strtok(argv[2], ":");
    destinationHost = strdup(destination);
    destination = strtok(NULL, ":");
    destinationPort = atoi(destination);

    // create socket for the listening server
    listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // initialize the listening server address
    memset(&listenAddr, 0, sizeof(listenAddr));
    listenAddr.sin_family = AF_INET;
    listenAddr.sin_port = htons(atoi(argv[1]));
    listenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind the socket to the listening address
    if (bind(listenSocket, (struct sockaddr*)&listenAddr, sizeof(listenAddr)) == -1) {
        perror("Error binding socket to address");
        exit(1);
    }

    // listen for connections
    if (listen(listenSocket, 10) == -1) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Proxy server started on port %s, forwarding to %s:%d\n", argv[1], destinationHost, destinationPort);

    // accept and handle connections
    while (1) {
        connectedSocket = accept(listenSocket, NULL, NULL);
        if (connectedSocket == -1) {
            perror("Error accepting connection");
            continue;
        }

        // create a new process to handle the connection
        int pid = fork();
        if (pid == -1) {
            perror("Error creating process");
            exit(1);
        }
        if (pid == 0) { // child process
            close(listenSocket);
            createProxyConnection(connectedSocket, destinationHost, destinationPort);
            exit(0);
        } else { // parent process
            close(connectedSocket);
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}