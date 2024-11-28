// Lovenson Beaucicot
// 1123557
// Nov 28, 2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    TreeNode *buildTree(vector<int> &arr)
    {
        if (arr.empty() || arr[0] == -1)
            return nullptr;

        TreeNode *root = new TreeNode(arr[0]);
        queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size())
        {
            TreeNode *current = q.front();
            q.pop();

            // Left child
            if (i < arr.size() && arr[i] != -1)
            {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
            }
            i++;

            // Right child
            if (i < arr.size() && arr[i] != -1)
            {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }

    pair<int, int> diameterHelper(TreeNode *node)
    {
        if (!node)
            return {0, 0};

        auto [leftHeight, leftDiameter] = diameterHelper(node->left);
        auto [rightHeight, rightDiameter] = diameterHelper(node->right);
        int currentDiameter = leftHeight + rightHeight + 1;
        int maxDiameter = max({currentDiameter, leftDiameter, rightDiameter});

        return {max(leftHeight, rightHeight) + 1, maxDiameter};
    }

public:
    int calculateDiameter(vector<int> &arr)
    {
        if (arr.empty() || (arr.size() == 1 && arr[0] == -1))
            return 0;

        TreeNode *root = buildTree(arr);

        return diameterHelper(root).second;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, -1, -1, -1, -1, 6, 7};
    Solution solution;

    cout << "Diameter of the binary tree: "
         << solution.calculateDiameter(input) << endl;

    return 0;
}