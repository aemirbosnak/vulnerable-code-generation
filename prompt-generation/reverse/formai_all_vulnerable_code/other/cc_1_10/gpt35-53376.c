//FormAI DATASET v1.0 Category: Firewall ; Style: scientific
//This program is a unique C firewall example that filters incoming and outgoing traffic
//It uses the iptables rules to block or allow packets based on a set of conditions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define IPTABLES "/sbin/iptables" //iptables location

#define DROP "DROP" //Action to drop packets
#define ACCEPT "ACCEPT" //Action to accept packets

#define IN "INPUT" //Filter incoming packets
#define OUT "OUTPUT" //Filter outgoing packets
#define FORWARD "FORWARD" //Filter forwarded packets

#define BUFF_SIZE 256 //Buffer size for reading from stdin

int main(int argc, char *argv[]) {
    int fd; //File descriptor for writing to the iptables
    char buff[BUFF_SIZE]; //Buffer for reading from stdin
    char *filename = "/tmp/firewall.log"; //File where logs are written

    //Open the file descriptor for /tmp/firewall.log
    if ((fd = open(filename, O_WRONLY|O_CREAT|O_APPEND, 0644)) == -1) {
        perror("open");
        exit(-1);
    }

    //Print the rules for filtering incoming traffic
    printf("Filtering incoming traffic...\n");
    fprintf(stdout, "\n");

    //Block incoming packets from a specific IP address
    snprintf(buff, sizeof(buff), "%s -A %s -s %s -j %s\n", IPTABLES, IN, "192.168.1.1", DROP);
    fprintf(stdout, "Blocking incoming traffic from 192.168.1.1...\n");
    fprintf(stdout, "iptables rule: %s", buff);
    assert(system(buff) == 0);

    //Allow incoming packets using a specific port
    snprintf(buff, sizeof(buff), "%s -A %s -p tcp --dport %d -j %s\n", IPTABLES, IN, 22, ACCEPT);
    fprintf(stdout, "Allowing incoming SSH traffic...\n");
    fprintf(stdout, "iptables rule: %s\n", buff);
    assert(system(buff) == 0);

    //Block incoming packets from a specific MAC address (using mac module)
    snprintf(buff, sizeof(buff), "%s -A %s -m mac --mac-source %s -j %s\n", IPTABLES, IN, "00:0C:29:FF:FF:FF", DROP);
    fprintf(stdout, "Blocking incoming traffic from MAC 00:0C:29:FF:FF:FF...\n");
    fprintf(stdout, "iptables rule: %s\n", buff);
    assert(system(buff) == 0);

    //Print the rules for filtering outgoing traffic
    printf("Filtering outgoing traffic...\n");
    fprintf(stdout, "\n");

    //Block outgoing packets using a specific protocol
    snprintf(buff, sizeof(buff), "%s -A %s -p %s -j %s\n", IPTABLES, OUT, "udp", DROP);
    fprintf(stdout, "Blocking outgoing UDP traffic...\n");
    fprintf(stdout, "iptables rule: %s\n", buff);
    assert(system(buff) == 0);

    //Allow outgoing packets using a specific port
    snprintf(buff, sizeof(buff), "%s -A %s -p %s --dport %d -j %s\n", IPTABLES, OUT, "tcp", 80, ACCEPT);
    fprintf(stdout, "Allowing outgoing HTTP traffic...\n");
    fprintf(stdout, "iptables rule: %s\n", buff);
    assert(system(buff) == 0);

    //Block outgoing packets to a specific IP address
    snprintf(buff, sizeof(buff), "%s -A %s -d %s -j %s\n", IPTABLES, OUT, "8.8.8.8", DROP);
    fprintf(stdout, "Blocking outgoing traffic to 8.8.8.8...\n");
    fprintf(stdout, "iptables rule: %s\n\n", buff);
    assert(system(buff) == 0);

    //Print the rules for filtering forward traffic
    printf("Filtering forward traffic...\n");
    fprintf(stdout, "\n");

    //Block forwarded packets using a specific protocol
    snprintf(buff, sizeof(buff), "%s -A %s -p %s -j %s\n", IPTABLES, FORWARD, "icmp", DROP);
    fprintf(stdout, "Blocking forwarded ICMP traffic...\n");
    fprintf(stdout, "iptables rule: %s\n", buff);
    assert(system(buff) == 0);

    //Allow forward packets using a specific port
    snprintf(buff, sizeof(buff), "%s -A %s -p %s --dport %d -j %s\n", IPTABLES, FORWARD, "tcp", 3389, ACCEPT);
    fprintf(stdout, "Allowing forwarded RDP traffic...\n");
    fprintf(stdout, "iptables rule: %s\n", buff);
    assert(system(buff) == 0);

    //Block forward packets to a specific IP address
    snprintf(buff, sizeof(buff), "%s -A %s -d %s -j %s\n", IPTABLES, FORWARD, "192.168.1.2", DROP);
    fprintf(stdout, "Blocking forward traffic to 192.168.1.2...\n");
    fprintf(stdout, "iptables rule: %s\n", buff);
    assert(system(buff) == 0);

    //Log all traffic that reaches this point
    snprintf(buff, sizeof(buff), "%s -A %s -j LOG --log-level debug --log-prefix \"MyFirewall:\"\n", IPTABLES, IN);
    fprintf(stdout, "Logging all incoming traffic...\n");
    fprintf(stdout, "iptables rule: %s\n\n", buff);
    assert(system(buff) == 0);

    //Close the file descriptor
    close(fd);

    return 0;
}