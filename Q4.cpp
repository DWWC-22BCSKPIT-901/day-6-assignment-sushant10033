Q4 2.	Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

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

// Helper function for the recursive DFS
void dfs(TreeNode* node, int depth, vector<int>& result) {
    if (!node) return;
    if (depth == result.size()) {
        result.push_back(node->val); // Add the first node of this depth
    }
    dfs(node->right, depth + 1, result); // Traverse right subtree first
    dfs(node->left, depth + 1, result);  // Then traverse left subtree
}

// Function to get the right side view of a binary tree
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    dfs(root, 0, result);
    return result;
}

// Utility function to create a binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, nullptr, new TreeNode(5));
    root->right = new TreeNode(3, nullptr, new TreeNode(4));
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    vector<int> result = rightSideView(root);
    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
