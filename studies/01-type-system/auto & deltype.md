## auto 타입 추론

`auto`는 초기화 식으로부터 타입을 추론한다.

- 표준에서는 `placeholder type`이 추론된 타입으로 대체되는 과정을 `deduction`으로 정의한다

```cpp
int x = 10;
const int cx = 20;

auto a = x; // int
auto b = cx; // int, top-level const가 제거 되었다.
auto& c = cx; // const int&
```

auto는 참조를 기본적으로 버린다.

```cpp
int x = 10;
int& r = x;
auto a = r; // int
auto& b= r; // int&
```

#### `auto&&`는 forwarding reference가 될 수 있다.

#### [forwarding reference](https://deulee.tistory.com/120)

```cpp
template <typename T>
void inspect(T&& value){
    if constexpr(std::is_lvalue_reference_v<T>){
        std::cout << "lvalue" << std::endl;
    }else{
        std::cout << "rvalue" << std::endl;
    }
}
```

## `decltype`

## [코드](./code/decltype.cpp)

표현식의 타입을 얻음.

- `auto`와 다르게, 값 범주를 더 민감하게 반영함.
- 표준은 Type을 참조하기 위한 용도로 사용하라고 함
- 일반적인 완전 타입 요구가 적용되지 않는 경우도 있음.

```cpp
int x = 10;
static_assert(std::is_same_v<decltype(x),int>);
static_assert(std::is_same_v<decltype(x),int&>);

decltype(x) // x라는 이름의 선언 타입: int
decltype((x)) // 표현식 (x)는 lvalue: int&
```
