#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 100

// Vector that will keep the word written for the user.
char word[100];
void PalindromeCheck(int len);

void NormalizeString(int len){
    int j = 0;
    for(int i = 0 ; i < len ; i++){
        if (isalnum((unsigned char)word[i])){
            word[j++] = tolower((unsigned char)word[i]);
        }
    }
    word[j] = '\0';
}

// Assignment the word input from user.
void Assignment(){
    printf("---------------------- Enter a word and i will check if is a Palindrome or not -----------------------\nThe word: ");
    fgets(word,100,stdin);
    word[strcspn(word, "\n")] = '\0';
    int len = strlen(word);
    // Call of the functions
    NormalizeString(len);
    PalindromeCheck(strlen(word));
}


// Check a Palindrome
void PalindromeCheck(int len){
    // Variable that will keep the inverse word.
    char inverseWord[100];

    // Reverse the initial word.
    for(int i = len - 1, j = 0; i >= 0 ; i--, j++){
        inverseWord[j] = word[i];
    }
    // Add the NULL value in the end of inverseWord.
    inverseWord[len] = '\0';

    // Comparasion if it's or not a palindrome.
    if(strcmp(inverseWord,word) == 0){
        printf("%s and %s: It's a palindrome\n",word,inverseWord);
    }
    else{
        printf("%s and %s: It's not a palindrome\n",word,inverseWord);
    }
}

int main(){
    Assignment();
    return 0;
}
