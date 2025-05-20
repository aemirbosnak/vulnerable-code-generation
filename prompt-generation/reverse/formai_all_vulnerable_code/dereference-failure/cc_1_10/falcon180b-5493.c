//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

struct fortune {
    char *text;
    int lucky_number;
};

void generate_fortunes(struct fortune fortunes[NUM_FORTUNES]) {
    srand(time(NULL));

    for (int i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].text = malloc(50 * sizeof(char));
        fortunes[i].lucky_number = rand() % 100;

        switch (fortunes[i].lucky_number) {
            case 0:
                strcpy(fortunes[i].text, "You will have good luck today. ");
                break;
            case 1:
                strcpy(fortunes[i].text, "A new opportunity will come your way. ");
                break;
            case 2:
                strcpy(fortunes[i].text, "You will meet someone special soon. ");
                break;
            case 3:
                strcpy(fortunes[i].text, "Your hard work will pay off. ");
                break;
            case 4:
                strcpy(fortunes[i].text, "You will receive unexpected good news. ");
                break;
            case 5:
                strcpy(fortunes[i].text, "Your financial situation will improve. ");
                break;
            case 6:
                strcpy(fortunes[i].text, "You will have a successful trip or journey. ");
                break;
            case 7:
                strcpy(fortunes[i].text, "You will overcome a challenge or obstacle. ");
                break;
            case 8:
                strcpy(fortunes[i].text, "You will have a lucky day in love. ");
                break;
            case 9:
                strcpy(fortunes[i].text, "You will have a good day for creativity or inspiration. ");
                break;
            default:
                strcpy(fortunes[i].text, "Your lucky number is not on this list. ");
        }
    }
}

void print_fortune(struct fortune fortune) {
    printf("Your lucky number is %d.\n", fortune.lucky_number);
    printf("Your fortune: %s\n", fortune.text);
}

int main() {
    struct fortune fortunes[NUM_FORTUNES];

    generate_fortunes(fortunes);

    int choice;
    printf("Enter the number of the fortune you want to read:\n");
    for (int i = 0; i < NUM_FORTUNES; i++) {
        printf("%d. %s\n", i+1, fortunes[i].text);
    }

    scanf("%d", &choice);

    print_fortune(fortunes[choice-1]);

    return 0;
}