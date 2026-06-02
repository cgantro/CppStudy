## Enum

C 스타일 `enum`은 암시적으로 정수 변환이 된다.

```cpp
enum State{
    Idle,
    Running
};

int x = Idle; // 가능
```

`enum class`는 더 안전하다.

```cpp
enum class State{
    Idle,
    Running
};

State s = State::Idle;
int x = s; // 에러
int x = static_cast<int>(s); // 명시적 변환이 필요하다.

```

## 차이점

| 기능               | `enum`(Unscoped)                       | `enum class`(Scoped)                           |
| ------------------ | -------------------------------------- | ---------------------------------------------- |
| 스코프             | 전역(또는 선언된 범위)에 노출          | 열거형 내부에만 이름이 갇힘.                   |
| 암시적 형변환      | `int`타입으로 자동 변환                | 자동 변환 x                                    |
| 네임 스페이스 충돌 | 서로 다른 `enum`간 멤버 이름 중복 불가 | 동일한 멤버 이름을 다른 `enum`에서도 사용 가능 |
| 기본 데이터 타입   | 컴파일러 임의 지정                     | 기본적으로 `int` 고정                          |

## 스코프 이름 충돌

```cpp
enum Status{None, Success, Fail};
enum Result{Success, Warning}; // Success 중복이라 에러

enum class Status {None, Success, Fail};
enum class Result {Success, Warning};

Status s = Status::Success;
Result r = Result::Success;
```

## 기본 데이터 타입 지정

둘 다 원하는 경우 자료형 지정 가능

- 그러나 기본 작동 방식이 다름

`enum`

- 타입 명시 x -> 적당한 크기(보통은 `int`)를 알아서 할당

`enum class`

- 타입을 명시하지 않으면 `int` 고정

```cpp
// 메모리 절약을 위해 1바이트 크기 열거형 생성 가능
enum class EnemyType : unsigned char{
    Minion, Boss
}
```
