#include "stockAlertManager.h"

StockAlertManager::StockAlertManager(shared_ptr<StockPriceMonitor> monitor) : monitor(monitor) {}

void StockAlertManager::addAlert(const string& user_id, const string& stock_code, double target_price) {
    alert_map[stock_code].push({target_price, user_id});
    cout << "Added alert: User [" << user_id << "] -> " << stock_code << " at " << target_price << endl;
}

void StockAlertManager::removeAlert(const string& user_id, const string& stock_code, double target_price) {
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>> temp;
    while (!alert_map[stock_code].empty()) {
        auto top = alert_map[stock_code].top();
        alert_map[stock_code].pop();
        if (!(top.first == target_price && top.second == user_id)) {
            temp.push(top);
        }
    }
    alert_map[stock_code] = temp;
}

void StockAlertManager::update(const string &message) {
    cout << "StockAlertManager received notification: " << message << endl;

    for (auto& [stock_code, pq] : alert_map) {
        double current_price = monitor->getPrice(stock_code);
        while (!pq.empty() && pq.top().first <= current_price) {
            cout << "Alert! User [" << pq.top().second << "] -> " 
                 << stock_code << " reached " << pq.top().first 
                 << " (current: " << current_price << ")\n";
            pq.pop();
        }
    }
}
