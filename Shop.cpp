#include "Shop.h"



Shop::Shop() : products(nullptr), numProducts(0) {}

Shop::~Shop() {
    delete[] products;
}

 void Shop::registerArrival(const ProductOnStock& product) {
    // Створення тимчасового масиву більшого розміру
    ProductOnStock* tempProducts = new ProductOnStock[numProducts + 1];

    // Копіювання існуючих товарів у тимчасовий масив
    for (int i = 0; i < numProducts; i++) {
        tempProducts[i] = products[i];
    }

    // Додавання нового товару у кінець тимчасового масиву
    tempProducts[numProducts] = product;

    // Видалення старого масиву
    delete[] products;

    // Оновлення вказівника на новий масив та збільшення лічильника товарів
    products = tempProducts;
    numProducts++;
}

void Shop::registerShipment(const std::string& productName, int quantity) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].getProductName() == productName) {
            int currentQty = products[i].getQuantity();
            if (currentQty >= quantity) {
                products[i].setQuantity(currentQty - quantity);
                std::cout << "Товар \"" << productName << "\" відгружено." << std::endl;
                return;
            }
            else {
                std::cout << "У магазині недостатньо товару \"" << productName << "\" для відгрузки." << std::endl;
                return;
            }
        }
    }

    std::cout << "Товар \"" << productName << "\" не знайдено у магазині." << std::endl;
}

void Shop::displayInventory() const {
    std::cout << "Інвентарна відомість:" << std::endl;
    for (int i = 0; i < numProducts; i++) {
        std::cout << "Назва товару: " << products[i].getProductName() << std::endl;
        std::cout << "Кількість: " << products[i].getQuantity() << std::endl;
        std::cout << "Вартість одиниці: " << products[i].getUnitPrice() << " грн/ " << products[i].getUnitOfMeasure() << std::endl;
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