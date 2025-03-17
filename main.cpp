#include <iostream>
#include "stockPriceMonitor.h"
#include "stockAlertManager.h"

using namespace std;

int main(){
    srand(time(0));
    
    shared_ptr<StockPriceMonitor> monitor = make_shared<StockPriceMonitor>();
    shared_ptr<StockAlertManager> alertManager = make_shared<StockAlertManager>(monitor);

    monitor->subscribe(alertManager);

    alertManager->addAlert("Alice", "AAPL",150.5);
    alertManager->addAlert("Bob", "TSLA", 789.5);
    alertManager->addAlert("Alice", "GOOGLE", 2806.0);

    for (int i = 0; i < 5; i++) {
        cout << "\n=== Update " << i + 1 << " ===\n";
        monitor->updatePrice();
    }


    return 0;
}