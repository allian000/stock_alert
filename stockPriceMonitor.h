// stockPriceMonitor.h
#ifndef STOCK_PRICE_MONITOR_H
#define STOCK_PRICE_MONITOR_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

// 觀察者介面
class Observer {
    public:
        virtual void update(const string &message) = 0;
        virtual ~Observer() = default;
};

// 股票價格監視器類別
class StockPriceMonitor {
    public:
        StockPriceMonitor();
        
        double getPrice(const string &stock_code);
        
        void updatePrice();

        void subscribe(shared_ptr<Observer> observer);
        
        void unsubscribe(shared_ptr<Observer> observer);
        
        void notify(const string &message);

    private:
        unordered_map<string, double> stock_map;
        vector<shared_ptr<Observer>> observers;
};

class ConcreteObserver : public Observer {
    public:
        explicit ConcreteObserver(const string& name);
        void update(const string& message);
        string getName();
    private:
        string name;
};

#endif // STOCK_PRICE_MONITOR_H
