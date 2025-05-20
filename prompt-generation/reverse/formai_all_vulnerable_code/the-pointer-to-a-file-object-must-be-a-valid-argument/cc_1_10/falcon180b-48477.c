//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define MAX_NUM_OF_FORTUNES 100

typedef struct fortune {
    char* text;
    int length;
} Fortune;

Fortune fortunes[MAX_NUM_OF_FORTUNES];
int num_of_fortunes = 0;

void load_fortunes() {
    FILE* file = fopen("fortunes.txt", "r");
    char line[100];
    while(fgets(line, 100, file)!= NULL) {
        int length = strlen(line);
        if(length > 0 && line[length - 1] == '\n') {
            line[length - 1] = '\0';
        }
        fortunes[num_of_fortunes].text = strdup(line);
        fortunes[num_of_fortunes].length = length;
        num_of_fortunes++;
        if(num_of_fortunes == MAX_NUM_OF_FORTUNES) {
            break;
        }
    }
    fclose(file);
}

void tell_fortune() {
    int index = rand() % num_of_fortunes;
    printf("%s\n", fortunes[index].text);
}

int main(int argc, char** argv) {
    srand(time(NULL));
    load_fortunes();
    while(1) {
        char input[100];
        printf("Ask me anything: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "quit") == 0) {
            break;
        }
        tell_fortune();
    }
    return 0;
}