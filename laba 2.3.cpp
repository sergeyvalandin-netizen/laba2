#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char method;
    double amount;

    cout << "Введите способ оплаты (C - карта, T - перевод, E - кошелек): ";
    cin >> method;
    cout << "Введите сумму платежа: ";
    cin >> amount;

    if (amount < 0) {
        cout << "Ошибка: сумма не может быть отрицательной.\n";
        return 1;
    }

    double commission_percent = 0.0;
    bool valid_method = true;

    // Определение комиссии через switch
    switch (method) {
    case 'C':
    case 'c':
        commission_percent = 1.5;
        break;
    case 'T':
    case 't':
        commission_percent = 0.5;
        break;
    case 'E':
    case 'e':
        commission_percent = 2.0;
        break;
    default:
        valid_method = false;
        break;
    }

    if (!valid_method) {
        cout << "Ошибка: неизвестный способ оплаты.\n";
        return 1;
    }

    double commission = amount * (commission_percent / 100.0);

    // Проверка минимальной комиссии
    if (amount < 10.0 && commission < 0.5) {
        commission = 0.5;
    }

    double total_deduction = amount + commission;

    cout << fixed << setprecision(2);
    cout << "\n--- Результат ---\n";
    cout << "Размер комиссии: " << commission << "\n";
    cout << "Общая сумма списания: " << total_deduction << "\n";

    return 0;
}