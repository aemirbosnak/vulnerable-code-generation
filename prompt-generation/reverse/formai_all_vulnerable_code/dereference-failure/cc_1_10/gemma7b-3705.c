//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAPID_MODE 0xDEADBEEF

void _wibble(int argc, char **argv) {
    char key[20] = "THE_SECRET_KEY";
    int i = 0;
    char **phone_book = NULL;
    FILE *fp = fopen("phonebook.txt", "r");
    if (fp) {
        phone_book = malloc(sizeof(char *) * 20);
        for (; i < 20; i++) {
            phone_book[i] = malloc(sizeof(char) * 20);
        }
        while (!feof(fp)) {
            fscanf(fp, "%s %s\n", phone_book[i], phone_book[i + 1]);
            i += 2;
        }
        fclose(fp);
    } else {
        fprintf(stderr, "Error opening phonebook.txt\n");
        exit(1);
    }

    // Now, the real fun begins...

    char query[20] = "SEARCH_FOR_NAME";
    int found = 0;
    for (i = 0; i < 20; i++) {
        if (strcmp(query, phone_book[i]) == 0) {
            found = 1;
            printf("%s: %s\n", phone_book[i], phone_book[i + 1]);
        }
    }

    if (!found) {
        printf("Name not found.\n");
    }

    // Cleanup...

    for (i = 0; i < 20; i++) {
        free(phone_book[i]);
    }
    free(phone_book);

    return;
}

int main() {
    _wibble(0, NULL);
    return 0;
}