#include <iostream>
using namespace std;

int main() {
    //declare a variable.
    int n;

    //enter a number.
    cout << "Enter a positive integer: ";
    cin >> n;

    //for finding sum.
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        int sum = (n * (n + 1)) / 2;
        cout << "The sum of the first " << n << " natural numbers is: " << sum << endl;
    }

    return 0;
}
