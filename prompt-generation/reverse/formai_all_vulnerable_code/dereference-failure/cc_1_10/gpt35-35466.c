//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define SERVER_ADDR "localhost"
#define PORT 5000
#define MSG_LEN 256

/* Helper function for error handling */
void error(char *msg) {
    perror(msg);
    exit(1);
}

/* Main function */
int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char buffer[MSG_LEN];
    pid_t pid;

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* Get server IP address */
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL)
        error("ERROR, no such host");

    /* Initialize server address */
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr,
          server->h_length);
    server_addr.sin_port = htons(PORT);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *) &server_addr,
                sizeof(server_addr)) < 0)
        error("ERROR connecting");

    /* Start sending and receiving messages */
    while (1) {
        bzero(buffer, MSG_LEN);

        /* Read message from user */
        printf("\nEnter message to send to server: ");
        fgets(buffer, MSG_LEN, stdin);

        /* Write message to socket */
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");

        /* Read server acknowledgement */
        n = read(sockfd, buffer, MSG_LEN);
        if (n < 0)
            error("ERROR reading from socket");

        /* Print server response */
        printf("\nServer response: %s", buffer);

        /* Check for connection reset */
        if (n == 0) {
            printf("\nConnection reset by peer\n");
            close(sockfd);
            exit(0);
        }

        /* Introduce artificial delay */
        usleep(500000);
    }

    return 0;
}