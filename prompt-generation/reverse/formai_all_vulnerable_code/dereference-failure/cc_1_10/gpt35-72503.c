//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define WIFI_SCAN_PORT 9090 /* port number for wifi scan */

int main(int argc, char **argv) {
    int sock, count;
    struct sockaddr_in scan_server;
    char recv_buf[1024];
    time_t timestamp;
    struct tm *tm_info;

    /* Create socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    /* Set server address */
    scan_server.sin_family = AF_INET;
    scan_server.sin_port = htons(WIFI_SCAN_PORT);
    scan_server.sin_addr.s_addr = inet_addr("127.0.0.1"); // set IP address of wifi scan server

    /* Connect to server */
    if (connect(sock, (struct sockaddr *)&scan_server, sizeof(scan_server)) < 0) {
        perror("Connection to scan server failed");
        return EXIT_FAILURE;
    }

    /* Request wifi network scan */
    if (send(sock, "scan", strlen("scan"), 0) < 0) {
        perror("Request for wifi scan failed");
        return EXIT_FAILURE;
    }

    printf("Scanning for wifi networks...\n");

    /* Receive scan results from server */
    count = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (count < 0) {
        perror("Receiving scan results failed");
        return EXIT_FAILURE;
    }

    printf("Scan results:\n%s\n", recv_buf);

    /* Print timestamp */
    timestamp = time(NULL);
    tm_info = localtime(&timestamp);
    printf("Scan completed at %02d:%02d:%02d\n", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

    /* Close socket */
    close(sock);

    return EXIT_SUCCESS;
}