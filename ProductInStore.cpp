#pragma once
#include "ProductInStore.h"



// ����������� �����
ProductInStore::ProductInStore() {
    // ����������� ���� ����� �� �������������
    productName = "";
    manufacturingDate = "";
    qualityCertificate = "";
    unitPrice = 0.0;
    unitOfMeasure = "";
    quantity = 0;
    lastStockedDate = "";
}
ProductInStore::ProductInStore(const std::string& name, const std::string& manDate,
    const std::string& cert, double price,
    const std::string& unit, int qty,
    const std::string& stockedDate)
    : productName(name), manufacturingDate(manDate), qualityCertificate(cert),
    unitPrice(price), unitOfMeasure(unit), quantity(qty),
    lastStockedDate(stockedDate) {}
ProductInStore::~ProductInStore() {
    // ���������� �����������
    
}
// �������
std::string ProductInStore::getProductName() const {
    return productName;
}

std::string ProductInStore::getManufacturingDate() const {
    return manufacturingDate;
}

std::string ProductInStore::getQualityCertificate() const {
    return qualityCertificate;
}

double ProductInStore::getUnitPrice() const {
    return unitPrice;
}

std::string ProductInStore::getUnitOfMeasure() const {
    return unitOfMeasure;
}

int ProductInStore::getQuantity() const {
    return quantity;
}

std::string ProductInStore::getLastStockedDate() const {
    return lastStockedDate;
}

// �������
void ProductInStore::setProductName(const std::string& name) {
    productName = name;
}

void ProductInStore::setManufacturingDate(const std::string& date) {
    manufacturingDate = date;
}

void ProductInStore::setQualityCertificate(const std::string& cert) {
    qualityCertificate = cert;
}

void ProductInStore::setUnitPrice(double price) {
    unitPrice = price;
}

void ProductInStore::setUnitOfMeasure(const std::string& unit) {
    unitOfMeasure = unit;
}

void ProductInStore::setQuantity(int qty) {
    quantity = qty;
}

void ProductInStore::setLastStockedDate(const std::string& date) {
    lastStockedDate = date;
}

// �������������� ��������� ��������� =
ProductInStore& ProductInStore::operator=(const ProductInStore& other) {
    if (this != &other) {
        productName = other.productName;
        manufacturingDate = other.manufacturingDate;
        qualityCertificate = other.qualityCertificate;
        unitPrice = other.unitPrice;
        unitOfMeasure = other.unitOfMeasure;
        quantity = other.quantity;
        lastStockedDate = other.lastStockedDate;
    }
    return *this;
}

// �������������� ��������� +
ProductInStore ProductInStore::operator+(double amount) const {
    ProductInStore result = *this;
    result.unitPrice += amount;
    return result;
}

// �������������� ��������� -
ProductInStore ProductInStore::operator-(double amount) const {
    ProductInStore result = *this;
    result.unitPrice -= amount;
    return result;
}

// �������������� ���������� ��������� �������� >>
std::istream& operator>>(std::istream& is, ProductInStore& product) {
    // ��� ��� �������� ������� ��'���� � ������
    // ���������, �������������� is >> productField;
    return is;
}

// �������������� ���������� ��������� ��������� <<
std::ostream& operator<<(std::ostream& os, const ProductInStore& product) {
    // ��� ��� ��������� ������� ��'���� � ����
    // ���������, �������������� os << productField;
    return os;
}
// ��������� ����������� ������ displayPrice() � �������� ����
void ProductInStore::displayPrice() const {
    std::cout << "ֳ�� ������: " << unitPrice << " ���/ " << unitOfMeasure << std::endl;
}