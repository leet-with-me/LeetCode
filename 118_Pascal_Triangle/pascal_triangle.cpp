#include <vector>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/pascals-triangle/submissions/910441461/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;

        // Handle rows == 1
        if(numRows == 1)
        {
            vector<int> initValue = {1};
            results.push_back(initValue);
            return results;
        }

        // Handle Rows == 2
        if(numRows == 2)
        {
            vector<int> initValue1 = {1};
            vector<int> initValue2 = {1, 1};
            results.push_back(initValue1);
            results.push_back(initValue2);
            return results;
        }

        // Handle anything greater than 2
        if(numRows > 2)
        {
            vector<int> initValue1 = {1};
            vector<int> initValue2 = {1, 1};
            results.push_back(initValue1);
            results.push_back(initValue2);
        }

        // Keep track of the previous row
        vector<int> prevRow = {1, 1};

        // Go through the remain rows
        for(int x = 2; x < numRows; x++)
        {
            // Start with a 1
            vector<int> currentRow = {1};

            // Then add the previous row values
            for(int y = 0; y < (int)prevRow.size()-1; y++)
            {
                currentRow.push_back(prevRow[y] + prevRow[y+1]);
            }

            // Then end with a 1
            currentRow.push_back(1);

            // Add to results
            results.push_back(currentRow);

            // Set new previous row
            prevRow = currentRow;
        }

        return results;
    }
};