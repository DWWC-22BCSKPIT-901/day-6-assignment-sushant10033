Q2.Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper function for recursive preorder traversal
void preorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);           // Visit the root
    preorderHelper(root->left, result);   // Traverse the left subtree
    preorderHelper(root->right, result);  // Traverse the right subtree
}

// Function to perform preorder traversal
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorderHelper(root, result);
    return result;
}

// Utility function to create a binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2, new TreeNode(3), nullptr);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    vector<int> result = preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

