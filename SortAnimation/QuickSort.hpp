#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include "ISort.hpp"

class QuickSort: public ISort {
public:
    QuickSort(const QVector<int>& vec, std::function<bool(int, int)>&& func)
        : ISort(vec, std::forward<std::function<bool(int, int)>&&>(func), "QuickSort") {}
protected:
    virtual void _sort() override;
private:
    void __sort(int, int);
    int __partition(int, int);
};

void QuickSort::_sort()
{
    if(isEmpty()) {
        fmt::print("Array is empty, terminate!\n");
        return;
    }
    __sort(0, size());
}

void QuickSort::__sort(int left, int right)
{
    if(left >= right)
        return;
    int pivot = __partition(left, right);
    __sort(left, pivot);
    __sort(pivot + 1, right);
}

int QuickSort::__partition(int low, int high)
{
    int randomIndex = rg->getOneElement(low, high);
    swap(low, randomIndex);

}




#endif // QUICKSORT_HPP
