<a href="url"><img src="https://raw.githubusercontent.com/VikSn0w/EntropyMaxxing/refs/heads/main/gitimg/cover.png" align="center" height="auto" width="100%" ></a>


# 🌀 EntropyMaxxing

Welcome to **EntropyMaxxing**, a C-based (C11 standard compliant) collection of the most cursed, inefficient, and bizarre "sorting" algorithms known to computer science.

If you are looking for `O(n log n)` performance, you are in the wrong place. We optimize for high entropy, multithreaded chaos, and hoping the universe aligns our arrays for us.

If you use one of these monstrosities in production, you will be fired, into the sun.

## 📦 Included Sorting Algorithms

Below is the directory of included sorting algorithms, along with their completely practical and highly competitive theoretical complexities:

| Algorithm | Time Complexity (Avg/Worst) | Space Complexity | Description                                                                                                                                                                    |
| :--- | :--- | :--- |:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Bead Sort** | `O(n * max)` | `O(n * max)` | Simulates falling beads. Allocates a 2D matrix proportional to the maximum value in the array.                                                                                 |
| **Bogo Sort** | `O(n * n!)` | `O(1)` | Randomly shuffles the array over and over until it magically becomes sorted.                                                                                                   |
| **Bozo Sort** | `O(n * n!)` | `O(1)` | Picks two random elements and swaps them until the array is sorted.                                                                                                            |
| **Intelligent Design Sort** | `O(1)` | `O(1)` | The array is exactly how the creator intended it to be. It skips sorting entirely.                                                                                             |
| **Jingle Sort** | `O(max + n)` | `O(n)` | A festive take on Sleep Sort. Spawns threads that sleep proportionally to their value before appending themselves.                                                             |
| **Miracle Sort** | `O(∞)` | `O(1)` | Continuously checks if the array is sorted, waiting for cosmic rays or divine intervention to flip the bits into order.                                                        |
| **No Sort** | `O(n)` | `O(1)` | Checks if the array is sorted, and if it isn't... well, it just gives up.                                                                                                      |
| **Pancake Sort** | `O(n²)` | `O(1)` | Sorts the array by repeatedly flipping prefixes, much like flipping a stack of pancakes with a spatula.                                                                        |
| **Pick One** | `O(1)` | `O(1)` | Destroys the array by shrinking its size to `1` and assigning it a random element from the original data, which by definition, is a perfectly sorted array.                    |
| **Quantum Bogo Sort** | `O(n)`* | `O(1)` | Randomizes the array. If it's not sorted, it terminates the program (and thus the universe timeline). *You will only observe the `O(n)` timeline where it succeeded first try. |
| **Sleep Sort** | `O(max + n)` | `O(n)` | Assigns a thread to each element, making the thread sleep for a duration proportional to the element's value.                                                                  |
| **Slow Sort** | `O(n ^ (log n))` | `O(n)` | A "multiply and surrender" algorithm. It is recursively, intentionally, and beautifully awful.                                                                                 |
| **Stalin Sort** | `O(n)` | `O(1)` | Single-pass sort that ruthlessly eliminates (deletes) any element that is not in order.                                                                                        |
| **Stooge Sort** | `O(n^2.709)` | `O(n)` | Recursively sorts the first 2/3, the last 2/3, and the first 2/3 again.                                                                                                        |
| **Thanos Sort** | `O(n)` | `O(1)` | Repeatedly snaps half the array out of existence until the remaining surviving elements happen to be perfectly sorted.                                                         |
## 🛠️ Prerequisites

To build and run this project, you will need:
* A C compiler supporting the **C11 standard** or later.
* **CMake** (version 4.1 or higher).
* POSIX Threads (`pthread`) support (required by Sleep Sort and Jingle Sort).

## 🚀 Building and Running

This project uses CMake for building.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/VikSn0w/entropymaxxing.git](https://github.com/VikSn0w/entropymaxxing.git)
   cd entropymaxxing
Generate build files and compile:

Bash
mkdir build
cd build
cmake ..
make
Run the executable:

Bash
./entropymaxxing
Note: The main entry point main.c is currently configured to test jingle_sort. You can easily swap it out for any other sorting header provided in the SORTINGS/ directory!

📂 Repository Structure
main.c: The entry point of the program.

addons.c / addons.h: Helper utilities for array manipulation (swapping, checking if sorted, printing, etc.).

import.h: Standard library includes used across the project.

SORTINGS/: Contains subdirectories for every sorting algorithm, complete with their .c implementations and .h headers.

⚠️ Disclaimer
Please do not use any of these algorithms in a production environment. Half of them will crash your system, wait until the end of time, or purposefully delete your data. Use them strictly for educational chaos.