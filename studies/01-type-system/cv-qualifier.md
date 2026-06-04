## const, volatile

---

### `const`의 핵심

"이 이름을 통해서는 수정할 수 없다"는 의미. 객체 자체가 불변인 것과 다르다.

```cpp
int x = 10;
const int y = 30;
// y = 40;  // 에러

int x = 10;
const int*  p1 = &x;  // const int에 대한 포인터 (가리키는 값 수정 불가)
int* const  p2 = &x;  // int에 대한 const 포인터 (포인터 자체 수정 불가)
const int* const p3 = &x;  // 둘 다 const
```

---

### top-level const vs low-level const

```cpp
const int x = 10;
int y = x;  // top-level const는 복사 시 사라짐

int a = 10;
const int* p = &a;
// int* q = p;  // 에러: low-level const는 제거 불가

// auto 타입 추론에서 중요
const int cx = 10;
auto  a = cx;   // int         (top-level const 제거)
auto& b = cx;   // const int&  (참조로 받으면 유지)
```

---

### `volatile`

컴파일러 최적화를 막는 키워드. "이 변수는 프로그램 외부에서 언제든 바뀔 수 있다"는 의미다.

```cpp
volatile int reg = 0;  // 메모리 맵 레지스터 등
```

컴파일러는 보통 반복 읽기를 레지스터 캐싱으로 최적화한다. `volatile`이 있으면 매번 실제 메모리에서 읽는다.

```cpp
// volatile 없으면 컴파일러가 루프를 최적화해 한 번만 읽을 수 있음
volatile bool ready = false;
while (!ready) {}  // ready가 다른 곳(인터럽트 등)에서 바뀌길 기다림
```

- 멀티스레드 동기화에는 `volatile`이 아닌 `std::atomic`을 사용해야 한다
- `volatile`은 원자성이나 메모리 순서를 보장하지 않는다

---

### `mutable`

`const` 멤버 함수 안에서도 수정 가능한 멤버를 표시한다.  
논리적 const(외부 관찰 가능한 상태는 변하지 않음)를 유지하면서 내부 캐시 등을 갱신할 때 쓴다.

```cpp
class Cache {
public:
    int get(int key) const {
        if (cache_valid_) return cached_value_;  // const 함수
        cached_value_ = compute(key);  // mutable이므로 수정 가능
        cache_valid_ = true;
        return cached_value_;
    }
private:
    int         compute(int key) const { return key * 2; }
    mutable int cached_value_ = 0;
    mutable bool cache_valid_ = false;
};
```

---

### `constexpr` vs `const`

| | `const` | `constexpr` |
|---|---|---|
| 값 결정 시점 | 런타임도 가능 | 반드시 컴파일 타임 |
| 함수에 적용 | 멤버 함수의 const | 컴파일 타임 평가 가능 함수 |
| 용도 | 읽기 전용 보장 | 상수 표현식, 배열 크기, 템플릿 인자 |

```cpp
const int a = rand();       // ok: 런타임 값도 됨
// constexpr int b = rand();  // 에러: 컴파일 타임에 알 수 없음
constexpr int c = 42;       // ok

constexpr int square(int x) { return x * x; }
constexpr int val = square(5);  // 컴파일 타임에 25로 대체됨
```
