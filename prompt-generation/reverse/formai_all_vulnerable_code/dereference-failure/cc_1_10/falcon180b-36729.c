//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define SLEEP_TIME 1

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Connection successful!\n");
            close(sock);
            return 0;
        } else {
            attempts++;
            printf("Connection failed. Retrying...\n");
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1) {
                printf("Error creating socket\n");
                return 1;
            }
        }
        sleep(SLEEP_TIME);
    }

    printf("Connection failed after %d attempts\n", attempts);
    close(sock);
    return 1;
}