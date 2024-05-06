#include <iostream>
#include <stack>
#include <cctype> 
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};
class ExpressionTree {
private:
    TreeNode* root;
public:
    ExpressionTree() : root(nullptr) {}
    void buildTree(string prefixExpr) {
        stack<TreeNode*> stk;
        for (int i = prefixExpr.size() - 1; i >= 0; --i) {
            char ch = prefixExpr[i];
            TreeNode* newNode = new TreeNode(ch);
            if (isdigit(ch) || isalpha(ch)) stk.push(newNode);
            else {
                newNode->left = stk.top();
                stk.pop();
                newNode->right = stk.top();
                stk.pop();
                stk.push(newNode);
            }
        }
        root = stk.top();
    }
    void postorderTraversal() {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        TreeNode* current = root;
        do {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            while (!current && !stk.empty()) {
                TreeNode* topNode = stk.top();
                if (topNode->right && topNode->right != prev) {
                    current = topNode->right;
                } else {
                    cout << topNode->data << " ";
                    prev = topNode;
                    stk.pop();
                }
            }
        } while (!stk.empty());
    }
    void deleteTree(TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    ~ExpressionTree() { deleteTree(root); }
};
int main() {
    ExpressionTree et;
    string prefixExpr;
    cout << "Enter a prefix expression: ";
    getline(cin, prefixExpr);
    et.buildTree(prefixExpr);
    cout << "Post-order traversal: ";
    et.postorderTraversal();
    cout << endl;
    return 0;
}
