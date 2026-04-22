#include <iostream>
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
    bool validate(TreeNode* node, long long low, long long high) {
        if (node == NULL) {
            return true;
        }

        if (node->val <= low || node->val >= high) {
            return false;
        }

        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution obj;
    cout << (obj.isValidBST(root) ? "true" : "false") << endl;

    return 0;
}
