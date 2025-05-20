//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAXPORT 65535 // maximum port number
#define MAXIPLEN 16 // maximum IP length

void scan_port(char ip[], int port); // function to scan a single port
void scan_range(char ip[], int start_port, int end_port); // function to scan a range of ports
void print_banner(); // function to display scanner banner

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s <ip address> [<start port>] [<end port>]\n", argv[0]);
        exit(0);
    }
    else if (argc < 2 || argc > 4) {
        printf("Invalid usage: %s -h for help\n", argv[0]);
        exit(1);
    }

    char ip[MAXIPLEN] = "";
    strncpy(ip, argv[1], MAXIPLEN);

    // Check if IP address is valid
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    if (result == 0) {
        printf("%s is not a valid IP address\n", ip);
        exit(1);
    }

    int start_port = 1;
    int end_port = MAXPORT;
    if (argc >= 3) {
        start_port = atoi(argv[2]);
    }
    if (argc == 4) {
        end_port = atoi(argv[3]);
    }

    print_banner();

    // Call recursive function to scan ports
    scan_range(ip, start_port, end_port);

    return 0;
}

void scan_port(char ip[], int port) {
    struct sockaddr_in sa;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return;
    }
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    inet_pton(AF_INET, ip, &(sa.sin_addr));
    int result = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    if (result == 0) {
        printf("%s:%d - Open\n", ip, port);
    }
    close(sockfd);
}

void scan_range(char ip[], int start_port, int end_port) {
    if (start_port == end_port) {
        scan_port(ip, start_port);
    }
    else if (start_port < end_port) {
        int mid_port = (start_port + end_port) / 2;
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
        }
        else if (pid == 0) {
            scan_range(ip, start_port, mid_port);
            exit(0);
        }
        else {
            scan_range(ip, mid_port + 1, end_port);
            waitpid(pid, NULL, 0);
        }
    }
}

void print_banner() {
    printf("-----------------------------------------------------------\n");
    printf("                   Wireless Network Scanner                 \n");
    printf("-----------------------------------------------------------\n");
    printf("Scanning...\n");
}