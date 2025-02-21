#include <iostream>
#include <vector>
#include <Windows.h>

#include "MyCalculations/A.h"

using std:: cout;
using std:: vector;
using Caclulations:: get_sum_of_negative_elements;
using Caclulations:: simple_iteration;
using Caclulations:: f;
using Caclulations:: g;

typedef std::vector<int> intVector;
typedef std::vector<double> doubleVector;
typedef std::vector<float> floatVector;

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    const intVector int_arr = {1, -2, 3, -4, 5};
    const doubleVector double_arr = {1.1, -2.2, 3.3, -4.4, 5.5};

    cout << "Сумма отрицательных элементов (int): " << get_sum_of_negative_elements(int_arr) << '\n';
    cout << "Сумма отрицательных элементов (double): " << get_sum_of_negative_elements(double_arr) << '\n';

    // шаблонные функции
    floatVector floatArr = {1.3f, -2.32f, 3.35f, -4.35f, 5.5f};
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
