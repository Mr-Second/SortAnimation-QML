#ifndef ISORT_H
#define ISORT_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDebug>

#include <chrono>
#include <utility>
#include <algorithm>
#include <functional>

#include "fmt/core.h"
#include "fmt/chrono.h"
#include "fmt/ranges.h"

class ISort: public QObject {

signals:
    void sendData(QVector<int>& data);

public:
    explicit ISort(const QVector<int>& vec, std::function<bool(int, int)>&& func, QString&& name)
        : m_name{name}, cmp{func}, m_data{vec}, m_swapTime{0} {}

    void sort() { monitorMission(std::bind(&ISort::_sort, this)); }

protected:
    virtual void _sort() = 0;
    QString m_name;
    std::function<bool(int, int)> cmp;
    QVector<int> m_data;

    bool isEmpty() {return m_data.empty();}
    int size() {return m_data.size();}
    bool isValidIndex(int index) {return index >= 0 && index < m_data.size();}

    void swap(int i, int j);
    void monitorMission(const std::function<void()>& func);
private:
    size_t m_swapTime;
};

void ISort::swap(int i, int j) {
    if(!isValidIndex(i) || !isValidIndex(j)) {
        fmt::print("index {} or index {} is (are) out of range!", i, j);
    } else {
        int tmp = m_data[i];
        m_data[i] = m_data[j];
        m_data[j] = tmp;
        ++m_swapTime;
    }
}

void ISort::monitorMission(const std::function<void ()>& func) {
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::system_clock::now();
    func();
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    fmt::print("Algorithm {} sorts {} numbers and cost time of {}, swap times {}, the numbers are ordered: {}\n", m_name.toStdString(), size(), duration, m_swapTime, std::is_sorted(m_data.begin(), m_data.end(), cmp));
    fmt::print("{}\n", m_data.toStdVector());
}


#endif // ISORT_H
