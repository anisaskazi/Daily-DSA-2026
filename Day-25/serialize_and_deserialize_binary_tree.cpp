#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);
        string result = "";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                result += "null,";
            } else {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        stringstream ss(data);
        string value;
        getline(ss, value, ',');

        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, value, ',')) break;
            if (value != "null") {
                node->left = new TreeNode(stoi(value));
                q.push(node->left);
            }

            if (!getline(ss, value, ',')) break;
            if (value != "null") {
                node->right = new TreeNode(stoi(value));
                q.push(node->right);
            }
        }

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;

    string serializedTree = codec.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    TreeNode* deserializedRoot = codec.deserialize(serializedTree);
    cout << "Root after Deserialization: " << deserializedRoot->val << endl;

    return 0;
}
