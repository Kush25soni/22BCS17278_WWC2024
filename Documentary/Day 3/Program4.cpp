#include <iostream>

using namespace std;

int findTheWinner(int n, int k) {
    int winner = 0; // Base case: Josephus(1, k) = 0 (0-based index)
    
    // Calculate the position for each number of friends from 2 to n
    for (int i = 2; i <= n; ++i) {
        winner = (winner + k) % i; // Update the winner's position
    }
    
    return winner + 1; // Convert to 1-based index
}

int main() {
    int n, k;
    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;

    int winner = findTheWinner(n, k);
    cout << "The winner is friend number: " << winner << endl;

    return 0;
}


/*

OUTPUT:

Enter the number of friends (n): 5
Enter the step count (k): 6
The winner is friend number: 4

*/
