find_package(benchmark REQUIRED)

add_executable(BENCHMARK_INDICES benchmark_indices.cpp)
target_compile_options(BENCHMARK_INDICES PRIVATE "-O3")
target_link_libraries(BENCHMARK_INDICES PRIVATE benchmark matrix)
