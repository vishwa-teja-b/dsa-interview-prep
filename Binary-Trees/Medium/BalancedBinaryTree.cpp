#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(abs(findHeight(root->left) - findHeight(root->right)) > 1) return false;

        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;

        return true;
    }

private:
    int findHeight(TreeNode* root){
        if(!root) return -1;

        return 1 + max(findHeight(root->left), findHeight(root->right));
    }
};

int main(){
    TreeNode* root=  new TreeNode(3);
    root->left=  new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution* sol = new Solution();


}