#include <iostream>
#include <vector>
#include <fstream>

#include "helper.h"
#include "logic.h"

using namespace std;

void searchAndPrintSearchResults(string word, vector<string> &word_puzzle);

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
    string foundDirection;
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
                    foundDirection = "right";
                    found = true;
                    //word found,no need to search in other directions.
                    break;
                }
                if (remainingFoundToTheLeft(i, j, word, word_puzzle))
                {
                    foundDirection = "left";
                    found = true;
                    break;
                }
                if (remainingFoundUpwards(i, j, word, word_puzzle))
                {
                    foundDirection = "up";
                    found = true;
                    break;
                }
                if (remainingFoundDownwards(i, j, word, word_puzzle))
                {
                    foundDirection = "down";
                    found = true;
                    break;
                }
                if (remainingFoundNorthEast(i, j, word, word_puzzle))
                {
                    foundDirection = "north-east";
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
        cout << word << ", Found at line " << foundRow << " , location " << foundColumn << ", going " << foundDirection << endl;
    }
    else
    {
        cout << word << ", Not Found" << endl;
    }
}
