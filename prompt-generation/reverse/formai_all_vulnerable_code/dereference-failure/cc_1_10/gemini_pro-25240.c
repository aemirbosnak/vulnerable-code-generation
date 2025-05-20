//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
// Embark on a Mail Management Odyssey:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our Mail Recipient as a Captain of Data
typedef struct Recipient {
    char name[50];  // Ahoy, Matey! Stow yer name!
    char email[50]; // Ready yer email, for messages shall sail!
} Recipient;

// And now, for our esteemed Captain's Log:
typedef struct Log {
    Recipient recipient; // Our fearless recipient stands ready!
    char subject[100];  // The subject: a beacon to guide our message
    char message[256];  // The message itself: a treasure to be deciphered
} Log;

// Our grand ship, ready to set sail with a crew of Logs:
typedef struct List {
    Log *logs;       // Our logbook, chronicling every voyage
    int num_logs;    // The count of our maritime adventures
    int max_capacity;// Our ship's capacity: how many logs can it hold?
} List;

// Prepare our vessel for its maiden voyage:
List* create_list(int size) {
    List *list = (List*) malloc(sizeof(List));
    list->logs = (Log*) malloc(sizeof(Log) * size);
    list->num_logs = 0;
    list->max_capacity = size;
    return list;
}

// Avast! Retrieve a log by its unique number:
Log* get_log(List *list, int index) {
    if (index >= 0 && index < list->num_logs)
        return &list->logs[index];
    return NULL; // Return a ghostly log if index be out of bounds
}

// Hoist the sails! Add a new log to our list:
void add_log(List *list, Log log) {
    if (list->num_logs < list->max_capacity) {
        list->logs[list->num_logs] = log;
        list->num_logs++;
    } else {
        printf("Shiver me timbers! Our ship be full!\n");
    }
}

// Let us send forth a message to the boundless sea:
void send_message(Log log) {
    printf("Hoist the message flag!\n");
    printf("To: %s\n", log.recipient.name);
    printf("Email: %s\n", log.recipient.email);
    printf("Subject: %s\n", log.subject);
    printf("Message: %s\n", log.message);
    printf("Message sent, matey!\n");
}

// Argh, prune the list of old logs:
void prune_logs(List *list, int threshold) {
    int i = 0;
    while (i < list->num_logs) {
        if (list->logs[i].recipient.email[0] < threshold) {
            // This log be old! Cast it overboard!
            for (int j = i; j < list->num_logs - 1; j++) {
                list->logs[j] = list->logs[j + 1];
            }
            list->num_logs--;
        } else {
            i++; // Keep this log, it be a treasure!
        }
    }
    printf("Logs pruned, matey!\n");
}

// And now, let us hoist our anchors and set sail!
int main() {
    // Let us create our very own list of logs, matey!
    List *list = create_list(10);

    // Let us add some logs to our list, filled with messages for our fellow sailors:
    Log log1 = {{"Captain Jack", "jack@seas.com"}, "Treasure Map", "X marks the spot!"};
    Log log2 = {{"First Mate Mary", "mary@seas.com"}, "New Land Ho!", "Prepare the cannons!"};
    Log log3 = {{"Bosun Bill", "bill@seas.com"}, "Kraken Attacked!", "Send more rum!"};

    add_log(list, log1);
    add_log(list, log2);
    add_log(list, log3);

    // Let us send forth these messages, spreading cheer and tidings across the waves:
    send_message(list->logs[0]);
    send_message(list->logs[1]);
    send_message(list->logs[2]);

    // Time to clean up our ship, matey! Let us prune the old logs, keeping only those that be worthy:
    prune_logs(list, 90);

    // And now, let us disembark with our list, ready for new adventures on the boundless digital sea!
    free(list->logs);
    free(list);

    return 0; // Our voyage ends, but the digital seas call for more adventures!
}