#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> stack1, stack2;

    // Push all elements of l1 into stack1
    while (l1 != NULL) {
        stack1.push(l1->val);
        l1 = l1->next;
    }

    // Push all elements of l2 into stack2
    while (l2 != NULL) {
        stack2.push(l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    ListNode* result = NULL;

    // Perform addition using stacks
    while (!stack1.empty() || !stack2.empty() || carry != 0) {
        int sum = carry;
        if (!stack1.empty()) {
            sum += stack1.top();
            stack1.pop();
        }
        if (!stack2.empty()) {
            sum += stack2.top();
            stack2.pop();
        }

        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);
        newNode->next = result;
        result = newNode;
    }

    // Combine all nodes into a single node
    int combinedValue = 0;
    while (result != NULL) {
        combinedValue = combinedValue * 10 + result->val;
        result = result->next;
    }

    return new ListNode(combinedValue);
}

// Helper function to create a linked list from user input
ListNode* createLinkedList() {
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    if (n <= 0) return NULL;

    cout << "Enter the digits in normal order (space-separated): ";
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

// Helper function to print a single node
void printSingleNode(ListNode* node) {
    if (node != NULL) {
        cout << node->val << endl;
    } else {
        cout << "Empty list" << endl;
    }
}

int main() {
    cout << "Input for the first number:\n";
    ListNode* l1 = createLinkedList();

    cout << "Input for the second number:\n";
    ListNode* l2 = createLinkedList();

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Resulting single node: ";
    printSingleNode(result);

    return 0;
}


/********************************************************

Output:

Input for the first number:
Enter the number of digits: 2
Enter the digits in normal order (space-separated): 1 5
Input for the second number:
Enter the number of digits: 2
Enter the digits in normal order (space-separated): 5 1
Resulting single node: 66

*****************************************************************/    
