//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>

#define BUFSIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    struct hostent *host;

    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        error("ERROR: Could not resolve hostname.");
    }

    int port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR: Could not create socket.");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = *(unsigned long *) host->h_addr_list[0];
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        error("ERROR: Connection failed.");
    }

    printf("Connected to %s:%d\n", argv[1], port);

    char buffer[BUFSIZE];
    FILE *fp = popen("ping -c 5 google.com", "r");

    if (fp == NULL) {
        error("ERROR: Could not execute command.");
    }

    fgets(buffer, BUFSIZE, fp);

    int sent = atoi(strrchr(buffer, ' ') + 1);
    fgets(buffer, BUFSIZE, fp);
    int received = atoi(strrchr(buffer, ' ') + 1);
    double loss = (sent - received) / (double) sent * 100;

    fclose(fp);

    printf("Ping Results:\n");
    printf("Sent: %d\n", sent);
    printf("Received: %d\n", received);
    printf("Packet Loss: %.2f%%\n", loss);

    if (loss >= 20) {
        printf("WARNING: High packet loss detected.\n");
    } else {
        printf("Status: OK\n");
    }

    close(sock);

    return 0;
}