//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 256

struct signature {
    char *name;
    unsigned char *pattern;
    int len;
};

struct signature signatures[MAX_SIGS];
int num_sigs = 0;

void load_signatures() {
    FILE *fp = fopen("signatures.txt", "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ":");
        char *pattern = strtok(NULL, "\n");

        int len = strlen(pattern) / 2;
        unsigned char *buf = malloc(len);
        for (int i = 0; i < len; i++) {
            char c = pattern[i * 2];
            int n;
            if (c >= '0' && c <= '9')
                n = c - '0';
            else if (c >= 'a' && c <= 'f')
                n = c - 'a' + 10;
            else if (c >= 'A' && c <= 'F')
                n = c - 'A' + 10;
            else
                continue;
            buf[i] = n << 4;
            c = pattern[i * 2 + 1];
            if (c >= '0' && c <= '9')
                n = c - '0';
            else if (c >= 'a' && c <= 'f')
                n = c - 'a' + 10;
            else if (c >= 'A' && c <= 'F')
                n = c - 'A' + 10;
            else
                continue;
            buf[i] |= n;
        }

        struct signature sig = {name, buf, len};
        signatures[num_sigs++] = sig;
    }

    fclose(fp);
}

int scan_file(FILE *fp) {
    unsigned char buf[4096];
    while (fread(buf, 1, sizeof(buf), fp) > 0) {
        for (int i = 0; i < num_sigs; i++) {
            struct signature *sig = &signatures[i];
            for (int j = 0; j < sizeof(buf) - sig->len; j++) {
                if (memcmp(buf + j, sig->pattern, sig->len) == 0) {
                    printf("Found %s at offset %d\n", sig->name, j);
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_signatures();

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    int infected = scan_file(fp);

    fclose(fp);

    return infected;
}