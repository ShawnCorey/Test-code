#include <iostream>

#include <queue>
#include <stack>
using namespace std;

string foo[] = {"bat","bar"};

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode*> qNodes;

        if(root == NULL)
            return;

        qNodes.push(root);

        while(qNodes.empty() == false)
        {
            TreeNode* temp = qNodes.top();
            qNodes.pop();
            if(temp->left != NULL)
            {
                if(temp->right != NULL) qNodes.push(temp->right);

                temp->right = temp->left;
                temp->left = NULL;
                qNodes.push(temp->right);
            } else if (temp->right != NULL){
                qNodes.push(temp->right);
            }


            if(temp->right == NULL && qNodes.empty() == false){
                temp->right = qNodes.top();
            }
        }
    }
};

int main()
{
    Solution foo;
    TreeNode tree1(1);
    TreeNode tree2(2);
    TreeNode tree3(3);
    TreeNode tree4(4);
    TreeNode tree5(5);
    TreeNode tree6(6);

    tree1.right = &tree2;
    tree2.left = &tree3;



    foo.flatten(&tree1);

    return 0;
}
