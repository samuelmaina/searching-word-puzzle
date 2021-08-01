

#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

    if (starting_index - word_size < -1)
    {
        return false;
    }
    else
    {
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

bool remainingFoundUpwards(int row, int column, string word, vector<string> &string_to_search)
{
    int word_size = word.size();

    int starting_index = row;
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
            //start to search in the next  upword position.
            starting_index--;
            if (word[k] != string_to_search[starting_index][column])
            {
                return false;
            }
        }
    }
    return true;
}

bool remainingFoundDownwards(int row, int column, string word, vector<string> &string_to_search)
{
    int word_size = word.size();

    int starting_index = row;
    int found_column = column;

    //prevent going out of bound. Ensure that there is enough positions to search for the remaining chars.
    if (starting_index + word_size > string_to_search.size())
    {
        return false;
    }
    else
    {
        //start from 1 since  the first char of the word was found previosly.
        for (int k = 1; k < word_size; k++)
        {
            //start to search in the next  upword position.
            starting_index++;
            if (word[k] != string_to_search[starting_index][column])
            {
                return false;
            }
        }
    }
    return true;
}

bool remainingFoundNorthEast(int row, int column, string word, vector<string> &string_to_search)
{
    int word_size = word.size();

    int starting_index = row;
    int found_column = column;

    //prevent going out of bound. Ensure that there is enough positions to search for the remaining chars.
    if (row - word_size < -1 || column + word_size > string_to_search[row].size())
    {
        return false;
    }
    else
    {
        //start from 1 since  the first char of the word was found previosly.
        for (int k = 1; k < word_size; k++)
        {
            if (word[k] != string_to_search[row - k][column + k])
            {
                return false;
            }
        }
    }
    return true;
}

bool remainingFoundNorthWest(int row, int column, string word, vector<string> &string_to_search)
{
    int word_size = word.size();

    int starting_index = row;
    int found_column = column;

    //prevent going out of bound. Ensure that there is enough positions to search for the remaining chars.
    if (row - word_size < -1 || column - word_size < -1)
    {
        return false;
    }
    else
    {
        //start from 1 since  the first char of the word was found previosly.
        for (int k = 1; k < word_size; k++)
        {
            if (word[k] != string_to_search[row - k][column - k])
            {
                return false;
            }
        }
    }

    for (int k = 0; k < word_size; k++)
    {
        string_to_search[row - k][column - k] = '.';
    }
    return true;
}

bool remainingFoundSouthWest(int row, int column, string word, vector<string> &string_to_search)
{
    int word_size = word.size();
    int found_column = column;

    //prevent going out of bound. Ensure that there is enough positions to search for the remaining chars.
    if (row + word_size > string_to_search.size() || column - word_size < -1)
    {
        return false;
    }
    else
    {
        //start from 1 since  the first char of the word was found previosly.
        for (int k = 1; k < word_size; k++)
        {
            if (word[k] != string_to_search[row + k][column - k])
            {
                return false;
            }
        }
    }

    for (int k = 0; k < word_size; k++)
    {
        string_to_search[row + k][column - k] = '.';
    }
    return true;
}

bool remainingFoundSouthEast(int row, int column, string word, vector<string> &string_to_search)
{
    int word_size = word.size();
    int found_column = column;

    //prevent going out of bound. Ensure that there is enough positions to search for the remaining chars.
    if (row + word_size > string_to_search.size() || column + word_size > string_to_search[row].size())
    {
        return false;
    }
    else
    {
        //start from 1 since  the first char of the word was found previosly.
        for (int k = 1; k < word_size; k++)
        {
            if (word[k] != string_to_search[row + k][column + k])
            {
                return false;
            }
        }
    }

    for (int k = 0; k < word_size; k++)
    {
        string_to_search[row + k][column + k] = '.';
    }
    return true;
}
