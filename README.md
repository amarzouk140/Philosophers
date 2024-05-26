# Philosophers

The Philosophers project is a concurrent programming exercise designed to illustrate the problem of deadlock and resource sharing in a multi-threaded environment. The project simulates a classic synchronization problem called the Dining Philosophers Problem.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Dining Philosophers Problem is a well-known problem in computer science that illustrates the challenges of synchronizing multiple threads that share resources. The project involves implementing a solution to this problem using threads and mutexes to avoid deadlock and ensure that all philosophers can eat without conflicts.

## Features

- **Mandatory Part:**
  - Simulates the Dining Philosophers Problem using threads and mutexes.
  - Ensures that philosophers pick up and put down forks correctly.
  - Avoids deadlock and starvation.

- **Bonus Part:**
  - Additional synchronization mechanisms (e.g., semaphores).
  - Improved efficiency and fairness in resource allocation.
  - Visual representation of the philosophers' states.

## Requirements

- GNU Make
- GCC

## Installation

1. Clone the repository:

    ```sh
    git clone https://github.com/amarzouk140/philosophers.git
    cd philosophers
    ```

2. Compile the project:

    ```sh
    make
    ```

This will create the `philo` and `philo_bonus` executables for the mandatory and bonus parts, respectively.

## Usage

### Mandatory Part

To run the mandatory part of the project:

```sh
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
