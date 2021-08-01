#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void readFileAndWriteInto1DArray(string file_name, vector<string> &array);

void printArrayContent(vector<string> &array);

int main(int argc, char const *argv[])
{
    string search_words_file = "words.txt";
    vector<string> search_words;
    readFileAndWriteInto1DArray(search_words_file, search_words);
    printArrayContent(search_words);

    string word_puzzle_file = "word_puzzle.txt";
    vector<string> word_puzzle;
    readFileAndWriteInto1DArray(word_puzzle_file, word_puzzle);
    printArrayContent(word_puzzle);
    return 0;
}

void readFileAndWriteInto1DArray(string file_name, vector<string> &array)
{
    ifstream inputFile(file_name);
    if (inputFile.good())
    {
        string word;
        while (inputFile >> word)
        {
            array.push_back(word);
        }
        inputFile.close();
    }
    else
    {
        cout << "Could not open the file in a good state.!";
        exit(1);
    }
}

void printArrayContent(vector<string> &array)
{
    for (auto word : array)
    {
        cout << word << endl;
    }
}
