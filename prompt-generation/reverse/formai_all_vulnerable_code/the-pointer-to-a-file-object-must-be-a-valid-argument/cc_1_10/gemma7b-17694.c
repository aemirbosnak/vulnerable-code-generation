//Gemma-7B DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 0, n, m, k, l, r;
    char str[1000], cmd[100], tmp[100];
    FILE *fp;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of lines for the test case: ");
        scanf("%d", &m);

        printf("Enter the command: ");
        scanf("%s", cmd);

        printf("Enter the left and right indices: ");
        scanf("%d %d", &l, &r);

        fp = fopen("test.txt", "w");

        for (k = 0; k < m; k++)
        {
            printf("Enter the line: ");
            scanf("%s", tmp);
            fprintf(fp, "%s\n", tmp);
        }

        fclose(fp);

        system(cmd);

        printf("The output of the command is:\n");
        FILE *fp2 = fopen("test.txt", "r");
        while (fgets(str, 1000, fp2) != NULL)
        {
            printf("%s", str);
        }
        fclose(fp2);

        printf("\n");
    }

    return 0;
}