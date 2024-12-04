#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Recursively output all combinations of chars[]
void printCombos(vector<string> chars, string combo, int index) {
    // Base Case: Reach the end of chars[]
    if(index == chars.size()) {
        // Output combo
        cout << combo << " ";
    }
    // Default Case: Assign next combo char
    else {
        // Iterate through each char in current chars[] element
        for(int i = 0; i < chars[index].length(); i++) {
            // Update combo char at index with current chars[] char
            combo.at(index) = chars[index].at(i);
            // Recursively call printCombos() for next combo assignment / combo output
            printCombos(chars, combo, index + 1);
        }
        // Output new line after each last chars[] element
        if(index == chars.size() - 1) {
            cout << endl;
        }
    }
}
// Return a vector<string> values with respect to nums[] valued 2 - 9
vector<string> numsToChars(int nums[], int length) {
    // Alphabet organized to match that of a standard phone dial pad
    map<int, string> charSets = {
        {2, "ABC"}, {3, "DEF"}, {4, "GHI"}, {5, "JKL"},
        {6, "MNO"}, {7, "PQRS"}, {8, "TUV"}, {9, "WXYZ"}
    };
    // Declare a vector<string> for charSets value storage
    vector<string> chars;
    // Iterate through each nums[] element
    for(int i = 0; i < length; i++) {
        // If nums[i] is valid...
        if(nums[i] > 1 && nums[i] < 10) {
            // Push the associated charSets value to chars[]
            chars.push_back(charSets[nums[i]]);
        }
    }
    // Return the vector<string> of charSets values
    return chars;
}
// Driver Code
int main() {
    // Driver Arrays
    int nums[] = {4, 2, 9, 7};            // Driver 1: 4 digits
    //int nums[] = {6, 3};                // Driver 2: 2 digits
    //int nums[] = {8, 9, 2, 5, 4, 7, 2}; // Driver 3: 7 digits
    //int nums[] = {2, 0, 9, 1};          // Driver 4: 4 digits, 2 invalid

    // Recursively print combinations of each numsToChars[] element
    int len = (sizeof(nums) / sizeof(nums[0]));
    vector<string> chars = numsToChars(nums, len);
    printCombos(chars, string(chars.size(), '#'), 0);

    return 0;
}
