//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
/* A Romeo and Juliet inspired Website Uptime Monitor */

#include <stdio.h>
#include <stdlib.h>

/* Define constants for ease of use */
#define MAX_URL_LENGTH 100
#define MAX_FAILS_ALLOWED 3

/* Declare structs for holding website data */
struct website {
    char url[MAX_URL_LENGTH];
    int fails;
};

/* Declare function for checking website uptime */
void check_website(struct website* w);

/* Main function */
int main() {
    /* Declare variables */
    struct website* websites;
    int num_websites, i;

    /* Ask Romeo how many websites he wishes to monitor */
    printf("Oh Romeo, how many websites shall we monitor today? ");
    scanf("%d", &num_websites);

    /* Allocate memory for the website struct array */
    websites = (struct website*) malloc(num_websites * sizeof(struct website));

    /* Get the URLs from Romeo */
    for (i = 0; i < num_websites; i++) {
        printf("\nMy sweet Romeo, what is the URL of website number %d? ", i+1);
        scanf("%s", websites[i].url);
        websites[i].fails = 0;
    }

    /* Begin monitoring the websites */
    while (1) {
        printf("\n\n***************** Monitoring Websites *****************\n\n");
        for (i = 0; i < num_websites; i++) {
            check_website(&websites[i]);
            if (websites[i].fails >= MAX_FAILS_ALLOWED) {
                printf("Oh no! %s has failed %d times. Alas, poor website.\n", websites[i].url, websites[i].fails);
                printf("Shall we try again or give up on this site? (1 for try, 0 for give up) ");
                scanf("%d", &websites[i].fails);
                if (websites[i].fails == 1) {
                    websites[i].fails = 0;
                }
            }
        }
        /* Sleep for 30 seconds before checking websites again */
        sleep(30);
    }
    /* Free the allocated memory */
    free(websites);
    return 0;
}

/* Function for checking website uptime */
void check_website(struct website* w) {
    /* Generate random number to simulate website uptime */
    int uptime = rand() % 10;

    /* If uptime is less than or equal to 7, website is up */
    if (uptime <= 7) {
        printf("%s is up!\n", w->url);
        w->fails = 0;
    }
    /* If uptime is greater than 7, website is down */
    else {
        printf("Oh cruel fate! %s is down...again.\n", w->url);
        w->fails += 1;
    }
}