#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void searchAndPrintSearchResults(string word, vector<string> &word_puzzle);

bool remainingFoundToTheRight(int row, int column, string word, vector<string> &word_puzzle);

bool remainingFoundToTheLeft(int row, int column, string word, vector<string> &string_to_search);

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

    for (auto word : search_words)
    {
        searchAndPrintSearchResults(word, word_puzzle);
    }
    return 0;
}

void searchAndPrintSearchResults(string word, vector<string> &word_puzzle)
{
    bool found = false;
    int foundRow, foundColumn;
    for (int i = 0; i < word_puzzle.size(); i++)
    {
        for (int j = 0; j < word_puzzle[i].size(); j++)
        {
            //found the first letter of the word in the grid.
            if (word[0] == word_puzzle[i][j])
            {
                foundRow = i;
                foundColumn = j;
                if (remainingFoundToTheRight(i, j, word, word_puzzle))
                {
                    found = true;
                    //word found,no need to search in other directions.
                    break;
                }
                if (remainingFoundToTheLeft(i, j, word, word_puzzle))
                {
                    found = true;
                    break;
                }
            }
        }
        //word found in the current row hence no need to continue to the next row.
        if (found)
            break;
    }
    if (found)
    {
        cout << word << ", Found at line " << foundRow << " , location " << foundColumn << endl;
    }
    else
    {
        cout << word << ", Not Found" << endl;
    }
}

bool remainingFoundToTheRight(int row, int column, string word, vector<string> &word_puzzle)
{

    bool found;
    string search_string = word_puzzle[row];

    int word_size = word.size();

    int starting_index = column;
    int found_column = column;

    //prevent going out of bound. Ensure that there is enough positions to search for the remaining chars.
    if (word_size + starting_index > search_string.size())
    {
        return false;
    }
    else
    {
        //start from 1 since  the first char of the word was found previosly.
        for (int k = 1; k < word_size; k++)
        {
            //start to search in the next position.
            starting_index++;
            if (word[k] != search_string[starting_index])
            {
                return false;
            }
        }
    }

    return true;
}

bool remainingFoundToTheLeft(int row, int column, string word, vector<string> &string_to_search)
{
    string search_string = string_to_search[row];

    int word_size = word.size();

    int starting_index = column;
    int found_column = column;

    //prevent going out of bound. Ensure that there is enough positions to search for the remaining chars.
    if (starting_index - word_size < -1)
    {
        return false;
    }
    else
    {
        //start from 1 since  the first char of the word was found previosly.
        for (int k = 1; k < word_size; k++)
        {
            //start to search in the next position.
            starting_index--;
            if (word[k] != search_string[starting_index])
            {
                return false;
            }
        }
    }

    return true;
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
