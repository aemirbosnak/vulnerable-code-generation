//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
        exit(0);
    }

    struct hostent *server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr, "error: no such host\n");
        exit(0);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("error: couldn't open socket\n");
    }

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("error: couldn't connect\n");
    }

    char *request = "GET / HTTP/1.0\r\nHost: ";
    char *hostname = argv[1];
    int request_size = strlen(request) + strlen(hostname) + 4;
    char *message = calloc(request_size, sizeof(char));
    sprintf(message, "%s%s\r\n\r\n", request, hostname);

    if(send(sockfd, message, request_size, 0) < 0){
        error("error: couldn't send request\n");
    }

    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, 1024, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, stdout);
    }

    free(message);
    close(sockfd);
    return 0;
}