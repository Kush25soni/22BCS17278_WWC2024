#include <iostream>
using namespace std;

int main() {
    //Declare all the variable.
    int num;
    bool isPrime = true;

    //Taking input of number.
    cout << "Enter a number: ";
    cin >> num;

    //Cheak Number whether number is Prime or not.
    if (num <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    //Print if it is prime.
    if (isPrime)
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}
