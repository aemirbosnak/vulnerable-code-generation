//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int argc, char *argv[])
{
    int i;
    char *buf;
    FILE *fp;
    srand(time(NULL));

    // Read the script from the file
    fp = fopen("haunted_house.txt", "r");
    buf = (char *)malloc(1024);
    fread(buf, 1024, 1, fp);
    fclose(fp);

    // Spook the user
    for (i = 0; buf[i] != '\0'; i++)
    {
        switch (buf[i])
        {
            case 'M':
                printf("A cold wind blows through the halls...\n");
                break;
            case 'F':
                printf("The smell of decay fills the air...\n");
                break;
            case 'S':
                printf("The sound of a dripping faucet echoes through the house...\n");
                break;
            case 'H':
                printf("You hear footsteps in the hallway...\n");
                break;
            case 'N':
                printf("A disembodied voice whispers your name...\n");
                break;
            default:
                break;
        }
        sleep(rand() % 3);
    }

    // Release the memory
    free(buf);

    return;
}

int main()
{
    haunted_house(0, NULL);

    return 0;
}