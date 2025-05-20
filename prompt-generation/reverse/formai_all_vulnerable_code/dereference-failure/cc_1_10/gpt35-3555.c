//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 4096
#define MAX_INTERFACE_NAME_SIZE 64

int main(){
    int fd;
    struct ifreq ifr;
    char *iface = NULL;
    struct sockaddr_in *sin_ptr;
    char buffer[MAX_BUFFER_SIZE];

    // create socket
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("Socket creation failed!");
        exit(-1);
    }

    // allocate memory for interface name
    iface = (char *) malloc(MAX_INTERFACE_NAME_SIZE);
    if (iface == NULL) {
        perror("Memory allocation failed!");
        close(fd);
        exit(-1);
    }

    // get interface name
    printf("Enter the wireless interface name: ");
    scanf("%s", iface);

    // set interface name in ifreq struct
    strncpy(ifr.ifr_name, iface, strlen(iface));

    // get IP address, broadcast address, and netmask
    if (ioctl(fd, SIOCGIFADDR, &ifr) == -1) {
        perror("Error getting IP address!");
        close(fd);
        exit(-1);
    }

    // extract IP address from ifreq struct
    sin_ptr = (struct sockaddr_in *) &ifr.ifr_addr;
    printf("IP Address: %s\n", inet_ntoa(sin_ptr->sin_addr));

    // get the broadcast address
    if (ioctl(fd, SIOCGIFBRDADDR, &ifr) == -1) {
        perror("Error getting broadcast address!");
        close(fd);
        exit(-1);
    }

    // extract broadcast address from ifreq struct
    sin_ptr = (struct sockaddr_in *) &ifr.ifr_broadaddr;
    printf("Broadcast Address: %s\n", inet_ntoa(sin_ptr->sin_addr));

    // get the netmask
    if (ioctl(fd, SIOCGIFNETMASK, &ifr) == -1) {
        perror("Error getting netmask!");
        close(fd);
        exit(-1);
    }

    // extract netmask from ifreq struct
    sin_ptr = (struct sockaddr_in *) &ifr.ifr_netmask;
    printf("Netmask: %s\n", inet_ntoa(sin_ptr->sin_addr));

    // close socket and free memory
    close(fd);
    free(iface);

    return 0;
}