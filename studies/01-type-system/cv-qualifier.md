## const, volatile

### `const`의 핵심
```cpp
int x = 10;
const int y = 30;
// y = 30;
```
const는 이 이름을 통해 수정할 수 없다는 의미
```cpp
int x = 10;
const int* p1 = &x; // const int에 대한 포인터
int* const p2 = &x; // const 포인터에 대한 int
const int* const p3 = &x;
```

---

### top-level const vs low-level const
```cpp
const int x = 10;
int y = x // top level const는 복사 시에 사라진다.

int a 10;
const int* p = &a;
int *q = p;
// low-level const 제거 불가

// auto 타입 추론에서 중요함.
const int x = 10;

auto a = x;       // int
const auto b = x; // const int
auto& c = x;      // const int&
```