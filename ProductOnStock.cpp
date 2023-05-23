#include "ProductOnStock.h"

// Конструктор за замовчуванням
ProductOnStock::ProductOnStock() : markup(0.0), expirationDate("") {}

// Конструктор, який приймає аргументи
ProductOnStock::ProductOnStock(const std::string& name, const std::string& manDate,
    const std::string& cert, double price,
    const std::string& unit, int qty,
    const std::string& stockedDate,
    double mark, const std::string& expDate)
    : ProductInStore(name, manDate, cert, price, unit, qty, stockedDate),
    markup(mark), expirationDate(expDate) {}

// Деструктор
ProductOnStock::~ProductOnStock() {
    // Код деструктора (якщо потрібно)
}

// Методи роботи з полями даних
void ProductOnStock::setMarkup(double mark) {
    markup = mark;
}

void ProductOnStock::setExpirationDate(const std::string& expDate) {
    expirationDate = expDate;
}

double ProductOnStock::getMarkup() const {
    return markup;
}

std::string ProductOnStock::getExpirationDate() const {
    return expirationDate;
}
// Перевизначення віртуального методу displayPrice() у похідному класі
void ProductOnStock::displayPrice() const {
    double totalCost = unitPrice + markup;
    std::cout << "Ціна товару на складі та в магазині: " << totalCost << " грн/ " << unitOfMeasure << std::endl;
}
    

