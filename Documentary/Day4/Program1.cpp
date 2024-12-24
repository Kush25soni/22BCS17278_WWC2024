#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

// Transaction structure
struct Transaction {
    int id;                // Transaction ID
    double amount;         // Transaction amount
    int frequency;         // Frequency of transactions by the same account
    double locationDeviation; // Deviation from usual location (in km)
    double score;          // Suspiciousness score

    Transaction(int i, double amt, int freq, double locDev)
        : id(i), amount(amt), frequency(freq), locationDeviation(locDev), score(0) {}
};

// Function to calculate suspiciousness score
double calculateSuspiciousnessScore(double amount, int frequency, double locationDeviation) {
    // Example weighted scoring formula
    return (0.6 * log(amount + 1)) + (0.3 * frequency) + (0.1 * locationDeviation);
}

// Comparator for priority queue (max-heap)
struct CompareScore {
    bool operator()(const Transaction& t1, const Transaction& t2) {
        return t1.score < t2.score; // Higher scores have higher priority
    }
};

int main() {
    vector<Transaction> transactions;

    // User input for number of transactions
    int n;
    cout << "Enter the number of transactions: ";
    cin >> n;

    // Input details for each transaction
    for (int i = 1; i <= n; ++i) {
        double amount, locationDeviation;
        int frequency;
        cout << "Enter details for Transaction " << i << endl;
        cout << "Amount: ";
        cin >> amount;
        cout << "Frequency (number of transactions by the same account): ";
        cin >> frequency;
        cout << "Location Deviation (in km): ";
        cin >> locationDeviation;

        // Create a transaction object
        Transaction transaction(i, amount, frequency, locationDeviation);
        transaction.score = calculateSuspiciousnessScore(amount, frequency, locationDeviation);

        // Add to the transaction list
        transactions.push_back(transaction);
    }

    // Priority queue to store top suspicious transactions
    priority_queue<Transaction, vector<Transaction>, CompareScore> pq;

    // Push all transactions into the priority queue
    for (const auto& transaction : transactions) {
        pq.push(transaction);
    }

    // Output the top suspicious transactions
    cout << "\nTop Suspicious Transactions:" << endl;
    int count = 0; // Limit the number of results
    while (!pq.empty() && count < 3) { // Retrieve top 3 transactions
        Transaction t = pq.top();
        pq.pop();
        cout << "Transaction ID: " << t.id
             << ", Score: " << fixed << setprecision(2) << t.score
             << ", Amount: " << t.amount
             << ", Frequency: " << t.frequency
             << ", Location Deviation: " << t.locationDeviation << " km" << endl;
        count++;
    }

    return 0;
}



/***********************************************************************************

Output:

Enter the number of transactions: 5
Enter details for Transaction 1
Amount: 1000.00
Frequency (number of transactions by the same account): 10
Location Deviation (in km): 50.00
Enter details for Transaction 2
Amount: 5000
Frequency (number of transactions by the same account): 5
Location Deviation (in km): 10
Enter details for Transaction 3
Amount: 200
Frequency (number of transactions by the same account): 20
Location Deviation (in km): 100
Enter details for Transaction 4
Amount: 15000
Frequency (number of transactions by the same account): 3
Location Deviation (in km): 5
Enter details for Transaction 5
Amount: 3000
Frequency (number of transactions by the same account): 8
Location Deviation (in km): 20

Top Suspicious Transactions:
Transaction ID: 3, Score: 19.18, Amount: 200.00, Frequency: 20, Location Deviation: 100.00 km
Transaction ID: 1, Score: 12.15, Amount: 1000.00, Frequency: 10, Location Deviation: 50.00 km
Transaction ID: 5, Score: 9.20, Amount: 3000.00, Frequency: 8, Location Deviation: 20.00 km

***************************************************************************************/



