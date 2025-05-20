//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
#define CONFIG_FILE "config.txt"

int read_config(int *port, int *interval, char *host) {
    FILE *fp;
    char line[50];

    if ((fp = fopen(CONFIG_FILE, "r")) == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "port=", 5) == 0) {
            *port = atoi(&line[5]);
        } else if (strncmp(line, "interval=", 9) == 0) {
            *interval = atoi(&line[9]);
        } else if (strncmp(line, "host=", 5) == 0) {
            strcpy(host, &line[5]);
            host[strlen(host) - 1] = 0; //remove newline
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    int interval = 5, port = 1234, sockfd;
    char host[50] = "127.0.0.1", buf[BUFSIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int optval = 1;

    if (read_config(&port, &interval, host) < 0) {
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        return 1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host as \"%s\"\n", host);
        return 1;
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    while (1) {
        sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
        if (write(sockfd, buf, strlen(buf)) < 0) {
            perror("write");
            break;
        }

        memset(buf, 0, sizeof(buf));
        if (read(sockfd, buf, BUFSIZE) < 0) {
            perror("read");
            break;
        }

        printf("Bytes received: %d\n", (int)strlen(buf));

        sleep(interval);
    }

    close(sockfd);
    return 0;
}