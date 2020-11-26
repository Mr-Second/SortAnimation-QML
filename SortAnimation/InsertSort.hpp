#ifndef INSERTSORT_HPP
#define INSERTSORT_HPP
#include "ISort.hpp"

class InsertSort : public ISort {
public:
    InsertSort(const QVector<int>& vec, std::function<bool(int, int)>&& func)
        : ISort(vec, std::forward<std::function<bool(int, int)>&&>(func), "InsertSort") {}
protected:
    virtual void _sort() override;
};

void InsertSort::_sort() {
    if(isEmpty()) {
        fmt::print("Array is empty, terminate!\n");
        return;
    }

    int sz = size();
    for(int i = 1; i < sz; ++i) {
        fmt::print("{}\n", std::vector<int>(m_data.begin(), m_data.end()));
        int stored_data = m_data[i];
        int j = i - 1;
        while(j >= 0 && cmp(stored_data, m_data[j])) {
            m_data[j + 1] = m_data[j];
            increaseSwapTime();
            --j;
        }
        m_data[j + 1] = stored_data;
    }
}

#endif // INSERTSORT_HPP
