//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for the periodic table */
#define MAX_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3
#define MAX_NAME_LENGTH 30

/* Define a struct to represent an element in the periodic table */
typedef struct {
    int atomic_number;
    char symbol[MAX_SYMBOL_LENGTH];
    char name[MAX_NAME_LENGTH];
} Element;

/* Define a function to initialize an element */
void initialize_element(Element *element, int number, const char *symbol, const char *name){
    element->atomic_number = number;
    strncpy(element->symbol, symbol, MAX_SYMBOL_LENGTH);
    strncpy(element->name, name, MAX_NAME_LENGTH);
}

/* Define a function to print out an element */
void print_element(Element *element){
    printf("%-2d  %-2s  %-20s\n", element->atomic_number, element->symbol, element->name);
}

/* Define a function to print out the periodic table */
void print_periodic_table(Element *table[]){
    printf("%-2s  %-2s  %-20s\n", "Z", "Sym", "Name");
    for(int i = 0; i < MAX_ELEMENTS; i++){
        if(table[i] != NULL){
            print_element(table[i]);
        }
    }
}

int main(){
    /* Allocate memory for the periodic table */
    Element **periodic_table = malloc(sizeof(Element*) * MAX_ELEMENTS);
    if(periodic_table == NULL){
        printf("Error allocating memory for periodic table");
        return 1;
    }

    /* Initialize each element in the periodic table */
    initialize_element(&periodic_table[0][1], 1, "H", "Hydrogen");
    initialize_element(&periodic_table[0][18], 2, "He", "Helium");
    initialize_element(&periodic_table[1][0], 3, "Li", "Lithium");
    initialize_element(&periodic_table[1][1], 4, "Be", "Beryllium");
    initialize_element(&periodic_table[2][0], 5, "B", "Boron");
    initialize_element(&periodic_table[2][1], 6, "C", "Carbon");
    initialize_element(&periodic_table[2][2], 7, "N", "Nitrogen");
    initialize_element(&periodic_table[2][3], 8, "O", "Oxygen");
    initialize_element(&periodic_table[2][4], 9, "F", "Fluorine");
    initialize_element(&periodic_table[2][5], 10, "Ne", "Neon");
    initialize_element(&periodic_table[3][0], 11, "Na", "Sodium");
    initialize_element(&periodic_table[3][1], 12, "Mg", "Magnesium");
    initialize_element(&periodic_table[4][0], 13, "Al", "Aluminum");
    initialize_element(&periodic_table[4][1], 14, "Si", "Silicon");
    initialize_element(&periodic_table[4][2], 15, "P", "Phosphorus");
    initialize_element(&periodic_table[4][3], 16, "S", "Sulfur");
    initialize_element(&periodic_table[4][4], 17, "Cl", "Chlorine");
    initialize_element(&periodic_table[4][5], 18, "Ar", "Argon");
    initialize_element(&periodic_table[5][0], 19, "K", "Potassium");
    initialize_element(&periodic_table[5][1], 20, "Ca", "Calcium");
    initialize_element(&periodic_table[5][12], 21, "Sc", "Scandium");
    initialize_element(&periodic_table[5][13], 22, "Ti", "Titanium");
    initialize_element(&periodic_table[5][14], 23, "V", "Vanadium");
    initialize_element(&periodic_table[5][15], 24, "Cr", "Chromium");
    initialize_element(&periodic_table[5][16], 25, "Mn", "Manganese");
    initialize_element(&periodic_table[5][17], 26, "Fe", "Iron");
    initialize_element(&periodic_table[5][18], 27, "Co", "Cobalt");
    initialize_element(&periodic_table[5][19], 28, "Ni", "Nickel");
    initialize_element(&periodic_table[5][20], 29, "Cu", "Copper");
    initialize_element(&periodic_table[5][21], 30, "Zn", "Zinc");
    initialize_element(&periodic_table[5][22], 31, "Ga", "Gallium");
    initialize_element(&periodic_table[5][23], 32, "Ge", "Germanium");
    initialize_element(&periodic_table[5][24], 33, "As", "Arsenic");
    initialize_element(&periodic_table[5][25], 34, "Se", "Selenium");
    initialize_element(&periodic_table[5][26], 35, "Br", "Bromine");
    initialize_element(&periodic_table[5][27], 36, "Kr", "Krypton");
    initialize_element(&periodic_table[6][0], 37, "Rb", "Rubidium");
    initialize_element(&periodic_table[6][1], 38, "Sr", "Strontium");
    initialize_element(&periodic_table[6][12], 39, "Y", "Yttrium");
    initialize_element(&periodic_table[6][13], 40, "Zr", "Zirconium");
    initialize_element(&periodic_table[6][14], 41, "Nb", "Niobium");
    initialize_element(&periodic_table[6][15], 42, "Mo", "Molybdenum");
    initialize_element(&periodic_table[6][16], 43, "Tc", "Technetium");
    initialize_element(&periodic_table[6][17], 44, "Ru", "Ruthenium");
    initialize_element(&periodic_table[6][18], 45, "Rh", "Rhodium");
    initialize_element(&periodic_table[6][19], 46, "Pd", "Palladium");
    initialize_element(&periodic_table[6][20], 47, "Ag", "Silver");
    initialize_element(&periodic_table[6][21], 48, "Cd", "Cadmium");
    initialize_element(&periodic_table[6][22], 49, "In", "Indium");
    initialize_element(&periodic_table[6][23], 50, "Sn", "Tin");
    initialize_element(&periodic_table[6][24], 51, "Sb", "Antimony");
    initialize_element(&periodic_table[6][25], 52, "Te", "Tellurium");
    initialize_element(&periodic_table[6][26], 53, "I", "Iodine");
    initialize_element(&periodic_table[6][27], 54, "Xe", "Xenon");
    initialize_element(&periodic_table[7][0], 55, "Cs", "Cesium");
    initialize_element(&periodic_table[7][1], 56, "Ba", "Barium");
    initialize_element(&periodic_table[7][12], 57, "La", "Lanthanum");
    initialize_element(&periodic_table[7][13], 58, "Ce", "Cerium");
    initialize_element(&periodic_table[7][14], 59, "Pr", "Praseodymium");
    initialize_element(&periodic_table[7][15], 60, "Nd", "Neodymium");
    initialize_element(&periodic_table[7][16], 61, "Pm", "Promethium");
    initialize_element(&periodic_table[7][17], 62, "Sm", "Samarium");
    initialize_element(&periodic_table[7][18], 63, "Eu", "Europium");
    initialize_element(&periodic_table[7][19], 64, "Gd", "Gadolinium");
    initialize_element(&periodic_table[7][20], 65, "Tb", "Terbium");
    initialize_element(&periodic_table[7][21], 66, "Dy", "Dysprosium");
    initialize_element(&periodic_table[7][22], 67, "Ho", "Holmium");
    initialize_element(&periodic_table[7][23], 68, "Er", "Erbium");
    initialize_element(&periodic_table[7][24], 69, "Tm", "Thulium");
    initialize_element(&periodic_table[7][25], 70, "Yb", "Ytterbium");
    initialize_element(&periodic_table[7][26], 71, "Lu", "Lutetium");
    initialize_element(&periodic_table[7][28], 72, "Hf", "Hafnium");
    initialize_element(&periodic_table[7][29], 73, "Ta", "Tantalum");
    initialize_element(&periodic_table[7][30], 74, "W", "Tungsten");
    initialize_element(&periodic_table[7][31], 75, "Re", "Rhenium");
    initialize_element(&periodic_table[7][32], 76, "Os", "Osmium");
    initialize_element(&periodic_table[7][33], 77, "Ir", "Iridium");
    initialize_element(&periodic_table[7][34], 78, "Pt", "Platinum");
    initialize_element(&periodic_table[7][35], 79, "Au", "Gold");
    initialize_element(&periodic_table[7][36], 80, "Hg", "Mercury");
    initialize_element(&periodic_table[7][37], 81, "Tl", "Thallium");
    initialize_element(&periodic_table[7][38], 82, "Pb", "Lead");
    initialize_element(&periodic_table[7][39], 83, "Bi", "Bismuth");
    initialize_element(&periodic_table[7][40], 84, "Po", "Polonium");
    initialize_element(&periodic_table[7][41], 85, "At", "Astatine");
    initialize_element(&periodic_table[7][42], 86, "Rn", "Radon");
    initialize_element(&periodic_table[8][0], 87, "Fr", "Francium");
    initialize_element(&periodic_table[8][1], 88, "Ra", "Radium");
    initialize_element(&periodic_table[8][12], 89, "Ac", "Actinium");
    initialize_element(&periodic_table[8][13], 90, "Th", "Thorium");
    initialize_element(&periodic_table[8][14], 91, "Pa", "Protactinium");
    initialize_element(&periodic_table[8][15], 92, "U", "Uranium");
    initialize_element(&periodic_table[8][16], 93, "Np", "Neptunium");
    initialize_element(&periodic_table[8][17], 94, "Pu", "Plutonium");
    initialize_element(&periodic_table[8][18], 95, "Am", "Americium");
    initialize_element(&periodic_table[8][19], 96, "Cm", "Curium");
    initialize_element(&periodic_table[8][20], 97, "Bk", "Berkelium");
    initialize_element(&periodic_table[8][21], 98, "Cf", "Californium");
    initialize_element(&periodic_table[8][22], 99, "Es", "Einsteinium");
    initialize_element(&periodic_table[8][23], 100, "Fm", "Fermium");
    initialize_element(&periodic_table[8][24], 101, "Md", "Mendelevium");
    initialize_element(&periodic_table[8][25], 102, "No", "Nobelium");
    initialize_element(&periodic_table[8][26], 103, "Lr", "Lawrencium");
    initialize_element(&periodic_table[8][28], 104, "Rf", "Rutherfordium");
    initialize_element(&periodic_table[8][29], 105, "Db", "Dubnium");
    initialize_element(&periodic_table[8][30], 106, "Sg", "Seaborgium");
    initialize_element(&periodic_table[8][31], 107, "Bh", "Bohrium");
    initialize_element(&periodic_table[8][32], 108, "Hs", "Hassium");
    initialize_element(&periodic_table[8][33], 109, "Mt", "Meitnerium");
    initialize_element(&periodic_table[8][34], 110, "Ds", "Darmstadtium");
    initialize_element(&periodic_table[8][35], 111, "Rg", "Roentgenium");
    initialize_element(&periodic_table[8][36], 112, "Cn", "Copernicium");
    initialize_element(&periodic_table[8][37], 113, "Nh", "Nihonium");
    initialize_element(&periodic_table[8][38], 114, "Fl", "Flerovium");
    initialize_element(&periodic_table[8][39], 115, "Mc", "Moscovium");
    initialize_element(&periodic_table[8][40], 116, "Lv", "Livermorium");
    initialize_element(&periodic_table[8][41], 117, "Ts", "Tennessine");
    initialize_element(&periodic_table[8][42], 118, "Og", "Oganesson");

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Type in the chemical symbol of each element, and see how many you can get right!\n");
    printf("Type \"quit\" to exit the program.\n\n");

    /* Set up variables for the quiz */
    char input[MAX_SYMBOL_LENGTH];
    int num_correct = 0;
    int num_total = 0;

    /* Loop through the quiz */
    while(1){
        /* Pick a random element from the periodic table */
        int index = rand() % MAX_ELEMENTS;
        Element *element = periodic_table[index];

        /* Prompt for input */
        printf("%-20s: ", element->name);
        scanf("%2s", input);

        /* Remove any trailing newline character from input */
        input[strcspn(input, "\n")] = '\0';

        /* Check for quit command */
        if(strcmp(input, "quit") == 0){
            break;
        }

        /* Compare input to the correct symbol for the element */
        if(strcmp(input, element->symbol) == 0){
            printf("Correct!\n");
            num_correct++;
        }
        else{
            printf("Incorrect. The correct symbol is %s.\n", element->symbol);
        }
        num_total++;
    }

    printf("\nYou got %d out of %d correct!\n", num_correct, num_total);

    /* Free memory allocated for the periodic table */
    for(int i = 0; i < MAX_ELEMENTS; i++){
        free(periodic_table[i]);
    }
    free(periodic_table);

    return 0;
}