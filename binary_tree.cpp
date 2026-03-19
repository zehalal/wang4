#include "binary_tree.h"
#include <algorithm>

// ──────────────────────────────────────────────
// 构造 / 析构
// ──────────────────────────────────────────────

BinaryTree::BinaryTree() : root_(nullptr) {}

BinaryTree::~BinaryTree() {
    destroy_(root_);
}

void BinaryTree::destroy_(TreeNode* node) {
    if (!node) return;
    destroy_(node->left);
    destroy_(node->right);
    delete node;
}

// ──────────────────────────────────────────────
// 公开接口
// ──────────────────────────────────────────────

void BinaryTree::insert(int val) {
    root_ = insert_(root_, val);
}

TreeNode* BinaryTree::search(int val) const {
    return search_(root_, val);
}

void BinaryTree::remove(int val) {
    root_ = remove_(root_, val);
}

void BinaryTree::inorder(std::function<void(int)> visit) const {
    inorder_(root_, visit);
}

void BinaryTree::preorder(std::function<void(int)> visit) const {
    preorder_(root_, visit);
}

void BinaryTree::postorder(std::function<void(int)> visit) const {
    postorder_(root_, visit);
}

int BinaryTree::height() const {
    return height_(root_);
}

int BinaryTree::size() const {
    return size_(root_);
}

bool BinaryTree::empty() const {
    return root_ == nullptr;
}

// ──────────────────────────────────────────────
// 私有递归实现
// ──────────────────────────────────────────────

// 插入：相同值不重复插入
TreeNode* BinaryTree::insert_(TreeNode* node, int val) {
    if (!node) return new TreeNode(val);
    if (val < node->val)
        node->left = insert_(node->left, val);
    else if (val > node->val)
        node->right = insert_(node->right, val);
    // val == node->val：重复，不插入
    return node;
}

// 查找
TreeNode* BinaryTree::search_(TreeNode* node, int val) const {
    if (!node || node->val == val) return node;
    if (val < node->val) return search_(node->left, val);
    return search_(node->right, val);
}

// 找子树最小节点（最左节点）；调用者须保证 node 非空
TreeNode* BinaryTree::minNode_(TreeNode* node) const {
    if (!node) return nullptr;
    while (node->left) node = node->left;
    return node;
}

// 删除
TreeNode* BinaryTree::remove_(TreeNode* node, int val) {
    if (!node) return nullptr;

    if (val < node->val) {
        node->left = remove_(node->left, val);
    } else if (val > node->val) {
        node->right = remove_(node->right, val);
    } else {
        // 找到目标节点
        if (!node->left) {
            TreeNode* tmp = node->right;
            delete node;
            return tmp;
        }
        if (!node->right) {
            TreeNode* tmp = node->left;
            delete node;
            return tmp;
        }
        // 两个子节点：用右子树最小值替换，然后删除右子树最小节点
        TreeNode* successor = minNode_(node->right);
        node->val = successor->val;
        node->right = remove_(node->right, successor->val);
    }
    return node;
}

// 中序遍历
void BinaryTree::inorder_(TreeNode* node, std::function<void(int)>& visit) const {
    if (!node) return;
    inorder_(node->left, visit);
    visit(node->val);
    inorder_(node->right, visit);
}

// 前序遍历
void BinaryTree::preorder_(TreeNode* node, std::function<void(int)>& visit) const {
    if (!node) return;
    visit(node->val);
    preorder_(node->left, visit);
    preorder_(node->right, visit);
}

// 后序遍历
void BinaryTree::postorder_(TreeNode* node, std::function<void(int)>& visit) const {
    if (!node) return;
    postorder_(node->left, visit);
    postorder_(node->right, visit);
    visit(node->val);
}

// 高度
int BinaryTree::height_(TreeNode* node) const {
    if (!node) return 0;
    return 1 + std::max(height_(node->left), height_(node->right));
}

// 节点数
int BinaryTree::size_(TreeNode* node) const {
    if (!node) return 0;
    return 1 + size_(node->left) + size_(node->right);
}
