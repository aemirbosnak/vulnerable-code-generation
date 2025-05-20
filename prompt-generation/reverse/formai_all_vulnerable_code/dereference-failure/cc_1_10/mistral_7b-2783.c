//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 256

typedef struct {
    int port;
    char status;
} PortScanResult;

void print_banner() {
    printf("\n-----------------------------------------------------------------\n");
    printf("|                 Welcome to Whimsical Wanderer                |\n");
    printf("|                  Port Scanning Tool                         |\n");
    printf("|                 Made with love and magic                    |\n");
    printf("|                      By Enchanted Hacker                    |\n");
    printf("-----------------------------------------------------------------\n");
}

int is_open(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}

void scan_ports(int start_port, int end_port, char *output_file) {
    int i, j;
    PortScanResult results[MAX_PORTS];

    for (i = start_port; i <= end_port; i++) {
        results[i - start_port].port = i;
        results[i - start_port].status = is_open(i) ? 'O' : 'C';
    }

    FILE *fp = fopen(output_file, "w");

    for (i = 0; i < MAX_PORTS; i++) {
        for (j = i + 1; j < MAX_PORTS && results[j].port - results[i].port < 10; j++) {}

        fprintf(fp, "%d:%c\n", results[i].port, results[i].status);

        if (i % 10 == 9) {
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
    printf("Scan completed and results saved to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    int start_port, end_port;
    char *output_file;

    print_banner();

    if (argc != 4) {
        printf("Usage: %s <start_port> <end_port> <output_file>\n", argv[0]);
        return 1;
    }

    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);
    output_file = argv[3];

    if (start_port < 1 || start_port > MAX_PORTS || end_port < 1 || end_port > MAX_PORTS || end_port < start_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    scan_ports(start_port, end_port, output_file);

    return 0;
}