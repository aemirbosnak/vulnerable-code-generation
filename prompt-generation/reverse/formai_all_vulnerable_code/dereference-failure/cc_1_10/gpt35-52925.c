//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct hostent *server;
	struct sockaddr_in serv_addr;
	char buffer[BUF_SIZE];
	
	if (argc < 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
	
	portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
	
	server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

	bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
	
	char *message = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
	
	if (send(sockfd, message, strlen(message), 0) == -1) {
        error("ERROR sending message");
    }

    while ((n = recv(sockfd, buffer, BUF_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    if (n < 0) {
        error("ERROR receiving message");
    }
	
    close(sockfd);
    return EXIT_SUCCESS;
}