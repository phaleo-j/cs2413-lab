/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int checkAVL(struct TreeNode* node, int* prev, bool* first) {
    if (node == NULL) return 0;

    // Left subtree
    int lh = checkAVL(node->left, prev, first);
    if (lh == -1) return -1;

    // BST check via inorder (strictly increasing)
    if (!*first && node->val <= *prev) return -1;
    *first = false;
    *prev = node->val;

    // Right subtree
    int rh = checkAVL(node->right, prev, first);
    if (rh == -1) return -1;

    // AVL balance check
    int diff = lh - rh;
    if (diff < -1 || diff > 1) return -1;

    // Height
    return (lh > rh ? lh : rh) + 1;
}


bool isAVL(struct TreeNode* root) {
    int prev = 0;
    bool first = true;
    return checkAVL(root, &prev, &first) != -1;
}
