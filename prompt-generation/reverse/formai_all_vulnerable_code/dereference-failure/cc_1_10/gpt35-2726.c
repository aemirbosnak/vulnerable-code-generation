//FormAI DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

void handler(int signal)
{
   printf("Signal %d received. Exiting...\n", signal);
   exit(0);
}

int main(int argc, char **argv)
{
    char *target;
    int socket_descriptor, result;
    int timeout = 5;
    struct sockaddr_in target_address;
    struct hostent *target_info;

    signal(SIGINT, handler);

    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return -1;
    } else {
        target = argv[1];
    }

    socket_descriptor = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (socket_descriptor < 0) {
        printf("ERROR: Unable to open socket\n");
        return -1;
    }

    target_info = gethostbyname(target);

    if (target_info == NULL) {
        printf("ERROR: Unable to resolve hostname %s\n", target);
        return -1;
    }

    target_address.sin_family = AF_INET;
    target_address.sin_port = 0;
    memcpy(&target_address.sin_addr.s_addr, target_info->h_addr_list[0], target_info->h_length);

    result = connect(socket_descriptor, (struct sockaddr *)&target_address, sizeof(target_address));

    if (result < 0) {
        printf("ERROR: Unable to connect to %s\n", target);
        return -1;
    }

    printf("PING %s\n", target);

    while (1) {

        struct timeval timeout_val;
        timeout_val.tv_sec = timeout;
        timeout_val.tv_usec = 0;

        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(socket_descriptor, &read_set);

        int result = select(socket_descriptor+1, &read_set, NULL, NULL, &timeout_val);

        if (result < 0) {
            printf("ERROR: select() failed, %s\n", strerror(errno));
        }
        else if (result == 0) {
            printf("Timeout\n");
        }
        else {
            char buffer[1024];
            ssize_t bytes_received = recv(socket_descriptor, buffer, sizeof(buffer), 0);

            if (bytes_received < 0) {
                printf("ERROR: recvfrom() failed, %s\n", strerror(errno));
                break;
            }

            printf("Received response from %s\n", target);

            if (bytes_received > 0) {
                printf("%zu bytes received\n", bytes_received);
            }
        }

        sleep(1); // Wait one second before sending next ping

        result = sendto(socket_descriptor, NULL, 0, 0, (struct sockaddr *)&target_address, sizeof(target_address));

        if (result < 0) {
            printf("ERROR: sendto() failed, %s\n", strerror(errno));
            break;
        }
    }

    close(socket_descriptor);

    return 0;
}