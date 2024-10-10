#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_GUESS 1
#define MAX_GUESS 100

int get_user_guess(){
    int guess;
    printf("Guess a number between 1 and 100: ", MIN_GUESS, MAX_GUESS);
    while(scanf("%d", &guess) != 1){
        while(getchar() != '\n')
        printf("Invalid input. Please enter an number: ");
    }

    while(guess < 1 || guess > 100){
        printf("Please enter a number between 1 and 100: ");
        scanf("%d", &guess);
    }
    return guess;
}

char get_yes_or_no() {
    char answer;

    while (1) {
        printf("Would you like to play again? (y/n): ");
        if (scanf(" %c", &answer) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter y or n: ");
            continue; 
        }
        break; 
    }
    return answer;
}
void give_feedback(int guess, int rand_value){
    if(guess > rand_value){
        printf("Too high!\n");
    }else if(guess < rand_value){   
        printf("Too low!\n");
    }else{
        printf("You guessed it!\n");
    }
}

void play_game(){
    int number = 0;
    int guesses = 0;

    srand(time(NULL));
    int rand_value = rand() % 100 + 1;

    while (number != rand_value){
        number = get_user_guess();
        guesses++;
        give_feedback(number, rand_value);
    }
    printf("It took you %d guesses!\n", guesses);
}

int main(){
    char play_again;
    int game_count = 0;

    do{
        play_game();
        game_count++;
        play_again = get_yes_or_no();
    }while(play_again == 'y' | play_again == 'Y');

    printf("You played %d games!\n", game_count);
    return 0;
}

