#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double cost;
    int level;

    cout << "Введите стоимость заказа: ";
    cin >> cost;
    cout << "Введите уровень клиента (0, 1 или 2): ";
    cin >> level;

    // Проверка корректности ввода
    if (cost < 0) {
        cout << "Ошибка: стоимость заказа не может быть отрицательной.\n";
        return 1;
    }
    if (level < 0 || level > 2) {
        cout << "Ошибка: уровень клиента должен быть 0, 1 или 2.\n";
        return 1;
    }

    double discount_percent = 0.0;

    // Скидка не предоставляется, если заказ меньше 20
    if (cost >= 20) {
        if (level == 1) {
            discount_percent = 5.0;
        }
        else if (level == 2) {
            discount_percent = 10.0;
        }
    }

    double discount_amount = cost * (discount_percent / 100.0);
    double final_cost = cost - discount_amount;

    cout << fixed << setprecision(2);
    cout << "\n--- Результат ---\n";
    cout << "Процент скидки: " << discount_percent << "%\n";
    cout << "Размер скидки: " << discount_amount << "\n";
    cout << "Итоговая сумма: " << final_cost << "\n";

    return 0;
}