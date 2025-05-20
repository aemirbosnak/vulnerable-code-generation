//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define BUFLEN 1024
#define INTERVAL 1000000

struct sockaddr_in serv_addr;
int sockfd;
int running = 1;

void sigint_handler(int signum) {
    running = 0;
}

int main(int argc, char *argv[]) {
    struct rlimit rlim;
    struct timeval tv;
    char buf[BUFLEN];

    // Set the process to real-time priority
    getrlimit(RLIMIT_RTPRIO, &rlim);
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_RTPRIO, &rlim);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Set up the signal handler
    signal(SIGINT, sigint_handler);

    // Start the QoS monitor
    while (running) {
        // Send a message to the server
        sprintf(buf, "PING %s", argv[3]);
        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            exit(1);
        }

        // Receive a response from the server
        if (recv(sockfd, buf, BUFLEN, 0) == -1) {
            perror("recv");
            exit(1);
        }

        // Parse the response
        sscanf(buf, "%s", buf);

        // Print the response
        printf("%s\n", buf);

        // Sleep for the specified interval
        usleep(INTERVAL);
    }

    // Close the socket
    close(sockfd);

    return 0;
}