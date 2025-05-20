//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAXDATASIZE 100

const char* banner = "___   ___           __  __           _  _        ___    ___  \n| _ \\ |_ _|_ _  ___ / _|/ _|___ _ __ | || |__ _  / __|  / _ \\ \n|   /  | || ' \\/ -_)  _|  _/ _ \\ '  \\| __ / _` | \\__ \\ | (_) |\n|_|_\\ |___|_||_\\___|_| |_| \\___/_|_|_|_||_\\__,_| |___/  \\___/ ";

static volatile int keepRunning = 1;
void intHandler(int dummy) {
    keepRunning = 0;
}

int main(int argc, char **argv) {
    int sockfd, numbytes;  
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr; /* connector's address information */
    char hostname[MAXDATASIZE];
    int port;
    struct sigaction sa;
    int interval = 10;

    if (argc != 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    printf("Monitoring network QoS for %s:%d...\n", hostname, port);

    /* set up the sigaction to handle Ctrl+C */
    sa.sa_handler = intHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    while (keepRunning) {
        if ((he=gethostbyname(hostname)) == NULL) {  /* get the host info */
            perror("gethostbyname");
            exit(1);
        }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            exit(1);
        }

        their_addr.sin_family = AF_INET;      /* host byte order */
        their_addr.sin_port = htons(port);    /* short, network byte order */
        their_addr.sin_addr = *((struct in_addr *)he->h_addr);
        memset(&(their_addr.sin_zero), '\0', 8);  /* zero the rest of the struct */

        if (connect(sockfd, (struct sockaddr *)&their_addr,
                    sizeof(struct sockaddr)) == -1) {
            perror("connect");
            exit(1);
        }

        /* send a PING to the server */
        const char* ping_msg = "PING";
        if (send(sockfd, ping_msg, strlen(ping_msg), 0) == -1) {
            perror("send");
        }

        /* receive the response */
        if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
            perror("recv");
        }

        if (numbytes > 0) {
            buf[numbytes] = '\0';
            printf("%s: %s", hostname, buf);
        }

        close(sockfd);
        sleep(interval);
    }

    printf("Monitoring stopped.\n");
    return 0;
}