//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surrealist Fortune Teller

#define MAX_FORTUNES 100
#define FORTUNE_LENGTH 80

struct fortune {
    char text[FORTUNE_LENGTH];
};

void generate_fortunes() {
    FILE *fortunes_file = fopen("fortunes.txt", "w");
    if (fortunes_file == NULL) {
        printf("Error: Could not create fortunes file.\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < MAX_FORTUNES; i++) {
        struct fortune fortune = {0};
        char *adjective = "mysterious, surreal, bizarre, strange, dreamlike, whimsical, absurd, nonsensical";
        char *noun = "vision, prophecy, omen, prediction, revelation, message, sign, portent";
        char *verb = "reveals, foretells, predicts, warns, advises, counsels, guides, instructs";

        sprintf(fortune.text, "A %s %s %s your future.", adjective[rand() % strlen(adjective) - 1], noun[rand() % strlen(noun) - 1], verb[rand() % strlen(verb) - 1]);

        fprintf(fortunes_file, "%s\n", fortune.text);
    }

    fclose(fortunes_file);
}

void tell_fortune() {
    FILE *fortunes_file = fopen("fortunes.txt", "r");
    if (fortunes_file == NULL) {
        printf("Error: Could not open fortunes file.\n");
        exit(1);
    }

    char fortune_text[FORTUNE_LENGTH] = {0};
    fgets(fortune_text, FORTUNE_LENGTH, fortunes_file);

    printf("%s\n", fortune_text);

    fclose(fortunes_file);
}

int main() {
    generate_fortunes();
    tell_fortune();

    return 0;
}