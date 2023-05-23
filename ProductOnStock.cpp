#include "ProductOnStock.h"

// ����������� �� �������������
ProductOnStock::ProductOnStock() : markup(0.0), expirationDate("") {}

// �����������, ���� ������ ���������
ProductOnStock::ProductOnStock(const std::string& name, const std::string& manDate,
    const std::string& cert, double price,
    const std::string& unit, int qty,
    const std::string& stockedDate,
    double mark, const std::string& expDate)
    : ProductInStore(name, manDate, cert, price, unit, qty, stockedDate),
    markup(mark), expirationDate(expDate) {}

// ����������
ProductOnStock::~ProductOnStock() {
    // ��� ����������� (���� �������)
}

// ������ ������ � ������ �����
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
// �������������� ����������� ������ displayPrice() � ��������� ����
void ProductOnStock::displayPrice() const {
    double totalCost = unitPrice + markup;
    std::cout << "ֳ�� ������ �� ����� �� � �������: " << totalCost << " ���/ " << unitOfMeasure << std::endl;
}
    

