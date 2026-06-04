## auto 타입 추론

`auto`는 초기화 식으로부터 타입을 추론한다.

- 표준에서는 `placeholder type`이 추론된 타입으로 대체되는 과정을 `deduction`으로 정의한다

```cpp
int x = 10;
const int cx = 20;

auto a = x;   // int         (top-level const 제거)
auto b = cx;  // int         (top-level const 제거)
auto& c = cx; // const int&  (참조로 받으면 const 유지)
```

`auto`는 참조와 top-level const를 기본적으로 버린다.

```cpp
int x = 10;
int& r = x;

auto  a = r;  // int   (참조 벗겨짐)
auto& b = r;  // int&
```

### `auto`와 범위 기반 for

```cpp
std::vector<std::string> names = {"Alice", "Bob"};

for (auto name : names)       // 복사
for (auto& name : names)      // 참조 (수정 가능)
for (const auto& name : names) // const 참조 (읽기 전용, 복사 없음) ← 권장
```

---

### `auto&&` — Forwarding Reference

템플릿 또는 `auto&&` 문맥에서 lvalue가 오면 lvalue 참조, rvalue가 오면 rvalue 참조로 추론된다.

```cpp
template <typename T>
void inspect(T&& value) {
    if constexpr (std::is_lvalue_reference_v<T>) {
        std::cout << "lvalue\n";
    } else {
        std::cout << "rvalue\n";
    }
}

int a = 10;
inspect(a);   // lvalue
inspect(10);  // rvalue
```

#### [forwarding reference](https://deulee.tistory.com/120)

---

## `decltype`

#### [코드](./code/decltype.cpp)

표현식의 **정확한 타입(값 범주 포함)**을 얻는다. `auto`와 달리 참조와 const를 그대로 보존한다.

```cpp
int x = 10;

decltype(x)    // int    — x라는 이름의 선언 타입
decltype((x))  // int&   — (x)는 lvalue 표현식이므로 lvalue 참조

static_assert(std::is_same_v<decltype(x),   int>);
static_assert(std::is_same_v<decltype((x)), int&>);
```

- 표준은 "타입을 참조하기 위한 용도"로 사용하라고 한다
- 일반적인 완전 타입 요구가 적용되지 않는 경우도 있다

---

### `decltype(auto)`

`auto`의 추론 규칙이 아니라 `decltype`의 규칙을 따르면서 초기화식으로부터 타입을 결정한다.  
반환 타입에서 참조를 그대로 전달해야 할 때 유용하다.

```cpp
int x = 10;
int& ref = x;

auto           a = ref;  // int   (참조 벗겨짐)
decltype(auto) b = ref;  // int&  (참조 유지)

// 반환 타입에서 활용
decltype(auto) getRef() {
    static int v = 42;
    return v;   // decltype(v) → int, 값 반환
}

decltype(auto) getRef2() {
    static int v = 42;
    return (v);  // decltype((v)) → int&, 참조 반환
}
```
