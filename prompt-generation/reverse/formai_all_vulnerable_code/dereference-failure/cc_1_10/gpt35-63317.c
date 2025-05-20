//FormAI DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
/* 
 * ‘Tis but thy network that is my enemy;
 * Thou art thyself, though not a scanner.
 * What’s a scanner? It is nor port, nor IP address,
 * Nor IP range, nor MAC address, nor anything else
 * Belonging to a network. O, be some other name!
 * What’s in a name? That which we call a port
 * By any other name would smell as sweet;
 * So Romeo would, were he not Romeo call’d,
 * Retain that dear port scanner which he owes
 * Without the name. Port denial-of-service,
 * Doth port or block the port? that is the question:
 * Whether ’tis nobler in the mind to scan
 * The ports and services of outrageous hosts,
 * Or to take arms against a sea of protocols,
 * And by denying, end them? To scan, to block;
 * No more; and by a block to say we end
 * The heartache and the thousand cyber attacks
 * That network admins are heir to:
 * ’tis a consummation
 * Devoutly to be wished. To scan, to block;
 * To block: perchance to deny: ay, there’s the rub;
 * For in that block of service what protocols may come
 * When we have shuffled off this vulnerable code,
 * Must give us pause: there’s the respect
 * That makes calamity of so long life;
 * For who would bear the whips and scans of hackers,
 * Th’ oppressor’s wrong, the proud man’s contumely,
 * The pangs of dispriz’d scanners, the law’s delay,
 * The insolence of JavaScript and the spurns
 * That patient merit of vulnerabilities takes,
 * When he himself might his network defend
 * With a bare scanner? who would fardels bear,
 * To grunt and sweat under a weary tool?
 * But that the dread of something after blockage,
 * The undiscover’d exploits, from whose bourn
 * No security code returns, puzzles the will
 * And makes us rather bear those vulnerabilities we have
 * Than find an end to them by blocking. Thus scanning,
 * Does make cowards of us all; and thus
 * The native hue of network administrators
 * Is sicklied o’er with the pale cast of fear,
 * And threats of impending intrusion
 * With this regard their currents turn awry,
 * And lose the name of slackers. -- Soft you now!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    if(argc != 4) {
        printf("Usage: %s <IP address> <starting port> <ending port>\n", argv[0]);
        exit(1);
    }
    
    char *target_ip = argv[1];
    int starting_port = atoi(argv[2]);
    int ending_port = atoi(argv[3]);
    
    printf("Starting port scanner on %s from %d to %d\n", target_ip, starting_port, ending_port);
    
    for(int port = starting_port; port <= ending_port; port++) {
        struct sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(target_ip);
        target.sin_port = htons(port);
        
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        
        if(connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
            printf("Port %d closed.\n", port);
        } else {
            printf("Port %d open.\n", port);
        }
        
        close(sock);
    }
    
    return 0;
}