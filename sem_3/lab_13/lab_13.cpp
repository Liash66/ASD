#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool putInTable(int HashValue, const std::string& value, std::vector<std::string>& HashTable)
{
    for (size_t i = HashValue; i < HashTable.size(); i++)
    {
        if (HashTable[i].empty())
        {
            HashTable[i] = value;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ifstream in("input.txt");
    if (!in.is_open())
        std::cerr << "Error" << std::endl;

    std::vector<std::string> words;
    std::string word;
    while (in >> word)
    {
        std::string cleanword;
        for (char c : word)
        {
            if (c != '.' && c != '?' && c != '!' && c != ',' && c != ';' && c != ':' && c != '(' && c != ')')
                cleanword += c;
        }
        words.push_back(cleanword);
    }
    in.close();

    std::vector<std::string> HashTable(words.size() * 2);

    for (std::string& word : words)
    {
        int temp = 0;
        for (char c : word)
        {
            temp += static_cast<int>(c);
        }

        int HashValue = temp % HashTable.size();

        if (!putInTable(HashValue, word, HashTable))
            putInTable(HashValue, word, HashTable);
    }

    std::ofstream out("output.txt");
    if (!out.is_open())
        std::cerr << "Error";

    for (size_t i = 0; i < HashTable.size(); i++)
    {
        out << i << " : " << HashTable[i] << std::endl;
    }

    out.close();
 
    return 0;
}