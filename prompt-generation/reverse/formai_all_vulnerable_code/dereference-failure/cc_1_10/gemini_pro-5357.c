//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#include <netdb.h>

#define INET_ATON inet_aton

#ifndef HAVE_STRERROR
extern char *sys_errlist[];
extern int sys_nerr;
#define strerror(e) ((e)<0||(e)>=sys_nerr?"Unknown error":sys_errlist[e])
#endif

struct cidr {
    int mask;
    unsigned long net, bcast, first, last, hosts;
};

int cidr_parse(struct cidr *c, const char *s)
{
    struct sockaddr_in addr;
    int i, bits;

    if (!INET_ATON(s, &addr.sin_addr))
        return 1;

    c->net = ntohl(addr.sin_addr.s_addr) & 0xfffffffful;
    if (strstr(s, "/")) {
        c->mask = atoi(strstr(s, "/") + 1);
    } else {
        bits = 0;
        for (i=31; i>=0; i--) {
            if (c->net & (1ul<<i))
                bits++;
            else
                break;
        }
        c->mask = bits;
    }

    c->hosts = (1ul<<((32-c->mask)-1));
    c->bcast = c->net | ~((c->hosts)-1);
    c->first = c->net + 1;
    c->last = c->bcast - 1;

    return 0;
}

int main(int argc, char **argv)
{
    int i, verbose;
    struct cidr c;
    char s[32];

    verbose = 0;
    if (argc > 1) {
        for (i=1; i<argc; i++) {
            if (!strcmp(argv[i], "-v")) {
                verbose = 1;
                continue;
            }
            if (!strcmp(argv[i], "-help")) {
                printf("Usage: %s [-v] [-help] <network>/<mask> | <broadcast>\n", argv[0]);
                exit(0);
            }
            if (cidr_parse(&c, argv[i])) {
                printf("Invalid argument '%s'\n", argv[i]);
                exit(1);
            }
            break;
        }
    }

    if (argc < 2) {
        printf("Enter an IPv4 network address and mask (e.g. 10.0.0.0/24): ");
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n\r")] = '\0';
        if (cidr_parse(&c, s)) {
            printf("Invalid input\n");
            exit(1);
        }
    }

    printf("Network %s\n", inet_ntoa((struct in_addr){ntohl(c.net)}));
    printf("Netmask %s\n", inet_ntoa((struct in_addr){ntohl(c.bcast)^ntohl(c.net)}));
    printf("Broadcast %s\n", inet_ntoa((struct in_addr){ntohl(c.bcast)}));
    printf("First usable IP %s\n", inet_ntoa((struct in_addr){ntohl(c.first)}));
    printf("Last usable IP %s\n", inet_ntoa((struct in_addr){ntohl(c.last)}));
    printf("Total hosts in subnet %lu\n", c.hosts);

    if (verbose) {
        printf("Binary netmask %08x\n", ntohl(c.bcast)^ntohl(c.net));
        printf("Binary network %08x\n", ntohl(c.net));
        printf("Binary broadcast %08x\n", ntohl(c.bcast));
        printf("Binary first usable IP %08x\n", ntohl(c.first));
        printf("Binary last usable IP %08x\n", ntohl(c.last));
    }

    return 0;
}