//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int checksum(char* data, int len) {
    int sum = 0;
    for(int i=0; i<len; i++) {
        sum += tolower(data[i]);
    }
    return sum;
}

int main(int argc, char* argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <filename> <output>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");
    if(f == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char* data = (char*)malloc(1024);
    int len = 0;

    while(!feof(f)) {
        int c = fgetc(f);
        if(c == EOF) {
            break;
        }
        if(len >= 1024) {
            printf("Error: file %s is too large\n", argv[1]);
            free(data);
            fclose(f);
            return 1;
        }
        data[len++] = c;
    }

    int checksum_val = checksum(data, len);
    sprintf(data+len, "%d", checksum_val);
    len += 4;

    FILE* out = fopen(argv[2], "wb");
    if(out == NULL) {
        printf("Error: could not create file %s\n", argv[2]);
        free(data);
        fclose(f);
        return 1;
    }

    fwrite(data, len, 1, out);
    fclose(out);
    fclose(f);
    free(data);

    return 0;
}