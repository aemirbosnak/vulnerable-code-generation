//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

/* Global variables */
int listen_sock, port = 8888;
char bssid[18], essid[32];
int signal_strength;

/* Set up signal handler for SIGINT */
void intHandler(int sig) {
    printf("\n");
    close(listen_sock);
    exit(0);
}

/* Thread for receiving data from socket */
void *recvData(void *arg) {
    char buffer[1024];
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int recv_len;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recv_len = recvfrom(listen_sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &client, &len);
        if (recv_len > 0) {
            char *pos;
            if ((pos = strstr(buffer, "BSSID:")) != NULL) {
                sscanf(pos, "BSSID:%s", bssid);
            }
            if ((pos = strstr(buffer, "ESSID:")) != NULL) {
                sscanf(pos, "ESSID:%s", essid);
            }
            if ((pos = strstr(buffer, "Signal level=")) != NULL) {
                sscanf(pos, "Signal level=%d", &signal_strength);
            }
        }
    }
    return NULL;
}

/* Main function */
int main(int argc, char *argv[]) {

    /* Parse command line arguments */
    if (argc == 2) {
        port = atoi(argv[1]);
    }
    else if (argc > 2) {
        printf("Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    /* Set up signal handler for SIGINT */
    signal(SIGINT, intHandler);

    /* Create socket */
    if ((listen_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    /* Set options for socket */
    int option = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    /* Bind to port */
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    if (bind(listen_sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error binding to port");
        exit(1);
    }

    /* Set up thread for receiving data from socket */
    pthread_t recv_thread;
    if (pthread_create(&recv_thread, NULL, recvData, NULL) < 0) {
        perror("Error creating thread");
        exit(1);
    }

    /* Print header for data */
    printf("%-17s %-32s %-16s\n", "BSSID", "ESSID", "SIGNAL STRENGTH");
    printf("------------------------------------------------------------\n");

    /* Loop to print data */
    while (1) {
        printf("%-17s %-32s %-16d\r", bssid, essid, signal_strength);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}