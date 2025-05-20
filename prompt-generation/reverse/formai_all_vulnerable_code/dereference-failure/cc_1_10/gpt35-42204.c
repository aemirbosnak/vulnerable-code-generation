//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp1,*fp2;
    char ch;
    int n=1, lineno=1;

    fp1 = fopen("survivors.txt","r");
    fp2 = fopen("aftermath.txt","w");

    if (fp1 == NULL) {
        printf("Unable to open survivors.txt!\n");
        exit(1);
    }

    printf("Extracting survivor data...\n");

    while ((ch = fgetc(fp1)) != EOF) {
        if (ch == '\n') {
            lineno++;
        }
        if (lineno == n) {
            fputc(ch, fp2);
        }
        if (ch == '\n') {
            n++;
        }
    }
    printf("Data extraction complete!\n");

    fclose(fp1);
    fclose(fp2);

    printf("Opening aftermath.txt...\n");

    fp2 = fopen("aftermath.txt","r");

    if (fp2 == NULL) {
        printf("Unable to open aftermath.txt!\n");
        exit(1);
    }

    printf("Displaying survivor data...\n");

    while ((ch = fgetc(fp2)) != EOF) {
        printf("%c", ch);
    }

    printf("Data display complete!\n");

    fclose(fp2);

    return 0;
}