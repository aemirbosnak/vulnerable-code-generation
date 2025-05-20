//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#define MIN_PORT 0
#define MAX_PORT 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd;
    struct ifreq ifr;
    char buffer[BUFFER_SIZE];
    int i, j, k;
    
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    strcpy(ifr.ifr_name, "wlan0");
    if (ioctl(sock_fd, SIOCGIFADDR, &ifr) < 0) {
        perror("Failed to get IP address");
        exit(EXIT_FAILURE);
    }
    
    printf("IP address: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
    printf("Scanning...\n");

    for (i = MIN_PORT; i <= MAX_PORT; i++) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr.s_addr = inet_addr(inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
        memset(&(addr.sin_zero), 0, 8);

        int s = socket(AF_INET, SOCK_STREAM, 0);
        if (s == -1) {
            perror("Failed to create socket");
            exit(EXIT_FAILURE);
        }

        if (connect(s, (struct sockaddr *)&addr, sizeof(struct sockaddr)) == 0) {
            printf("Port %d is open\n", i);

            // Get banner
            sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36\r\n\r\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
            send(s, buffer, strlen(buffer), 0);

            int bytes_received = 0;
            memset(buffer, 0, BUFFER_SIZE);
            while ((bytes_received = recv(s, buffer, BUFFER_SIZE - 1, 0)) > 0) {
                buffer[bytes_received] = '\0';
                printf("%s", buffer);
                memset(buffer, 0, BUFFER_SIZE);
            }
        }

        close(s);
    }

    printf("Scan finished\n");

    return 0;
}