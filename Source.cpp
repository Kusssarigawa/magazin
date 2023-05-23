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

// Функція для виводу меню та отримання вибору користувача
MenuOption getMenuChoice() {
    std::cout << "МЕНЮ:" << std::endl;
    std::cout << "1. Додати новий товар" << std::endl;
    std::cout << "2. Зареєструвати надходження товару" << std::endl;
    std::cout << "3. Зареєструвати відгрузку товару" << std::endl;
    std::cout << "4. Вивести інвентарну відомість" << std::endl;
    std::cout << "5. Обчислити прибуток магазину" << std::endl;
    std::cout << "6. Пройтись по товарам магазину" << std::endl;
    std::cout << "0. Вийти з програми" << std::endl;

    int choice;
    std::cout << "Виберіть опцію: ";
    std::cin >> choice;

    return static_cast<MenuOption>(choice);
}

// Функція для додавання нового товару в магазин
void addProduct(Shop& shop) {
    std::string productName;
    std::cout << "Введіть назву товару: ";
    std::cin.ignore();
    std::getline(std::cin, productName);

    std::string manufacturingDate;
    std::cout << "Введіть дату виготовлення товару: ";
    std::cin >> manufacturingDate;

    std::string qualityCertificate;
    std::cout << "Введіть свідоцтво якості товару: ";
    std::cin.ignore();
    std::getline(std::cin, qualityCertificate);

    double unitPrice;
    std::cout << "Введіть вартість одиниці товару: ";
    std::cin >> unitPrice;

    std::string unitOfMeasure;
    std::cout << "Введіть одиницю виміру товару: ";
    std::cin >> unitOfMeasure;

    int quantity;
    std::cout << "Введіть кількість товару: ";
    std::cin >> quantity;

    std::string lastShipmentDate;
    std::cout << "Введіть дату останнього завезення товару: ";
    std::cin >> lastShipmentDate;

    double markup;
    std::cout << "Введіть націнку товару: ";
    std::cin >> markup;

    std::string expiryDate;
    std::cout << "Введіть термін придатності товару: ";
    std::cin >> expiryDate;

    ProductOnStock product(productName, manufacturingDate, qualityCertificate, unitPrice, unitOfMeasure, quantity,
        lastShipmentDate, markup, expiryDate);

  
    std::cout << "Товар успішно додано до магазину!" << std::endl;
}

// Функція для зареєстрування надходження товару
void registerArrival(Shop& shop) {
    
    ProductOnStock productName;
    std::cout << "Введіть назву товару: ";
    std::cin.ignore();
   

    int quantity;
    std::cout << "Введіть кількість товару: ";
    std::cin >> quantity;

    shop.registerArrival(productName);
    std::cout << "Надходження товару зареєстровано!" << std::endl;
}

// Функція для зареєстрування відгрузки товару
void registerShipment(Shop& shop) {
    std::string productName;
    std::cout << "Введіть назву товару: ";
    std::cin.ignore();
    std::getline(std::cin, productName);

    int quantity;
    std::cout << "Введіть кількість товару: ";
    std::cin >> quantity;

    shop.registerShipment(productName, quantity);
    std::cout << "Відгрузка товару зареєстрована!" << std::endl;
}

// Функція для виведення інвентарної відомості
void displayInventory(const Shop& shop) {
    std::cout << "ІНВЕНТАРНА ВІДОМІСТЬ:" << std::endl;
    shop.displayInventory();
}

// Функція для обчислення прибутку магазину
void calculateProfit(const Shop& shop) {
    double profit = shop.calculateProfit();
    std::cout << "Прибуток магазину: " << profit << " грн" << std::endl;
}

// Функція для проходження по товарам магазину
// Функція для ітерації по товарам магазину
void iterateProducts(const Shop& shop) {
    std::cout << "Ітерація по товарам магазину:" << std::endl;
  ShopIterator<ProductOnStock> iterator(shop.getProducts(), shop.getNumProducts());
    while (iterator.hasNext()) {
        const ProductOnStock& product = iterator.next();
        std::cout << "Назва товару: " << product.getProductName() << std::endl;
        std::cout << "Дата виготовлення: " << product.getManufacturingDate() << std::endl;
        std::cout << "Свідоцтво якості: " << product.getQualityCertificate() << std::endl;
        std::cout << "Вартість одиниці: " << product.getUnitPrice() << " грн" << std::endl;
        std::cout << "Одиниця виміру: " << product.getUnitOfMeasure() << std::endl;
        std::cout << "Кількість: " << product.getQuantity() << std::endl;
        std::cout << "Дата останнього завезення: " << product.getManufacturingDate() << std::endl;
        std::cout << "Націнка: " << product.getMarkup() << std::endl;
        std::cout << "Термін придатності: " << product.getExpirationDate() << std::endl;
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
                std::cout << "Дякую за використання програми. До побачення!" << std::endl;
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
                break;
            }
        }
        catch (const std::exception& ex) {
            std::cout << "Виникла помилка: " << ex.what() << std::endl;
        }
    } while (choice != MenuOption::EXIT);

    return 0;
}
