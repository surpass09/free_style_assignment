
#include <iostream>
using namespace std;

/*
 * num: -
 *
 */
bool is_prime(const int num) {

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            cout <<"FAIL"<<endl;
            return false;
        }
    }
    cout <<"PASS"<<endl;
    return true;

}

int main() {

    is_prime(11);

    is_prime(12);

    is_prime(13);

    is_prime(77);

    is_prime(3);

    return 0;
}
