# CSCI-3160-Matrix-Multiplication-Project
Naïve Matrix Multiplication Comparison Project
Goal
The purpose of this project is to capstone the lecture material over computer systems hardware and compilation and the work performed in the optimization and vector operations labs with a study that compares naïve matrix multiplication execution time across several programming languages and runtime environments.

Teams of 4 or 5 students will produce, at a minimum, a set of applications that perform naïve matrix multiplication in a compiled language, an interpreted language, and a just-in-time (JIT) compiled language. In addition, student teams will benchmark each implementation and present their results during a presentation during the last week of classes.

Teams may exceed project expectations by incorporating systems hardware knowledge, linear algebra and parallelization libraries, and hardware accelerators for further experimentation in reducing naïve matrix multiplication’s execution time.

Requirements
At a minimum, the project shall consist of:

Three applications implementing naïve square matrix multiplication on 32-bit signed integers and 64-bit floating point numbers.
Applications shall be implemented in C, Python 3.x, and Java.
All applications shall benchmark matrices of size 128, 256, and 512.
Multiplicand matrices (matrix A) shall consist of elements of all 1s, all 2s, and incrementing by 1 per element in row-major order.
Multiplier matrices (matrix B) shall consist of the identity matrix, all 1s, and all 2s.
Each application shall be capable of writing the product matrix to the standard output.
Benchmarks shall consist of wall-clock time measurements for execution time of matrix multiplication.
Benchmark recordings shall be recorded with at least one-hundredth of a second precision.
Benchmarking experiments shall be performed in the supplied 3160 environment on ETSU Brinkley Center Computing lab machines.
For more detailed requirements, refer to the full project description.

Presentation
Student teams shall prepare a 10–15-minute presentation that includes:

Introduction of the student team
Description of experiments performed
Demonstration of implementations using a small square matrix
Reporting results from experimentation
Analysis of observed results
Retrospective on the project’s development process
Exceeding Expectations
Suggestions for exceeding expectations include:

Implementing matrix multiplication using additional libraries
Accelerating matrix multiplication via parallelism, vector-based operations, or hardware accelerators
Leveraging memory hierarchy optimizations
Deliverables
Submit source codes, benchmarking results, and presentation materials to the Dropbox by the last day of classes. Include directions for installing any required tools or libraries.

Grading
Functional matrix multiplication source codes meeting the project requirements, along with a sufficient presentation, meet expectations. Exceeding expectations depends on the quality of extensions for the experiment and excellence of the presentation.


