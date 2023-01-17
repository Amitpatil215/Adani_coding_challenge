/* Submission towards Adani Coding Challenge on 17 Jan 2023*/
/*  by Amit Patil (Enroll 19104004) Jaypee Institute Of Information technology*/
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

/*
1. Write a function to create a 2-D List/Array with random integers between 0 to 100.
This function should take two arguments - numberOfRows and numberOfColumns and return 2D list.
*/
vector<vector<int>> create2DList(int numberOfRows, int numberOfColumns)
{
    vector<vector<int>> list(numberOfRows, vector<int>(numberOfColumns));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            list[i][j] = dis(gen);
        }
    }

    return list;
}

/*
2. Write a function to sort the 2-D list based on column index keeping the rows intact.
This function should take two arguments - 2D list created above and column Index and return sorted 2D list.
 */
vector<vector<int>> sort2DList(vector<vector<int>> &list, int col)
{
    sort(list.begin(), list.end(), [col](const vector<int> &a, const vector<int> &b)
         { return a[col] < b[col]; });
    return list;
}
int main()
{
    int numberOfRows = 5;
    int numberOfColumns = 5;
    cout << "Enter no of rows and no of cols with a space in b/w" << endl;
    cin >> numberOfRows >> numberOfColumns;

    vector<vector<int>> list = create2DList(numberOfRows, numberOfColumns);

    cout << "Generated 2D Array" << endl;
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter col index to sort" << endl;
    int colIndex = 0;
    cin >> colIndex;
    vector<vector<int>> sortedList = sort2DList(list, colIndex);
    cout << "Sorted 2D Array" << endl;
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            cout << sortedList[i][j] << " ";
        }
        cout << endl;
    }
}
