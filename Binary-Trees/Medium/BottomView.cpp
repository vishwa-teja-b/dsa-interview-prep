#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;

        map<int,int> mpp;

        bfs(root,mpp);

        for(auto &pair : mpp) ans.push_back(pair.second);

        return ans;
    }

    void bfs(Node* root, map<int,int> &mpp){
        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto current = q.front(); q.pop();

            int vertical = current.second;
            Node* currentNode = current.first;

            mpp[vertical] = currentNode->data;

            if(currentNode->left) q.push({currentNode->left, vertical-1});
            if(currentNode->right) q.push({currentNode->right, vertical+1});
        }
    }
};

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = nullptr;
    root->right->right = new Node(6);
}