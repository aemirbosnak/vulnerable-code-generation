//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[1024];
    struct hostent *server;

    if (gethostname(buf, 1024) == -1) {
        perror("gethostname");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 2;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(20);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 3;
    }

    printf("Enter file name to upload (or 'quit' to quit): ");
    fgets(buf, sizeof(buf), stdin);

    if (strcmp(buf, "quit") == 0) {
        printf("Closing connection...\n");
        close(sockfd);
        return 0;
    }

    printf("Enter file to upload: ");
    fflush(stdin);
    n = read(0, buf, sizeof(buf));
    buf[n] = '\0';
    printf("Uploading %s...\n", buf);

    if (write(sockfd, buf, n) < 0) {
        perror("write");
        return 4;
    }

    printf("File uploaded successfully.\n");

    close(sockfd);
    return 0;
}