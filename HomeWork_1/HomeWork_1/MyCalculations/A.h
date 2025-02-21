#pragma once
#include <vector>

namespace Caclulations
{
    // Исходная функция f(x) = 0.25x^3 + x + 1.2502
    inline double f(double x)
    {
        return 0.25 * pow(x, 3) + x + 1.2502;
    }

    // Функция g(x) для метода простых итераций
    // x = g(x), выбираем g(x) = -0.25 * x^3 - 1.2502
    // g(x) должна сходиться, проверяем |g'(x)| < 1

    inline double g(double x)
    {
        return -0.25 * pow(x, 3) - 1.2502;
    }

    inline bool simple_iteration(double (*func)(double), double (*g)(double), double x0, double tol, int max_iter,
                                 double& root)
    {
        int iter = 0;
        double x = x0;
        while (iter < max_iter)
        {
            double x_next = g(x);
            if (fabs(x_next - x) < tol)
            {
                // Проверка условия остановки
                root = x_next;
                return true;
            }
            x = x_next;
            iter++;
        }
        return false; // Если не сошлось
    }


    template <typename T>
    T get_sum_of_negative_elements(const std::vector<T> vector)
    {
        T sum = 0;

        for (int i = 0; i < vector.size(); ++i)
        {
            if (vector[i] < 0)
                sum += vector[i];
        }

        return sum;
    }

    inline int get_sum_of_negative_elements(const std::vector<int> vector)
    {
        int sum = 0;

        for (int i = 0; i < vector.size(); ++i)
        {
            if (vector[i] < 0)
                sum += vector[i];
        }

        return sum;
    }

    inline double get_sum_of_negative_elements(const std::vector<double> vector)
    {
        double sum = 0;

        for (int i = 0; i < vector.size(); ++i)
        {
            if (vector[i] < 0)
                sum += vector[i];
        }

        return sum;
    }
}
