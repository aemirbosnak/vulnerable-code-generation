//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

void *ping(void *args) {
    struct sockaddr_in addr;
    struct hostent *host;
    char *hostname;
    char *message;
    char *reply;
    int sockfd, port, n;

    args = (struct sockaddr_in *) args;
    hostname = (char *) args + 1;
    port = *(int *) (args + 4);

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "No such host\n");
        return NULL;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        return NULL;
    }

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&addr.sin_addr.s_addr, host->h_length);
    addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        return NULL;
    }

    message = (char *) malloc(sizeof(char) * 255);
    sprintf(message, "PING %s (%s:%d)\r\n\r\n", hostname, inet_ntoa(addr.sin_addr), port);
    if (write(sockfd, message, strlen(message)) < 0) {
        fprintf(stderr, "Error writing to socket\n");
        return NULL;
    }

    bzero(reply, sizeof(reply));
    n = read(sockfd, reply, sizeof(reply));
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        return NULL;
    }

    if (reply[strlen(reply) - 1]!= '\n') {
        reply[strlen(reply) - 1] = '\0';
    }

    printf("%s\n", reply);

    close(sockfd);
    free(reply);
    free(message);

    return NULL;
}

int main() {
    int i;
    int port;
    char *host;
    struct hostent *host_entry;

    host = "localhost";
    port = 80;

    for (i = 0; i < 10; i++) {
        struct sockaddr_in addr;
        pthread_t thread;

        memset(&addr, 0, sizeof(struct sockaddr_in));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons(port);

        if (pthread_create(&thread, NULL, ping, (void *)&addr)) {
            fprintf(stderr, "Error creating thread\n");
            return -1;
        }

        if (pthread_join(thread, NULL)) {
            fprintf(stderr, "Error joining thread\n");
            return -1;
        }

        if (port == 80) {
            port = 443;
        } else {
            port = 80;
        }
    }

    return 0;
}