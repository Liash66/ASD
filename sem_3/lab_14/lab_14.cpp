#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void putInTable(std::vector<std::vector<std::string>>& table, int hash, std::string value)
{
    table[hash].push_back(value);
}

int main()
{
    std::ifstream in("input.txt");
    std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::vector<std::string> words;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    std::vector<std::vector<std::string>> table(words.size() * 2);
    for (const std::string& word : words) {
        int temp_sum = 0;
        for (char c : word) {
            if (c == '!' || c == '.' || c == ',' || c == '?' || c == ';') {
                int hash = c % table.size();
                putInTable(table, hash, std::string(1, c));
                std::string word = word.substr(0, word.length() - 1);
            }
            temp_sum += static_cast<int>(c);
        }
        int myhash = temp_sum % table.size();
        putInTable(table, myhash, word);
    }

    std::ofstream out("output.txt");
    for (int i = 0; i < table.size(); ++i) {
        std::string temp_string = std::to_string(i) + " : ";
        for (const std::string& value : table[i]) {
            temp_string += value + " ";
        }
        temp_string += "\n";
        out << temp_string;
    }
    out.close();

    return 0;
}