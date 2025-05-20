//FormAI DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <errno.h>

/* global variables */
char *progname;
int has_errors = 0;

/* function prototypes */
void display_usage();
void display_error();
int parse_arguments(int argc, char **argv, char **hostname);
void ping(char *hostname);

/* main function */
int main(int argc, char **argv) {

    char *hostname = NULL;

    /* set program name */
    progname = argv[0];

    /* parse arguments */
    if (parse_arguments(argc, argv, &hostname) != 0) {
        display_usage();
        return EXIT_FAILURE;
    }

    /* ping the specified host */
    ping(hostname);

    /* exit program */
    return (has_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

/* function to display program usage */
void display_usage() {
    printf("Usage: %s hostname\n", progname);
}

/* function to display error messages */
void display_error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    has_errors = 1;
}

/* function to parse command line arguments */
int parse_arguments(int argc, char **argv, char **hostname) {

    /* check for correct number of arguments */
    if (argc != 2) {
        display_error("Incorrect number of arguments.");
        return -1;
    }

    /* get hostname */
    *hostname = argv[1];

    /* return success */
    return 0;
}

/* function to perform ping test */
void ping(char *hostname) {

    struct hostent *host;
    struct sockaddr_in addr;
    int sock, val, ret;
    float timeout = 1.0; // 1 second timeout
    char buff[256];
    struct timeval start, end;

    /* resolve hostname */
    if ((host = gethostbyname(hostname)) == NULL) {
        display_error("Could not resolve host name.");
        return;
    }

    /* create socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        display_error("Could not create socket.");
        return;
    }

    /* set socket options */
    val = 1;
    ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (ret < 0) {
        display_error("Could not set socket options.");
        close(sock);
        return;
    }

    /* set address */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = *((unsigned long*) host->h_addr_list[0]);

    /* start timer */
    gettimeofday(&start, NULL);

    /* connect to server */
    ret = connect(sock, (struct sockaddr*) &addr, sizeof(addr));
    if (ret < 0) {
        display_error("Could not connect to server.");
        close(sock);
        return;
    }

    /* stop timer */
    gettimeofday(&end, NULL);

    /* calculate round-trip time */
    double rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    /* print results */
    printf("Ping to %s (%s): time=%.2fms\n", hostname, inet_ntoa(addr.sin_addr), rtt);

    /* close socket */
    close(sock);
}