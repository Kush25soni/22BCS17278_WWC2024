#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

// Helper function to create a linked list from user input
ListNode* createLinkedList() {
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    if (n <= 0) return NULL;

    cout << "Enter the digits in reverse order (space-separated): ";
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

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    cout << "Input for the first number:\n";
    ListNode* l1 = createLinkedList();

    cout << "Input for the second number:\n";
    ListNode* l2 = createLinkedList();

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Resulting linked list: ";
    printLinkedList(result);

    return 0;
}


/******************************************************

Output:

Input for the first number:
Enter the number of digits: 1
Enter the digits in reverse order (space-separated): 2
Input for the second number:
Enter the number of digits: 1
Enter the digits in reverse order (space-separated): 3
Resulting linked list: 5

    ******************************************************/
