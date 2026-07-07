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
// iterative way 
    int sumOfLeftLeaves(TreeNode* root) {
        
        int res = 0;

        if(!root) return res;
        
        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){
            auto current = st.top(); st.pop();

            if(current->left && isLeaf(current->left)) res += current->left->val;

            if(current->left) st.push(current->left);
            if(current->right) st.push(current->right);
        }

        return res;
    }

private:
    bool isLeaf(TreeNode* node){
        return node->left==nullptr && node->right==nullptr;
    }
};

int main(){
    TreeNode* root=  new TreeNode(3);
    root->left=  new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
}