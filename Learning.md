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
