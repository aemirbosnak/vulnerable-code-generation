//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crypt(char *str, int *len) {
    int i, j, k;
    char temp;

    for (i = 0, j = *len - 1; i < *len / 2; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    for (i = 0; i < *len; i++) {
        if (str[i] > 'z')
            str[i] -= 32;
        if (str[i] > 'A' && str[i] < 'Z') {
            str[i] += 13;
            if (str[i] > 'Z')
                str[i] -= 26;
        }
    }

    for (i = 0, k = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            str[i] = str[k];
            str[k] = str[i];
            k++;
        }
    }

    *len += 2;
    str[*len] = '\0';
    str[*len + 1] = '\0';
}

int main(int argc, char **argv) {
    char input[100];
    int len;

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    len = strlen(input);
    crypt(input, &len);

    printf("Encrypted String: %.*s\n", len, input);

    return 0;
}