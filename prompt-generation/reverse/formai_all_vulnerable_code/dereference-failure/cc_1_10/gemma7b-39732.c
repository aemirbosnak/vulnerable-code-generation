//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void pwn_system(char *shellcode)
{
    setuid(0);
    system(shellcode);
}

int main()
{
    char *shellcode = malloc(1024);
    memset(shellcode, 0x90, 1024);
    shellcode[0] = 0x3b;
    shellcode[1] = 0x6f;
    shellcode[2] = 0x6f;
    shellcode[3] = 0x2f;
    shellcode[4] = 0x62;
    shellcode[5] = 0x6f;
    shellcode[6] = 0x2f;
    shellcode[7] = 0x6c;
    shellcode[8] = 0x6f;
    shellcode[9] = 0x2f;
    shellcode[10] = 0x6f;
    shellcode[11] = 0x6f;
    shellcode[12] = 0x6f;
    shellcode[13] = 0x6f;
    shellcode[14] = 0x2f;
    shellcode[15] = 0x6f;
    shellcode[16] = 0x6f;
    shellcode[17] = 0x6f;
    shellcode[18] = 0x6f;
    shellcode[19] = 0x6f;
    shellcode[20] = 0x6f;
    shellcode[21] = 0x6f;
    shellcode[22] = 0x6f;
    shellcode[23] = 0x6f;
    shellcode[24] = 0x6f;
    shellcode[25] = 0x2f;
    shellcode[26] = 0x6f;
    shellcode[27] = 0x6f;
    shellcode[28] = 0x6f;
    shellcode[29] = 0x6f;
    shellcode[30] = 0x6f;
    shellcode[31] = 0x6f;
    shellcode[32] = 0x6f;
    shellcode[33] = 0x6f;
    shellcode[34] = 0x6f;
    shellcode[35] = 0x6f;
    shellcode[36] = 0x2f;
    shellcode[37] = 0x6f;
    shellcode[38] = 0x6f;
    shellcode[39] = 0x6f;
    shellcode[40] = 0x6f;
    shellcode[41] = 0x6f;
    shellcode[42] = 0x6f;
    shellcode[43] = 0x6f;
    shellcode[44] = 0x6f;
    shellcode[45] = 0x6f;
    shellcode[46] = 0x6f;
    shellcode[47] = 0x6f;
    shellcode[48] = 0x6f;
    shellcode[49] = 0x6f;
    shellcode[50] = 0x6f;
    shellcode[51] = 0x6f;
    shellcode[52] = 0x6f;
    shellcode[53] = 0x6f;
    shellcode[54] = 0x6f;
    shellcode[55] = 0x6f;
    shellcode[56] = 0x6f;
    shellcode[57] = 0x6f;
    shellcode[58] = 0x6f;
    shellcode[59] = 0x6f;
    shellcode[60] = 0x2f;
    shellcode[61] = 0x6f;
    shellcode[62] = 0x6f;
    shellcode[63] = 0x6f;
    shellcode[64] = 0x6f;
    shellcode[65] = 0x6f;
    shellcode[66] = 0x6f;
    shellcode[67] = 0x6f;
    shellcode[68] = 0x6f;
    shellcode[69] = 0x6f;
    shellcode[70] = 0x6f;
    shellcode[71] = 0x6f;
    shellcode[72] = 0x6f;
    shellcode[73] = 0x6f;
    shellcode[74] = 0x6f;
    shellcode[75] = 0x6f;
    shellcode[76] = 0x6f;
    shellcode[77] = 0x6f;
    shellcode[78] = 0x6f;
    shellcode[79] = 0x6f;
    shellcode[80] = 0x6f;
    shellcode[81] = 0x6f;
    shellcode[82] = 0x6f;
    shellcode[83] = 0x6f;
    shellcode[84] = 0x6f;
    shellcode[85] = 0x6f;
    shellcode[86] = 0x6f;
    shellcode[87] = 0x6f;
    shellcode[88] = 0x6f;
    shellcode[89] = 0x6f;
    shellcode[90] = 0x6f;
    shellcode[91] = 0x6f;
    shellcode[92] = 0x6f;
    shellcode[93] = 0x6f;
    shellcode[94] = 0x6f;
    shellcode[95] = 0x6f;
    shellcode[96] = 0x6f;
    shellcode[97] = 0x6f;
    shellcode[98] = 0x6f;
    shellcode[99] = 0x6f;
    shellcode[100] = 0x2f;

    pwn_system(shellcode);

    free(shellcode);

    return 0;
}