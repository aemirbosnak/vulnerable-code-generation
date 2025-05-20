//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_SSID_LEN 32
#define MAX_BUF_SIZE 1024

// Function to get the wireless network interface
char *getWirelessInterface() {
    char *interface = NULL;
    FILE *fp = popen("iwconfig 2>&1 | grep 'Wireless' | awk '{print $1}'", "r");
    if (fp != NULL) {
        char buffer[1024] = {0};
        fgets(buffer, 1024, fp);
        pclose(fp);
        if (strlen(buffer) > 0) {
            interface = (char *) malloc(sizeof(char) * (strlen(buffer) + 1));
            strcpy(interface, buffer);
            interface[strlen(interface) - 1] = '\0';
        }
    }
    return interface;
}

// Function to get all the wireless networks
void getWirelessNetworks() {
    char *interface = getWirelessInterface();
    if (interface == NULL) {
        printf("No wireless interface found..!\n");
        return;
    }

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        free(interface);
        return;
    }

    struct iwreq req;
    memset(&req, 0, sizeof(struct iwreq));
    strcpy(req.ifr_name, interface);

    // Get the wireless interface's attributes
    if (ioctl(sock_fd, SIOCGIWNAME, &req) < 0) {
        printf("Getting wireless interface attributes failed: %s\n", strerror(errno));
        free(interface);
        close(sock_fd);
        return;
    }

    // Get the wireless scan results
    char buffer[MAX_BUF_SIZE] = {0};
    req.u.data.pointer = (caddr_t) buffer;
    req.u.data.length = MAX_BUF_SIZE;
    req.u.data.flags = 1;

    if (ioctl(sock_fd, SIOCGIWSCAN, &req) < 0) {
        printf("Getting wireless scan results failed: %s\n", strerror(errno));
        free(interface);
        close(sock_fd);
        return;
    }

    printf("Networks found:\n");
    char *ptr = buffer + sizeof(struct iw_event);
    int idx = 1;
    while (ptr < buffer + MAX_BUF_SIZE) {
        struct iw_event *event = (struct iw_event *) ptr;
        if (event->cmd == SIOCGIWAP) {
            char ssid[MAX_SSID_LEN] = {0};
            struct sockaddr *addr = (struct sockaddr *) (event + 1);
            sprintf(ssid, "%.*s", event->len - 4, event->u.name + 4);
            printf("%d. %s (%02x:%02x:%02x:%02x:%02x:%02x)\n", idx, ssid,
                    (unsigned char) addr->sa_data[0], (unsigned char) addr->sa_data[1],
                    (unsigned char) addr->sa_data[2], (unsigned char) addr->sa_data[3],
                    (unsigned char) addr->sa_data[4], (unsigned char) addr->sa_data[5]);
            idx++;
        }
        ptr += event->len;
    }

    free(interface);
    close(sock_fd);
}

int main() {
    getWirelessNetworks();
    return 0;
}