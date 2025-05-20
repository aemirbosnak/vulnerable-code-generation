//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BLOCK_SIZE 1024
#define CHECKSUM_SIZE 2

unsigned short checksum(unsigned short *buf, int len) {
    unsigned short sum = 0;
    int i;

    for (i = 0; i < len; i += 2) {
        sum += ntohs(*(unsigned short *)(&buf[i]));
    }

    if (len & 1)
        sum += ntohs(*(unsigned short *)&buf[len - 1]);

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    return htons(~sum & 0xFFFF);
}

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serv_addr;
    unsigned char buffer[BLOCK_SIZE];
    unsigned short checksum_calc, checksum_recv;
    int len;
    int i, j;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <FILE_NAME>\n", argv[0]);
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5005);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    FILE *fp = fopen(argv[2], "rb");

    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while ((len = fread(buffer, 1, BLOCK_SIZE, fp)) > 0) {
        checksum_calc = checksum((unsigned short *)buffer, len);

        if (sendto(sockfd, buffer, len, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("Error sending data to server");
            exit(1);
        }

        if (recvfrom(sockfd, &checksum_recv, CHECKSUM_SIZE, 0, NULL, NULL) < 0) {
            perror("Error receiving checksum from server");
            exit(1);
        }

        if (checksum_calc != checksum_recv) {
            printf("Error: Checksums do not match.\n");
            exit(1);
        }
    }

    if (fclose(fp) < 0) {
        perror("Error closing file");
        exit(1);
    }

    printf("Checksum verification successful.\n");
    close(sockfd);

    // Just for fun, let's create a message and send it to the server
    if (sendto(sockfd, "C Checksum Calculator Rockin'!", 25, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    unsigned short message_checksum = checksum((unsigned short *)"C Checksum Calculator Rockin'!", 25);

    if (recvfrom(sockfd, &checksum_recv, CHECKSUM_SIZE, 0, NULL, NULL) < 0) {
        perror("Error receiving checksum from server");
        exit(1);
    }

    if (message_checksum != checksum_recv) {
        printf("Error: Message checksums do not match.\n");
        exit(1);
    }

    printf("Message checksum verification successful.\n");
    close(sockfd);

    return 0;
}