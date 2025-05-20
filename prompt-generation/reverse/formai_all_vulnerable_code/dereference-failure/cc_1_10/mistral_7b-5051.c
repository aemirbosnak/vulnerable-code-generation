//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ada Lovelace, the first computer programmer, would have used elegant names
typedef struct {
    char name[50];
    char email[100];
} Subscriber;

// Subscription list, managed by the noble Countess of MailingList
Subscriber * subscribers = NULL;
int subscriberCount = 0;

// Countess, gracious and generous, accepts new subscribers
void addSubscriber(char * name, char * email) {
    if (subscriberCount + 1 > 100) {
        printf("Countess' mailing list is full.\n");
        return;
    }

    Subscriber * newSubscriber = malloc(sizeof(Subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);

    subscribers = realloc(subscribers, (subscriberCount + 1) * sizeof(Subscriber));
    subscribers[subscriberCount++] = *newSubscriber;
}

// Countess, ever watchful, sends out her newsletter to all subscribers
void sendNewsletter() {
    printf("Sending newsletter to %d subscribers:\n", subscriberCount);

    for (int i = 0; i < subscriberCount; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
        // Send email using some library or API here
    }
}

// Countess, wise and prudent, allows subscribers to unsubscribe
void removeSubscriber(int index) {
    if (index < 0 || index >= subscriberCount) {
        printf("Invalid index.\n");
        return;
    }

    Subscriber * temp = &subscribers[index];
    for (int i = index; i < subscriberCount - 1; i++) {
        subscribers[i] = subscribers[i + 1];
    }

    subscribers = realloc(subscribers, (subscriberCount - 1) * sizeof(Subscriber));
    free(temp);
    subscriberCount--;
}

int main() {
    addSubscriber("Lady Grace", "ladygrace@example.com");
    addSubscriber("Lord Charming", "lordcharming@example.com");

    sendNewsletter();

    addSubscriber("Duke Dashing", "dukedashing@example.com");
    sendNewsletter();

    removeSubscriber(0);
    sendNewsletter();

    return 0;
}