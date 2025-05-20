//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

// Custom Checksum function
uint16_t custom_checksum(uint16_t *buf, size_t len) {
    uint32_t sum = 0;
    for (size_t i = 0; i < len; i += 2) {
        sum += ntohs(*(uint16_t *) &buf[i]);
    }
    while (len & 1) {
        sum = (sum >> 1) + (sum & 0x5555);
        len--;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    return htons(~sum & 0xFFFF);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <port>\n", argv[0]);
        return 1;
    }

    // Open file and check for errors
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        fclose(fp);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Read file in chunks and calculate checksum
    size_t len = 0;
    char buffer[4096];
    uint16_t *data_ptr = calloc(4096, sizeof(uint16_t));
    while ((len = fread(buffer, sizeof(char), sizeof(buffer), fp))) {
        for (size_t i = 0; i < len; i += 2) {
            *((uint16_t *) &data_ptr[i / 2]) = ntohs(*(uint16_t *) &buffer[i]);
        }
        uint16_t checksum = custom_checksum(data_ptr, len / 2);
        sendto(sockfd, &checksum, sizeof(checksum), 0, (struct sockaddr *) &server_addr, sizeof(server_addr));
    }

    free(data_ptr);
    fclose(fp);
    close(sockfd);

    printf("Checksum calculation and transmission complete!\n");

    return 0;
}