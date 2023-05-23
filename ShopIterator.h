#ifndef SHOPITERATOR_H
#define SHOPITERATOR_H

#include "Shop.h"
    
template<typename T>
class ShopIterator {
protected:
    T* data;               // Масив даних для ітерації
    int currentIndex;      // Поточний індекс
    int dataSize;          // Розмір масиву даних

public:
    ShopIterator(T* arr, int size);  // Конструктор
    bool hasNext() const;            // Перевірка доступності наступного елементу
    T& next();                       // Отримання наступного елементу
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
