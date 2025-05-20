//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time;
    double total_time;
    unsigned long total_bytes;

    if(argc!= 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);

    if(server == NULL) {
        printf("Error: No such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        printf("Error: Socket creation failed\n");
        exit(0);
    }

    portno = 80;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(0);
    }

    start_time = difftime(time(0), time(0));
    total_bytes = 0;
    while(1) {
        n = read(sockfd, buffer, BUFFER_SIZE);

        if(n <= 0) {
            break;
        }

        total_bytes += n;
        total_time = difftime(time(0), start_time);
        printf("\rDownloading... %.2f KB/s", (double)total_bytes / total_time);
        fflush(stdout);
    }

    close(sockfd);
    printf("\n");

    return 0;
}