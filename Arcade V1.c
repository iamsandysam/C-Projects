#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int RandNum(int UpperLimit, int LowerLimit){
    int num = (rand() % (UpperLimit - LowerLimit + 1)) + LowerLimit;
    return num;
}
void LuckyNum(){
    int ans = RandNum(9, 0);
    int guess;
    printf("\nTry to guess the LUCKY NUMBER!!\nEnter a number(0-9): ");
    scanf("%d", &guess);
    if(guess == ans){
        printf("WOOHOOOOO YOU WON!!");
    }
    else{
        printf("Sorry you lost, correct answer was: %d", ans);
    }
}
char Word[30];
int WordLength;
void RandWord(){
    char Words[][30] = {"apple", "banana", "statue", "switch", "elephant", "frog", "grape", "shoes", "icecream", "jacket",
        "kite", "lion", "moon", "nest", "orange", "penguin", "keyboard", "rainbow", "tubelight", "tiger",
        "umbrella", "violin", "watermelon", "xylophone", "yoga", "zebra", "airplane", "book", "candle", "desk",
        "earth", "flower", "guitar", "house", "island", "juice", "motorcycle", "laptop", "mountain", "notebook",
        "ocean", "piano", "start", "ready", "star", "train", "vase", "window", "mirror", "calculator",
        "stand", "butterfly", "cookie", "compass", "dolphin", "eclipse", "firefly", "globe", "mouse",
        "ingot", "puzzle", "kangaroo", "lighthouse", "mango", "noodle", "parrot", "monitor", "cable", "perfume",
        "turtle", "bottle", "volcano", "whale", "print", "thread", "curtain", "cupboard", "dance", "candy",
        "marker", "string", "rose", "image", "infinite", "photo", "scope", "shelf",
        "sweat", "attack", "octopus", "chaos", "liquid", "blanket", "song", "cake", "cord",
        "number", "container", "backpack", "yogurt", "zipper"};
    int NumWords = sizeof(Words) / sizeof(Words[0]);
    int WordPosition = RandNum(NumWords - 1, 0);
    strcpy(Word, Words[WordPosition]);
    WordLength = strlen(Word);
    //printf("%s", Word);
}
int visible1;
int visible2 = 100;
void InitiallyVisible(int WordLength){
    if (WordLength <= 5){
        visible1 = RandNum((WordLength - 1), 0);
    }
    else if (WordLength > 5){
        visible1 = RandNum((WordLength - 1), 0);
        visible2 = RandNum((WordLength - 1), 0);
        while (visible2 == visible1){
            visible2 = RandNum((WordLength - 1), 0);
        }
    }
}
int CheckChar(char Word[30], int WordLength, char guess, int guessed[30]){
    for (int i = 0; i < WordLength; i++){
        if (Word[i] == guess){            
            guessed[i] = 1;
        }
    }
    for (int i = 0; i < WordLength; i++){
        if (Word[i] == guess){            
            return 1;
        }
    }
    return 0;
}
void WordDisplay(char Word[30], int WordLength, int guessed[30]){
    for (int i = 0; i < WordLength; i++){
        if (guessed[i] == 1 || Word[i] == Word[visible1] || Word[i] == Word[visible2]){
            printf("%c ", Word[i]);
        }
        else{
            printf("_ ");
        }
    }
}
void Hangman(){
    RandWord();
    InitiallyVisible(WordLength);
    int IGuesses = 0;
    int guessed[30] = {0};
    while (IGuesses < 6){
        printf("You have %d lives left\n", (6 - IGuesses));
        WordDisplay(Word, WordLength, guessed);
        char guess;
        printf("\nGuess a character (a-z or A-Z): ");
        scanf(" %c", &guess);
        int CharFound = CheckChar(Word, WordLength, (tolower(guess)), guessed);
        if (CharFound == 1){
            printf("Correct Guess!!");
        }
        else{
            printf("Uh-oh Wrong Guess");
            IGuesses++;
        }
        int GameComplete = 1;
        for (int i = 0; i < WordLength; i++){
            if (guessed[i] == 0 && Word[i] != Word[visible1] && Word[i] != Word[visible2]){
                GameComplete = 0;
                break;
            }
        }
        if (GameComplete == 1){
            printf("\n\nYou Won YAAYYYYY\nWord was = %s", Word);
            return;
        }
        
    }
    printf("\n\nThe Correct Word was %s", Word);
    printf("\nBetter Luck Next Time!");
}

int main(){
    srand(time(NULL));
    int ch;
    while (ch != 3){
        printf("Welcome to the Arcade!!\nWhat do want to play?\n1. Lucky Number Game!\n2. Hangman!\n3. Exit\nChoose one: ");
        scanf("%d", &ch);
        if (ch == 1){
            LuckyNum();
        }
        else if (ch == 2){
            Hangman();
        }
    }
}