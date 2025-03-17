#ifndef STOCK_ALERT_MANAGER_H
#define STOCK_ALERT_MANAGER_H

#include "stockPriceMonitor.h"
#include <queue>
#include <unordered_map>

class StockAlertManager : public Observer, public enable_shared_from_this<StockAlertManager>  {
public:
    explicit StockAlertManager(shared_ptr<StockPriceMonitor> monitor);

    void addAlert(const string& user_id, const string& stock_code, double target_price);
    void removeAlert(const string& user_id, const string& stock_code, double target_price);

    void update(const string &message) override;

private:
    shared_ptr<StockPriceMonitor> monitor;
    unordered_map<string, priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>>> alert_map;
};

#endif // STOCK_ALERT_MANAGER_H
