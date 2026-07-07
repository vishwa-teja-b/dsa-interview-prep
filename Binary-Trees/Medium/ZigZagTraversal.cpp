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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> currentLevel(size);

            for(int i=0;i<size;i++){
                auto current = q.front(); q.pop();

                int index = level % 2 == 0 ? i : size - 1 - i;

                currentLevel[i] = current->val;

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }

            level++;
        }

        return result;
    }

private:
    vector<vector<int>> zigzagLevelOrderNaive(TreeNode* root){
        
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
}