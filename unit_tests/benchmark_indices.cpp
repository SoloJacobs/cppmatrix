#include "indices.hpp"
#include "matrix.hpp"
#include <benchmark/benchmark.h>
#include <random>

static void TimeDefault(benchmark::State &state) {
  int size = state.range(0);
  Matrix<float> mat(size, size);
  std::random_device rd{};
  std::mt19937 gen{};
  std::uniform_real_distribution<float> dist(1.0, 2.0);
	benchmark::DoNotOptimize(mat);

  for (auto _ : state) {
    for (std::size_t i{0}; i < size; ++i) {
      for (std::size_t j{0}; j < size; ++j) {
        float a = dist(gen);
        mat(i, j) = a * i + j;
      }
    }
  }
}

static void TimeIndices(benchmark::State &state) {
  int size = state.range(0);
  Matrix<float> mat(size, size);
  std::random_device rd{};
  std::mt19937 gen{};
  std::uniform_real_distribution<float> dist(1.0, 2.0);
	benchmark::DoNotOptimize(mat);

  for (auto _ : state) {
    for (auto [i, j] : Indices(size, size)) {
      float a = dist(gen);
      mat(i, j) = a * i + j;
    }
  }
}

BENCHMARK(TimeDefault)->Arg(5)->Arg(100)->Arg(1000);

BENCHMARK(TimeIndices)->Arg(5)->Arg(100)->Arg(1000);

BENCHMARK_MAIN();
