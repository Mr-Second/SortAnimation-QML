#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP
#include "ISort.hpp"

class BubbleSort: public ISort {
public:
    BubbleSort(const QVector<int>& vec, std::function<bool(int, int)>&& func)
        : ISort(vec, std::forward<std::function<bool(int, int)>&&>(func), "BubbleSort") {}
protected:
    virtual void _sort() override;
};


void BubbleSort::_sort() {
    if(isEmpty()){
        fmt::print("Array is empty, terminate!\n");
        return;
    }
    int sz = size();
    int sortedBorder = sz - 1;
    int lastExchangeIndex = 0;

    for(int i = 0; i < sz - 1; ++i) {
        bool hasSwap = false;
        for(int j = 0; j < sortedBorder; ++j) {
            if(!cmp(m_data[j], m_data[j + 1])) {
                swap(j, j + 1);
                hasSwap = true;
                lastExchangeIndex = j;
            }
        }

        sortedBorder = lastExchangeIndex;
        if(!hasSwap)
            break;
    }
}

#endif // BUBBLESORT_HPP
