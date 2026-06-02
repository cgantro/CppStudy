# C++ Deep Lab

현대 C++(C++17/20/23)을 핵심부터 시스템 수준까지 단계적으로 학습하는 저장소입니다.

## 구조

```
CppStudy/
├── studies/        # 개념별 학습 예제 (각 폴더 = 하나의 주제)
├── labs/           # 단발성 실험 코드
├── projects/       # 응용 프로젝트
├── notes/          # 학습 기록
├── docs/           # 로드맵 / 설계 문서
├── tests/          # 테스트
├── benchmarks/     # 성능 측정
└── cmake/          # 공통 빌드 설정
```

## 빌드

**요구사항:** CMake 3.20+, C++20 지원 컴파일러 (GCC 11 / Clang 13 / MSVC 2022 이상)

```bash
cmake -B build -G Ninja   # 또는 -G "Visual Studio 17 2022"
cmake --build build
```

특정 예제만 빌드:

```bash
cmake --build build --target s01_type_system
```

## 학습 로드맵

| Phase | 주제 | 디렉토리 |
|-------|------|----------|
| 1 | 타입 시스템, 메모리, 포인터, const | `studies/01~05` |
| 2 | OOP — 클래스, 상속, 다형성 | `studies/10~14` |
| 3 | RAII, 스마트 포인터, 이동 의미론 | `studies/20~23` |
| 4 | 템플릿, SFINAE, Concepts | `studies/30~34` |
| 5 | STL — 컨테이너, 반복자, 알고리즘 | `studies/40~44` |
| 6 | 현대 C++ (C++17/20/23) | `studies/50~54` |
| 7 | 동시성 — 스레드, atomic, 락프리 | `studies/60~63` |
| 8 | 성능 최적화, Sanitizer | `studies/70~72` |
| 9 | 빌드 시스템 — CMake, Make, Ninja | `studies/80~82` |

전체 상세 로드맵 → [docs/Roadmap.md](docs/Roadmap.md)

## 참고 자료

- [cppreference.com](https://en.cppreference.com)
- *Effective Modern C++* — Scott Meyers
- *C++ Templates: The Complete Guide* — Vandevoorde & Josuttis
- *C++ Concurrency in Action* — Anthony Williams
