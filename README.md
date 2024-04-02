# LBYARCH-MCO2
**Members**: GABINI, Brian Pitallo | VERANO, Carl Matthew<br>
**Section**: S13

## Correctness Check
![image](https://github.com/briangabini/LBYARCH-MCO2/assets/113345631/2a3b4b3b-a5a1-4d45-82a2-8848b8aec71b)<br>
The correctness check is simply comparing the C and Assembly outputs; thus both outputs were printed right after the other to cross-check the values for correctness immediately.

## Brief Overview
The program performs the DAXPY function (A * X + Y) both in C and x86-64 Assembly; the vector’s first element is initialized as 1.0 and 11.0, respectively (for the first and second vector). Afterwards, its entries are filled by adding incrementally randomly from 1 to 100 per iteration. The execution times were measured 30 times for each vector size for both C and Assembly.

## Performance Results & Analysis: <br>
**Input size**: $2^{20}$, $2^{24}$, $2^{27}$ <br>
**Result metric**: seconds (s) <br>

![image](https://github.com/briangabini/LBYARCH-MCO2/assets/113345631/f03a970a-a1c0-40ab-aba7-49ff44969f88)<br>

Tests were done for vector sizes 220, 224 and only up to 227since the device lags anything beyond this value. The performances were obtained by averaging out the execution 30 times. <br>

For the debug configuration, both the C and Assembly kernel have minimal performance disparities, with some sizes of the vectors performing better for C, and others better in Assembly. However, for the release configuration, according to this [reference](https://community.st.com/t5/stm32cubeide-mcus/what-is-the-difference-between-debug-and-release-of-a-project/td-p/183634#:~:text=The%20difference%20is%20the%20compiler,unless%20performance%20becomes%20an%20issue.), this configuration optimizes the compiler, which may have significantly improved C’s performance compared to Assembly, which may have resulted in higher disparities in their performances.
