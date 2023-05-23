#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "ProductOnStock.h"
#include "ShopIterator.h"


class Shop  {
private:
    ProductOnStock* products;  // ��������� ����� ��'���� ����� "ProductOnStock"
    int numProducts;           // ʳ������ ������ � �������

public:
    Shop();
    ~Shop();

    void registerArrival(const ProductOnStock& product); // ��������� ����������� ������
    void registerShipment(const std::string& productName, int quantity); // ��������� �������� ������

    void displayInventory() const; // ��������� ���������� �������

    double calculateProfit() const; // ���������� �������� ��������
    ProductOnStock* getProducts() const;  // �������� ������ �������
    int getNumProducts() const;           // �������� ���������� �������
};

#endif  // STORE_H
