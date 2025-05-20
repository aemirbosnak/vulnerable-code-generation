//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <IPv4 Network Address>\n", argv[0]);
        exit(1);
    }

    char *network_address = argv[1];
    struct in_addr addr;
    if (!inet_aton(network_address, &addr)) {
        printf("Invalid network address: %s\n", network_address);
        exit(1);
    }

    char ping_cmd[100];
    sprintf(ping_cmd, "ping -c 1 %s", network_address);

    FILE *ping_output_file;
    char ping_output_file_name[20];
    sprintf(ping_output_file_name, "%s.txt", network_address);

    ping_output_file = fopen(ping_output_file_name, "w");
    if (ping_output_file == NULL) {
        error("Error opening file");
    }

    char buffer[BUFFER_SIZE];
    char cmd_output[BUFFER_SIZE];
    size_t buffer_len;

    int i, j, k, l, m;
    for (i = 1; i < 255; i++) {
        memset(buffer, 0, sizeof buffer);
        sprintf(buffer, "%s.%d", network_address, i);

        memset(cmd_output, 0, sizeof cmd_output);
        FILE *ping_pipe = popen(ping_cmd, "r");
        if (ping_pipe == NULL) {
            printf("Error running ping command for IP address: %s", buffer);
            exit(1);
        }
        fread(cmd_output, 1, sizeof cmd_output, ping_pipe);

        if (strstr(cmd_output, "1 received")) {
            printf("Host %s is UP\n", buffer);
            fprintf(ping_output_file, "Host %s is UP\n", buffer);
        } else {
            printf("Host %s is DOWN\n", buffer);
            fprintf(ping_output_file, "Host %s is DOWN\n", buffer);
        }
    }

    fclose(ping_output_file);

    return 0;
}