CODE:-

#include <iostream>
#include <vector>
#include <algorithm>

struct Ad {
    int id;
    double bidAmount;
    double engagementRate;
    double remainingBudget;

    // Constructor
    Ad(int id, double bid, double engagement, double budget)
        : id(id), bidAmount(bid), engagementRate(engagement), remainingBudget(budget) {}
};

bool compareAds(const Ad &a, const Ad &b) {
    if (a.bidAmount != b.bidAmount) {
        return a.bidAmount > b.bidAmount; // Higher bid first
    }
    return a.engagementRate > b.engagementRate; // Then by engagement rate
}

int main() {
    std::vector<Ad> ads = {
        Ad(1, 100.0, 0.5, 1000.0),
        Ad(2, 150.0, 0.7, 800.0),
        Ad(3, 120.0, 0.6, 900.0)
    };

    std::sort(ads.begin(), ads.end(), compareAds);

    for (const auto &a : ads) {
        std::cout << "Ad ID: " << a.id << ", Bid Amount: " << a.bidAmount << std::endl;
    }

    return 0;
}
/*
OUTPUT

Ad ID: 2, Bid Amount: 150
Ad ID: 3, Bid Amount: 120
Ad ID: 1, Bid Amount: 100
*/
