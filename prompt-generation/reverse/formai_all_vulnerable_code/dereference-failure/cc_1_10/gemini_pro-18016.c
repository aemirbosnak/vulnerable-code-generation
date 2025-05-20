//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// The unfathomable lexicon of words
char *lex[][2] = {
    {"abacus", "A device for calculating"},
    {"abracadabra", "A magic word"},
    {"acoustic", "Relating to sound"},
    {"acre", "A unit of area"},
    {"acrobat", "A performer who does acrobatic feats"},
    {"acronym", "A word formed from the initial letters of other words"},
    {"actor", "A person who acts in plays or movies"},
    {"actress", "A woman who acts in plays or movies"},
    {"acupuncture", "A system of healing that involves inserting needles into the skin"},
    {"acute", "Sharp or severe"},
    {"adagio", "A slow and graceful dance"},
    {"add", "To join or combine"},
    {"adder", "A venomous snake"},
    {"addict", "A person who is addicted to something"},
    {"address", "The place where someone lives or works"},
    {"adept", "Skilled or proficient"},
    {"adhesive", "A substance that causes things to stick together"},
    {"adjective", "A word that describes a noun"},
    {"admiral", "A high-ranking naval officer"},
    {"admire", "To regard with respect or admiration"},
    {"admission", "The act of admitting"},
    {"adobe", "A type of brick made from sun-dried clay"},
    {"adopt", "To take (a child) into one's family as one's own"},
    {"adore", "To love or admire deeply"},
    {"adrenaline", "A hormone that is released in response to stress"},
    {"adult", "A person who is fully grown"},
    {"adverb", "A word that modifies a verb, adjective, or another adverb"},
    {"adversary", "An opponent or enemy"},
    {"adventure", "An exciting or unusual experience"},
    {"adventurous", "Fond of or seeking adventure"},
    {"adverb", "A word that modifies a verb, adjective, or another adverb"},
    {"aerosol", "A substance that is dispensed as a fine spray"},
    {"aesthetic", "Relating to beauty or art"},
    {"affair", "A relationship, especially a romantic one"},
    {"affect", "To have an effect on"},
    {"affection", "A feeling of fondness or love"},
    {"affidavit", "A written statement that is sworn to be true"},
    {"affiliate", "To associate with"},
    {"affinity", "A natural liking or sympathy"},
    {"affirm", "To state or assert positively"},
    {"affix", "To attach or fasten"},
    {"afflict", "To cause pain or suffering"},
    {"affluent", "Wealthy or prosperous"},
    {"afford", "To have enough money or resources to buy or do something"},
    {"affray", "A fight or brawl"},
    {"affront", "An insult or offense"},
    {"afraid", "Feeling fear or anxiety"},
    {"African", "Relating to Africa or its people"},
    {"after", "Following in time or place"},
    {"afternoon", "The period of time between noon and evening"},
    {"afterthought", "A thought that occurs after something has been said or done"},
    {"afterward", "Following in time or place"},
    {"again", "Once more"}
};

// The enigmatic word counter
int countWords(char *str) {
    int count = 0;
    char *word = strtok(str, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// The inscrutable main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // The ethereal string
    char *str = argv[1];

    // The uncanny word count
    int wordCount = countWords(str);

    // The enigmatic printf
    printf("The string \"%s\" contains %d words.\n", str, wordCount);

    return 0;
}