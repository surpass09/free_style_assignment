//
// Created by Surya Pasupuleti on 4/1/25.
//

#include <iostream>
using namespace std;

/*
 * This is the method comparing the bit val of n and n - 1
 *
 */
bool power_of_two_bit(int n) {
    if (n <= 0) { // case for n < 0
        return false;
    }
    return (n & (n - 1)) == 0; // by comparing prev number we ensure that every digit is different
}

/*
 * n: number to be checked
 * uses a loop to ensure that all the as we reduce the number it reduces to one
 * to check if it is a power then returns true
 * else false
 */
bool power_of_two_loop(int n) {
    if (n <= 0) {
        return false;
    }

    while (n % 2 == 0) {
        n = n / 2;
    }
    if (n == 1) {
        return true;
    }
    return false;
}

/*
 * num: - number to be checked if power of 2
 * checks if  both methods are valid
 * returns VALID if true
 * return INVLAID if false
 */
void run_test_cases(int num) {
    if (power_of_two_loop(num) && power_of_two_bit(num)) {
        cout << "VALID" << endl;
    }
    else {
        cout << "INVALID" << endl;
    }
}

int main() {

    // test case 1
    run_test_cases(4);

    // test case 2
    run_test_cases(16);

    // test case 3
    run_test_cases(69);

    // test case 4
    run_test_cases(48);

    // test case 5
    run_test_cases(1);

    // test case 6
    run_test_cases(64);

}