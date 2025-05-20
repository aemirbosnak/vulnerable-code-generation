//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input_file[100], output_file[100], key[100];
    FILE *fp_in, *fp_out;
    int i, j, k, n, len;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    len = strlen(key);
    for (i = 0; i < len; i++) {
        key[i] = tolower(key[i]);
    }

    n = 0;
    while ((fgetc(fp_in))!= EOF) {
        if (isalpha(fgetc(fp_in))) {
            j = tolower(fgetc(fp_in)) - 'a';
            k = tolower(key[n % len]) - 'a';
            fputc((j + k) % 26 + 'a', fp_out);
            n++;
        } else {
            fputc(fgetc(fp_in), fp_out);
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("File encrypted successfully.\n");

    return 0;
}