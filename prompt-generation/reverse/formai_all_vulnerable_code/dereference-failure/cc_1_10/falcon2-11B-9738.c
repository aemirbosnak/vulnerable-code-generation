//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    struct hostent *host;
    struct sockaddr_in serv_addr;
    int sockfd, n;
    char buffer[100];

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("ERROR: Unknown host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *) &serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    printf("Pinging %s...\n", argv[1]);
    n = send(sockfd, "GET / HTTP/1.0\r\n\r\n", 41, 0);
    if (n < 0) {
        perror("ERROR sending data");
        return 1;
    }

    bzero(buffer, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("ERROR receiving data");
        return 1;
    }

    if (n == 0) {
        printf("Empty response from server.\n");
        return 1;
    }

    printf("Response from %s:\n%s\n", argv[1], buffer);

    close(sockfd);
    return 0;
}