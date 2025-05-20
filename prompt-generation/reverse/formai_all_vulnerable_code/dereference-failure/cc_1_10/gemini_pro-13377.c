//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <net/if.h>
#include <linux/rtnetlink.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IFNAMSIZ    16

int main(int argc, char **argv)
{
    int fd;
    struct rtgenmsg *msg;
    char buf[4096];
    struct nlmsghdr *nh;
    struct ifinfomsg *ifinfo;
    char *ptr;
    int len;
    int ifindex;
    char ifname[IFNAMSIZ];

    // Create a socket to communicate with the kernel.
    fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Allocate a buffer for the message.
    msg = malloc(NLMSG_ALIGN(sizeof(struct rtgenmsg)));
    if (msg == NULL) {
        perror("malloc");
        close(fd);
        return EXIT_FAILURE;
    }

    // Fill in the message header.
    memset(msg, 0, NLMSG_ALIGN(sizeof(struct rtgenmsg)));
    msg->rtgen_family = AF_UNSPEC;

    // Send the message to the kernel.
    if (send(fd, msg, NLMSG_ALIGN(sizeof(struct rtgenmsg)), 0) == -1) {
        perror("send");
        free(msg);
        close(fd);
        return EXIT_FAILURE;
    }

    // Receive the message from the kernel.
    while ((len = recv(fd, buf, sizeof(buf), 0)) > 0) {
        // Parse the message.
        ptr = buf;
        while (ptr < buf + len) {
            nh = (struct nlmsghdr *)ptr;
            ifinfo = (struct ifinfomsg *)NLMSG_DATA(nh);
            ifindex = ifinfo->ifi_index;
            memset(ifname, 0, IFNAMSIZ);
            if_indextoname(ifindex, ifname);

            // Print the interface name.
            printf("%s\n", ifname);

            // Move to the next message.
            ptr += NLMSG_ALIGN(nh->nlmsg_len);
        }
    }

    // Close the socket.
    close(fd);

    // Free the message buffer.
    free(msg);

    return EXIT_SUCCESS;
}