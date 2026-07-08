#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        map<int,int> mpp;

        vector<int> ans;
        
        if(!root) return ans;

        // bfs(root, mpp);
        leftDFS(root, 0, mpp);

        for(pair<const int,int> &p : mpp) ans.push_back(p.second);

        return ans;    
    }

    void bfs(Node* root, map<int,int> &mpp){
        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto current = q.front(); q.pop();

            int level = current.second;
            Node* currentNode = current.first;

            if(mpp.find(level) == mpp.end()) mpp[level] = currentNode->data;

            if(currentNode->left) q.push({currentNode->left,level+1});
            if(currentNode->right) q.push({currentNode->right, level+1});
        }
    }
    
    void leftDFS(Node* root, int level, map <int,int> &mpp){
        
        if(!root) return ;
        
        if(mpp.find(level) == mpp.end()) mpp[level] = root->data;

        if(root->left) leftDFS(root->left, level+1, mpp);
        if(root->right) leftDFS(root->right, level+1, mpp);
    }
};