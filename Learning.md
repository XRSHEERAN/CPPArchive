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
