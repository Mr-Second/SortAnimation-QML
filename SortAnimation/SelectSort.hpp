#ifndef SELECTSORT_HPP
#define SELECTSORT_HPP
#include "ISort.hpp"

class SelectSort: public ISort {
public:
    SelectSort(const QVector<int>& vec, std::function<bool(int, int)>&& func)
        : ISort(vec, std::forward<std::function<bool(int, int)>&&>(func), "SelectSort") {}
protected:
    virtual void _sort() override;
};

void SelectSort::_sort() {
    if(isEmpty()){
        fmt::print("Array is empty, terminate!\n");
        return;
    }

    int sz = size();
    for(int i = 0; i < sz; ++i) {
        int minIndex = i;
        for(int j = i + 1; j < sz; ++j)
            if(!cmp(m_data[minIndex], m_data[j]))
                minIndex = j;
        swap(minIndex, i);
    }
}


#endif // SELECTSORT_HPP
