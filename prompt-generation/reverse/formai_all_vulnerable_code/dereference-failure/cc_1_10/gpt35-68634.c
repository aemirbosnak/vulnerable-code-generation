//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF 1024

int check_network_qos(const char* dev, int seq)
{
    char path[MAX_BUF];
    char buf[MAX_BUF];
    snprintf(path, MAX_BUF, "/sys/class/net/%s/tx_queue_%d/bytes", dev, seq);
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }
    if (read(fd, buf, MAX_BUF) == -1) {
        perror("Error reading file");
        return -1;
    }
    close(fd);
    return atoi(buf);
}

void monitor_network_qos(const char* dev, int seq, int threshold)
{
    int bytes = check_network_qos(dev, seq);
    if (bytes == -1) {
        printf("Could not monitor network QoS\n");
        return;
    }

    if (bytes >= threshold) {
        printf("WARNING: Network QoS threshold exceeded on %s tx_queue_%d\n", dev, seq);
    }

    sleep(1);
    monitor_network_qos(dev, seq, threshold);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: qos_monitor <interface> <threshold>\n");
        return 1;
    }

    const char* dev = argv[1];
    int threshold = atoi(argv[2]);

    printf("Monitoring network QoS for %s with threshold of %d bytes...\n", dev, threshold);

    monitor_network_qos(dev, 0, threshold);
    return 0;
}