Q1. Find Maximum Depth

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: [3,9,20,null,null,15,7]
Output: 3


#include <iostream>
#include <queue>
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

// Function to find the maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0; // Base case: If the tree is empty, the depth is 0
    }
    int leftDepth = maxDepth(root->left);  // Recursively find the depth of the left subtree
    int rightDepth = maxDepth(root->right); // Recursively find the depth of the right subtree
    return max(leftDepth, rightDepth) + 1; // Add 1 for the current node and return the maximum depth
}

// Utility function to create a binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    cout << "Maximum depth: " << maxDepth(root) << endl;
    return 0;
}
