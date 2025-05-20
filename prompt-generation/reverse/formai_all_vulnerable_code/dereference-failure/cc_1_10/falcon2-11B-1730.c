//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void* analyze_signal(void* arg) {
    char* ssid = (char*)arg;
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    char buffer[1024];
    char ssid_buffer[64];
    int ssid_length;
    int signal_strength;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("8.8.8.8");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(53);

    while (1) {
        strncpy(ssid_buffer, ssid, sizeof(ssid_buffer));
        ssid_length = strlen(ssid_buffer);

        n = sendto(sockfd, ssid_buffer, ssid_length, 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        if (n < 0) {
            perror("ERROR sending data");
            exit(1);
        }

        memset(buffer, 0, sizeof(buffer));
        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n < 0) {
            perror("ERROR receiving data");
            exit(1);
        }

        signal_strength = atoi(buffer);

        printf("%s: Signal strength: %d\n", ssid, signal_strength);

        sleep(1);
    }

    close(sockfd);
    return NULL;
}

int main() {
    pthread_t thread;
    char ssid[64];
    int signal_strength;

    printf("Enter SSID to analyze signal strength: ");
    fgets(ssid, sizeof(ssid), stdin);
    signal_strength = analyze_signal(ssid);

    printf("Signal strength for SSID \"%s\": %d\n", ssid, signal_strength);

    return 0;
}