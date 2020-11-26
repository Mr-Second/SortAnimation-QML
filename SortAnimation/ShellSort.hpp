#ifndef SHELLSORT_HPP
#define SHELLSORT_HPP
#include <QStack>

#include "ISort.hpp"

class ShellSort: public ISort {
public:
    ShellSort(const QVector<int>& vec, std::function<bool(int, int)>&& func)
        : ISort(vec, std::forward<std::function<bool(int, int)>&&>(func), "ShellSort") {}
protected:
    virtual void _sort() override;
};

void ShellSort::_sort() {
    if(isEmpty()){
        fmt::print("Array is empty, terminate!\n");
        return;
    }
    int sz = size();
    for(int increment = sz /2; increment > 0; increment /= 2) {
        for(int i = increment; i < sz; ++i) {
            int stored_data = m_data[i];
            int j = i;
            while (j >= increment && cmp(stored_data, m_data[j - increment])) {
                m_data[j] = m_data[j - increment];
                j -= increment;
            }
            m_data[j] = stored_data;
        }
    }
};



#endif // SHELLSORT_HPP
