//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_BUFFER_SIZE 1024

// function to convert IP address in decimal form to binary
void convert_ip_to_binary(int ip[], char* binary_ip)
{
    sprintf(binary_ip, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

// function to convert subnet mask in decimal form to binary
void convert_subnet_mask_to_binary(int subnet_mask, char* binary_subnet_mask)
{
    int binary[32];
    for (int i = 0; i < 32; i++)
    {
        if ((subnet_mask >> i) & 1)
            binary[31 - i] = 1;
        else
            binary[31 - i] = 0;
    }

    sprintf(binary_subnet_mask, "%d.%d.%d.%d", binary[0]*128 + binary[1]*64 + binary[2]*32 + binary[3]*16 + binary[4]*8 + binary[5]*4 + binary[6]*2 + binary[7]*1,
                                                binary[8]*128 + binary[9]*64 + binary[10]*32 + binary[11]*16 + binary[12]*8 + binary[13]*4 + binary[14]*2 + binary[15]*1,
                                                binary[16]*128 + binary[17]*64 + binary[18]*32 + binary[19]*16 + binary[20]*8 + binary[21]*4 + binary[22]*2 + binary[23]*1,
                                                binary[24]*128 + binary[25]*64 + binary[26]*32 + binary[27]*16 + binary[28]*8 + binary[29]*4 + binary[30]*2 + binary[31]*1);
}

// function to get number of host bits from subnet mask
int get_host_bits_from_subnet_mask(int subnet_mask)
{
    int host_bits = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((subnet_mask >> i) & 1)
            break;
        else
            host_bits++;
    }

    return host_bits;
}

// function to convert IP address to array
void convert_ip_to_array(char* ip, int* ip_array)
{
    const char* delim = ".";
    char* token;
    char* ip_copy = strdup(ip);

    int index = 0;
    token = strtok(ip_copy, delim);

    while (token != NULL)
    {
        ip_array[index] = atoi(token);
        token = strtok(NULL, delim);
        index++;
    }

    free(ip_copy);
}

// function to perform bitwise AND operation between IP address and subnet mask
void perform_bitwise_and(int* ip_array, int subnet_mask, int* result_array)
{
    for (int i = 0; i < 4; i++)
    {
        result_array[i] = ip_array[i] & (subnet_mask >> (i * 8));
    }
}

int main()
{
    char input[INPUT_BUFFER_SIZE];
    char* token;
    const char* delim = "/";
    char* ip;
    char* subnet_mask_str;
    int subnet_mask;
    int ip_array[4];
    int result_array[4];
    char binary_ip[16];
    char binary_subnet_mask[16];
    int host_bits;

    printf("Enter IP address and subnet mask in CIDR notation: ");
    fgets(input, INPUT_BUFFER_SIZE, stdin);
    strtok(input, "\n");

    token = strtok(input, delim);
    ip = token;
    token = strtok(NULL, delim);
    subnet_mask_str = token;
    subnet_mask = atoi(subnet_mask_str);

    // convert IP address to binary
    convert_ip_to_array(ip, ip_array);
    convert_ip_to_binary(ip_array, binary_ip);

    // convert Subnet mask to binary
    convert_subnet_mask_to_binary(subnet_mask, binary_subnet_mask);

    // perform bitwise AND operation to get network address
    perform_bitwise_and(ip_array, subnet_mask, result_array);

    // get number of host bits from subnet mask
    host_bits = get_host_bits_from_subnet_mask(subnet_mask);

    printf("\n\nIP Address: %s\nBinary IP Address: %s\nSubnet Mask: %s\nBinary Subnet Mask: %s\nNetwork Address: %d.%d.%d.%d/%d\n",
           ip, binary_ip, subnet_mask_str, binary_subnet_mask, result_array[0], result_array[1], result_array[2], result_array[3], 32 - host_bits);

    return 0;
}