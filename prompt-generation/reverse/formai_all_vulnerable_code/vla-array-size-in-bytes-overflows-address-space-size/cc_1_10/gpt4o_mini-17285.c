//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>

typedef struct {
    int item;         // What you carry, an item so grand
    int value;       // Its worth in gold, to fill up your hand
    int weight;      // Its weight on your back, a balancing act
    float ratio;     // Value to weight, a prudent pact
} Item;

// Function to compare two items based on their value/weight ratio
int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    return (item2->ratio - item1->ratio); // For sorting, high to low
}

// The greedy knight's adventure begins!
void fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare); // Sort the items, oh so bold

    float totalValue = 0.0; // The treasure amassed, as the story unfolds

    // The journey through each item unfolds
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Full treasure, we claim it all
            capacity -= items[i].weight; // The scale does not stall
            totalValue += items[i].value; // Our fortune does sprawl
            printf("Took item %d (Full) - Weight: %d, Value: %d\n",
                   items[i].item, items[i].weight, items[i].value);
        } else {
            // A parting with grace, we take what we can
            float fraction = (float)capacity / items[i].weight; // Hoisting the plan
            totalValue += items[i].value * fraction; // Our share from the can
            printf("Took item %d (Fraction) - Weight: %d, Value: %.2f\n",
                   items[i].item, capacity, items[i].value * fraction);
            break; // The quest completes, we rest our hand
        }
    }
    printf("Total value in the knapsack: %.2f\n", totalValue); // A grand final stand
}

int main() {
    int n; // Number of items, for the tale to be told

    // The whisper of input, the dataset unfolds
    printf("Enter the number of items: ");
    scanf("%d", &n); // The true battle begins

    // The declaration of a band of items, poised for the dance
    Item items[n];
    
    printf("Enter item details (Item, Value, Weight):\n");
    for (int i = 0; i < n; i++) {
        items[i].item = i + 1; // Label our heroes with numbers, unique chance
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight; // Their strength in balance
    }

    int capacity; // The strength of the vessel, its limit we must embody
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity); // The bounds of our journey, we shall not be gaudy

    fractionalKnapsack(capacity, items, n); // The pressing call of adventure expounds

    return 0; // The end of a quest, the cycle now rounds
}