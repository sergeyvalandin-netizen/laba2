#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double cost, mass;
    int urgent, remote;

    cout << "Введите стоимость заказа: ";
    cin >> cost;
    cout << "Введите массу посылки (кг): ";
    cin >> mass;
    cout << "Срочная доставка (0 - нет, 1 - да): ";
    cin >> urgent;
    cout << "Удаленный регион (0 - нет, 1 - да): ";
    cin >> remote;

    // Обработка некорректных данных
    if (cost < 0 || mass < 0) {
        cout << "Ошибка: стоимость и масса не могут быть отрицательными.\n";
        return 1;
    }
    if (urgent != 0 && urgent != 1 || remote != 0 && remote != 1) {
        cout << "Ошибка: признаки должны быть 0 или 1.\n";
        return 1;
    }

    // Расчет обычной доставки
    double regular_delivery = 6.0;
    if (mass > 5.0) regular_delivery += 4.0;
    if (remote == 1) regular_delivery += 7.0;

    // Надбавка за срочность
    double urgent_surcharge = (urgent == 1) ? 10.0 : 0.0;

    // Если заказ >= 150, обычная часть бесплатна
    if (cost >= 150.0) {
        regular_delivery = 0.0;
    }

    double total_delivery = regular_delivery + urgent_surcharge;
    double total_cost = cost + total_delivery;

    cout << fixed << setprecision(2);
    cout << "\n--- Результат ---\n";
    cout << "Стоимость доставки: " << total_delivery << "\n";
    cout << "Итоговая сумма с доставкой: " << total_cost << "\n";

    return 0;
}