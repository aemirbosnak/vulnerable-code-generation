//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Retro-style Anti-Virus Scanner in C
 * By: Chatbot
 */

int scanFile(char* filename);
void printLogo();

int main(int argc, char* argv[])
{
    if(argc < 2) {
        printf("Usage: %s <file path>\n", argv[0]);
        return 1;
    }

    printLogo();
    int threats_found = scanFile(argv[1]);

    if(threats_found == 0) {
        printf("No threats found\n");
    } 
    else {
        printf("Found %d threat(s)!!!\n", threats_found);
    }

    return 0;
}

/* Scan a file for any malicious signatures */
int scanFile(char* filename) 
{
    FILE* file;
    int threats_found = 0;

    file = fopen(filename, "r");
 
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        if(strstr(line, "virus") != NULL) {
            printf("Virus Found: %s", line);
            threats_found++;
        }
    }

    fclose(file);

    return threats_found;
}

/* Print Retro-Style AntiVirus Software logo ASCII Art */
void printLogo() 
{
    printf("<==============| Retro Antivirus |==============>\n");
    printf("                    \\ | /\n");
    printf("          ._____.    @ @    ,' ,-----.\n");
    printf("          |     |   ,=[,,=]`/ /       \\\n");
    printf("          |_____|  [_/\"\"\"\"\"\\\\_/   /    \\\n");
    printf("       ___|_|___|________|_|____\\_____/___\n");
    printf("<================================================>");
}