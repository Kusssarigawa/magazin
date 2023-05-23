#ifndef SHOPITERATOR_H
#define SHOPITERATOR_H

#include "Shop.h"
    
template<typename T>
class ShopIterator {
protected:
    T* data;               // ����� ����� ��� ��������
    int currentIndex;      // �������� ������
    int dataSize;          // ����� ������ �����

public:
    ShopIterator(T* arr, int size);  // �����������
    bool hasNext() const;            // �������� ���������� ���������� ��������
    T& next();                       // ��������� ���������� ��������
};

template<typename T>
ShopIterator<T>::ShopIterator(T* arr, int size)
    : data(arr), currentIndex(0), dataSize(size) {}

template<typename T>
bool ShopIterator<T>::hasNext() const {
    return currentIndex < dataSize;
}

template<typename T>
 T& ShopIterator<T>::next() {
    if (hasNext()) {
        return data[currentIndex++];
    }
    else {
        throw std::out_of_range("End of iterator reached.");
    }
}

#endif  // SHOPITERATOR_H
