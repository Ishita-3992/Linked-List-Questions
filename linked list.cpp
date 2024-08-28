//LINKED LIST:
--similar to arrays, but they are not contiguous and  their length can be varied unlike arrays where
size is fixed.
--it stores the address or location of next member of list through which we traverse the items.
--first is head and last is null
-- used in stacks and queues(length is variable)
--1-D
-- real life: browser- search something-next tabs-can be traversed back-varaible no of actions possible
--int x=2, dtype: int
-- int*y=&x; dtype:pointer-storing memory address
-- ll has both value and address,no fixed dtype, that is why we define structure.
struct node{
	int data;
	node* next; //for next location
	node(d1,ad1) //constructor
	{
		data=d1;
		next=ad1;
	}
};
//assigning values:
node x= node(2,nullptr)
node*y=&x;
node is dtype,x variable,node is calling constructor
node*y= new node(2,nullptr)

//ARRAY TO LL:
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;
    public:
    node(int data1,node*next1)
    {
        data=data1;
        next=next1;
    }
    public:
    node(int data1){
        data=data1;
        next=nullptr;
    }
};
node*arrayll(vector<int>&arr)
{
    node*head=new node(arr[0]);
    node*curr=head;
    for(int i=1;i<arr.size();i++)
    {
        node*temp= new node(arr[i]);
        curr->next=temp;
        curr=temp;
    }
    return head;
}
int main(){
    vector <int>arr={2,3,5,8,7};
    node*head=arrayll(arr);
    node* curr = head;
    while (curr != nullptr) {
    cout << curr->data<< " ";
 curr = curr->next;

    }
    
}

//length of ll
int lengthll(node*head)
{
    int cnt=0;
    node*curr=head;
    while(curr)
    {
        curr=curr->next;
        cnt++;
    }
    return cnt;
}

// search:
int search(node*head,int el)
{
    node*temp=head;
    while(temp)
    {
        if(temp->data==el)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

//delete the head of ll:
node* del(node*head)
{
    if(head==NULL) return head;
    node*temp=head;
    head=head->next;
    delete temp;
    return head;
}
int main(){
    vector <int>arr={2,3,5,8,7};
    node*head1=arrayll(arr);
    node* curr = head1;
    while (curr != nullptr) {
    cout << curr->data<< " ";
    curr = curr->next;
    }
    cout<<" ";
    head1=del(head1);
    node* curr1 = head1;
    while (curr1 != nullptr) {
    cout << curr1->data<< " ";
    curr1 = curr1->next;
    }
    
    
 //delete from tail
    node*delfromtail(node*head)
{
    node*temp=head;
    if(head==NULL|| head->next==NULL)
    {
        return NULL;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

//delete a particular value:
node* delel(node* head, int val) {
    node* temp = head;
    node* prev = NULL;

    if (head == NULL) {
        return NULL;
    }

    // If the head node itself holds the value to be deleted
    if (head->data == val) {
        node* curr = head;
        head = head->next; // Change head
        delete curr; // Free old head
        return head;
    }

    // Search for the value to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the linked list
    if (temp == NULL) {
        cout << "element not found";
        return head; // Return the unchanged head
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp; // Free memory

    return head;
}
// delete from a fixed position:
node* delpos(node* head, int pos) {
    node* temp = head;
    node* prev = NULL;

    if (head == NULL) {
        return NULL;
    }

    // IF THE GIVEN POSITION IS 1
    if (pos==1) {
        node* curr = head;
        head = head->next; // Change head
        delete curr; // Free old head
        return head;
    }
    int cnt=0;
    while (temp != NULL) {
        cnt++;
        if(cnt==pos)
        {
            prev->next=prev->next->next;
            break;
        }
        prev=temp;
        temp = temp->next;
    }
    return head;
}

//insertion:
node* insert(node* head, int pos,int val) {
    if (head == NULL) {
        return NULL;
    }
    if (pos==1) {
        node* temp = new node(val,head);
        return temp;
    }
    int cnt=0;
    node*temp=head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt== (pos-1))
        {
            node*x=new node(val,temp->next);
            temp->next=x;
            
        }
        temp=temp->next;
    }
 return head;   
}

// insertion before a given value:
node* insert(node* head, int el,int val) 
{
    if (head == NULL) {
        return NULL;
    }
    if (head->data==val) {
        node* temp = new node(el,head);
        return temp;
    }
    node*temp=head;
    while(temp!=NULL && temp->next->data!=val)
    {
        
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        cout<<"value not found";
        return head;
    }
        node*x=new node(el,temp->next);
        temp->next=x;
        
    

 return head;   
}

//doubly  linked list: has both next and previous pointers:
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    public:
    node(int data1,node*next1,node*prev1)
    {
        data=data1;
        next=next1;
        prev=prev1;
    }
    public: //default constructor
    node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
node*arrayll(vector<int>&arr)
{
    node*head=new node(arr[0]);
    node*prev=head;
    for(int i=1;i<arr.size();i++)
    {
        node*temp= new node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
int main(){
    vector <int>arr={2,3,5,8,7};
    node*head=arrayll(arr);
    node* curr = head;
    while (curr != nullptr) {
    cout << curr->data<< " ";
    curr = curr->next;

    }
    
}

//delete a head from dll:
node* del(node*head)
{
    if(head==NULL) return head;
    node*temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
}

// tail:
Node * deleteHead(Node *head) {
    if (head == NULL) 
        return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    
    return head;
}

//delete the kth position node
Node *deleteNode(Node *head, int k){
    if (head == nullptr) return nullptr; // Empty list case

    Node *temp = head;
    int cnt = 1; // Start count at 1 to match the given k

    // Traverse the list to find the k-th node
    while (temp != nullptr && cnt < k) {
        cnt++;
        temp = temp->next; 
    }

    // If k is greater than the length of the list
    if (temp == nullptr) return head;

    // Node to be deleted is found at 'temp'
    Node *prev = temp->prev;
    Node *front = temp->next;

    if (prev == nullptr) { // If deleting the head node
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    } else if (front == nullptr) { // If deleting the last node
        prev->next = nullptr;
        delete temp;
        return head;
    } else { // If deleting a middle node
        prev->next = front;
        front->prev = prev;
        delete temp;
        return head;
    }
}

//There exists a doubly linked list with nodes containing integer values. You are given a specified node of the list which 
//you have to delete.
void deleteNode(Node* node) {
   Node*prev=node->prev;
    Node*front=node->next;
    if(front==nullptr)
    {
        prev->next=nullptr;
        delete node;
    }
    else{
    prev->next=front;
    front->prev=prev;
    delete node;
    }
   
}

//Insertion before head:
Node* insertAtFront(Node *head, int k) {
    Node*x=new Node(k,nullptr,head);
    if(head!=nullptr)
    {
     head->prev=x;
    }
    head=x;
    return head;
}

//insertion before tail
Node* tail = head;
while(tail->next != NULL) {
tail = tail->next;
}
Node* prev = tail->back;
Node* newNode = new Node (val, tail, prev);
prev->next = newNode;
tail->back = newNode;
return head;

//insertion before kth node:
Node insertBeforeKth Element (Nodes head, int k, int val) {
if(k=1) {
return insertBeforeHead (head, val);
}
Node* temp = head;
int cnt = 0;
while(temp != NULL) {
cnt++;
if(cnt k) break;
temp = temp->next;
}
Node* prev temp->back;
Node* newNode new Node(val, temp, prev);
prev->next = newNode;
temp->back = newNode;
return head;
}

//insertion after tail:
Node * insertAtTail(Node *head, int k) {
    Node*x=new Node(k,nullptr,nullptr);
    if(head==nullptr)
    {
      return x;
    }
    Node*temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    x->prev=temp;
    temp->next=x;
    return head;
}

//reversing a dll:
//brute force:
O(2n),o(n)

#include<bits/stdc++.h>
Node* reverseDLL(Node* head)
{   
    Node*temp=head;
    stack <int> st;
    while(temp!=nullptr)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    Node*temp1=head;
    while(temp1!=nullptr)
    {
        temp1->data=st.top();
        st.pop();
        temp1=temp1->next;
    }
    return head;
}



//optimal:
#include<bits/stdc++.h>
Node* reverseDLL(Node* head)
{   
    Node*temp=head;
    if(head==nullptr) return nullptr;
    if(head->next==nullptr)
    return head;
    Node*newhead=nullptr;
    while(temp!=nullptr)
    {
        Node*curr=temp->prev;
        temp->prev=temp->next;
        temp->next=curr;
        newhead=temp;
        temp=temp->prev;
        
    }
    return newhead;
}

//adding elements in a ll:
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // we wil use concept of dummy node,whwnever a newlist is involved use,
    //dummy node
    Node*t1=num1;
    Node*t2=num2;
    Node*dummy=new Node(-1);
    Node*curr=dummy;
    int carry=0;
    while(t1!=nullptr || t2!=nullptr)
    {
        int sum= carry;
        if(t1) sum += t1->data; 
        if(t2) sum += t2->data; 
        Node*x= new Node (sum % 10); 
        carry =sum / 10;
        curr->next = x;
        curr = curr->next;
        if(t1) t1 =t1->next;
        if(t2) t2 = t2->next;
    }
if(carry)
 { Node*x = new Node (carry); 
 curr->next = x;
}
return dummy->next;
    }

// odd even list:
//brute:
Node* oddEvenList(Node* head)
{
	//we will create an array first:store all odd  pos values, followed by 
    //even pos values
    //then move temp back to head and make the array into a ll,return head
    if(head==nullptr||head->next==nullptr)
    return head;
    vector <int> arr;
    Node*temp=head;
    while(temp!=nullptr && temp->next!=nullptr)
    {
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    //if odd numbers of entries last element will be left out
    if(temp)
    {
        arr.push_back(temp->data);
    }
    Node*temp1=head->next;
    while(temp1!=nullptr&& temp1->next!=nullptr)
    {
        arr.push_back(temp1->data);
        temp1=temp1->next->next;
    }
    //if odd numbers of entries last element will be left out
    if(temp1)
    {
        arr.push_back(temp1->data);
    }
    int i=0;
    Node*temp2=head;
    while(temp2!=nullptr)
    {
        temp2->data=arr[i];
        i++;
        temp2=temp2->next;
    }
    return head;

}
//optimal:
Node* oddEvenList(Node* head)
{
	if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even!=NULL && even->next!=NULL)
    {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
    }

        odd->next = evenHead;//go back to even pos starting,after all odd pos,even will be filled
        return head;
    }

// sorting 0s,1s,2s:
//brute: reaching a node before
Node* sortList(Node *head){
    Node*temp=head;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    while(temp!=nullptr)
    {
       if(temp->data==0) cnt0++;
       else if(temp->data==1) cnt1++;
       else cnt2++;
       temp=temp->next;
    }
    Node*t1=head;
    while(t1!=nullptr)
    {
      if(cnt0)
      {
          t1->data=0;
          cnt0--;
      }
       else if(cnt1)
      {
          t1->data=1;
          cnt1--;
      }
      else
      {
          t1->data=2;
          cnt2--;
      }
      t1=t1->next;
    }
    return head;
}

//optimal
Node* sortList(Node *head){
    Node*temp=head;
    Node*zeroh=new Node(-1);
    Node*oneh=new Node(-1);
    Node*twoh=new Node(-1);
    Node*zero=zeroh;
    Node*one=oneh;
    Node*two=twoh;
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    while(temp!=nullptr)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=temp;
        }
        else
        {
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=oneh->next? oneh->next:twoh->next;
    //zero ka last will poiint to one ka first if it is present,otherwise
    //it will poin to second ka first,to continue the chain
    one->next= twoh->next;
    two->next=nullptr;
    Node*newhead=zeroh->next;
    return newhead;
}

//remove the kth node from end in single ll:
//brute:
Node* removeKthNode(Node* head, int K)
{
    if(head==nullptr) return nullptr;
    Node*temp=head;
    int cnt=0;
    while(temp!=nullptr)
    {
        cnt++;
        temp=temp->next;
    }
    if(cnt==K) // head needs to be removed
    {
        Node*newhead=head->next;
        delete head;
        return newhead;
    }
    int res=cnt-K;
    Node*temp1=head;
    while(temp1!=nullptr)
    {
        res--;
        if(res==0)
        {
            break;
        }
        temp1=temp1->next;
    }
    Node*delnode=temp1->next;
    temp1->next=temp1->next->next;       
    delete delnode;
    return head;
}

//optimal:

Node* removeKthNode(Node* head, int K)
{
    //this approach takes two pointers,fast and slow both starting from head
    //fast will start from head and traverse k times.
    //now,slow will begin from head and move till the fast reaches null
    //both will traverse simultaneously
    if(head==nullptr) return nullptr;
    Node*temp=head;
    Node*fast=head;
    Node*slow=head;
    for(int i=0;i<K;i++) fast=fast->next;
    if(fast==nullptr) //heads needs to be removed
    {
        Node*newh=head->next;
        delete head;
        return newh;
    }
    while(fast->next!=nullptr)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node*delnode=slow->next;
    slow->next=slow->next->next;
    delete delnode;
    return head;
}

//reversing  a single ll:
//brute:
#include<bits/stdc++.h>
Node* reverseLinkedList(Node *head)
{
    Node*temp=head;
    stack <int> st;
    while(temp!=nullptr)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    Node*temp1=head;
    while(temp1!=nullptr)
    {
        temp1->data=st.top();
        st.pop();
        temp1=temp1->next;
    }
    return head;
}

//optimal:
#include<bits/stdc++.h>
Node* reverseLinkedList(Node *head)
{
    Node*temp=head;
    if(head==nullptr||head->next==nullptr) return head;
    Node*prev=nullptr;
    Node*front;
    while(temp!=nullptr)
    {
        front= temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

//palindrome or not:
//brute using stack: o(2n),o(n)
#include<bits/stdc++.h>
bool isPalindrome(Node *head)
{
    if (head == nullptr) {
        return true; // Empty list is a palindrome
    }

    // Step 1: Push all elements of the list into a stack
    Node* temp = head;
    stack<int> st;
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Step 2: Check if the elements from the stack match the elements in the list
    temp = head; // Reset temp to the head of the list
    while (temp != nullptr) {
        int top = st.top();
        st.pop();
        if (temp->data != top) {
            return false; // Mismatch found
        }
        temp = temp->next;
    }

    return true; // All 
    
}

//optimal:
/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/
#include<bits/stdc++.h>
Node* reverseLinkedList(Node *head)
{
    Node*temp=head;
    if(head==nullptr||head->next==nullptr) return head;
    Node*prev=nullptr;
    Node*front;
    while(temp!=nullptr)
    {
        front= temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    bool is=true;
    //tortoise algo using slow and fast pointer
    //to check palindrome ,we will first find the middle of list
    //if even no of elements: we will take middle1, else only one middle is there
    //reverse the second half of list and check it with first half
    //slow moves one pointer,fast moves 2
    if (head == nullptr||head->next!=nullptr) {
        return is; // Empty list is a palindrome
    }
    Node* temp = head;
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr)
    {
      slow=slow->next;
      fast=fast->next->next;
    }
    Node*newh= reverseLinkedList(slow->next);
    Node*f=head;
    Node*s=newh;
    while(s!=nullptr)
    {
        if(s->data!=f->data)
        {
            is=false;
            break;
        }
        f=f->next;
        s=s->next;
    }
    reverseLinkedList(newh);
    return is; // All 
    
}

//middle of ll:
Node *findMiddle(Node *head) {
    Node*temp=head;
    Node*slow=head;
    Node*fast=head;
    if(head==nullptr || head->next==nullptr) return head;
    int cnt=0;
    while(temp!=nullptr)
    {
        cnt++;
        temp=temp->next;
    }
    if(cnt%2==0)
    {//in even,fast will reach second last element
    while(fast->next!=nullptr&&fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
      return slow->next;
    }    
    else
    {
        //in odd,it will reach last element
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    }
}

//adding 1 to a ll:
//brute:
Node *reverse(Node *head){
    if(head == NULL || head->next ==NULL){
        return head; 
    }
    Node *newhead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
//naive:
//reverse the list,carry =1,add to temp;s data
//if res<10,carry=0
//if res>10,temp ka data will be 0,carry =1
//carry out same till temp is null
//in the end,reverse the list and check carry:
//if 1,add in front of head
Node *addOne(Node *head)
{
    head = reverse(head);
    Node* temp = head;
    int carry = 1;
    while(temp!=NULL){
        temp->data = temp->data+carry;
        if(temp->data<10){
            carry =0;
            break;
        }else{
            temp->data =0;
            carry =1;
        }

        temp= temp->next;
    }
    if(carry ==1){
        Node* newNode= new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }

    head = reverse(head);
    return head;
}

//recursion:
refer video

// INTERSECTION NODE OF A SLL:
//brute:
#include<bits/stdc++.h>
#include<map>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node*temp=firstHead;
    map <Node*,int> intsec;
    while(temp!=nullptr)
    {
        intsec[temp]=1;
        temp=temp->next;
    }
    temp=secondHead;
    while(temp!=nullptr)
    {
        if(intsec.find(temp)!=intsec.end())
        {
          return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}

//better:
Node* coll(Node*t1,Node*t2,int d)
    {
      while(d)
      {
          d--;
          t2=t2->next;
      }
      while(t1!=t2) //came at same level
      {
          t1=t1->next;
          t2=t2->next;
      }
      return t1;
    }
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node*temp1=firstHead;
    int n1=0;
    int n2=0;
    while(temp1!=nullptr)
    {
        n1++;
        temp1=temp1->next;
    }
    Node*temp2=secondHead;
    while(temp2!=nullptr)
    {
        n2++;
        temp2=temp2->next;
    }
    temp1=firstHead;
    temp2=secondHead;
    if(n1<n2)
    {
        return coll(temp1,temp2,n2-n1);
    }
    else{
         return coll(temp2,temp1,n1-n2);

    }


}

//optimal:

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node*t1=firstHead;
    Node*t2=secondHead;
    if(firstHead==nullptr && secondHead==nullptr) return nullptr;
    while(t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;
        if(t1==t2)
        {
            return t1;
        }
        if(t1==nullptr)
        {
            t1=secondHead;
        }
        if(t2==nullptr)
        {
            t2=firstHead;
        }
    }
    
}

//detecting a cycle:
#include<bits/stdc++.h>
bool detectCycle(Node *head)
{
    map <Node*,int> mpp;
    Node*temp=head;
    while(temp!=nullptr)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return true;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}

//optimal:
#include<bits/stdc++.h>
bool detectCycle(Node *head)
{

    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast) return true;
    }
    return false;
}

//length of the loop:
//hashing:
#include<bits/stdc++.h>
int lengthOfLoop(Node *head) {
    map <Node*,int> mpp;
    Node*temp=head;
    int cnt=1;
    int value;
    while(temp!=nullptr)
    {
        
        if(mpp.find(temp)!=mpp.end())
        {
            value= mpp[temp];
            return (cnt-value);
        }
        mpp[temp]=cnt;
        cnt++;
        temp=temp->next;
    }
    return 0;
}

//optimal: tortoise algo: slow,fast
int len(Node*sl,Node*fas)
{
    int cnt=1;
    fas=fas->next;
    while(sl!=fas)
    {
       fas=fas->next;
       cnt++;
    }
    return cnt;
}
int lengthOfLoop(Node *head) {
    Node*slow=head;
    Node*fast=head;
    int cnt=0;
    while(fast!=nullptr && fast->next!=nullptr)
    {
      slow=slow->next;
      cnt++;
      fast=fast->next->next;
      if(slow==fast) return len(slow,fast);
    }
    return 0;
}

//deletinf middle node:
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
Node*mid(Node*head)
{
    Node*temp=head;
    Node*slow=head;
    Node*fast=head;
    if(head==nullptr || head->next==nullptr) return head;
    int cnt=0;
    while(temp!=nullptr)
    {
        cnt++;
        temp=temp->next;
    }
    if(cnt%2==0)
    {//in even,fast will reach second last element
    while(fast->next!=nullptr&&fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
      return slow->next;
    }    
    else
    {
        //in odd,it will reach last element
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    }
}
Node* deleteMiddle(Node* head){
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or has only one node, return nullptr (or handle accordingly)
        delete head;
        return nullptr;
    }
    Node*temp=head;
    Node*prev=head;
    Node*midl= mid(head);
    while(temp!=midl)
    {
       prev=temp;
       temp=temp->next;
      
    }
    if(temp==midl)
    {
        //Node*res=midl;
        delete midl;
        prev->next=temp->next;
    }
    return head;
}

//returning the head of loop:
//hashing:
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    map <Node*,int> mpp;
    Node*temp=head;
    while(temp!=nullptr)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return nullptr;
}
//slow,fast:
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast){
          slow=head;
          while(slow!=fast)
          {
              slow=slow->next;
              fast=fast->next;
          }
          return slow;
      }
    }
    return nullptr;
}

//deleting occurences of a key in dll:
Node* deleteAllOccurrences(Node* head, int k) {
    if (head == nullptr) return nullptr;

    // Deleting all occurrences at the beginning
    while (head != nullptr && head->data == k) {
        Node* toDelete = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete toDelete;
    }

    // Now handle the rest of the list
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == k) {
            Node* toDelete = temp;
            if (temp->prev != nullptr) temp->prev->next = temp->next;
            if (temp->next != nullptr) temp->next->prev = temp->prev;
            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }

    return head;
}

// given a dll,find all  pairs returning a particular sum k:
//brute:
#include<bits/stdc++.h>
#include<vector>
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>> ans;
    Node* temp1=head;
    while(temp1!=nullptr)
    {
        Node*temp2=temp1->next;
        while(temp2!=nullptr)
        {
            if(temp1->data+temp2->data==k)
            {
                ans.push_back({temp1->data, temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
   return ans;
}

//optimal:
#include<bits/stdc++.h>
#include<vector>
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>> ans;
    Node* left=head;
    Node* right=head;
    while(right->next!=nullptr)
    {
        right=right->next;
    }
    while(left->data < right->data)
    {
        if(left->data+right->data==k)
        {
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;

        }
        else if(left->data+right->data<k)
        {
            left=left->next;
        }
        else
        {
          right=right->prev;
        }
       
    }
   return ans;
}

//remove duplicate nodes:
Node * removeDuplicates(Node *head)
{
    Node* temp = head;

    while(temp->next!=nullptr){
        if(temp->data == temp->next->data){
            if(temp==head){
                head=head->next;
            }

            Node* prevNode=temp->prev;
            Node* nextNode=temp->next;

            if(prevNode) prevNode->next=nextNode;
            if(nextNode) nextNode->prev=prevNode;

            free(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }
    }

    return head;
}

//reversing the sll by kth groups:

//rotating the ll k times:
Node*finl(Node*temp,int k)
{
    int cnt=1;
    while(temp!=nullptr)
    {
        if(cnt==k) return temp;
         cnt++;
         temp=temp->next;
    }
    return temp;
}
Node *rotate(Node *head, int k) {
     //we will go to last node,tail,find th length
     //check k ,how many rotations needed
     //if k%len==0,no rotation,return head
     //otherwise k=k%len,itni baar rotate krnaa
     //now attach the tail tp head,new lastnode->next=null
     //update head;

     Node*tail=head;
     int len=1;
     while(tail->next!=nullptr)
     {
       len++;
       tail=tail->next;
     }
     if(k%len==0) return head;
     k=k%len;
     tail->next=head;
     Node*newl=finl(head,len-k);
     head=newl->next;
     newl->next=nullptr;
     return head;
}

//merge 2 sorted ll:
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
     Node<int>* dummy = new Node<int>(-1); // Specify the template type
    Node<int>* temp = dummy;
    Node<int>* t1 = first;
    Node<int>* t2 = second;
     while(t1!=nullptr && t2!=nullptr)
     {
         if(t1->data<t2->data)
         {
             temp->next=t1;
             temp=t1;
             t1=t1->next;
         }
         else{
            temp->next=t2;
             temp=t2;
             t2=t2->next; 
         }
     }
     if(t1!=nullptr)
     {
         temp->next=t1;
     }
     else
         temp->next=t2;
    return dummy->next;
}

// Flattten a linked list

#include<bits/stdc++.h>
Node* flattenLinkedList(Node* head) 
{
    //brute:
	//take temp and temp2,temp 2will traverse the child
	//move from top to botttom and then left to right and insert all nodes in an array
	//sort the array
	//and then transform the array into vertical ll
	Node*temp=head;
	vector <int> vec;
	if(head==nullptr||head->next==nullptr)
	{
		return head;
	}
	while(temp)
	{
		Node*child=temp;
		while(child)
		{
			vec.push_back(child->data);
			child=child->child;
		}
		temp=temp->next;
	}
	if(vec.size()==0)
	{
		return nullptr;
	}
	sort(vec.begin(),vec.end());
	//vec to vertical ll
	Node* newhead = new Node(vec[0]);
	Node* mover = newhead;
	for(int i=1;i<vec.size();i++)
	{
		
		Node*temp1= new Node(vec[i]);
		mover->child=temp1;
		mover=mover->child;
	}
	return newhead;

}

//optimal:

Node*merge(Node*list1,Node*list2)
{
	Node* dummyNode = new Node(-1);
	//dummynode ka next will poin to new node
	Node* res = dummyNode;
	while(list1 != NULL && list2 != NULL) {
		//last 2 lists ke heads ko comapre krenge konsa chota hai vo phle res mein daal denge,
		//then move further and do same
		//a merged listwe will get,recursively caall other lists
		if(list1->data < list2->data) {
			res->child = list1;
			res = list1;
			list1 = list1->child;
		} else {
			res->child = list2;
			res = list2;
			list2 = list2->child;
		}
		
	}

	if(list1) {
		res->child = list1;
	} else {
		res->child = list2;
	}

	if(dummyNode->child) {
		dummyNode->child->next = nullptr;
	}
	res->child->next = nullptr; // this line will get rid of that error
	return dummyNode->child;
}
Node* flattenLinkedList(Node* head) 
{
	//we will move to the end of all the heads
	//and then recursively do backtracking,followed by merge function
	//jab bhi last node pahochenge,head->next==null hojaega aur head return hojaega jaha call hua tha function yani ki 
	//prev wale merhehead par
	//ab merge call hoga us present head aur next head jo ki mergehead mein agyaaa
	if(head == NULL || head->next == NULL) {
		return head;
	}
	Node* mergedHead = flattenLinkedList(head->next);
	head = merge(head, mergedHead);
	return head;
}

//merge k sorted lists:

//make a priority queue: <int,node>
//store the heads of all the lists in the pq
//now from pq,choose the min value,pop it,insert it in ll,after dummy node
//and place the element prrsent next of that head into pq
//again select mninum and get the it out,repeat
//all operations of pq take logk operations

/*A dummy node is created to serve as the head of the merged list, and `tail` is initialized to this dummy node.
ii). The merging process continues until the PriorityQueue is empty:
iii). It pops the smallest node from the PriorityQueue.
iv). This node is appended to the merged list by updating the `next` pointer of the `tail`.
v).`tail` is moved to the appended node, ensuring it always points to the last node of the merged list.
vi). If the popped node has a non-null next node, it is added to the PriorityQueue, as it still has elements left to be merged.*/

 PriorityQueue<Pair<Integer, ListNode>> pq = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());
        for (int i = 0; i < lists.length; i++) {
            if (lists[i]!= null) {
                pq.add(new Pair<>(lists[i].val, lists[i]));
            }
        }
        ListNode dummyNode = new ListNode(-1);
        ListNode temp = dummyNode;
        while (!pq.isEmpty()) {
            Pair<Integer, ListNode> pair = pq.poll();
            ListNode node = pair.getValue();
            if (node.next != null) {
                pq.add(new Pair<>(node.next.val, node.next));
            }
            temp.next = node;
            temp = temp.next;
        }
        return dummyNode.next;
    }
    
    //sorting: brute: o(2n+nlogn),o(n)
    Node *sortLL(Node *head)
{
    // brute
	Node*temp=head;
	vector <int> v;
	while(temp)
	{
		v.push_back(temp->data);
		temp=temp->next;
	}
	sort(v.begin(),v.end());
	temp=head;
	int i=0;
	while(temp!=nullptr)
	{
		temp->data=v[i];
		i++;
		temp=temp->next;
	}
	return head;
}

//optimal:

//merge sort:
//find low,high,mid
//breakdown the list into 2 parts,low to mid and mid+1 to high
// break until single element left
//combine lists using merging 2 sorted lists

Node *findMiddle(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* sortTwoLists(Node* first, Node* second)
{
     Node* dummy = new Node(-1); // Specify the template type
    Node* temp = dummy;
    Node* t1 = first;
    Node* t2 = second;
     while(t1!=nullptr && t2!=nullptr)
     {
         if(t1->data<t2->data)
         {
             temp->next=t1;
             temp=t1;
             t1=t1->next;
         }
         else{
            temp->next=t2;
             temp=t2;
             t2=t2->next; 
         }
     }
     if(t1!=nullptr)
     {
         temp->next=t1;
     }
     else
         temp->next=t2;
    return dummy->next;
}
Node *sortLL(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* middle = findMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;

    Node* left = sortLL(head);
    right = sortLL(right);

    return sortTwoLists(left, right);
}

































