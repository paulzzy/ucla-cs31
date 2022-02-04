#include <iostream>
#include <string>

using namespace std;

int locateMinimum(const string array[], int n) {
    // For loop does not work with arrays of size 1, so validation is done in
    // advance
    if (n > 1) {
        int min_value_index = 0;

        for (int i = 1; i < n; i++) {
            if (array[n] < array[n - 1]) {
                min_value_index = i;
            }
        }

        return min_value_index;
    } else if (n == 1) {
        return 0;
    } else {
        return -1;
    }
}

int countCommonElements(const string array1[], int n1, const string array2[],
                        int n2) {
    if (n1 > 0 && n2 > 0) {
        int num_common_elements = 0;

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                num_common_elements = array1[i] == array2[j]
                                          ? num_common_elements + 1
                                          : num_common_elements;
            }
        }

        return num_common_elements;
    } else {
        return -1;
    }
}

int countVowels(const string array[], int n) {
    if (n > 0) {
        int num_vowels = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < array[i].length(); j++) {
                const char letter = tolower(array[i].at(j));
                num_vowels = letter == 'a' || letter == 'e' || letter == 'i' ||
                                     letter == 'o' || letter == 'u' ||
                                     letter == 'y'
                                 ? num_vowels + 1
                                 : num_vowels;
            }
        }

        return num_vowels;
    } else {
        return -1;
    }
}

bool hasThreeOfX(const string array[], int n, string x) {
    if (n > 0) {
        int num_x = 0;

        for (int i = 0; i < n; i++) {
            num_x = array[i] == x ? num_x + 1 : num_x;
        }

        return num_x == 3;
    } else {
        return false;
    }
}

string majorityElement(const string array[], int n);

bool shiftRight(string array[], int n, int amount, string placeholder);

bool rotateLeft(string array[], int n, int amount);

int replaceAll(string array[], int n, char letterToReplace, char letterToFill);

int main() { return 0; }
