#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int x;

    std::cout << "Введите число x" << std::endl;
    std::cin >> x;
    std::cout << "Результат" << std::endl;

    for (size_t K = 0; pow(3, K) < (x + 1); K++)
    {
        for (size_t L = 0; pow(3, K) * pow(5, L) < (x + 1); L++)
        {
            for (size_t M = 0; pow(3, K) * pow(5, L) * pow(7, M) < (x + 1); M++)
            {
                int y = pow(3, K) * pow(5, L) * pow(7, M);
                if (y <= x)
                    std::cout << y << std::endl;
            }
        }
    }

    return 0;
}