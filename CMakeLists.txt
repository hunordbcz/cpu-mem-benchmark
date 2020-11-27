cmake_minimum_required(VERSION 3.16)
project(scs_terminal)

set(CMAKE_CXX_STANDARD 14)

add_executable(scs_terminal
        main.cpp
        Benchmark.cpp Benchmark.h
        algorithms/Algorithm.cpp algorithms/Algorithm.h
        algorithms/TestAlgorithm.cpp algorithms/TestAlgorithm.h
        UI.cpp UI.h
        SystemInfo.cpp SystemInfo.h
        algorithms/GreatestCommonDivisor.cpp algorithms/GreatestCommonDivisor.h
        algorithms/FibonacciNumber.cpp algorithms/FibonacciNumber.h
        algorithms/PiApproximation.cpp algorithms/PiApproximation.h
        algorithms/PiApproximation.cpp algorithms/PiApproximation.h
        algorithms/Ackermann.cpp algorithms/Ackermann.h
        algorithms/LucasLehmer.cpp algorithms/LucasLehmer.h
        algorithms/LIIDS.cpp algorithms/LIIDS.h)
target_link_libraries(scs_terminal pthread)