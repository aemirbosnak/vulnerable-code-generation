//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Sherlock Holmes
// It was a gloomy day in London and Sherlock Holmes was sitting in his study,
// sipping his tea and tinkering with his computer. He had received a case from
// a client who wanted him to build a HTTP Client. Sherlock accepted the case,
// pulled up his sleeves and started typing away on his keyboard.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket");
        exit(0);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting");
        exit(0);
    }

    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    n = write(sockfd,buffer,strlen(buffer));

    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket");
        exit(0);
    }

    bzero(buffer,256);

    while ((n = read(sockfd,buffer,255)) > 0) {
        printf("%s", buffer);
    }

    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket");
        exit(0);
    }

    close(sockfd);

    return 0;
}
// After a few hours of intense coding and debugging, Sherlock had a working
// HTTP client. He ran the program to make sure everything was working fine.
// The program successfully connected to the server and displayed the response.
// Satisfied with his work, Sherlock sipped his tea and waited for his client's feedback.