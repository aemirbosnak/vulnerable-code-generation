//FormAI DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to C File Synchronizer!\nAre you ready to synchronize your files? (y/n)\n");

    char answer[2];
    fgets(answer, 2, stdin);

    if (strcmp(answer, "y") == 0) {
        printf("Great! Please enter the name of the first file.\n");
        char file1[100];
        fgets(file1, sizeof(file1), stdin);

        printf("Please enter the name of the second file.\n");
        char file2[100];
        fgets(file2, sizeof(file2), stdin);

        FILE* fp1 = fopen(file1, "r");
        FILE* fp2 = fopen(file2, "r");
        if (fp1 == NULL || fp2 == NULL) {
            printf("Error opening files.\n");
            return 1;
        }

        printf("Synchronizing files: %s and %s\n", file1, file2);

        char ch1 = getc(fp1);
        char ch2 = getc(fp2);

        int line = 1;
        while (ch1 != EOF || ch2 != EOF)
        {
            if (ch1 == '\n' && ch2 == '\n') line++;

            if (ch1 != ch2) {
                printf("Difference found at line %d.\n", line);
                break;
            }

            ch1 = getc(fp1);
            ch2 = getc(fp2);
        }

        printf("Synchronization complete!\n");
        fclose(fp1);
        fclose(fp2);
        return 0;

    } else {
        printf("No problem, maybe next time!\n");
        return 0;
    }

}