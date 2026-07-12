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
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);

        return root;
    }

    void dfs(TreeNode* left, TreeNode* right, bool isOddLevel){
        if(!left || !right) return ;

        if(isOddLevel) swap(left,right);

        dfs(left->left, right->right, !isOddLevel);
        dfs(left->right, right->left, !isOddLevel);
    }

private:
    void swap(TreeNode* left, TreeNode* right){
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
    }

    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        
    }
};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);

    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);
}