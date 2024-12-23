#include <iostream>
using namespace std;

int eliminationGame(int n) {
    int start = 1;  // The first number in the current range
    int step = 1;   // Step size, doubles each iteration
    int remaining = n;  // Number of elements remaining
    bool leftToRight = true;  // Direction of elimination

    while (remaining > 1) {
        // Update the start only if we are moving left-to-right or remaining is odd
        if (leftToRight || remaining % 2 == 1) {
            start += step;
        }
        // Halve the remaining elements and double the step
        remaining /= 2;
        step *= 2;
        leftToRight = !leftToRight;  // Toggle direction
    }

    return start;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = eliminationGame(n);
    cout << "The last remaining number is: " << result << endl;

    return 0;
}





/***********************************************************

Output:

Enter the value of n: 20
The last remaining number is: 6

***********************************************************/
