//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80
#define HOST "www.google.com"

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    int sockfd;
    struct hostent *host;
    char buffer[1024];
    int len;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: socket failed\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *) &server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    len = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (len < 0) {
        fprintf(stderr, "Error: connect failed\n");
        exit(1);
    }

    printf("Connected to %s\n", host->h_name);

    while (1) {
        printf("Enter a command: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "exit") == 0)
            break;

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            fprintf(stderr, "Error: send failed\n");
            exit(1);
        }

        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            fprintf(stderr, "Error: recv failed\n");
            exit(1);
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}