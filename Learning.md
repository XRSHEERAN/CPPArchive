#### Some Notes

```CPP
std::cin >> num1 >> num2... //seperate by space can take multiple input
```

```CPP
//Naming can use either underscore or capital style
int age=2;
int age(2);
int age{2};
```

```CPP
//Global vs local
int num{0};
int main(){
  int num{1};
  //codes local will use the variable declared locally, which is 1
}//global is not a good practice
```

```CPP
#includes <climits> //defines the size and precision of the primitive type (Machine defined)
```

```CPP
//constant cannot be changed or it will cause a compiler err
//Occupy storage
const
constexpr
enum
//avoid using #define for const
```

```CPP
//Array (replaced by vector)
int arr[10]{1,2};
int multi[2][2]{{}};
```

```CPP
//range based
for(auto num : {1,2,3,4,5}){
  cout<<num;
  }
```

```CPP
#include<cctype>
char c;
isalpha(c);//if a letter
isalnum(c);//if a letter or digit
//...
```

##### String
a sequence of characters used in c style, called string literals. Strings are end by null
```CPP
#include<cstring>

char my_name[]{"Sheeran"};//eight characters include null in the end
char partial[4]='y';//fine, else are null
strcpy(my_name,"Xianrun");//but no equal after initialization, no partial="newS";
```
```CPP
#include <cstring>
#include <cctype>
char* first_name="Bjarne";
char last_name[]{"Stroustrup"};
char whole_name[strlen(first_name)+strlen(last_name)+1]{};
    
int first_name_length=strlen(first_name);
int last_name_length=strlen(last_name);
strcpy(whole_name,first_name);
strcat(whole_name,last_name);
int whole_name_length=strlen(whole_name);
```
#### String vs cString
- dynamic sizing
- also work with input with output streams
- builtin functions

```CPP
#include<string>
string s1;
string s2{"Sheeran"};
string s3 {s2};
string s3{s2,2,2};//"22", start position and length of substring
std::cout<<s2[0]<<s2.at(0);
string s4=s2+"a";//ok
string s5="a"+"B";//not okay as they are both cstyle strings
for(char i : s)
for(int i : s)//all represent characters
//== != >= < <= can use on string  vs other strings
s1.substr(0,2);//substring
s2.find('s');//0
s2.erase(0,5);//delete 5 characters from 0
s2.clear();//erase all
getline(cin,s1);//get all until /n
getline(cin,s1,'x');//get line until 'x'
```

```CPP
int proto(int);//function prototype
int defaultProto(double rate=0.1);//prototype contains default definition
int funcRef(int&);
int funcRef(int &pass){
}//can define in the function
int funcV(const std::vector<int> &v){
}//pass without having a copy and protect data in v
//Without the reference symbol, c++ will always pass by value
//inline insert the codes when executing instead of replacing which is suit for smaller functions
inline in func(int a){
  return 0;
  }
```

#### Pointer
A variable stores the address of memory
```CPP
int num{10};
int* ptr{null};//this is pointer, p is it's value, &p is the address of p, all pointers have the same size
ptr=&num;//points to the integer address
*ptr=200;//deference and reassign value in the address
//pointers allocate memory on heap
ptr=new int;//allocate memory for another interger
delete ptr;//must delete after using for safety
//array are not pointers but they can use the same syntax
ptr=new int[2];
delete[] ptr;
*(ptr+1)=ptr[0];
int* a, b;
...
int num=a-b;//this is the number of elements between the two numbers;

//constant
const int* ptr{&num};//the num is constant and cannot change
ptr=&num2;//the pointer can still point to elsewhere
int const* ptr{&num};//this pointer is constant and cannot point elsewhere
```

#### Pass by Pointer
Pass by pointer can be more convinient when manipulating array data and it can point to null.

Reference is like a constant pointer that automatically deferences.
```CPP
void fun(double* ptr){
}
int* func(double a){
int* ptr;
return ptr;
}
```
#### Classes
```CPP
class my{
  string s;
  void insideFunc(){
    std::cout<<"fuction Within";
  }
  void funcOut();
}
my::funcOut(){
  cout<<"Function declared outside";
}
my somObj;//declare object
my* ptr=new my();//a pointer to object
delete ptr;
ptr->s;//access with ->
```
#### Private can be accessed when implementing
Default constructor will be provided only when there is no constructor defined
```CPP
#include <iostream>
#include <string>
class my{
  std::string s;
  public:
  my(){
    s="Yes";
  }
  //overload
  my(string s){
  }
  std::string str();
};

int main() {
  my test;
  my param{"something"};
  std::cout << test.str();
}
std::string my::str(){
  return s;
}
```

#### Copy Constructor
```CPP
Player::Player(const Player& pt){};
```

#### This Operator
A variable stores the current object
```CPP
this->classMember
```

#### Struct vs Class
- Struct and Class are almost the same except class is private and struct is public by default.
- Generally dont declare methods in struct

#### Inheritance
```CPP
class superC{}
class subC : public superC, private superC{};//private by default
subC::subC(int x):superC{1},value(x){}
```
- Protected class members can be accessed in derived classes, but not objects.
- Derived class will call the base constructor first

#### Redefine Base Methods
```CPP
class a{
  virtual void SuperFunc(){
  }
  final void myown(){};//this function cannot be deriveed
}
final class f{}//this class cannot be 
class child : a{
//inherit default private methods
  virtual void SuperFunc(){
  //redefine
  }
  

a* ptr=new child();
ptr->superFunc();//calls the child class function by run time binding virtual function, normal functions cannot
```
- Reference also binds dynamically

```CPP
//Pure Virtual Functions
class abstractClass{
  virtual purev()=0;//contains at least one such function
}
//if derived class doesn't override the pure virtual functions, then they are alsp abstract functions
//abstract class can contain implementation, but not final
//CPP doesn't have interface, use override and pure virtual instead
//must have a virtual destructor if using a pointer to base class
```

#### STL

```CPP
std::sort(vec.begin(),vec.end());//use of functions and iterators
std::reverse(vec.begin(),vec.end());//use of functions and iterators
```
Containers: sequential (vector, etc), associate and stacks...

Template:
```CPP
template <typename T>
T func(T a, T b){return a;}
```
