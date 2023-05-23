#include "Shop.h"



Shop::Shop() : products(nullptr), numProducts(0) {}

Shop::~Shop() {
    delete[] products;
}

 void Shop::registerArrival(const ProductOnStock& product) {
    // ��������� ����������� ������ ������� ������
    ProductOnStock* tempProducts = new ProductOnStock[numProducts + 1];

    // ��������� �������� ������ � ���������� �����
    for (int i = 0; i < numProducts; i++) {
        tempProducts[i] = products[i];
    }

    // ��������� ������ ������ � ����� ����������� ������
    tempProducts[numProducts] = product;

    // ��������� ������� ������
    delete[] products;

    // ��������� ��������� �� ����� ����� �� ��������� ��������� ������
    products = tempProducts;
    numProducts++;
}

void Shop::registerShipment(const std::string& productName, int quantity) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].getProductName() == productName) {
            int currentQty = products[i].getQuantity();
            if (currentQty >= quantity) {
                products[i].setQuantity(currentQty - quantity);
                std::cout << "����� \"" << productName << "\" ���������." << std::endl;
                return;
            }
            else {
                std::cout << "� ������� ����������� ������ \"" << productName << "\" ��� ��������." << std::endl;
                return;
            }
        }
    }

    std::cout << "����� \"" << productName << "\" �� �������� � �������." << std::endl;
}

void Shop::displayInventory() const {
    std::cout << "���������� �������:" << std::endl;
    for (int i = 0; i < numProducts; i++) {
        std::cout << "����� ������: " << products[i].getProductName() << std::endl;
        std::cout << "ʳ������: " << products[i].getQuantity() << std::endl;
        std::cout << "������� �������: " << products[i].getUnitPrice() << " ���/ " << products[i].getUnitOfMeasure() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

double Shop::calculateProfit() const {
    double totalProfit = 0.0;
    for (int i = 0; i < numProducts; i++) {
        double markup = products[i].getMarkup();
        double unitPrice = products[i].getUnitPrice();
        int quantity = products[i].getQuantity();

        totalProfit += (unitPrice + markup) * quantity;
    }

    return totalProfit;
}
ProductOnStock* Shop::getProducts() const {
    return products;
}

int Shop::getNumProducts() const {
    return numProducts;
}