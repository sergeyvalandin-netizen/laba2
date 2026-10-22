#include <iostream>
#include <iomanip>
#include <algorithm> // для std::max

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char category;
    double price;
    int quantity;
    int promo, express;

    cout << "Введите категорию товара (A, B или C): ";
    cin >> category;
    cout << "Введите цену товара: ";
    cin >> price;
    cout << "Введите количество: ";
    cin >> quantity;
    cout << "Есть промокод? (0 - нет, 1 - да): ";
    cin >> promo;
    cout << "Экспресс-доставка? (0 - нет, 1 - да): ";
    cin >> express;

    // Проверка корректности цены и количества
    if (price <= 0 || quantity <= 0) {
        cout << "Ошибка: цена и количество должны быть строго больше нуля.\n";
        return 1;
    }
    if (promo != 0 && promo != 1 || express != 0 && express != 1) {
        cout << "Ошибка: признаки должны быть 0 или 1.\n";
        return 1;
    }

    double base_cost = price * quantity;

    // Скидка категории через switch
    double category_discount = 0.0;
    switch (category) {
    case 'A':
    case 'a':
        category_discount = 3.0;
        break;
    case 'B':
    case 'b':
        category_discount = 7.0;
        break;
    case 'C':
    case 'c':
        category_discount = 12.0;
        break;
    default:
        cout << "Ошибка: неизвестная категория товара.\n";
        return 1;
    }

    // Скидка по промокоду
    double promo_discount = (promo == 1) ? 10.0 : 0.0;

    // Применяется только большая скидка
    double max_discount = max(category_discount, promo_discount);
    double cost_after_discount = base_cost * (1.0 - max_discount / 100.0);

    // Дополнительная скидка за количество
    double final_goods_cost = cost_after_discount;
    if (quantity >= 5) {
        final_goods_cost *= 0.95; // уменьшаем на 5%
    }

    // Расчет доставки
    double delivery_cost = 0.0;
    if (express == 1) {
        delivery_cost = (final_goods_cost >= 100.0) ? 7.0 : 12.0;
    }
    else {
        delivery_cost = (final_goods_cost >= 100.0) ? 0.0 : 5.0;
    }

    double total_cost = final_goods_cost + delivery_cost;

    // Вывод промежуточных и итоговых сумм
    cout << fixed << setprecision(2);
    cout << "\n--- Промежуточные расчеты ---\n";
    cout << "Базовая стоимость товаров: " << base_cost << "\n";
    cout << "Примененная скидка: " << max_discount << "%\n";
    cout << "Стоимость после основной скидки: " << cost_after_discount << "\n";
    if (quantity >= 5) {
        cout << "Применена доп. скидка за количество (5%)\n";
    }
    cout << "Итоговая стоимость товаров: " << final_goods_cost << "\n";
    cout << "Стоимость доставки: " << delivery_cost << "\n";

    cout << "\n--- ИТОГ ---\n";
    cout << "Общая сумма к оплате: " << total_cost << "\n";

    return 0;
}