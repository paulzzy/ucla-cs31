#include <iostream>
#include <string>

using namespace std;

int locateMinimum(const string array[], int n) {
    // For loop does not work with arrays of size 1, so validation is done in
    // advance
    if (n > 1) {
        int min_value_index = 0;
        string min_value = array[0];

        for (int i = 1; i < n; i++) {
            if (array[i] < min_value) {
                min_value_index = i;
                min_value = array[i];
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
            for (size_t j = 0; j < array[i].length(); j++) {
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

// Uses Boyer–Moore majority vote algorithm
string majorityElement(const string array[], int n) {
    if (n > 1) {
        string majority_candidate = array[0];
        int candidate_count = 1;
        int majority_threshold = n / 2;
        int majority_candidate_count = 0;

        // First pass finds the majority element, if it exists
        for (int i = 1; i < n; i++) {
            if (array[i] == majority_candidate) {
                candidate_count++;
            } else {
                candidate_count--;

                majority_candidate =
                    candidate_count <= 0 ? array[i] : majority_candidate;
            }
        }

        // Second pass to check that majority_candidate is actually the majority
        // element
        for (int i = 0; i < n; i++) {
            majority_candidate_count = array[i] == majority_candidate
                                           ? majority_candidate_count + 1
                                           : majority_candidate_count;
        }

        return majority_candidate_count > majority_threshold
                   ? majority_candidate
                   : "";
    } else {
        return "";
    }
}

bool shiftRight(string array[], int n, int amount, string placeholder) {
    if (n > 0 && amount > n) {
        for (int i = 0; i < n; i++) {
            array[i] = placeholder;
        }

        return true;
    } else if (n > 0 && amount > 0) {
        // Moves each element forward by one index, down to amount
        for (int i = n - 1; i >= amount; i--) {
            array[i] = array[i - amount];
        }

        for (int i = 0; i < amount; i++) {
            array[i] = placeholder;
        }

        return true;
    } else {
        return false;
    }
}

void reverseArray(string array[], int start, int end) {
    // Note that start to end - 1 is reversed, inclusive
    for (int i = start; i < end / 2; i++) {
        int partner = end - i - 1;
        string temp = array[i];
        array[i] = array[partner];
        array[partner] = temp;
    }
}

bool rotateLeft(string array[], int n, int amount) {
    // array stays the same when amount is a multiple of n
    if (n > 0 && amount > 0 && amount % n != 0) {
        // Rotating by more than n is equivalent to rotating by modulo n. For
        // example, rotating by 9 is equivalent to rotating by 1. Modulo
        // operation is performed inside the if statement to avoid
        // division-by-zero errors.
        amount = amount % n;
        reverseArray(array, 0, n);
        // Reverses elements that are not moved to the end of the array when
        // rotating left
        reverseArray(array, 0, n - amount);
        // Reverses elements that are moved to the end of the array when
        // rotating left
        reverseArray(array, n - amount, n);

        return true;
    } else {
        return false;
    }
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill) {
    if (n > 0) {
        int num_replacements = 0;

        for (int i = 0; i < n; i++) {
            for (size_t j = 0; j < array[i].length(); j++) {
                if (array[i].at(j) == letterToReplace) {
                    array[i].at(j) = letterToFill;
                    num_replacements++;
                }
            }
        }

        return num_replacements;
    } else {
        return -1;
    }
}

int main() { return 0; }
