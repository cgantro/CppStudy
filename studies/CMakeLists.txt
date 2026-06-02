# Phase 1 — Core
add_subdirectory(01-type-system)
add_subdirectory(02-memory)
add_subdirectory(03-pointers)
add_subdirectory(04-const)
add_subdirectory(05-functions)

# Phase 2 — OOP
add_subdirectory(10-classes)
add_subdirectory(11-special-members)
add_subdirectory(12-inheritance)
add_subdirectory(13-polymorphism)
add_subdirectory(14-operators)

# Phase 3 — Resource Management
add_subdirectory(20-raii)
add_subdirectory(21-smart-ptrs)
add_subdirectory(22-move-semantics)
add_subdirectory(23-exceptions)

# Phase 4 — Templates
add_subdirectory(30-templates-basic)
add_subdirectory(31-sfinae)
add_subdirectory(32-variadic)
add_subdirectory(33-concepts)
add_subdirectory(34-tmp)

# Phase 5 — STL
add_subdirectory(40-containers)
add_subdirectory(41-iterators)
add_subdirectory(42-algorithms)
add_subdirectory(43-ranges)
add_subdirectory(44-strings)

# Phase 6 — Modern C++
add_subdirectory(50-cpp17)
add_subdirectory(51-vocabulary-types)
add_subdirectory(52-coroutines)
add_subdirectory(53-modules)
add_subdirectory(54-cpp23)

# Phase 7 — Concurrency
add_subdirectory(60-threading)
add_subdirectory(61-atomics)
add_subdirectory(62-async)
add_subdirectory(63-lockfree)

# Phase 8 — Performance
add_subdirectory(70-optimization)
add_subdirectory(71-cache)
add_subdirectory(72-sanitizers)

# Phase 9 — Build Systems
add_subdirectory(80-cmake)
add_subdirectory(81-make)
add_subdirectory(82-ninja)
