//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
// Welcome to the Neon City, where algorithms dance in cyberspace!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cyberpunk-themed ASCII
const char* ascii =
"                ___--___                \n\
          .--.-'  /  _/_/ /  '-. --.       \n\
      .-' _/ /  / / / / /  \\ _/ _ '-.     \n\
     /_ / / /_  |/ / / / // _\\ \ \ _\\    \n\
    // / / / /  --- / / // / \_\\ \ / /    \n\
   // / / / /        / / // /     \ \ \_   \n\
   \\ \ \_ \\_//     / / // /       \__/   \n\
    \\\\__\\  /      / /// /___          \n\
     `----' /      / /// /___          \n\
     ,------'      / /// /___           \n\
    / /        _.-'/ /  ----'          \n\
    \\ \\      //     \\__                 \n\
     \\ \\    //       \\ \\                \n\
      \\ \\  //        \\ \\               \n\
       \\ \\//          \\ \\              \n\
        \ `\            \\ \\             \n\
         '. '.           \\ \\            \n\
           '.'.           \\ \\           \n\
            '.'.           \\ \\          \n\
             '.'.           \\ \\         \n\
              '.'.           \\ \\        \n\
               '.'.           \\ \\       \n\
                '.'.           \\ \\      \n\
                 '.'.           \\ \\     \n\
                  '.'.           \\ \\    \n\
                   '.'.           \\ \\   \n\
                    '.'.           \\ \\  \n\
                     '.'.           \\ \\ \n\
                      '.'.           \\ \\\n\
                       '.'.           \\\n\
                        '.'.           \\\n\
                         '.'.           \\\n\
                          '.'.           \\\n\
                           '.'.           \\\n\
                            '.'.           \\\n\
                             '.'.           \\\n\
                              '.'.           \\\n\
                               '.'.           \\\n\
                                '. '.           \\\\\n\
                                  '. '.          \\ \\\n\
                                    '. '.         \\  \\\n\
                                      '. '.        \\   \\\n\
                                        '. '.       \\    \\\n\
                                          '. '.      \\     \\\n\
                                            '. '.     \\      \\\n\
                                              '. '.    \\       \\\n\
                                                '. '.   \\        \\\n\
                                                  '. '.  \\         \\\n\
                                                    '. '. \\          \\\n\
                                                      '. '.\\           \\\n\
                                                        '. '.\            \\\n\
                                                          '. '.\             \\\n\
                                                            '. '.\              \\\n";

// Function to generate a random array within a given range
int* generate_random_array(int size, int range) {
    int* arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
    return arr;
}

// Cyberpunk-themed linear search function
int linear_search(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Main function - the entry point of your program
int main() {
    srand(time(NULL)); // Initialize the random number generator

    // Welcome message in Cyberpunk style
    printf("\n\n%s\n\n", ascii);
    printf("Welcome to Neon City, where algorithms walk the mean streets.\n");
    printf("Prepare to witness a relentless hunt using the Linear Search algorithm.\n\n");

    // Array size and range
    int size = 10; // Number of elements in the array
    int range = 100; // Range of values for the elements

    // Generate a random array
    int* arr = generate_random_array(size, range);

    // Target value to search for
    int target = 55;

    // Initiate the search
    int result = linear_search(arr, size, target);

    // Display the search result in a Cyberpunk-esque manner
    if (result == -1) {
        printf("Target not located. The hunt ends in disappointment.\n");
    } else {
        printf("Target found at index %d. The search concludes with a cybernetic victory.\n", result);
    }

    printf("\n\n");

    return 0; // Program ends successfully
}