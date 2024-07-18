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
    // ָ��ǰ�ڵ����ӵ�ָ��
    BSTreeNode<K>* _left;
    // ָ��ǰ�ڵ��Һ��ӵ�ָ��
    BSTreeNode<K>* _right;
    // �洢�ڵ�ǰ�ڵ��еļ�ֵ
    K _key;

    // �ڵ�Ĺ��캯��������һ����ֵ����������ʼ���ڵ�
    BSTreeNode(const K& key)
        : _left(nullptr)  // ���ӳ�ʼ��Ϊ nullptr
        , _right(nullptr) // �Һ��ӳ�ʼ��Ϊ nullptr
        , _key(key)      // ������ļ�ֵ���浽�ڵ���
    {
    }
};

// ����һ��ģ���� BSTree�����е� K ��һ�����Ͳ�������ʾ���нڵ�洢�ļ�ֵ����
template<class K>
class BSTree {
    // ʹ�� typedef �򻯴��룬Node ��ʾ BSTreeNode<K> ������
    typedef BSTreeNode<K> Node;

public:
    // ������������в���һ����ֵ
    bool Insert(const K& key) {
        // �����Ϊ�գ�ֱ�ӽ��½ڵ���Ϊ���ڵ�
        if (_root == nullptr) {
            _root = new Node(key);
            return true;
        }

        // parent ���ڼ�¼����λ�õĸ��ڵ�
        // cur ���ڴӸ��ڵ㿪ʼ������
        Node* parent = nullptr;
        Node* cur = _root;
        // Ѱ�Һ��ʵĲ���λ��
        while (cur) {
            // �����ǰ�ڵ�ļ�ֵС��Ҫ����ļ�ֵ����������������Ѱ�Ҳ���λ��
            if (cur->_key < key) {
                parent = cur;
                cur = cur->_right;
            }
            // �����ǰ�ڵ�ļ�ֵ����Ҫ����ļ�ֵ����������������Ѱ�Ҳ���λ��
            else if (cur->_key > key) {
                parent = cur;
                cur = cur->_left;
            }
            // ����ҵ�����ͬ�ļ�ֵ��˵������Ҫ���룬���� false
            else {
                return false;
            }
        }

        // �����½ڵ㲢���뵽�ҵ���λ��
        cur = new Node(key);
        // ���ݼ�ֵ�븸�ڵ�Ĺ�ϵ�����½ڵ����ӵ����ڵ�����ӻ��Һ���
        if (parent->_key < key) {
            parent->_right = cur;
        }
        else {
            parent->_left = cur;
        }

        return true;
    }

    // �ڶ����������в���һ����ֵ
    bool Find(const K& key) {
        // �Ӹ��ڵ㿪ʼ����
        Node* cur = _root;
        // ������
        while (cur) {
            // �����ǰ�ڵ�ļ�ֵС��Ҫ���ҵļ�ֵ��������������������
            if (cur->_key < key) {
                cur = cur->_right;
            }
            // �����ǰ�ڵ�ļ�ֵ����Ҫ���ҵļ�ֵ��������������������
            else if (cur->_key > key) {
                cur = cur->_left;
            }
            // ����ҵ��˼�ֵ������ true
            else {
                return true;
            }
        }

        // �����������������û���ҵ���ֵ������ false
        return false;
    }

    // �Ӷ�����������ɾ��һ����ֵ
    bool Erase(const K& key) {
        // parent ���ڼ�¼Ҫɾ���ڵ�ĸ��ڵ�
        // cur ���ڼ�¼Ҫɾ���Ľڵ�
        Node* parent = nullptr;
        Node* cur = _root;
        // Ѱ��Ҫɾ���Ľڵ�
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
                // �ҵ���Ҫɾ���Ľڵ�
                // ��� 1��Ҫɾ���Ľڵ�û��������
                if (cur->_left == nullptr) {
                    // �ж�Ҫɾ���Ľڵ��Ǹ��ڵ�����ӻ����Һ��ӣ���������Ӧ�ĺ���ָ��
                    if (parent->_left == cur) {
                        parent->_left = cur->_right;
                    }
                    else {
                        parent->_right = cur->_right;
                    }
                    // ɾ���ڵ�
                    delete cur;
                }
                // ��� 2��Ҫɾ���Ľڵ�û��������
                else if (cur->_right == nullptr) {
                    // �ж�Ҫɾ���Ľڵ��Ǹ��ڵ�����ӻ����Һ��ӣ���������Ӧ�ĺ���ָ��
                    if (parent->_left == cur) {
                        parent->_left = cur->_left;
                    }
                    else {
                        parent->_right = cur->_left;
                    }
                    // ɾ���ڵ�
                    delete cur;
                }
                // ��� 3��Ҫɾ���Ľڵ�����������
                else {
                    // �ҵ�Ҫɾ���ڵ���������е���С�ڵ㣨���������е����ڵ㣩
                    Node* pminRight = cur;
                    Node* minRight = cur->_right;
                    while (minRight->_left) {
                        pminRight = minRight;
                        minRight = minRight->_left;
                    }

                    // ���������е���С�ڵ��滻Ҫɾ���Ľڵ�
                    cur->_key = minRight->_key;

                    // ɾ���������е���С�ڵ�
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

        // ���û���ҵ�Ҫɾ���Ľڵ㣬���� false
        return false;
    }

    // �����������������
    void InOrder() {
        _InOrder(_root);
        std::cout << std::endl;
    }

private:
    // ��������ĵݹ鸨������
    void _InOrder(Node* root) {
        // �����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���
        if (root == nullptr)
            return;

        // �ݹ����������
        _InOrder(root->_left);
        // ���ʵ�ǰ�ڵ�
        std::cout << root->_key << " ";
        // �ݹ����������
        _InOrder(root->_right);
    }

    // ���ĸ��ڵ�
    Node* _root = nullptr;
};

