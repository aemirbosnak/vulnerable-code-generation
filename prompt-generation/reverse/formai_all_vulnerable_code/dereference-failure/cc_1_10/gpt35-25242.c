//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IP 15
#define MAX_CIDR 2

char *decimal_to_binary(int decimal)
{
    char *binary = malloc(sizeof(char) * 8);
    int i = 0;

    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    binary[i] = '\0';

    int len = strlen(binary);
    char *reverse = malloc(sizeof(char) * len);
    for (i = 0; i < len; i++)
        reverse[len - i - 1] = binary[i];

    free(binary);

    return reverse;
}

int binary_to_decimal(char *binary)
{
    int decimal = 0;
    int base = 1;
    int i, len;

    len = strlen(binary);

    for (i = len - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += base;
        base *= 2;
    }

    return decimal;
}

void calculate_subnet(char *ip, char *cidr)
{
    int i, j;
    char *binary_ip[4], *binary_subnet[4];
    char *binary_cidr = decimal_to_binary(atoi(cidr));
    int nzeroes = 0;
    int subnet_mask[4];

    memset(binary_ip, 0, sizeof(binary_ip));
    memset(binary_subnet, 0, sizeof(binary_subnet));
    memset(subnet_mask, 0, sizeof(subnet_mask));

    for (i = 0, j = 0; ip[i] != '\0'; i++) {
        if (ip[i] == '.') {
            j++;
            continue;
        }

        binary_ip[j] = realloc(binary_ip[j], strlen(binary_ip[j]) + 8);
        strcat(binary_ip[j], decimal_to_binary(ip[i] - '0'));
    }

    for (i = 0; i < strlen(binary_cidr); i++)
        if (binary_cidr[i] == '0')
            nzeroes++;

    printf("IP address: %s\n", ip);
    printf("CIDR: %s\n", cidr);

    printf("Binary IP address: ");
    for (i = 0; i < 4; i++)
        printf("%s ", binary_ip[i]);
    printf("\n");

    for (i = 0; i < nzeroes; i++)
        binary_cidr[strlen(binary_cidr) - i - 1] = '1';

    for (i = 0; i < 32; i += 8)
        binary_subnet[i/8] = strndup(binary_cidr+i, 8);

    printf("Binary subnet mask: ");
    for (i = 0; i < 4; i++)
        printf("%s ", binary_subnet[i]);
    printf("\n");

    for (i = 0; i < 4; i++)
        subnet_mask[i] = binary_to_decimal(binary_subnet[i]);

    printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

    printf("\n");

    free(binary_cidr);
    for (i = 0; i < 4; i++) {
        free(binary_ip[i]);
        free(binary_subnet[i]);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s IP CIDR\n", argv[0]);
        return 1;
    }

    calculate_subnet(argv[1], argv[2]);

    return 0;
}