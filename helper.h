#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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
#endif