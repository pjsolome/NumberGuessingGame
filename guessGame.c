#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Global max for game
static int maxValue = 10;
//Variables
static bool quitProgram = false;
static int choice = 0;
static int randomNum;
static int guess;
static int proposedMax;

//Display main menu
int displayMenu() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("Current max is: %d\n", maxValue);
    printf("Press 1 to play a game \n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");

    return 0;
}

int main() {
    while(quitProgram == false){
        while(choice == 0){
            displayMenu();

            //Choose from menu
            fflush(stdout);
            scanf("%d", &choice);
        } 

        while(choice == 1){
            //Program chooses random number
            time_t t;
            srand((unsigned) time(&t));

            randomNum = (rand() % maxValue) + 1;

            //User enters number
            printf("Guess a number or press 0 to end the game: ");
            fflush(stdout);
            scanf("%d", &guess);

            //Loop to keep player in the game till they get the right number
            while(guess != randomNum) {
                //Pressing 'q' quits game
                if(guess == 0){
                    choice = 0;
                    break;
                //Check if number is between 1 and maxValue
                } else if(guess > 0 && guess <= maxValue) {
                    //Compare user number to random number and tell if higher/lower
                    if(guess > randomNum){
                        printf("\nYou guessed higher. Try again: ");
                        fflush(stdout);
                        scanf("%d", &guess);
                    } else if(guess < randomNum) {
                        printf("\nYou guessed lower. Try again: ");
                        fflush(stdout);
                        scanf("%d", &guess);
                    }
                } else {
                    printf("\nYou cannot guess above max! Current max is %d. Try again: ", maxValue);
                    fflush(stdout);
                    scanf("%d", &guess);
                }
            }
            //Tells user they got the right number
            if(guess == randomNum){
                printf("\nYou Win!\n");
                choice = 0;
            }
        }
    
        //Set a new max number; tell the user it can not go over 10
        while(choice == 2){
            printf("\nSelect a new max. Can not be more than 10 ");
            fflush(stdout);
            scanf("%d", &proposedMax);
            //Make sure new max is not negative and not more than 10
            if(proposedMax > 0 && proposedMax < 11) {
                maxValue = proposedMax;
                choice = 0;
            } else {
                printf("\nPlease choose a max that is less than 10 and not negative ");
                fflush(stdout);
                scanf("%d", &proposedMax);
            }
        }

        //Quit the program 
        while(choice >= 3 || choice < 0) {
            printf("\nThanks for playing!");
            quitProgram = true;
            break;
        }
    }
    return 0;
}