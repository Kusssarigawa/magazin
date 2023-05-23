#pragma once
#include "ProductInStore.h"
#include<iostream>
#ifndef PRODUCTONSTOCK_H
#define PRODUCTONSTOCK_H
class ProductOnStock : public ProductInStore {
private:
    double markup;
    std::string expirationDate;

public:
    // Конструктори
    ProductOnStock();
    ProductOnStock(const std::string& name, const std::string& manDate, const std::string& cert,
        double price, const std::string& unit, int qty, const std::string& stockedDate,
        double mark, const std::string& expDate);

    // Деструктор
    ~ProductOnStock();
    // Методи роботи з полями даних
    void setMarkup(double mark);
    void setExpirationDate(const std::string& expDate);

    double getMarkup() const;
    std::string getExpirationDate() const;
    void displayPrice() const;
   
};

#endif  // PRODUCTONSTOCK_H
