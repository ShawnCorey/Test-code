#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode*> qNodes;
        TreeLinkNode *endOfCurrentLevel = root;
        TreeLinkNode *endOfNextLevel;
        qNodes.push(root);
        while(qNodes.empty() == false)
        {
            TreeLinkNode *cur = qNodes.front();
            qNodes.pop();

            if(cur != endOfCurrentLevel && qNodes.empty() != true)
                cur->next = qNodes.front();

            if(cur->left != NULL)
            {
                qNodes.push(cur->left);
                endOfNextLevel = cur->left;
            }
            if(cur->right != NULL)
            {
                qNodes.push(cur->right);
                endOfNextLevel = cur->right;
            }
            if(cur == endOfCurrentLevel)
                endOfCurrentLevel = endOfNextLevel;

        }
    }
};

void dumpNexts(TreeLinkNode *root)
{
    queue<TreeLinkNode*> qNodes;
    TreeLinkNode *endOfCurrentLevel = root;
    TreeLinkNode *endOfNextLevel = NULL;

    if(root == NULL) return;
    cout << "in dumpNexts" << endl;
    qNodes.push(root);
    while(qNodes.empty() != true)
    {
        TreeLinkNode *cur = qNodes.front();
        qNodes.pop();
        cout << cur->val << " " << cur->next << endl;
        if(cur->left != NULL)
            qNodes.push(cur->left);
        if(cur->right != NULL)
            qNodes.push(cur->right);
    }

}

int main()
{
    Solution foo;
    cout << "Hello world!" << endl;
    TreeLinkNode node1(1);
    TreeLinkNode node2(2);
    TreeLinkNode node3(3);
    TreeLinkNode node4(4);
    TreeLinkNode node5(5);
    TreeLinkNode node6(6);
    TreeLinkNode node7(7);
    TreeLinkNode node8(8);

    node1.left = &node2;
    node1.right = &node3;

    node2.left = &node4;
    node2.right = &node5;
    node3.right = &node6;

    node4.left = &node7;
    node6.right = &node8;

    foo.connect(&node1);
    dumpNexts(&node1);


    return 0;
}
