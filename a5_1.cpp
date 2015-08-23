//============================================================================
//File Name   : a5_1.cpp
//Author      : Chris Jordan
//Revision History: None
//Date             Version     Change ID    Author          Comment
//7-17-15          1.0         NA           Chris Jordan    None
//============================================================================


#include <iostream>

using namespace std;


void reverseWithinBounds(char list[], int start, int end);
void reverseCstring(char *newString);


int main() {

    char *hello = new char[6];
    strcpy(hello, "Hello");
    cout << hello << endl;
    reverseCstring(hello);
    cout << hello;

}





/*  
    base case: start == end    (do nothing)
    strategy: move start value to end location and shift all values down one,
              then repeat with (end-1).
*/
void reverseWithinBounds(char list[], int start, int end) {
    if (start < end) {
        char swapHolder = list[start];
        int i = 0;
        while (start + i < end) {
            list[start + i] = list[start + i + 1];
            i++;
        }
        list[end] = swapHolder;
        reverseWithinBounds(list, start, end-1);
    }
}






void reverseCstring(char *newString) {
    reverseWithinBounds(newString, 0, (int) strlen(newString)-1);
}

