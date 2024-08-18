# Student Team Formation Project

## Overview

This project is designed to automate the process of forming student project teams based on various skill levels and preferences. It reads student data from a CSV file, creates balanced teams, computes skill scores for each team, and saves the results to an output CSV file.
![1](https://github.com/user-attachments/assets/094f6ac3-a435-43c5-8fb7-19d18d16867b)

## Features

- Load student data from a CSV file.
- Convert student information into structured objects.
- Create project teams while considering student preferences and skill levels.
- Compute and display scores for each team.
- Save team formation results to an output CSV file.

## Directory Structure

```
Student Team Formation/
├── csv_operations/
│   ├── csv_operations.cpp
│   ├── csv_operations.hpp
├── skill_level/
│   ├── skill_level.cpp
│   ├── skill_level.hpp
├── student_data/
│   ├── student_data.hpp
├── team_operations/
│   ├── team_operations.cpp
│   ├── team_operations.hpp
├── input.csv
├── main.cpp
├── Makefile
├── output.csv
├── README.md
```

## Dependencies

- **C++ Compiler:** Make sure you have a C++11 compatible compiler (e.g., g++).
- **Make:** A build tool to compile the project using the provided Makefile.

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/sijie-daiii/student-team-formation.git
cd student-team-formation
```

### 2. Build the Project

Use the provided `Makefile` to compile the project:

```bash
make
```

### 3. Run the Program

After compiling, run the executable:

```bash
./main
```

The program will prompt you to enter the input CSV file path, output file path, team size, and whether to prioritize student preferences.

### 4. Clean the Build Files

To remove the object files and the main executable, run:

```bash
make clean
```

## Input Format

The input CSV file should have the following structure:

```
Username,Programming Skill,Debugging Skill,Algorithm Skill,Avoid List,Prefer List
student1,Intermediate,Beginner,Advanced,student2:student3,student4:student5
...
```

- **Username:** The student's unique identifier.
- **Programming Skill:** One of `Beginner`, `Intermediate`, or `Advanced`.
- **Debugging Skill:** One of `Beginner`, `Intermediate`, or `Advanced`.
- **Algorithm Skill:** One of `Beginner`, `Intermediate`, or `Advanced`.
- **Avoid List:** A colon-separated list of students this student does not want to work with.
- **Prefer List:** A colon-separated list of students this student prefers to work with.

## Output Format

The output CSV file will contain the following columns:

```
Team number,Student usernames,Combined scores
1,student1;student2;student3,9;7;8
...
```

- **Team number:** The team identifier.
- **Student usernames:** A semicolon-separated list of students in the team.
- **Combined scores:** The total skill scores for Programming, Debugging, and Algorithms, respectively.

## Example Usage

To run the program with an example input file:

```bash
./main
```

Then provide the following inputs when prompted:

- Input file path: `input.csv`
- Output file path: `output.csv`
- Team size: `3` or `4`
- Prioritize student preferences: `y` or `n`

The results will be saved in `output.csv`.

## Contributing

[sijie-daiii](https://github.com/sijie-daiii)
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```
