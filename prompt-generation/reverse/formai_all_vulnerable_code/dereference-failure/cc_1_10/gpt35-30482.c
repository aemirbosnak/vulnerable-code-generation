//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct portscan_result {
    int port;
    int status; // 0 - Open, 1 - Closed
};

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535
#define BUFFER_SIZE 1024

void usage(char* command) {
    printf("Usage: %s <IP Address> [-p <Port> | -r <Port Range Start:Port Range End>]\n", command);
}

int is_port_open(char* ip_address, int port) {
    int status = -1;
    struct sockaddr_in target;
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);
    target.sin_port = htons(port);

    status = connect(sock, (struct sockaddr *)&target, sizeof(target));
    if(status < 0) {
        close(sock);
        return 1;
    }
    close(sock);
    return 0;
}

void scan_ports(char* ip_address, int start_port, int end_port, struct portscan_result** result_array) {
    int current_port = 0;
    int i = 0;
    for(current_port = start_port; current_port <= end_port; current_port++) {
        struct portscan_result* result = malloc(sizeof(struct portscan_result));
        result->port = current_port;
        result->status = is_port_open(ip_address, current_port);
        result_array[i] = result;
        i++;
    }
}

int main(int argc, char* argv[]) {
    char* ip_address;
    int port_range_start = PORT_RANGE_START;
    int port_range_end = PORT_RANGE_END;

    // Parse command line arguments
    if(argc < 2) {
        usage(argv[0]);
        return -1;
    } else {
        ip_address = argv[1];
        if(argc == 2) {
            port_range_start = PORT_RANGE_START;
            port_range_end = PORT_RANGE_END;
        } else if(argc == 4) {
            if(strcmp(argv[2], "-p") == 0) {
                int port = atoi(argv[3]);
                if(port < PORT_RANGE_START || port > PORT_RANGE_END) {
                    printf("Invalid port number. Please enter a port number between %d and %d.\n", PORT_RANGE_START, PORT_RANGE_END);
                    return -1;
                }
                port_range_start = port;
                port_range_end = port;
            } else if(strcmp(argv[2], "-r") == 0) {
                char* range = argv[3];
                char* tok = NULL;
                tok = strtok(range, ":");
                port_range_start = atoi(tok);
                if(port_range_start < PORT_RANGE_START || port_range_start > PORT_RANGE_END) {
                    printf("Invalid start port number. Please enter a port number between %d and %d.\n", PORT_RANGE_START, PORT_RANGE_END);
                    return -1;
                }
                tok = strtok(NULL, ":");
                port_range_end = atoi(tok);
                if(port_range_end < PORT_RANGE_START || port_range_end > PORT_RANGE_END) {
                    printf("Invalid end port number. Please enter a port number between %d and %d.\n", PORT_RANGE_START, PORT_RANGE_END);
                    return -1;
                }
                if(port_range_end < port_range_start) {
                    printf("End port can not be less than start port.\n");
                    return -1;
                }
            } else {
                usage(argv[0]);
                return -1;
            }
        } else {
            usage(argv[0]);
            return -1;
        }
    }

    // Scan ports
    struct portscan_result** results = malloc((port_range_end - port_range_start + 1) * sizeof(struct portscan_result*));
    scan_ports(ip_address, port_range_start, port_range_end, results);

    // Show results
    int i = 0;
    printf("Scanning ports %d-%d on %s...\n", port_range_start, port_range_end, ip_address);
    for(i = 0; i < (port_range_end - port_range_start + 1); i++) {
        printf("%d: %s\n", results[i]->port, results[i]->status == 0 ? "Open" : "Closed");
        free(results[i]);
    }
    free(results);

    return 0;
}