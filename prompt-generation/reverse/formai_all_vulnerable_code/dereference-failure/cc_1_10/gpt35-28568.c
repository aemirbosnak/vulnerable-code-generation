//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAXBUF 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, rv, len, bytes_recv, bytes_sent;
    char hostname[MAXBUF], msg[MAXBUF], buf[MAXBUF];
    struct addrinfo hints, *servinfo, *p;
    struct timeval start, end;
    double time_elapsed;

    if (argc != 2) {
        fprintf(stderr,"Usage: %s <hostname>\n", argv[0]);
        exit(1);
    } else {
        strncpy(hostname, argv[1], MAXBUF);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, "http", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break; // if we get here, we must have connected successfully
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    // Get IP Address of the server
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
    void *addr = &(ipv4->sin_addr);
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);

    printf("Connected to %s\n", ipstr);

    freeaddrinfo(servinfo); // all done with this structure

    printf("Enter Message: ");
    fgets(msg, MAXBUF, stdin);

    // Remove newline from message
    len = strlen(msg);
    if (msg[len-1] == '\n') {
        msg[len-1] = '\0';
    }

    // Start time
    gettimeofday(&start, NULL);

    // Send message
    bytes_sent = send(sockfd, msg, strlen(msg), 0);
    if (bytes_sent == -1) {
        perror("send");
        close(sockfd);
        exit(1);
    }

    // Wait for response
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    select(sockfd + 1, &readfds, NULL, NULL, &tv);

    if (FD_ISSET(sockfd, &readfds)) {
        // Message Received
        bytes_recv = recv(sockfd, buf, MAXBUF-1, 0);
        buf[bytes_recv] = '\0';
        printf("\nResponse: %s\n", buf);
    } else {
        // Timeout
        printf("Timeout: No response received from server\n");
        close(sockfd);
        exit(1);
    }

    // End time
    gettimeofday(&end, NULL);

    // Calculate time elapsed
    time_elapsed = (end.tv_sec - start.tv_sec) +
                  (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("\nTime Elapsed: %f seconds\n", time_elapsed);

    close(sockfd);

    return 0;
}