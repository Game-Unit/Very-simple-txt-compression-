#include <bits/stdc++.h>

class CompretionKey
{
private:
    std::map<char, std::string> compretionKey;
    std::map<std::string, char> deCompretionKey;
public:
    CompretionKey()
    {
        compretionKey = {
            {'a', "0"},
            {'b', "1"},
            {'c', "2"},
            {'d', "3"},
            {'e', "4"},
            {'f', "5"},
            {'g', "6"},
            {'h', "7"},
            {'i', "8"},
            {'j', "9"},
            {'k', "10"},
            {'l', "11"},
            {'m', "12"},
            {'n', "13"},
            {'o', "14"},
            {'p', "15"},
            {'q', "16"},
            {'r', "17"},
            {'s', "18"},
            {'t', "19"},
            {'u', "20"},
            {'v', "21"},
            {'w', "22"},
            {'x', "23"},
            {'y', "24"},
            {'z', "25"},
            {' ', "26"},
            {'.', "27"},
            {',', "28"},
            {'!', "29"},
            {'?', "30"},
            {'\n', "31"},
            {'A', "32"},
            {'B', "33"},
            {'C', "34"},
            {'D', "35"},
            {'E', "36"},
            {'F', "37"},
            {'G', "38"},
            {'H', "39"},
            {'I', "40"},
            {'J', "41"},
            {'K', "42"},
            {'L', "43"},
            {'M', "44"},
            {'N', "45"},
            {'O', "46"},
            {'P', "47"},
            {'Q', "48"},
            {'R', "49"},
            {'S', "50"},
            {'T', "51"},
            {'U', "52"},
            {'V', "53"},
            {'W', "54"},
            {'X', "55"},
            {'Y', "56"},
            {'Z', "57"},
            {'0', "58"},
            {'1', "59"},
            {'2', "60"},
            {'3', "61"},
            {'4', "62"},
            {'5', "63"},
            {'6', "64"},
            {'7', "65"},
            {'8', "66"},
            {'9', "67"}
            // Add more character mappings as needed
        };

        for (const auto& pair : compretionKey)
        {
            deCompretionKey[pair.second] = pair.first;
        }
    }

    std::map<char, std::string> GetCompretionData()
    {
        return compretionKey;
    }

    std::map<std::string, char> GetDecompretionData()
    {
        return deCompretionKey;
    }
};
