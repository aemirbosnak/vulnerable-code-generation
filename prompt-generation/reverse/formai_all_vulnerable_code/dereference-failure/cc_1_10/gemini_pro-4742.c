//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 100

typedef struct {
    char *sig;
    int len;
} sig_t;

sig_t sigs[MAX_SIGS];
int num_sigs;

void load_sigs(char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        char *sig = strdup(line);
        if (!sig) {
            perror("strdup");
            exit(1);
        }

        int len = strlen(sig);
        if (len > MAX_SIG_LEN) {
            fprintf(stderr, "Signature too long: %s\n", sig);
            free(sig);
            continue;
        }

        sigs[num_sigs].sig = sig;
        sigs[num_sigs].len = len;
        num_sigs++;
    }

    fclose(f);
}

int scan_file(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *data = malloc(size + 1);
    if (!data) {
        perror("malloc");
        exit(1);
    }

    fread(data, 1, size, f);
    data[size] = '\0';

    int found = 0;
    for (int i = 0; i < num_sigs; i++) {
        char *sig = sigs[i].sig;
        int len = sigs[i].len;

        char *p = data;
        while ((p = strstr(p, sig)) != NULL) {
            found = 1;
            printf("Found signature %d at offset %ld\n", i, p - data);
            p += len;
        }
    }

    free(data);
    fclose(f);

    return found;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <signatures file> <file to scan>\n", argv[0]);
        return 1;
    }

    load_sigs(argv[1]);
    int found = scan_file(argv[2]);

    if (found) {
        printf("File is infected\n");
        return 1;
    } else {
        printf("File is clean\n");
        return 0;
    }
}