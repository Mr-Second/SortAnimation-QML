#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include "ISort.hpp"

class MergeSort: public ISort {
public:
    MergeSort(const QVector<int>& vec, std::function<bool(int, int)>&& func)
        : ISort(vec, std::forward<std::function<bool(int, int)>&&>(func), "MergeSort") {}
protected:
    virtual void _sort() override;
private:
    void __sort(int, int);
    void __merge(int, int, int);
};

void MergeSort::_sort()
{
    if(isEmpty()){
        fmt::print("Array is empty, terminate!\n");
        return;
    }
    int sz = size();
    __sort(0, sz - 1);
}

void MergeSort::__sort(int low, int high)
{
    if(low < high) {
        int mid = (low + high) / 2;
        __sort(low, mid);
        __sort(mid + 1, high);
        __merge(low, mid, high);
    }
}

void MergeSort::__merge(int low, int mid, int high)
{
    int head1 = low, head2 = mid + 1, index = 0;
    QVector<int> tmp(high - low + 1);
    while (head1 <= mid && head2 <= high) {
        if(cmp(m_data[head1], m_data[head2]))
            tmp[index++] = m_data[head1++];
        else
            tmp[index++] = m_data[head2++];
    }

    while (head1 <= mid)
        tmp[index++] = m_data[head1++];
    while (head2 <= high)
        tmp[index++] = m_data[head2++];

    for(int i = low; i <= high; ++i)
        m_data[i] = tmp[i - low];
}




#endif // MERGESORT_HPP


