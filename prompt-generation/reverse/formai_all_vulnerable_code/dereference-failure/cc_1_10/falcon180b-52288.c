//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *position;
    char *organization;
    char *connection;
} Person;

Person *generate_person(void) {
    static char *names[] = {
        "George Soros", "Hillary Clinton", "Barack Obama", "Bill Gates",
        "Mark Zuckerberg", "Elon Musk", "Jeff Bezos", "Angela Merkel",
        "Vladimir Putin", "Xi Jinping", "Kim Jong-un", "Donald Trump"
    };
    static char *positions[] = {
        "billionaire", "politician", "businessman", "philanthropist",
        "CEO", "entrepreneur", "investor", "world leader",
        "dictator", "president", "supreme leader", "reality TV star"
    };
    static char *organizations[] = {
        "Open Society Foundations", "Clinton Foundation", "Democratic Party",
        "Microsoft", "Facebook", "Tesla", "Amazon", "Christian Democratic Union",
        "United Russia", "Workers' Party of Korea", "Republican Party",
        "Trump Organization"
    };
    static char *connections[] = {
        "globalist agenda", "deep state", "liberal media", "tech monopoly",
        "social media censorship", "space exploration", "online retail dominance",
        "European integration", "Russian interference", "nuclear weapons program",
        "Make America Great Again"
    };

    Person *person = malloc(sizeof(Person));
    person->name = names[rand() % sizeof(names) / sizeof(names[0])];
    person->position = positions[rand() % sizeof(positions) / sizeof(positions[0])];
    person->organization = organizations[rand() % sizeof(organizations) / sizeof(organizations[0])];
    person->connection = connections[rand() % sizeof(connections) / sizeof(connections[0])];

    return person;
}

void print_person(const Person *person) {
    printf("Name: %s\n", person->name);
    printf("Position: %s\n", person->position);
    printf("Organization: %s\n", person->organization);
    printf("Connection: %s\n\n", person->connection);
}

int main(void) {
    srand(time(NULL));

    Person *conspiracy[10];
    for (int i = 0; i < 10; ++i) {
        conspiracy[i] = generate_person();
        print_person(conspiracy[i]);
    }

    return 0;
}