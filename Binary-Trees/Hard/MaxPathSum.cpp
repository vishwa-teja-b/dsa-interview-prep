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
    int maxPathSum(TreeNode* root) {
        int maxPathSum = 0;

        dfs(root, maxPathSum);

        return maxPathSum;
    }

    int dfs(TreeNode* root, int &maxPathSum){
        if(!root) return 0;
        // if(root->val < 0) return 0;  //

        int left = dfs(root->left, maxPathSum);
        int right = dfs(root->right, maxPathSum);

        maxPathSum = max(maxPathSum, left + right + root->val);

        return root->val < 0 ? 0 : max(left,right) + root->val;
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);

    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);


    TreeNode* root2 = new TreeNode(-17);
    root2->left = new TreeNode(11);
    root2->right = new TreeNode(4);

    root2->left->left = new TreeNode(20);
    root2->left->right = new TreeNode(-2);

    root2->right->left = new TreeNode(10);


    TreeNode* root3 = new TreeNode(15);
    root3->left = new TreeNode(10);
    root3->right = new TreeNode(20);

    root3->right->left = new TreeNode(-30);
    root3->right->right = new TreeNode(-15);

    Solution* sol = new Solution();

    cout<<sol->maxPathSum(root3)<<endl;

    delete sol;
}