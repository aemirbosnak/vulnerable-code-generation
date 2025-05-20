//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFSIZE 4096

void error(char* message){
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {

    if(argc != 3){
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        exit(1);
    }

    char *proxyIP = argv[1];
    int proxyPort = atoi(argv[2]);

    int sockfd, connfd; 
    struct sockaddr_in proxy_addr, client_addr;
    int len = sizeof(client_addr);
    char buffer[BUFFSIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("Error creating socket");

    // configure address settings
    bzero(&proxy_addr, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxyPort);

    // bind socket to address
    if(bind(sockfd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0)
        error("Failed to bind socket to proxy address");

    // listen for incoming connections
    if(listen(sockfd, 5) < 0)
        error("Error listening on socket");

    printf("Proxy server running on IP %s and Port %d\n", proxyIP, proxyPort);

    while(1){
        // accept connections
        connfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
        if(connfd < 0)
            error("Error accepting on socket");

        printf("Received connection request from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // create new child process to handle client request
        int pid = fork();
        if(pid == 0){
            // child process
            close(sockfd);

            int serverfd, n;
            struct sockaddr_in server_addr;
            char *hostname = strtok(buffer, " ");
            char *filename;
            char *temp = NULL;
            char *temp2 = NULL;

            // create socket to connect to server
            serverfd = socket(AF_INET, SOCK_STREAM, 0);
            if(serverfd < 0){
                error("Error creating socket");
            }

            // configure address settings
            bzero(&server_addr, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = inet_addr(hostname+7);
            server_addr.sin_port = htons(80);

            // connect to server
            if(connect(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
                error("Error connecting to server");
            }

            // send client request to server
            if(write(serverfd, buffer, strlen(buffer)) < 0){
                error("Error writing to server");
            }

            // relay server response to client
            while((n = read(serverfd, buffer, BUFFSIZE)) > 0){
                write(connfd, buffer, n);
            }

            // close sockets
            close(serverfd);
            close(connfd);
            exit(0);
        }
        else if(pid < 0){
            error("Error forking child process");
        }
        else{
            // parent process
            close(connfd);
        }
    }

    // close socket
    close(sockfd);

    return 0;
}