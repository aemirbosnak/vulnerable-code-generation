//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct Romeo {
    char name[10];
    int love_count;
} Romeo;

typedef struct Juliet {
    char name[10];
    int love_count;
} Juliet;

void Romeo_s_Love(Romeo *r, const char *str) {
    int len = strlen(str);
    if (str[len - 2] == 'o' && str[len - 1] == 'k') {
        r->love_count++;
    }
}

void Juliet_s_Reply(Juliet *j, const char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == j->name[0]) {
            j->love_count++;
            break;
        }
    }
}

int main() {
    Romeo romeo = {"Romeo", 0};
    Juliet juliet = {"Juliet", 0};
    char *line = (char *)calloc(MAX_LEN, sizeof(char));

    while (fgets(line, MAX_LEN, stdin) != NULL) {
        if (strchr(line, ':') != NULL) { // assume each line contains a ":" as separator
            char *token = strtok(line, ":");
            if (strcmp(token, "Romeo") == 0) {
                Romeo_s_Love(&romeo, line + strlen("Romeo:") + 1);
            } else if (strcmp(token, "Juliet") == 0) {
                Juliet_s_Reply(&juliet, line + strlen("Juliet:") + 1);
            }
        }
    }

    if (romeo.love_count > juliet.love_count) {
        printf("O Romeo, Romeo! wherefore art thou Romeo\n");
        printf("Deny thy father and refuse thy name;\n");
        printf("Or, if thou wilt not, be but sworn my love,\n");
        printf("And I'll no longer be a Capulet.\n");
    } else if (juliet.love_count > romeo.love_count) {
        printf("O fair Juliet, wherefore art thou Juliet,\n");
        printf("Deny thy name, or I'll no longer love thee.\n");
    } else {
        printf("O serendipitous love,\n");
        printf("Equal in our passion and in name.\n");
    }

    free(line);
    return 0;
}