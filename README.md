# System Programming Assignment - Patient Records Handler

## Description

This program is a system programming assignment for the university course "Κ24 System Programming". It's designed to manage patient records using custom-implemented data structures that emulate the functionality of the Standard Template Library (STL).

### Compilation

Compile the code using a C++ compiler:

```bash
g++ -o programName *.cpp -I.
```

### Execution

Run the program with the following command:

```bash
./programName -p <patient_records_file> -h1 <disease_ht_entries> -h2 <country_ht_entries> -b <bucket_size>
```

### Examples of test files:

- sample.txt: Contains a small set of sample records for quick testing.
- sample2.txt: Contains a small set of sample records for quick testing.
- small.txt: A larger dataset to test the program's performance and capabilities.
- medium.txt: An even larger dataset
- large.txt: An even larger dataset

### Files and Modules

- main.cpp: Initializes and orchestrates the data processing workflow.
- diseaseMain.cpp: Handles disease-specific queries and operations.
- .cpp and .h files: Contain custom data structures mimicking STL components like linked lists, AVL trees, hash tables, heaps, etc.

### Project Structure

The project is structured with separate .cpp and .h files for each custom data structure and utility function, providing a learning platform for system programming and data structure implementation.

## License

This project is for educational use only and is part of the coursework for _Κ24 System Programming_ at _DiT, NKUA_.
