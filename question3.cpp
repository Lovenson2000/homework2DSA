// Lovenson Beaucicot
// 1123557
// Nov 28, 2024

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays)
{
    vector<int> result;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
    
    for (int i = 0; i < arrays.size(); ++i)
    {
        if (!arrays[i].empty())
        {
            minHeap.push(make_tuple(arrays[i][0], i, 0));
        }
    }

    while (!minHeap.empty())
    {
        auto [val, arrayIdx, elemIdx] = minHeap.top();
        minHeap.pop();
        result.push_back(val);

        if (elemIdx + 1 < arrays[arrayIdx].size())
        {
            minHeap.push(make_tuple(arrays[arrayIdx][elemIdx + 1], arrayIdx, elemIdx + 1));
        }
    }

    return result;
}

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> arrays(k);

    // Input arrays
    for (int i = 0; i < k; ++i)
    {
        int size;
        cin >> size;
        arrays[i].resize(size);
        for (int j = 0; j < size; ++j)
        {
            cin >> arrays[i][j];
        }
    }

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i)
    {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
