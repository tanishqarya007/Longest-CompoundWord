#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
vector<string> fileReading()
{
    ifstream inputFile("C:/Users/Tanishq/Downloads/longest_compound_word/Input_01.txt");

    vector<string> words;
    string word;

    while (inputFile >> word)
    {
        words.push_back(word);
    }

    inputFile.close();
    return words;
}
