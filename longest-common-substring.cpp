#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;

// Function to find the longest common substring
string longestCommonSubstring(const string& str1, const string& str2, int& maxLength) {
    int length1 = str1.length();
    int length2 = str2.length();

    // Dynamically allocate a 2D array for the lookup table
    int** lookupTable = new int*[length1 + 1];
    for (int i = 0; i <= length1; ++i) {
        lookupTable[i] = new int[length2 + 1]();
    }

    maxLength = 0; // Length of the longest common substring
    int endIndex = 0; // Index of the last character of the longest common substring in str1

    // Build the lookup table dynamically
    for (int i = 1; i <= length1; ++i) {
        for (int j = 1; j <= length2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;

                // Update maximum length and ending index
                if (lookupTable[i][j] > maxLength) {
                    maxLength = lookupTable[i][j];
                    endIndex = i - 1;
                }
            } else {
                lookupTable[i][j] = 0;
            }
        }
    }

    // Display the lookup table
    cout << "\nLookup Table:\n    ";
    for (int j = 0; j < length2; ++j) {
        cout << setw(3) << str2[j];
    }
    cout << "\n";

    for (int i = 0; i <= length1; ++i) {
        if (i > 0)
            cout << setw(3) << str1[i - 1] << " ";
        else
            cout << "    ";
        
        for (int j = 0; j <= length2; ++j) {
            cout << setw(3) << lookupTable[i][j];
        }
        cout << "\n";
    }

    // Extract the longest common substring
    string longestSubstring = str1.substr(endIndex - maxLength + 1, maxLength);

    // Free allocated memory
    for (int i = 0; i <= length1; ++i) {
        delete[] lookupTable[i];
    }
    delete[] lookupTable;

    return longestSubstring;
}

int main() {
    string str1, str2;

    // Take user input
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    // Ensure both strings are of the same length
    if (str1.length() != str2.length()) {
        cout << "Error: Both strings must have the same length. Exiting program.\n";
        return 1;
    }

    int maxLength;
    string result = longestCommonSubstring(str1, str2, maxLength);

    // Display results
    cout << "\nResult Summary:\n";
    cout << "----------------------------------\n";
    cout << "First String: " << str1 << "\n";
    cout << "Second String: " << str2 << "\n";
    cout << "Longest Common Substring: \"" << result << "\"\n";
    cout << "Length of Longest Common Substring: " << maxLength << "\n";
    cout << "----------------------------------\n";

    return 0;
}
