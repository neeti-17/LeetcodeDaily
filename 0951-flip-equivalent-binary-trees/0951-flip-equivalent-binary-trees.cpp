/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
         // Both trees are empty
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        // Just one of the trees is empty
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        // Corresponding values differ
        if (root1->val != root2->val) {
            return false;
        }

        // Check if corresponding subtrees are flip equivalent
        bool noSwap = flipEquiv(root1->left, root2->left) &&
                      flipEquiv(root1->right, root2->right);
        // Check if opposite subtrees are flip equivalent
        bool swap = flipEquiv(root1->left, root2->right) &&
                    flipEquiv(root1->right, root2->left);

        return swap || noSwap;
    }
};

//  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         return checker(root1, root2);
//     }
//     bool checker(TreeNode* node1, TreeNode* node2) {
//         if (!node1 && !node2) return true;
//         if (!node1 || !node2 || node1->val != node2->val) return false;

//         return (checker(node1->left, node2->left) || checker(node1->left, node2->right)) &&
//                (checker(node1->right, node2->right) || checker(node1->right, node2->left));
//     }