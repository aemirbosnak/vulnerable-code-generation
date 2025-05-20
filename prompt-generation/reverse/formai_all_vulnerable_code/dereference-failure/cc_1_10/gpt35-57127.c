//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define PORT 3000

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void check_qos(int sockfd)
{
    int enable = 1;
    setsockopt(sockfd, IPPROTO_TCP, TCP_USER_TIMEOUT, &enable, sizeof(enable));

    struct timeval start, end;
    int diff;
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));

    /* Start measuring time */
    gettimeofday(&start, NULL);

    /* Send a test message to the server */
    sprintf(buffer, "QoS Test Message\n");
    int n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("Error writing to socket");

    /* Receive the response from the server */
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) 
         error("Error reading from socket");

    /* Stop measuring time */
    gettimeofday(&end, NULL);
    diff = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    printf("Time taken: %d microseconds\n", diff);

    /* Check the network quality of service */
    if (diff > 1000)
        printf("Network quality of service is poor\n");
    else if (diff > 500)
        printf("Network quality of service is fair\n");
    else 
        printf("Network quality of service is excellent\n");
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr,"usage: %s hostname\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("Error connecting");

    check_qos(sockfd);

    close(sockfd);
    return 0;
}