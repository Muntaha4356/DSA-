#include <iostream>
using namespace std;
#include <string>  

struct StackInt{
	double* arr;
	int top;
	int capacity;
	
	StackInt(int size=0){
		capacity=size;
		top=0;
		arr = new double[capacity]; 
	}
	void push(double value){
		if(!isFull()){
			arr[top]=value;
			top++;
			cout << value << " pushed into stack.\n";
		}else{
			cout << "Stack Overflow!\n";
		}
		
		
	}
	void pop(){
		//here you have to check that what if it is empty
		if(!isEmpty()){
			cout << arr[--top] << " popped from stack.\n";
		}else{
			cout << "Stack Underflow!\n";
		}	
	}
	bool isEmpty(){
		return top<=0;
	}
	bool isFull(){
		return top==capacity;
	}
	void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top-1; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    double peek() {
    if (!isEmpty()) {
    	cout<<"Stack is peeked\n";
        return arr[top--];
    } else {
        cout << "Stack is empty!\n";
        return -1; 
	}}
	double Top() {
    if (!isEmpty()) {
    	cout<<"Stack is topped\n";
        return arr[top-1];
    } else {
        cout << "Stack is empty!\n";
        return -1; 
	}}
	~StackInt() {
    delete[] arr;
	}
};
//including the stack
struct Stack{
	char* arr;
	int top;
	int capacity;
	
	Stack(int size=0){
		capacity=size;
		top=0;
		arr = new char[capacity]; 
	}
	void push(char value) {
    if (!isFull()) {
        arr[top++] = value; // Store value and increment `top`
    } else {
        cout << "Stack Overflow!\n";
    }
}
	char pop() {
    if (!isEmpty()) {
        return arr[--top];  // Decrement first, then return the top element
    } else {
        cout << "Stack Underflow!\n";
        return '\0'; // Return null character to indicate failure
    }
}
	bool isEmpty(){
		return top<=0;
	}
	bool isFull(){
		return top==capacity;
	}
	void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top-1; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    char peek() {
    if (!isEmpty()) {
        return arr[top - 1]; // Return the top element without modifying `top`
    }
    cout << "Stack is empty!\n";
    return '\0';
}
	char Top() {
    if (!isEmpty()) {
        return arr[top - 1];  // Return last inserted element
    }
    cout << "Stack is empty!\n";
    return '\0'; // Return null character if stack is empty
}
	~Stack() {
    delete[] arr;
	}
};
//main program
int definePrecedence(char operand){
	if(operand == '/' || operand =='*'){
		return 2;
	}else if(operand=='+'|| operand=='-'){
		return 1;
	}
	return -1;
}
bool isAlphaNumeric(char ch) {
    return isalpha(ch) || isdigit(ch);  // Returns true if ch is a letter or digit
}
string converttoPostfix(string expression){
	Stack s(expression.length());
	string postfixexpression;
	int length= expression.length();
	for(int i=0; i<length; i++){
		if (isAlphaNumeric(expression[i])) {
//			postfixexpression+=expression[i];
		while (i < expression.length() && isAlphaNumeric(expression[i])) {
               	postfixexpression += expression[i];
               	
		        i++;
         }
         postfixexpression+=':';
         i--;
        
    } else if (expression[i] == '(')
            {s.push('(');
			}
	else if(expression[i]==')'){
			while(s.Top()!='('){
				postfixexpression+=s.Top();
				s.pop();
			}
			s.pop();
		}
	else{
    	cout<<expression[i];
    	if(s.isEmpty()){
    		cout<<"was empty"<<endl;
    		s.push(expression[i]);
		}
		
		
		else{
			if(definePrecedence(s.Top())<definePrecedence(expression[i])){
				s.push(expression[i]);
			}else{
				while (!s.isEmpty() && definePrecedence(s.Top()) >= definePrecedence(expression[i])){
					postfixexpression+=s.Top();
					s.pop();
				}
				s.push(expression[i]);
				
			}
		}
		s.display();
	}
	}
	while(!s.isEmpty()){
		postfixexpression+=s.Top();
		s.pop();
	}
	cout<<postfixexpression<<endl;
	return postfixexpression;
}
int evaluatePostfix(string expression){
	StackInt s(expression.length());
	//variable take its value
	string constexpression= "";
	for(int i=0; i<expression.length();i++){
		cout<<expression[i]<<endl;
		if(isalpha(expression[i])){
			string num="";
			cout<<"Please enter value of the variable "<< expression[i]<<endl;
			cin>>num;
			constexpression += num;
		}else{
			constexpression+= expression[i];
		}
	}
	cout<<"this is the constexpression"<<endl;
	cout<<constexpression;
	//you have to make enaother expresion that's consisting entirely of numbers
	//If the element is a number, push it into the stack.
	//If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack.
	for (int i=0; i<constexpression.length(); i++){
		if (isdigit(constexpression[i])) { 
			string num = ""; 
			while(constexpression[i]!=':' && isdigit(constexpression[i])){
				num += constexpression[i];
				i++;
				cout<<"this is the num"<<endl;
				cout<<num;
			}
            
            
//            
            s.push(stoi(num));
            
            s.display();
            
            //i--; // Adjust index since for-loop will increment it
        } else {
            // Now there will be an operand
            cout<<"it was an operand";
            double A; double B;
            B= s.Top();
            s.pop();
            A=s.Top();
            s.pop();
            char op = constexpression[i];
            double num;
            if(op=='+') {
			    
			        num = static_cast<double>(A) + static_cast<double>(B);
			        s.push(num);
			    }
			    else if(op=='-'){
			    	num = static_cast<double>(A) - static_cast<double>(B);
			    	s.push(num);
				}else if(op=='*'){
					num = static_cast<double>(A) * static_cast<double>(B);
					s.push(num);
				}else if(op=='/'){
					num = static_cast<double>(A) / static_cast<double>(B);
					s.push(num);
				}
				cout<<num;
				cout<<"it's displaying all";
				s.display();
				
			}
			
			
			
//        
        }
        
        
	}
	//put things wisely in stack
	

int main(){
	evaluatePostfix(converttoPostfix("22*(8+7-8)+2+(15/3)*9"));
	
}
