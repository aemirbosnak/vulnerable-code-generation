//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PASS_LEN 1024

int main()
{
    system("/bin/rm -rf /tmp/pwdgen");
    system("/bin/mkdir /tmp/pwdgen");
    system("/bin/chown root:root /tmp/pwdgen");

    char *pass = NULL;
    int pass_len = 0;

    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < MAX_PASS_LEN; i++)
    {
        int r = rand() % 3;
        switch (r)
        {
            case 0:
                pass = realloc(pass, pass_len + 1);
                pass[pass_len++] = 'a' + rand() % 26;
                break;
            case 1:
                pass = realloc(pass, pass_len + 1);
                pass[pass_len++] = 'A' + rand() % 26;
                break;
            case 2:
                pass = realloc(pass, pass_len + 1);
                pass[pass_len++] = rand() % 10 + '0';
                break;
        }
    }

    pass = realloc(pass, pass_len + 1);
    pass[pass_len++] = '\0';

    FILE *fp = fopen("/tmp/pwdgen/pass.txt", "w");
    fprintf(fp, "%s", pass);
    fclose(fp);

    system("/bin/rm -rf /tmp/pwdgen");

    return 0;
}