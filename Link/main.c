#include <stdio.h>
#include <stdlib.h>

// 定义链表的节点结构体
typedef struct Node {
    int data;       // 节点存储的数据
    struct Node* next;   // 指向下一个节点的指针
} Node;

// 创建一个新的节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // 分配内存
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;      // 设置节点数据
    newNode->next = NULL;      // 初始化 next 指针为 NULL
    return newNode;
}

// 在链表末尾添加新节点
void append(Node** head, int data) {
    Node* newNode = createNode(data);  // 创建新节点
    
    if (*head == NULL) {  // 如果链表为空，则新节点成为头节点
        *head = newNode;
        return;
    }
    
    Node* last = *head;   // 指向当前最后一个节点
    while (last->next != NULL) {  // 遍历到链表的最后一个节点
        last = last->next;
    }
    
    last->next = newNode;  // 将新节点添加到最后
}

// 查找给定值的节点
Node* find(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;  // 如果没有找到则返回 NULL
}

// 删除给定值的第一个匹配节点
void deleteNode(Node** head, int value) {
    Node* current = *head;
    Node* previous = NULL;
    
    if (current != NULL && current->data == value) {  // 如果头节点就是要删除的节点
        *head = current->next;  // 头节点变为下一个节点
        free(current);  // 释放内存
        return;
    }
    
    while (current != NULL && current->data != value) {  // 遍历直到找到要删除的节点
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {  // 如果遍历完链表都没有找到该节点
        return;
    }
    
    previous->next = current->next;  // 绕过要删除的节点
    free(current);  // 释放内存
}

// 修改给定值的节点
void updateNode(Node** head, int old_value, int new_value) {
    Node* nodeToUpdate = find(*head, old_value);
    if (nodeToUpdate != NULL) {
        nodeToUpdate->data = new_value;  // 更新节点数据
    }
}

// 打印链表的所有元素
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;  // 初始化空链表
    
    // 添加一些元素
    append(&head, 1);
    append(&head, 3);
    append(&head, 5);
    
    // 打印链表
    printf("Original list: ");
    printList(head);
    
    // 修改一个节点
    updateNode(&head, 3, 4);
    
    // 打印更新后的链表
    printf("Updated list: ");
    printList(head);
    
    // 删除一个节点
    deleteNode(&head, 5);
    
    // 打印删除节点后的链表
    printf("List after deletion: ");
    printList(head);
    
    return 0;
}