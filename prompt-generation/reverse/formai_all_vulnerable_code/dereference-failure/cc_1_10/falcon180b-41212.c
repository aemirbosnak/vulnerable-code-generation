//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];
    int len, bytes_received;
    time_t start_time, end_time;
    double elapsed_time;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    start_time = time(NULL);
    while (TRUE) {
        bytes_received = recv(sock, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);

        if (strstr(buffer, "ENDINPUT")!= NULL) {
            break;
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Elapsed time: %.2lf seconds\n", elapsed_time);

    close(sock);
    return 0;
}