#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int height(Node* root);

int rangeSum(Node *root, int L, int R) {
	
	//Base case - called on a null node -> return 0!	
	if(root == nullptr){
		return 0;
	}

	int sum = 0;
	sum += rangeSum(root->left, L, R);
	sum += rangeSum(root->right, L, R);

	if(root->key >= L && root->key <= R){
		sum+=root->key;
	}
	
	return sum;

	//Otherwise get the value of the left and right trees under you (recursive call)
	//Sum em
	//Should add node->key to the sum?
	//Return the sum!
}
    
bool isBalanced(Node *root) {
	//Get the heights of the left and right subtrees - helper func?
	//Determine if this node is balanced! If not ret false!
	if(root == nullptr){
		return true;
	}

	//check if the height difference is no more than 1, and also check if the subtrees are balanced
	if(height(root->left) - height(root->right) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
		return true;
	}
	return false;
	//Check if there are subtrees under us
	//Are they balanced?

	//If all nodes are balanced return true!
}

int height(Node* root){
	if(root == nullptr){
		return 0;
	}

	int lHeight = height(root->left);
	int rHeight = height(root->right);

	if(lHeight > rHeight){
		return 1 + lHeight;
	}
	else{
		return 1 + rHeight;
	}
}

/*

Given a binary tree, return the level order traversal of its nodes' values. (i.e. from left to right, level by level).


If you're given this binary tree as input:

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
vector<vector<int>> levelOrder(Node* root) {
	vector<vector<int>> results;
	if(root == nullptr){
		return results;
	}

	 queue<Node*> q;
    q.push(root);

	//start at the top of the tree
    while (!q.empty()) {
		//get how many nodes are on the current level
        int levelSize = q.size();
        vector<int> currentLevel;

		//go through each of those nodes, push back them into the current level,
		//and add their children into the queue
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            currentLevel.push_back(current->key);

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
		//add the current level to the results
        results.push_back(currentLevel);
    }
	return results;
}



