# C++ Deep Lab — Roadmap

## 목표
현대 C++(C++17/20/23)을 핵심부터 시스템 수준까지 체계적으로 학습한다.

---

## Phase 1 — 기초 재정비 (C++ Core)

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| 타입 시스템 & 값 카테고리 (lvalue/rvalue) | `studies/01-type-system/` | [ ] |
| 메모리 모델 & 스택/힙 | `studies/02-memory/` | [ ] |
| 포인터 & 레퍼런스 심화 | `studies/03-pointers/` | [ ] |
| const / constexpr / consteval | `studies/04-const/` | [ ] |
| 함수 오버로딩 & 기본 인자 | `studies/05-functions/` | [ ] |

---

## Phase 2 — 객체 지향 (OOP)

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| 클래스 설계 & 접근 제어 | `studies/10-classes/` | [ ] |
| 생성자 / 소멸자 / 복사·이동 의미론 | `studies/11-special-members/` | [ ] |
| 상속 & 가상 함수 & vtable | `studies/12-inheritance/` | [ ] |
| 다형성 & 순수 가상 함수 | `studies/13-polymorphism/` | [ ] |
| 연산자 오버로딩 | `studies/14-operators/` | [ ] |

---

## Phase 3 — 리소스 관리

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| RAII 패턴 | `studies/20-raii/` | [ ] |
| 스마트 포인터 (unique_ptr / shared_ptr / weak_ptr) | `studies/21-smart-ptrs/` | [ ] |
| 이동 의미론 & perfect forwarding | `studies/22-move-semantics/` | [ ] |
| 예외 안전성 (noexcept, strong guarantee) | `studies/23-exceptions/` | [ ] |

---

## Phase 4 — 템플릿 & 제네릭 프로그래밍

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| 함수 / 클래스 템플릿 기초 | `studies/30-templates-basic/` | [ ] |
| 템플릿 특수화 & SFINAE | `studies/31-sfinae/` | [ ] |
| 가변 인자 템플릿 (variadic) | `studies/32-variadic/` | [ ] |
| Concepts (C++20) | `studies/33-concepts/` | [ ] |
| 템플릿 메타프로그래밍 기초 | `studies/34-tmp/` | [ ] |

---

## Phase 5 — STL & 표준 라이브러리

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| 컨테이너 내부 구조 & 복잡도 | `studies/40-containers/` | [ ] |
| 반복자 & 범위(Range) | `studies/41-iterators/` | [ ] |
| 알고리즘 & 람다 | `studies/42-algorithms/` | [ ] |
| Ranges (C++20) | `studies/43-ranges/` | [ ] |
| 문자열 & 스트림 | `studies/44-strings/` | [ ] |

---

## Phase 6 — 현대 C++ (C++17/20/23)

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| structured binding & if constexpr | `studies/50-cpp17/` | [ ] |
| std::optional / variant / any | `studies/51-vocabulary-types/` | [ ] |
| Coroutines (co_await / co_yield) | `studies/52-coroutines/` | [ ] |
| Modules (C++20) | `studies/53-modules/` | [ ] |
| std::format & std::print (C++23) | `studies/54-cpp23/` | [ ] |

---

## Phase 7 — 동시성 & 시스템

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| std::thread & 동기화 기본 | `studies/60-threading/` | [ ] |
| std::atomic & 메모리 오더 | `studies/61-atomics/` | [ ] |
| std::async / future / promise | `studies/62-async/` | [ ] |
| 락프리 자료구조 기초 | `studies/63-lockfree/` | [ ] |

---

## Phase 8 — 성능 & 디버깅

| 주제 | 디렉토리 | 상태 |
|------|----------|------|
| 컴파일러 최적화 & 인라이닝 | `studies/70-optimization/` | [ ] |
| 캐시 친화적 자료구조 | `studies/71-cache/` | [ ] |
| Valgrind / AddressSanitizer | `studies/72-sanitizers/` | [ ] |
| 벤치마킹 (Google Benchmark) | `benchmarks/` | [ ] |

---

## 응용 프로젝트 목록 (`projects/`)

| 프로젝트 | 핵심 개념 | 상태 |
|----------|-----------|------|
| 커스텀 allocator 구현 | 메모리 관리, 템플릿 | [ ] |
| 간단한 스마트 포인터 구현 | RAII, 이동 의미론 | [ ] |
| 스레드 풀 구현 | 동시성, 람다 | [ ] |
| 직렬화 라이브러리 | 템플릿 메타프로그래밍 | [ ] |
| 이벤트 시스템 / 시그널-슬롯 | 함수 포인터, std::function | [ ] |

---

## 디렉토리 규칙

```
studies/<번호>-<주제>/
    main.cpp        # 실행 가능한 예제
    notes.md        # 개념 요약 & 핵심 포인트
labs/<실험명>/
    *.cpp           # 단발성 실험 코드
projects/<프로젝트명>/
    CMakeLists.txt
    src/
    include/
tests/
    <주제>_test.cpp
benchmarks/
    <주제>_bench.cpp
```

---

## 참고 자료

- [cppreference.com](https://en.cppreference.com)
- *Effective Modern C++* — Scott Meyers
- *C++ Templates: The Complete Guide* — Vandevoorde & Josuttis
- *C++ Concurrency in Action* — Anthony Williams
- [CppCon YouTube](https://www.youtube.com/@CppCon)
