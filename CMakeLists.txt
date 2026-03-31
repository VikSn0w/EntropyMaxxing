cmake_minimum_required(VERSION 4.1)
project(entropymaxxing C)

set(CMAKE_C_STANDARD 11)

add_executable(entropymaxxing main.c
        addons.c
        SORTINGS/MiracleSort/MiracleSort.c
        SORTINGS/MiracleSort/MiracleSort.h
        SORTINGS/BogoSort/BogoSort.c
        SORTINGS/BogoSort/BogoSort.h
        SORTINGS/ThanosSort/ThanosSort.c
        SORTINGS/ThanosSort/ThanosSort.h
        SORTINGS/StalinSort/StalinSort.c
        SORTINGS/StalinSort/StalinSort.h
        SORTINGS/NoSort/NoSort.c
        SORTINGS/NoSort/NoSort.h
        SORTINGS/PickOne/PickOne.c
        SORTINGS/PickOne/PickOne.h
        SORTINGS/SleepSort/SleepSort.c
        SORTINGS/SleepSort/SleepSort.c
        SORTINGS/SleepSort/SleepSort.h
        SORTINGS/BozoSort/BozoSort.c
        SORTINGS/PancakeSort/PancakeSort.c
        SORTINGS/PancakeSort/PancakeSort.h
        SORTINGS/BeadSort/BeadSort.c
        SORTINGS/BeadSort/BeadSort.h
        SORTINGS/SlowSort/SlowSort.c
        SORTINGS/SlowSort/SlowSort.h
        SORTINGS/StoogeSort/StoogeSort.c
        SORTINGS/StoogeSort/StoogeSort.h
        SORTINGS/JingleSort/JingleSort.c
        SORTINGS/JingleSort/JingleSort.h
        SORTINGS/IntelligentDesignSort/IntelligentDesignSort.c
        SORTINGS/IntelligentDesignSort/IntelligentDesignSort.h
        SORTINGS/QuantumBogosort/QuantumBogosort.c
        SORTINGS/QuantumBogosort/QuantumBogosort.h)
