//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    float download_speed, upload_speed;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];

    if(argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    clock_t start = clock();

    n = write(sockfd, "ping", strlen("ping"));
    if(n < 0)
        error("ERROR writing to socket");

    memset(buffer, 0, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if(n < 0)
        error("ERROR reading from socket");

    clock_t end = clock();

    close(sockfd);

    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    download_speed = (float)((((double)strlen(buffer) * 8) / 1024) / total_time);
    upload_speed = (float)((((double)strlen("ping") * 8) / 1024) / total_time);

    printf("Download speed: %.2f kbps\n", download_speed);
    printf("Upload speed: %.2f kbps\n", upload_speed);

    return 0;
}