CODE:-

#include <iostream>
#include <vector>
#include <algorithm>

struct Trade {
    std::string timestamp;
    std::string stockSymbol;
    double tradePrice;
    int tradeVolume;

    // Constructor
    Trade(std::string ts, std::string symbol, double price, int volume)
        : timestamp(ts), stockSymbol(symbol), tradePrice(price), tradeVolume(volume) {}
};

bool compareTrades(const Trade &a, const Trade &b) {
    if (a.timestamp != b.timestamp) {
        return a.timestamp < b.timestamp; // Sort by timestamp first
    }
    return a.stockSymbol < b.stockSymbol; // Then by stock symbol
}

int main() {
    std::vector<Trade> trades = {
        Trade("2023-10-01 10:00:00", "AAPL", 150.0, 100),
        Trade("2023-10-01 09:59:00", "GOOGL", 2800.0, 50),
        Trade("2023-10-01 10:00:00", "MSFT", 300.0, 200)
    };

    std::sort(trades.begin(), trades.end(), compareTrades);

    for (const auto &t : trades) {
        std::cout << "Trade Timestamp: " << t.timestamp << ", Stock: " << t.stockSymbol << std::endl;
    }

    return 0;
}
/*
output:-

Trade Timestamp: 2023-10-01 09:59:00, Stock: GOOGL
Trade Timestamp: 2023-10-01 10:00:00, Stock: AAPL
Trade Timestamp: 2023-10-01 10:00:00, Stock: MSFT
*/
