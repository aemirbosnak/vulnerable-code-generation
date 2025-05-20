//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORT_NUM 65535
#define MAX_HOSTNAME_LEN 256

static bool verbose = false;
static char *hostname;
static int min_port = 1;
static int max_port = MAX_PORT_NUM;

static void print_usage(char *progname) {
    fprintf(stderr, "Usage: %s [options] <hostname>\n", progname);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -v\t\tEnable verbose output\n");
    fprintf(stderr, "  -p <min>-<max>\tSpecify the range of ports to scan (default: 1-%d)\n", MAX_PORT_NUM);
    exit(EXIT_FAILURE);
}

static void parse_args(int argc, char **argv) {
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = true;
        } else if (strcmp(argv[i], "-p") == 0) {
            if (i + 1 < argc) {
                char *ports = argv[i + 1];
                char *min_port_str = strtok(ports, "-");
                char *max_port_str = strtok(NULL, "-");

                if (min_port_str != NULL) {
                    min_port = atoi(min_port_str);
                }
                if (max_port_str != NULL) {
                    max_port = atoi(max_port_str);
                }
            } else {
                fprintf(stderr, "Invalid port range specified\n");
                print_usage(argv[0]);
            }
        } else {
            hostname = argv[i];
        }
    }

    if (hostname == NULL) {
        fprintf(stderr, "No hostname specified\n");
        print_usage(argv[0]);
    }
}

static int scan_port(struct sockaddr_in *addr, int port) {
    int sockfd;
    int ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    addr->sin_port = htons(port);
    ret = connect(sockfd, (struct sockaddr *)addr, sizeof(*addr));
    close(sockfd);

    return ret;
}

static void scan_ports() {
    struct sockaddr_in addr;
    struct hostent *host;
    int port;
    char ip[INET6_ADDRSTRLEN];

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    addr.sin_family = host->h_addrtype;
    memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);

    for (port = min_port; port <= max_port; port++) {
        int ret = scan_port(&addr, port);

        if (verbose) {
            fprintf(stdout, "Scanning port %d: ", port);
        }
        if (ret == 0) {
            if (verbose) {
                fprintf(stdout, "open\n");
            }
            inet_ntop(AF_INET, &addr.sin_addr, ip, sizeof(ip));
            printf("%s:%d open\n", ip, port);
        } else if (errno == ECONNREFUSED) {
            if (verbose) {
                fprintf(stdout, "closed\n");
            }
        } else {
            fprintf(stderr, "Error scanning port %d: %s\n", port, strerror(errno));
        }
    }
}

int main(int argc, char **argv) {
    parse_args(argc, argv);
    scan_ports();
    return EXIT_SUCCESS;
}