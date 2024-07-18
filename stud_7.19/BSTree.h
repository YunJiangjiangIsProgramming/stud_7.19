#pragma once
#include<iostream>
//template<class K>
//struct BSTreeNode
//{
//	BSTreeNode<K>* _left;
//	BSTreeNode<K>* _right;
//	K _key;
//	BSTreeNode(const K& key)
//		:_left(nullptr)
//		,_right(nullptr)
//		,_key(key)
//	{}
//};
//
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode Node;
//public:
//	
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (_cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (_cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		cur = new Node(key);
//		if (parent->_key<key)
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		return true;
//	}
//	bool find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//private:
//	Node* _root = nullptr;
//
//};




#include <iostream>


template<class K>
struct BSTreeNode {
    // 指向当前节点左孩子的指针
    BSTreeNode<K>* _left;
    // 指向当前节点右孩子的指针
    BSTreeNode<K>* _right;
    // 存储在当前节点中的键值
    K _key;

    // 节点的构造函数，接收一个键值参数，并初始化节点
    BSTreeNode(const K& key)
        : _left(nullptr)  // 左孩子初始化为 nullptr
        , _right(nullptr) // 右孩子初始化为 nullptr
        , _key(key)      // 将传入的键值保存到节点中
    {
    }
};

// 定义一个模板类 BSTree，其中的 K 是一个类型参数，表示树中节点存储的键值类型
template<class K>
class BSTree {
    // 使用 typedef 简化代码，Node 表示 BSTreeNode<K> 的类型
    typedef BSTreeNode<K> Node;

public:
    // 向二叉搜索树中插入一个键值
    bool Insert(const K& key) {
        // 如果树为空，直接将新节点作为根节点
        if (_root == nullptr) {
            _root = new Node(key);
            return true;
        }

        // parent 用于记录插入位置的父节点
        // cur 用于从根节点开始遍历树
        Node* parent = nullptr;
        Node* cur = _root;
        // 寻找合适的插入位置
        while (cur) {
            // 如果当前节点的键值小于要插入的键值，则向右子树继续寻找插入位置
            if (cur->_key < key) {
                parent = cur;
                cur = cur->_right;
            }
            // 如果当前节点的键值大于要插入的键值，则向左子树继续寻找插入位置
            else if (cur->_key > key) {
                parent = cur;
                cur = cur->_left;
            }
            // 如果找到了相同的键值，说明不需要插入，返回 false
            else {
                return false;
            }
        }

        // 创建新节点并插入到找到的位置
        cur = new Node(key);
        // 根据键值与父节点的关系，将新节点链接到父节点的左孩子或右孩子
        if (parent->_key < key) {
            parent->_right = cur;
        }
        else {
            parent->_left = cur;
        }

        return true;
    }

    // 在二叉搜索树中查找一个键值
    bool Find(const K& key) {
        // 从根节点开始搜索
        Node* cur = _root;
        // 遍历树
        while (cur) {
            // 如果当前节点的键值小于要查找的键值，则向右子树继续查找
            if (cur->_key < key) {
                cur = cur->_right;
            }
            // 如果当前节点的键值大于要查找的键值，则向左子树继续查找
            else if (cur->_key > key) {
                cur = cur->_left;
            }
            // 如果找到了键值，返回 true
            else {
                return true;
            }
        }

        // 如果遍历完整个树都没有找到键值，返回 false
        return false;
    }

    // 从二叉搜索树中删除一个键值
    bool Erase(const K& key) {
        // parent 用于记录要删除节点的父节点
        // cur 用于记录要删除的节点
        Node* parent = nullptr;
        Node* cur = _root;
        // 寻找要删除的节点
        while (cur) {
            if (cur->_key < key) {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_key > key) {
                parent = cur;
                cur = cur->_left;
            }
            else {
                // 找到了要删除的节点
                // 情况 1：要删除的节点没有左子树
                if (cur->_left == nullptr) {
                    // 判断要删除的节点是父节点的左孩子还是右孩子，并更新相应的孩子指针
                    if (parent->_left == cur) {
                        parent->_left = cur->_right;
                    }
                    else {
                        parent->_right = cur->_right;
                    }
                    // 删除节点
                    delete cur;
                }
                // 情况 2：要删除的节点没有右子树
                else if (cur->_right == nullptr) {
                    // 判断要删除的节点是父节点的左孩子还是右孩子，并更新相应的孩子指针
                    if (parent->_left == cur) {
                        parent->_left = cur->_left;
                    }
                    else {
                        parent->_right = cur->_left;
                    }
                    // 删除节点
                    delete cur;
                }
                // 情况 3：要删除的节点有两个子树
                else {
                    // 找到要删除节点的右子树中的最小节点（或左子树中的最大节点）
                    Node* pminRight = cur;
                    Node* minRight = cur->_right;
                    while (minRight->_left) {
                        pminRight = minRight;
                        minRight = minRight->_left;
                    }

                    // 用右子树中的最小节点替换要删除的节点
                    cur->_key = minRight->_key;

                    // 删除右子树中的最小节点
                    if (pminRight->_left == minRight) {
                        pminRight->_left = minRight->_right;
                    }
                    else {
                        pminRight->_right = minRight->_right;
                    }
                    delete minRight;
                }

                return true;
            }
        }

        // 如果没有找到要删除的节点，返回 false
        return false;
    }

    // 中序遍历二叉搜索树
    void InOrder() {
        _InOrder(_root);
        std::cout << std::endl;
    }

private:
    // 中序遍历的递归辅助函数
    void _InOrder(Node* root) {
        // 如果当前节点为空，直接返回
        if (root == nullptr)
            return;

        // 递归遍历左子树
        _InOrder(root->_left);
        // 访问当前节点
        std::cout << root->_key << " ";
        // 递归遍历右子树
        _InOrder(root->_right);
    }

    // 树的根节点
    Node* _root = nullptr;
};

