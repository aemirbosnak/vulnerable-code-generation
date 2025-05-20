//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 8192

/* define a struct to hold the request data */
struct request {
    char *method;
    char *resource;
    char *http_version;
};

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];

    /* check for correct number of arguments */
    if (argc < 4) {
        fprintf(stderr,"usage %s hostname port path\n", argv[0]);
        exit(0);
    }

    /* set up the request data */
    char *method = "GET";
    char *resource = argv[3];
    char *http_version = "HTTP/1.1";
    struct request req = { method, resource, http_version };

    /* resolve hostname and get server address */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    /* set up the socket */
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* set up the server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    /* connect to the server */
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* build and send HTTP request */
    char *request_str = malloc(BUFSIZE);
    sprintf(request_str, "%s %s %s\r\nHost: %s\r\n\r\n", req.method, req.resource, req.http_version, argv[1]);
    n = write(sockfd, request_str, strlen(request_str));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* receive and print response */
    bzero(buffer, BUFSIZE);
    while ((n = read(sockfd, buffer, BUFSIZE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFSIZE);
    }
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    /* clean up and close socket */
    free(request_str);
    close(sockfd);
    return 0;
}