#include <iostream>
using namespace std;

// 链表节点结构体
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// 尾插法新建链表
ListNode* createList()
{
    ListNode *head = new ListNode(-1); // 头结点不存数据
    ListNode *p = head;
    int num;
    cout << "请输入链表元素，输入 -1 结束录入：";
    while (cin >> num && num != -1)
    {
        ListNode *newNode = new ListNode(num);
        p->next = newNode;
        p = p->next;
    }
    return head;
}

// 遍历打印链表所有元素
void printList(ListNode *head)
{
    ListNode *p = head->next;
    cout << "链表内容：";
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

// 按位置插入节点（pos从1开始）
void insertNode(ListNode *head, int pos, int val)
{
    ListNode *p = head;
    for (int i = 0; i < pos - 1 && p->next != nullptr; i++)
    {
        p = p->next;
    }
    ListNode *newNode = new ListNode(val);
    newNode->next = p->next;
    p->next = newNode;
}

// 按位置删除节点
void deleteNode(ListNode *head, int pos)
{
    ListNode *p = head;
    for (int i = 0; i < pos - 1 && p->next != nullptr; i++)
    {
        p = p->next;
    }
    if (p->next == nullptr)
    {
        cout << "删除位置不存在\n";
        return;
    }
    ListNode *del = p->next;
    p->next = del->next;
    delete del;
}

// 按数值查找，返回下标，找不到返回-1
int searchVal(ListNode *head, int target)
{
    ListNode *p = head->next;
    int index = 1;
    while (p != nullptr)
    {
        if (p->data == target)
            return index;
        p = p->next;
        index++;
    }
    return -1;
}

// 释放链表内存，防止内存泄漏
void freeList(ListNode *head)
{
    ListNode *p = head;
    while (p != nullptr)
    {
        ListNode *temp = p;
        p = p->next;
        delete temp;
    }
}

int main()
{
    // 1. 创建链表
    ListNode *link = createList();
    printList(link);

    // 2. 插入测试：第3位插入数字99
    insertNode(link, 3, 99);
    cout << "在第3位插入99后：";
    printList(link);

    // 3. 查找测试
    int target = 5;
    int res = searchVal(link, target);
    if (res == -1)
        cout << "未找到数值" << target << "\n";
    else
        cout << "数值" << target << "在第" << res << "位\n";

    // 4. 删除测试：删除第2个元素
    deleteNode(link, 2);
    cout << "删除第2位元素后：";
    printList(link);

    // 释放内存
    freeList(link);
    return 0;
}
