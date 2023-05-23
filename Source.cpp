#include <iostream>
#include <string>
#include "Shop.h"
#include "ShopIterator.h"
#include <Windows.h>

enum class MenuOption {
    EXIT,
    ADD_PRODUCT,
    REGISTER_ARRIVAL,
    REGISTER_SHIPMENT,
    DISPLAY_INVENTORY,
    CALCULATE_PROFIT,
    ITERATE_PRODUCTS
};

// ������� ��� ������ ���� �� ��������� ������ �����������
MenuOption getMenuChoice() {
    std::cout << "����:" << std::endl;
    std::cout << "1. ������ ����� �����" << std::endl;
    std::cout << "2. ������������ ����������� ������" << std::endl;
    std::cout << "3. ������������ �������� ������" << std::endl;
    std::cout << "4. ������� ���������� �������" << std::endl;
    std::cout << "5. ��������� �������� ��������" << std::endl;
    std::cout << "6. �������� �� ������� ��������" << std::endl;
    std::cout << "0. ����� � ��������" << std::endl;

    int choice;
    std::cout << "������� �����: ";
    std::cin >> choice;

    return static_cast<MenuOption>(choice);
}

// ������� ��� ��������� ������ ������ � �������
void addProduct(Shop& shop) {
    std::string productName;
    std::cout << "������ ����� ������: ";
    std::cin.ignore();
    std::getline(std::cin, productName);

    std::string manufacturingDate;
    std::cout << "������ ���� ������������ ������: ";
    std::cin >> manufacturingDate;

    std::string qualityCertificate;
    std::cout << "������ �������� ����� ������: ";
    std::cin.ignore();
    std::getline(std::cin, qualityCertificate);

    double unitPrice;
    std::cout << "������ ������� ������� ������: ";
    std::cin >> unitPrice;

    std::string unitOfMeasure;
    std::cout << "������ ������� ����� ������: ";
    std::cin >> unitOfMeasure;

    int quantity;
    std::cout << "������ ������� ������: ";
    std::cin >> quantity;

    std::string lastShipmentDate;
    std::cout << "������ ���� ���������� ��������� ������: ";
    std::cin >> lastShipmentDate;

    double markup;
    std::cout << "������ ������� ������: ";
    std::cin >> markup;

    std::string expiryDate;
    std::cout << "������ ����� ���������� ������: ";
    std::cin >> expiryDate;

    ProductOnStock product(productName, manufacturingDate, qualityCertificate, unitPrice, unitOfMeasure, quantity,
        lastShipmentDate, markup, expiryDate);

  
    std::cout << "����� ������ ������ �� ��������!" << std::endl;
}

// ������� ��� ������������� ����������� ������
void registerArrival(Shop& shop) {
    
    ProductOnStock productName;
    std::cout << "������ ����� ������: ";
    std::cin.ignore();
   

    int quantity;
    std::cout << "������ ������� ������: ";
    std::cin >> quantity;

    shop.registerArrival(productName);
    std::cout << "����������� ������ ������������!" << std::endl;
}

// ������� ��� ������������� �������� ������
void registerShipment(Shop& shop) {
    std::string productName;
    std::cout << "������ ����� ������: ";
    std::cin.ignore();
    std::getline(std::cin, productName);

    int quantity;
    std::cout << "������ ������� ������: ";
    std::cin >> quantity;

    shop.registerShipment(productName, quantity);
    std::cout << "³������� ������ ������������!" << std::endl;
}

// ������� ��� ��������� ���������� �������
void displayInventory(const Shop& shop) {
    std::cout << "���������� ²��̲���:" << std::endl;
    shop.displayInventory();
}

// ������� ��� ���������� �������� ��������
void calculateProfit(const Shop& shop) {
    double profit = shop.calculateProfit();
    std::cout << "�������� ��������: " << profit << " ���" << std::endl;
}

// ������� ��� ����������� �� ������� ��������
// ������� ��� �������� �� ������� ��������
void iterateProducts(const Shop& shop) {
    std::cout << "�������� �� ������� ��������:" << std::endl;
  ShopIterator<ProductOnStock> iterator(shop.getProducts(), shop.getNumProducts());
    while (iterator.hasNext()) {
        const ProductOnStock& product = iterator.next();
        std::cout << "����� ������: " << product.getProductName() << std::endl;
        std::cout << "���� ������������: " << product.getManufacturingDate() << std::endl;
        std::cout << "�������� �����: " << product.getQualityCertificate() << std::endl;
        std::cout << "������� �������: " << product.getUnitPrice() << " ���" << std::endl;
        std::cout << "������� �����: " << product.getUnitOfMeasure() << std::endl;
        std::cout << "ʳ������: " << product.getQuantity() << std::endl;
        std::cout << "���� ���������� ���������: " << product.getManufacturingDate() << std::endl;
        std::cout << "�������: " << product.getMarkup() << std::endl;
        std::cout << "����� ����������: " << product.getExpirationDate() << std::endl;
        std::cout << "----------------------------" << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Shop shop;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MenuOption choice = MenuOption::EXIT;
    do {
        try {
            choice = getMenuChoice();

            switch (choice) {
            case MenuOption::ADD_PRODUCT:
                addProduct(shop);
                break;
            case MenuOption::REGISTER_ARRIVAL:
                registerArrival(shop);
                break;
            case MenuOption::REGISTER_SHIPMENT:
                registerShipment(shop);
                break;
            case MenuOption::DISPLAY_INVENTORY:
                displayInventory(shop);
                break;
            case MenuOption::CALCULATE_PROFIT:
                calculateProfit(shop);
                break;
            case MenuOption::ITERATE_PRODUCTS:
                iterateProducts(shop);
                break;
            case MenuOption::EXIT:
                std::cout << "����� �� ������������ ��������. �� ���������!" << std::endl;
                break;
            default:
                std::cout << "������� ����. ��������� �� ���." << std::endl;
                break;
            }
        }
        catch (const std::exception& ex) {
            std::cout << "������� �������: " << ex.what() << std::endl;
        }
    } while (choice != MenuOption::EXIT);

    return 0;
}
