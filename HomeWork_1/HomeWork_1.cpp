#include <iostream>
#include <vector>

#include "MyCalculations/A.h"

using std:: cout;
using std:: end;
using std:: endl;
using std:: vector;

int main(int argc, char* argv[])
{
    const vector<int> int_arr = {1, -2, 3, -4, 5};
    const vector<double> double_arr = {1.1, -2.2, 3.3, -4.4, 5.5};

    cout << "Сумма отрицательных элементов (int): " << get_sum_of_negative_elements(int_arr) << '\n';
    cout << "Сумма отрицательных элементов (double): " << get_sum_of_negative_elements(double_arr) << '\n';

    // шаблонные функции
    vector<float> floatArr = {1.3f, -2.32f, 3.35f, -4.35f, 5.5f};
   cout << "Сумма отрицательных элементов (template float): " <<get_sum_of_negative_elements(floatArr) << '\n';

    // метод итераций
    constexpr double x0 = 0;      // Начальное приближение
    constexpr double tolerance = 1e-6;  // Точность
    constexpr int max_iterations = 100; // Максимальное число итераций
    double root;
    
    if (simple_iteration(f, g, x0, tolerance, max_iterations, root))
    {
        cout << "Приближенное решение: " << root << '\n';
        return 0;
    }
    
    cout << "Метод не сошелся за " << max_iterations << " итераций." << '\n';
    return 0;
}
