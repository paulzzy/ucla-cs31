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
                if (array1[i] == array2[j]) {
                    num_common_elements++;
                }
            }
        }

        return num_common_elements;
    } else {
        return -1;
    }
}

int countVowels(const string array[], int n);

bool hasThreeOfX(const string array[], int n, string x);

string majorityElement(const string array[], int n);

bool shiftRight(string array[], int n, int amount, string placeholder);

bool rotateLeft(string array[], int n, int amount);

int replaceAll(string array[], int n, char letterToReplace, char letterToFill);

int main() { return 0; }
