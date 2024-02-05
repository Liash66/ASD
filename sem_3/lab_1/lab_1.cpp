#include <iostream>
#include <stack>

bool strCheck(const std::string& str)
{
    std::stack<char> strStack;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                    strStack.push(str[i]);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (strStack.empty())
                return false;

            char top = strStack.top();
            strStack.pop();

            if ((str[i] == ')' && top != '(') ||
                (str[i] == ']' && top != '[') ||
                (str[i] == '}' && top != '{'))
                return false;
        }
    }

    return strStack.empty();
}

int main() {
    setlocale(LC_ALL, "rus");

    std::string string;
    std::cout << "Введите строку" << std::endl;
    std::cin >> string;

    if (strCheck(string)) 
        std::cout << "Строка существует" << std::endl;
    else
        std::cout << "строка не существует" << std::endl;

    return 0;
}