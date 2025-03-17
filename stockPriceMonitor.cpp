#include "stockPriceMonitor.h"

// StockPriceMonitor 類別
StockPriceMonitor::StockPriceMonitor() {
    this->stock_map = {
        {"AAPL", 150.25},
        {"GOOGLE", 2805.50},
        {"TSLA", 789.10}};
}

double StockPriceMonitor::getPrice(const string &stock_code) {
    if (this->stock_map.find(stock_code) != this->stock_map.end()) {
        return this->stock_map[stock_code];
    } else {
        cerr << "Stock " << stock_code << " not found!" << endl;
        return -1.0;
    }
}

void StockPriceMonitor::updatePrice() {
    for (auto &item : this->stock_map) {
        this->stock_map[item.first] += ((rand() % 200) - 100) / 100.0;
    }
}

void StockPriceMonitor::subscribe(shared_ptr<Observer> observer) {
    this->observers.push_back(observer);
}

void StockPriceMonitor::unsubscribe(shared_ptr<Observer> observer) {
    this->observers.erase(remove_if(observers.begin(), observers.end(),
                                    [&observer](const shared_ptr<Observer> &o) {
                                        return o == observer;
                                    }),
                          observers.end());
}

void StockPriceMonitor::notify(const string &message) {
    for (const auto &observer : observers) {
        observer->update(message); // 通知所有觀察者
    }
}

// ConcreteObserver 類別
ConcreteObserver::ConcreteObserver(const string& name) : name(name) {}

void ConcreteObserver::update(const string& message) {
    cout << "User: " << name << " got message: " << message << endl;
}

string ConcreteObserver::getName() {
    return this->name;
}
