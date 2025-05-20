//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>

#define BUFSIZE 1024
#define ERROR -1

int sockfd, clientfd, portno, pid;
char buffer[BUFSIZE];
struct sockaddr_in serv_addr, cli_addr;


void error(char *msg) {
    perror(msg);
    exit(1);
}


void cleanup(int sig) {
    close(sockfd);
    close(clientfd);
    exit(0);
}


int connect_server(char *hostname, int port) {
    int sockfd, rc;
    struct hostent *hp;
    struct sockaddr_in srv_addr;
    
    hp = gethostbyname(hostname);
    if (!hp) {
        return ERROR;
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return ERROR;
    }
    
    bzero((char *)&srv_addr, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    bcopy(hp -> h_addr, (char *)&srv_addr.sin_addr, hp -> h_length);
    
    rc = connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if (rc == -1) {
        close(sockfd);
        return ERROR;
    }
    
    return sockfd;
}


int main(int argc, char *argv[]) {
    signal(SIGINT, cleanup);
    signal(SIGPIPE, cleanup);
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("ERROR opening socket");
    }
    
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        close(sockfd);
        error("ERROR on binding");
    }
    
    listen(sockfd, 5);
    
    printf("Listening on port %d\n", portno);
    
    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        clientfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (clientfd == -1) {
            error("ERROR on accept");
        }
        
        pid = fork();
        if (pid == -1) {
            error("ERROR on fork");
        }
        
        
        if (pid == 0) {
            printf("New client connected, handling request...\n");
            char method[BUFSIZE], uri[BUFSIZE], protocol[BUFSIZE];
            sscanf(buffer, "%s %s %s", method, uri, protocol);
            if (strcmp(method, "GET") != 0) {
                error("This proxy only supports GET requests");
            }
            char *hostname = strtok(&uri[7], "/");
            char *path = strtok(NULL, "");
            int sockfd_remote = connect_server(hostname, 80);
            if (sockfd_remote == ERROR) {
                error("Error connecting to the remote server");
            }
            sprintf(buffer, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
            int bytes = send(sockfd_remote, buffer, strlen(buffer), 0);
            if (bytes == ERROR) {
                error("ERROR writing to socket");
            }
            while ((bytes = recv(sockfd_remote, buffer, BUFSIZE, 0)) > 0) {
                bytes = send(clientfd, buffer, bytes, 0);
                if (bytes == ERROR) {
                    error("ERROR writing to socket");
                }
            }
            close(sockfd_remote);
            close(clientfd);
            printf("Client connection closed\n");
            exit(0);
        }
        
        close(clientfd);
        while (waitpid(-1, NULL, WNOHANG) > 0);
    }
}