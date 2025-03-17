#include <iostream>
#include "stockPriceMonitor.h"

using namespace std;

int main(){
    auto stockPriceMonitor = make_shared<StockPriceMonitor>();
    auto user1 = make_shared<ConcreteObserver>("Alice");
    auto user2 = make_shared<ConcreteObserver>("Bob");

    stockPriceMonitor->subscribe(user1);
    stockPriceMonitor->subscribe(user2);

    cout << "Send message: Hello World!" << endl;
    stockPriceMonitor->notify("Hello World!");

    cout << "User: "  << user1->getName() << " unsubscribe!" << endl;
    stockPriceMonitor->unsubscribe(user1);

    cout << "Send message: Second message!" << endl;
    stockPriceMonitor->notify("Second message!");

    return 0;
}