// Joe Rensvold
// Section 2
// Project 2
// Due September 10th

/*
    This program will prompt the user for an input word or phrase
    that may be a palindrome. The letters from the line of input are then
    put into an array. The array's elements are then checked from first
    to determine if the user has entered a palindrome. If the elements of
    the array, checking first and last inwardly, are
    not the same characters then the user is told they have not entered a palindrome.
    If the elements of the array, checking first and last inwardly, are the same
    characters and there are no more elements to check then the user is told they have
    entered a palindrome.
*/

/*
    Pre-Condition: A word or phrase
    Post-Condition: Whether the word or phrase is a palindrome
*/

#include <iostream>
using namespace std;

int inputLine(char input[])
{

    int index = 0;
    char letter;

    cin.get(letter);

    while (letter >= ' ')
    {
        if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
        {
            letter = tolower(letter);
            input[index] = letter;
            index++;
            cin.get(letter);
        }

        else
            cin.get(letter);

    }

    return index - 1;

}

bool isPalindrome(char input[], int startIndex , int endIndex)
{
    if (input[startIndex] != input[endIndex])
    {
        cout << "This is NOT a palindrome." << endl;
        return false;
    }

    else
    {
        if (input[startIndex] == input[endIndex])
        {
            cout << "This is a palindrome" << endl;
            return true;
        }
        else
            isPalindrome(input, startIndex++, endIndex--);
    }

}

int main()
{
    const int MAX = 61;
    char userInput[MAX];
    int letterCount;

    cout << "Please enter a word or phrase that may be a palindrome: " << endl;

    letterCount = inputLine(userInput);

    isPalindrome(userInput, 0 ,letterCount);

    return 0;
}
