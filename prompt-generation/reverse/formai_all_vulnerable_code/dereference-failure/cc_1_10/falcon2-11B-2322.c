//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define MAX_LEN (1024)

int main(int argc, char **argv)
{
    unsigned char hash[MD5_DIGEST_LENGTH];
    unsigned char *buf;
    int len;
    int n;

    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    len = strlen(argv[1]);
    if (len > MAX_LEN)
    {
        fprintf(stderr, "Text too long (max %d characters)\n", MAX_LEN);
        return 1;
    }

    buf = (unsigned char *)malloc(len + 1);
    if (buf == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        return 1;
    }

    memset(buf, 0, len + 1);
    memcpy(buf, argv[1], len);

    MD5_CTX md;
    MD5_Init(&md);
    MD5_Update(&md, buf, len);
    MD5_Final(hash, &md);

    printf("Hash: ");
    for (n = 0; n < MD5_DIGEST_LENGTH; n++)
        printf("%02x", hash[n]);
    printf("\n");

    free(buf);

    return 0;
}