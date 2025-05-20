//Falcon2-11B DATASET v1.0 Category: Networking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    char msg[100];

    /* create socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    memcpy((char *) &serv_addr.sin_addr.s_addr,
          (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    /* connect to server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr,
                sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* send message to server */
    sprintf(msg, "Hello, World!");
    write(sockfd, msg, strlen(msg));

    /* receive response from server */
    read(sockfd, buffer, sizeof(buffer));
    printf("Server Response: %s\n", buffer);

    /* close socket */
    close(sockfd);

    return 0;
}