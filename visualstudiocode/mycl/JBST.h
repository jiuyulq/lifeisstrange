// JBST means jiuyu binary sort tree.
// 一个简单的二叉排序树
#include <iostream>
using std::cout;

typedef int NODE_DATA; //定义节点数据类型 node data type.

typedef struct Node {
    NODE_DATA data;
    Node* left = NULL;
    Node* right = NULL;
} JBST_NODE;

class JBST {
private:
    JBST_NODE* m_tree_root;

public:
    JBST()
    {
        m_tree_root = NULL;
    }
    ~JBST() {}
    JBST_NODE* get_m_tree_root()
    {
        return m_tree_root;
    }
    void insert(NODE_DATA _data); //插入数据到树中，升序。
    void show(JBST_NODE* _tree_root); // 打印树的内容到终端。
};

void JBST::insert(NODE_DATA _data)
{
    JBST_NODE* new_node = new JBST_NODE();
    new_node->data = _data;

    if (NULL == m_tree_root) { //插入第一个节点。
        m_tree_root = new_node;
        return;
    }

    JBST_NODE *p_node = m_tree_root, *p_node_remain;

    while (NULL != p_node) {
        p_node_remain = p_node;

        if (_data < p_node->data) {
            p_node = p_node->left;
        } else {
            p_node = p_node->right;
        }
    }

    if (_data < p_node_remain->data) {
        p_node_remain->left = new_node;
    } else {
        p_node_remain->right = new_node;
    }
}

void JBST::show(JBST_NODE* _tree_root)
{
    if (NULL != _tree_root) {
        show(_tree_root->left);
        cout << _tree_root->data << " ";
        show(_tree_root->right);
    }
}
