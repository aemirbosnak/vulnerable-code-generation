//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, valread, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Convert hostname to IP
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Set up the server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    int t1 = time(NULL);
    int t2 = time(NULL);
    int time_delta = 0;

    while (1) {
        time_delta = t2 - t1;
        t1 = t2;

        printf("Current temperature: %d\n", time_delta);
        sleep(1);

        valread = read(sockfd, &time_delta, sizeof(int));
        if (valread < 0) {
            perror("read() failed");
            exit(1);
        }
    }

    return 0;
}