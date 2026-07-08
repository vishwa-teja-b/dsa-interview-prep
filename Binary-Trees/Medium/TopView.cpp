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
    vector<int> topView(Node *root) {
        // code here
        map<int,int> mpp;

        vector<int> ans;

        bfs(root, mpp);

        for(pair<const int,int> &p : mpp) ans.push_back(p.second);

        return ans;    
    }

    void bfs(Node* root, map<int,int> &mpp){
        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto current = q.front(); q.pop();
            int vertical = current.second;
            Node* currentNode = current.first;

            if(mpp.find(vertical) == mpp.end()) mpp[vertical] = currentNode->data;

            if(currentNode->left) q.push({currentNode->left, vertical-1});
            if(currentNode->right) q.push({currentNode->right, vertical+1});
        }
    }
};

int main(){
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(90);
    root->right->right = new Node(100);
}