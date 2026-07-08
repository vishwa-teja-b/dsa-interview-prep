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


// TC : 0(N*LOGN) SC : O(N)
// HOW CAN I REDUCE TC TO LINEAR ?? --> RIGHT DFS

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(!root)return ans;

        map<int,int> mpp;

        bfs(root, mpp);

        for(auto &pair : mpp) ans.push_back(pair.second);

        return ans;
    }

    void bfs(TreeNode* root, map<int,int> &mpp){
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto current = q.front(); q.pop();

            int level = current.second;
            TreeNode* currentNode = current.first;

            mpp[level] = currentNode->val;

            if(currentNode->left) q.push({currentNode->left,level+1});
            if(currentNode->right) q.push({currentNode->right, level+1});
        }
    }

    void rightDFS(TreeNode* root, int level, map <int,int> &mpp){
        
        if(!root) return ;
        
        if(mpp.find(level) == mpp.end()) mpp[level] = root->val;

        if(root->right) rightDFS(root->right, level+1, mpp);
        if(root->left) rightDFS(root->left, level+1, mpp);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
}