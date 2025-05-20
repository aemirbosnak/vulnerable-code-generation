//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;
    int signal_strength;
    int max_signal_strength = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(80);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    while ((n = read(sock, buffer, BUFFER_SIZE)) > 0) {
        buffer[n] = '\0';
        if (strstr(buffer, "Wi-Fi Signal Strength:")!= NULL) {
            signal_strength = atoi(strstr(buffer, ":") + 1);
            if (signal_strength > max_signal_strength) {
                max_signal_strength = signal_strength;
            }
        }
    }

    close(sock);

    printf("Maximum Wi-Fi Signal Strength: %d\n", max_signal_strength);

    return 0;
}