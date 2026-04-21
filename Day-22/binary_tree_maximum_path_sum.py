#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int maximumSum = INT_MIN;

    int dfs(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        int leftGain = max(dfs(node->left), 0);
        int rightGain = max(dfs(node->right), 0);

        int currentPathSum = node->val + leftGain + rightGain;
        maximumSum = max(maximumSum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maximumSum;
    }
};

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << obj.maxPathSum(root) << endl;

    return 0;
}
