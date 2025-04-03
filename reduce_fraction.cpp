//
// Created by Surya Pasupuleti on 4/1/25.
//

/*
 *  x : - numerator
 *  y : - denominator
 */

#include <iostream>
#include <sstream>
using namespace std;


/*
 * x: - numerator
 * y: - denominator
 * NOTE: - I did take help from GPT to understand what happens when using the bits
 * i couldn't understanding how the power of 2 number differs from a number - 1
 * Calculates GCD given numerator in denominator
 *
 */
int calc_GCD(const int x, const int y) {

    int max_divisor = 1;
    const int limit = min(x, y);

    for (int i = 1; i <= limit; i++) {
        if (y % i == 0 && x % i == 0) {
            max_divisor = i;
        }
    }
    return max_divisor;
}

/*
 * &x: - reference to values x
 * &y: - reference to value y
 * GCD: - Greatest common divisor
 * Divides x and y by GCD to reduce to the lowest fraction AFTER
 * ensuring both are divisible by the GCD and updates the REFERENCE of the values
 * instead of making a copy
 */
int reduce(int &x, int &y, int GCD) {

    x = x / GCD;
    y = y / GCD;

    return 0;
}

/*
 * fraction: - fraction in string format
 * split the fraction using delimiter and reduces the fraction to the
 * lowest form
 */
void split(const string& fraction) {
    int numerator;
    int denominator;
    char slash;

    stringstream ss(fraction);
    ss >> numerator >> slash >> denominator;

    if (slash == '/') {
        cout << "the numerator is " << numerator << endl;
        cout << "the denominator is " << denominator << endl;

        // Calculate GCD
        int GCD = calc_GCD(numerator, denominator);


        // Reduce fractions as we reduce
        while (GCD > 1) {
            reduce(numerator, denominator, GCD);
            GCD = calc_GCD(numerator, denominator);
        }

        // checking numerator and the denominator values
        cout << numerator << "/" << denominator << endl << endl;


    } else {
        cout << "Invalid fraction" << endl;
    }

}
/*
 * Reducing the fraction to the lowest form.
 */
int main () {

    // test case 1
    split("4/8");

    // test case 2
    split("3/2");

    // test case 3
    split("12/14");

    // test case 4
    split("6/7");

    // test case 5
    split("12/18");

    return 0;
}

