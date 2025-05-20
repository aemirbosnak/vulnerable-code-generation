//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int score = 0; //initialize score to 0
    int questions = 0; //initialize questions attempted to 0
    int answer; //initialize user's answer to be entered later
    char choice; //initialize choice for multiple attempts
    
    srand(time(0)); //seed random number generator
    
    printf("\nWelcome to the Periodic Table Quiz Game!\n");
    printf("\nYou will be asked to guess the element based on its symbol.\n");
    printf("\nFor every correct answer, you will receive 5 points.\n");
    printf("\nLet's get started!\n");
    
    do{
        char symbols[118][3] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si",
                                "P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni",
                                "Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr",
                                "Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te",
                                "I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb",
                                "Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt",
                                "Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
                                "U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
                                
        char names[118][25] = {"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen",
                               "Oxygen","Fluorine","Neon","Sodium","Magnesium","Aluminum","Silicon",
                               "Phosphorus","Sulfur","Chlorine","Argon","Potassium","Calcium",
                               "Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt",
                               "Nickel","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium",
                               "Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirconium",
                               "Niobium","Molybdenum","Technetium","Ruthenium","Rhodium","Palladium",
                               "Silver","Cadmium","Indium","Tin","Antimony","Tellurium","Iodine",
                               "Xenon","Cesium","Barium","Lanthanum","Cerium","Praseodymium",
                               "Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium",
                               "Dysprosium","Holmium","Erbium","Thulium","Ytterbium","Lutetium",
                               "Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum",
                               "Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine",
                               "Radon","Francium","Radium","Actinium","Thorium","Protactinium","Uranium",
                               "Neptunium","Plutonium","Americium","Curium","Berkelium","Californium",
                               "Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium"};

        int num = rand() % 118; //generate random number between 0 and 117
        printf("\nWhat is the element with the symbol %s?", symbols[num]);
        
        fflush(stdin); //flush stdin 
        scanf("%25s", &choice);
        
        if(strcmp(names[num], choice) == 0){ //if user's answer matches the correct answer
            printf("\nCongratulations! You are correct.\n");
            score += 5; //add 5 to user's score
        }else{
            printf("\nSorry, that is incorrect. The correct answer was %s.\n", names[num]);
        }
        
        questions++; //increment questions attempted
        
        printf("\nDo you want to continue playing? (y/n)");
        fflush(stdin);
        scanf("%c", &choice);
        
        if(choice == 'n' || choice == 'N'){ //if user chooses to stop playing, display score and exit
            printf("\nThanks for playing! Your final score is %d out of %d\n", score, questions);
            exit(0);
        }
        
    }while(1); //infinite loop until user chooses to stop playing
    
    return 0;
}