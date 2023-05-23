#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "ProductOnStock.h"
#include "ShopIterator.h"


class Shop  {
private:
    ProductOnStock* products;  // Динамічний масив об'єктів класу "ProductOnStock"
    int numProducts;           // Кількість товарів у магазині

public:
    Shop();
    ~Shop();

    void registerArrival(const ProductOnStock& product); // Реєстрація надходження товару
    void registerShipment(const std::string& productName, int quantity); // Реєстрація відгрузки товару

    void displayInventory() const; // Виведення інвентарної відомості

    double calculateProfit() const; // Обчислення прибутку магазину
    ProductOnStock* getProducts() const;  // Получить массив товаров
    int getNumProducts() const;           // Получить количество товаров
};

#endif  // STORE_H
