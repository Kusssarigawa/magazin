#pragma once
#ifndef PRODUCTINSTORE_H
#define PRODUCTINSTORE_H
#include<iostream>
#include <string>

class ProductInStore {
protected:
    std::string productName;
    std::string manufacturingDate;
    std::string qualityCertificate;
    double unitPrice;
    std::string unitOfMeasure;
    int quantity;
    std::string lastStockedDate;

public:
    //������������
    ProductInStore(const std::string& name, const std::string& manDate, const std::string& cert,
        double price, const std::string& unit, int qty, const std::string& stockedDate);
    ProductInStore();
    //����������
    virtual ~ProductInStore();
    // �������
    std::string getProductName() const;
    std::string getManufacturingDate() const;
    std::string getQualityCertificate() const;
    double getUnitPrice() const;
    std::string getUnitOfMeasure() const;
    int getQuantity() const;
    std::string getLastStockedDate() const;

    // �������
    void setProductName(const std::string& name);
    void setManufacturingDate(const std::string& date);
    void setQualityCertificate(const std::string& cert);
    void setUnitPrice(double price);
    void setUnitOfMeasure(const std::string& unit);
    void setQuantity(int qty);
    void setLastStockedDate(const std::string& date);
    // �������������� ���������
    ProductInStore& operator=(const ProductInStore& other);
    ProductInStore operator+(double amount) const;
    ProductInStore operator-(double amount) const;

    // ������� ��������
    friend std::istream& operator>>(std::istream& is, ProductInStore& product);
    friend std::ostream& operator<<(std::ostream& os, const ProductInStore& product);
    virtual void displayPrice() const; // ³��������� ����� ��������� ���� ������
};

#endif  // PRODUCTINSTORE_H
